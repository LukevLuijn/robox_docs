
#include "AxialActuator.h"
#include "HallSensor.h"

namespace Device
{
    AxialActuator::AxialActuator(uint8_t stp, uint8_t dir, uint8_t enb, uint8_t limit, Microstepping_e microstepping,
                                 float reduction, bool inverted, HomingStyle_e style)
        : Actuator(stp, dir, enb, microstepping, reduction, inverted), m_stepsPerDegree(360.0 / m_stepsPerRevolution),
          m_limitPin(limit), m_homingStyle(style)
    {
    }
    void AxialActuator::MoveDegrees(float degrees)
    {
        float steps = degrees / m_stepsPerDegree;
        move(steps);
    }
    void AxialActuator::RunDegrees(float degrees)
    {
        float steps = degrees / m_stepsPerDegree;
        runToNewPosition(currentPosition() + steps);
    }
    void AxialActuator::HomingSequence(float speed, float accel)
    {
        switch (m_homingStyle)
        {
            case HomingStyle_e::SINGLE_MAGNET:
                HomeSingleMagnet(speed, accel);
                break;
            case HomingStyle_e::DOUBLE_MAGNET:
                HomeDoubleMagnet(speed, accel);
                break;
        }
    }
    void AxialActuator::HomeSingleMagnet(float speed, float accel)
    {
        int32_t homing = 1;

        pinMode(m_limitPin, INPUT);
        setMaxSpeed(speed);
        setAcceleration(accel);

        while (digitalRead(m_limitPin))
        {
            moveTo(homing);
            homing++;
            run();
            delayMicroseconds(300);
        }

        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);

        homing = 0;

        while (!digitalRead(m_limitPin))
        {
            moveTo(homing);
            run();
            homing--;
            delayMicroseconds(1000);
        }

        int32_t pos01 = currentPosition();
        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);

        RunDegrees(30.0f);

        while (digitalRead(m_limitPin))
        {
            moveTo(homing);
            run();
            homing--;
            delayMicroseconds(1000);
        }

        int32_t pos02 = currentPosition();
        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);

        int32_t zeroPos = (180.0f / m_stepsPerDegree) + (pos01 + pos02) / 2;
        move(-zeroPos);

        while (distanceToGo() != 0)
        {
            run();
        }

        stop();
        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);
        moveTo(0);
    }
    void AxialActuator::HomeDoubleMagnet(float speed, float accel)
    {
        auto findPosition = [&](uint8_t limitPin, bool direction) -> int32_t {
            int32_t homing = (direction) ? 0 : 1;

            setMaxSpeed(speed);
            setAcceleration(accel);

            while (digitalRead(m_limitPin))
            {
                moveTo(homing);
                homing += (direction) ? -1 : 1;
                run();
                delayMicroseconds(300);
            }

            int32_t position = currentPosition();
            setCurrentPosition(0);
            setMaxSpeed(speed);
            setAcceleration(accel);
            homing = (direction) ? 1 : 0;

            while (!digitalRead(m_limitPin))
            {
                moveTo(homing);
                homing += (direction) ? 1 : -1;
                run();
                delayMicroseconds(5000);
            }

            position += currentPosition();
            setCurrentPosition(0);
            return position;
        };

        pinMode(m_limitPin, INPUT);
        int32_t magnetPosition0 = findPosition(m_limitPin, true);
        int32_t magnetPosition1 = findPosition(m_limitPin, false);

        setMaxSpeed(speed);
        setAcceleration(accel);

        int32_t midPoint = magnetPosition1 / 2;
        (void) magnetPosition0;

        move(-midPoint);
        while (distanceToGo() != 0)
        {
            run();
        }

        stop();
        setCurrentPosition(0);
        setMaxSpeed(speed);
        setAcceleration(accel);
        moveTo(0);
    }
}// namespace Device