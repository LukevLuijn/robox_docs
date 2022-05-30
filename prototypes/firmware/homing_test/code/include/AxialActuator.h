#ifndef ROBOX_CONTROLLER_DEVICE_AXIAL_ACTUATOR_H
#define ROBOX_CONTROLLER_DEVICE_AXIAL_ACTUATOR_H

#include "Actuator.h"

namespace Device
{
    enum class HomingStyle_e : uint8_t;

    class AxialActuator : public Actuator
    {
    public:
        AxialActuator(uint8_t stp, uint8_t dir, uint8_t enb,uint8_t limit, Microstepping_e microstepping, float reduction,
                      bool inverted, HomingStyle_e style);
        ~AxialActuator() override = default;

        void MoveDegrees(float degrees);
        void MoveToAngle(float angle);

        void RunDegrees(float degrees);
        void RunToAngle(float angle);

        float GetCurrentAngle() const;
        float GetDegreesToTarget() const;

        void HomingSequence(float speed, float accel);

    private:
        void HomeSingleMagnet(float speed, float accel);
        void HomeDoubleMagnet(float speed, float accel);

    private:
        float m_stepsPerDegree;
        uint8_t m_limitPin;
        HomingStyle_e m_homingStyle;
    };

    enum class HomingStyle_e : uint8_t
    {
        SINGLE_MAGNET = 0,
        DOUBLE_MAGNET = 1,
    };
}// namespace Device

#endif// ROBOX_CONTROLLER_DEVICE_AXIAL_ACTUATOR_H