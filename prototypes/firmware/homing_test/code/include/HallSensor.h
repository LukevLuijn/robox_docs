#ifndef ROBOX_CONTROLLER_DEVICE_HALL_SENSOR_H
#define ROBOX_CONTROLLER_DEVICE_HALL_SENSOR_H

#include <Arduino.h>

#include "DeviceInterface.h"

namespace Device
{
    class HallSensor : public Interface::IDevice
    {
    public:
        HallSensor(uint8_t pin);
        virtual ~HallSensor() = default;

        virtual void Start() override;
        virtual void Run() override;

        bool Trigger();
        uint8_t Raw();

    private:
        uint8_t m_pin;
        int16_t m_lastSwitchState;
        int16_t m_switchState;
        int32_t m_lastDebounceTime;
        int32_t m_debounceDelay;
    };
}// namespace Device

#endif// ROBOX_CONTROLLER_DEVICE_HALL_SENSOR_H