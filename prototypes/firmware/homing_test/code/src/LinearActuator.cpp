
#include "LinearActuator.h"
#include "config.h"

namespace Device
{
    LinearActuator::LinearActuator(uint8_t stp, uint8_t dir, uint8_t enb, uint8_t limit, Microstepping_e microstepping,
                                   float reduction, bool inverted)
        : Actuator(stp, dir, enb, microstepping, reduction, inverted),
          m_stepsPerMilimeter(m_stepsPerRevolution / LEADSCREW_PITCH),
          m_limitPin(limit)
    {
    }
    void LinearActuator::MoveDistance(float distance)
    {
        float steps = distance * m_stepsPerMilimeter;
        move(steps);
    }
    void LinearActuator::RunDistance(float distance)
    {
        float steps = distance * m_stepsPerMilimeter;
        runToNewPosition(currentPosition() + steps);
    }
    void LinearActuator::HomingSequence(float speed, float accel)
    {
        int32_t homing = 0;

        pinMode(m_limitPin, INPUT);

        setMaxSpeed(speed);
        setAcceleration(accel);

        while (digitalRead(m_limitPin))
        {
            moveTo(homing);
            homing--;
            run();
            delayMicroseconds(300);
        }

        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);

        homing = 1;

        while (!digitalRead(m_limitPin))
        {
            moveTo(homing);
            run();
            homing++;
            delayMicroseconds(1000);
        }

        stop();
        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);
        moveTo(0);
    }
}// namespace Device