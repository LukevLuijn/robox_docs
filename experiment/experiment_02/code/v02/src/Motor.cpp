
#include "Motor.h"
#include "config.h"

namespace Devices
{
    Motor::Motor(uint8_t step, uint8_t dir, uint8_t enb, uint8_t hall, uint8_t microstepping, float reduction,
                 bool inverted)
        : AccelStepper(AccelStepper::DRIVER, step, dir), m_limit_pin(hall), m_limit(hall),
          m_microstepping(microstepping), m_motorState(MotorState_e::DISABLED), m_homingComplete(false)
    {
        m_stepsPerRevoltion = microstepping * DEFAULT_STEPS_PER_REVOLUTION * reduction;
        m_stepAngle = 360.0 / (m_stepsPerRevoltion);

        AccelStepper::setEnablePin(enb);
        AccelStepper::disableOutputs();
        AccelStepper::setMinPulseWidth(MIN_PULSE_WIDTH);

        setPinsInverted(inverted, false, false);
    }
    void Motor::Start()
    {
        float defaultSpeed = DEFAULT_STEPS_PER_REVOLUTION * m_microstepping * 1.875f;

        m_limit.Start();
        AccelStepper::enableOutputs();
        HomeMotor(defaultSpeed);
        m_homingComplete = true;
    }
    void Motor::Run()
    {
        AccelStepper::run();
    }
    void Motor::MoveDegrees(float degrees)
    {
        int32_t steps = degrees / m_stepAngle;
        AccelStepper::move(steps);
    }
    void Motor::RunDegrees(float degrees)
    {
        int32_t steps = degrees / m_stepAngle;
        AccelStepper::runToNewPosition(currentPosition() + steps);
    }
    void Motor::MoveToAngle(float angle)
    {
        int32_t position = angle / m_stepAngle;
        AccelStepper::moveTo(position);
    }
    void Motor::RunToAngle(float angle)
    {
        int32_t position = angle / m_stepAngle;
        AccelStepper::runToNewPosition(position);
    }
    float Motor::GetCurrentAngle()
    {
        int32_t position = AccelStepper::currentPosition();
        float angle = static_cast<float>(position) / m_stepAngle;
        return angle;
    }
    float Motor::GetDegreesToTarget()
    {
        uint32_t distance = AccelStepper::distanceToGo();
        float degrees = static_cast<float>(distance) / m_stepAngle;
        return degrees;
    }
    uint32_t Motor::GetStepsPerRevolution()
    {
        return m_stepsPerRevoltion;
    }
    uint8_t Motor::GetMicrostepping()
    {
        return m_microstepping;
    }
    bool Motor::HomingComplete()
    {
        return m_homingComplete;
    }
    void Motor::HomeMotor(float defaultSpeed)
    {
        setAcceleration(defaultSpeed);
        setMaxSpeed(defaultSpeed);

        const int32_t FAST = defaultSpeed/3;
        const int32_t SLOW = defaultSpeed/6;
        
        const uint32_t OFFSET = m_stepsPerRevoltion / 15;

        auto findLimit = [&](bool forwards) -> int32_t {
            setSpeed((forwards) ? FAST : -FAST);
            while (!m_limit.Triggered())
            {
                runSpeed();
            }
            runToNewPosition(currentPosition() + ((forwards) ? -OFFSET : OFFSET));
            setSpeed((forwards) ? SLOW : -SLOW);
            while (!m_limit.Triggered())
            {
                runSpeed();
            }
            return currentPosition();
        };

        int32_t pos_01 = findLimit(true);

        if (pos_01 > m_stepsPerRevoltion / 4)
        {
            setSpeed(defaultSpeed);
            move(m_stepsPerRevoltion * 0.3);
            runToPosition();
        }

        int32_t pos_02 = findLimit(false);

        if ((abs(pos_01) + abs(pos_02)) > m_stepsPerRevoltion / 2)
        {
            int32_t midPoint = (pos_01 + pos_02) / 2;
            // midPoint -= m_stepsPerRevoltion / 2;
            runToNewPosition(midPoint);
        }
        else
        {
            int32_t midPoint = (pos_01 + pos_02) / 2;
            runToNewPosition(midPoint);
        }

        stop();
        setCurrentPosition(0);
        setAcceleration(defaultSpeed);
        setMaxSpeed(defaultSpeed);
        moveTo(0);
    }


}// namespace Devices