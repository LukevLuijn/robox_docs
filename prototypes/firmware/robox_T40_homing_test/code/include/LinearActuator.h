#ifndef ROBOX_CONTROLLER_DEVICE_LINEAR_ACTUATOR_H
#define ROBOX_CONTROLLER_DEVICE_LINEAR_ACTUATOR_H

#include "Actuator.h"

namespace Device
{
    class LinearActuator : public Actuator
    {
    public:
        LinearActuator(uint8_t stp, uint8_t dir, uint8_t enb, uint8_t limit, Microstepping_e microstepping, float reduction, bool inverted);
        ~LinearActuator() override = default;

        void MoveDistance(float distance);
        void MoveToHeight(float height);

        void RunDistance(float distance);
        void RunToHeight(float height);

        float GetCurrentHeight() const;
        float GetDistanceToTarget() const;

        void HomingSequence(float speed, float accel);

    private:
        float m_stepsPerMilimeter;
        uint8_t m_limitPin;
    };
}// namespace Device

#endif// ROBOX_CONTROLLER_DEVICE_LINEAR_ACTUATOR_H