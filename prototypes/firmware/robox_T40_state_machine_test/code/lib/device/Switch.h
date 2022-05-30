// ======================================
// Filename:
//   Switch.h
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Device control; Switch.
// ======================================


#ifndef ROBOX_CONTROLLER_DEVICE_HALL_SENSOR_H
#define ROBOX_CONTROLLER_DEVICE_HALL_SENSOR_H

#include <Arduino.h>

namespace Device
{
    class Switch
    {
    public:
        Switch(uint8_t pin);
        virtual ~Switch() = default;

        /**
         * @brief Start switch device.
         * 
         */
        void Start();
        /**
         * @brief Check if switch was triggered, implements debounce.
         * 
         * @return true     If switch was triggered.
         * @return false    If switch was not triggered.
         */
        bool Trigger();
        /**
         * @brief Get raw value of switch pin.
         * 
         * @return uint8_t raw value of switch pin.
         */
        uint8_t GetRaw();

    private:
        uint8_t m_pin;
        int16_t m_lastSwitchState;
        int16_t m_switchState;
        int32_t m_lastDebounceTime;
        int32_t m_debounceDelay;
    };
}// namespace Device

#endif// ROBOX_CONTROLLER_DEVICE_HALL_SENSOR_H