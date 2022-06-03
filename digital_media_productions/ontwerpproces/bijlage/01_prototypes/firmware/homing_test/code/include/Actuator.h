#ifndef ROBOX_CONTROLLER_DEVICE_ACTUATOR_H
#define ROBOX_CONTROLLER_DEVICE_ACTUATOR_H

#include <AccelStepper.h>
#include <Arduino.h>

#include "DeviceInterface.h"

namespace Device
{
    enum class Microstepping_e : uint8_t;

    class Actuator : public AccelStepper, Interface::IDevice
    {
    public:
        Actuator(uint8_t stp, uint8_t dir, uint8_t enb, Microstepping_e microstepping, float reduction, bool inverted);
        virtual ~Actuator() = default;

        virtual void Start() override;
        virtual void Run() override;

        Microstepping_e GetMicrostepping() const;
        float GetStepsPerRevolution() const;

    protected:
        Microstepping_e m_microstepping;
        float m_stepsPerRevolution;
    };

    enum class Microstepping_e : uint8_t
    {
        MS400 = 2,
        MS800 = 4,
        MS1600 = 8,
        MS3200 = 16,
        MS6400 = 32,
        MS12800 = 64,
    };
}// namespace Device

#endif//ROBOX_CONTROLLER_DEVICE_ACTUATOR_H