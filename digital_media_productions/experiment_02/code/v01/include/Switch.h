#ifndef EXP_02_SWITCH_H
#define EXP_02_SWITCH_H

#include <Arduino.h>

namespace Devices
{
    class Switch
    {
    public:
        Switch(uint8_t pin);
        virtual ~Switch() = default;

        void Start();
        bool Triggered();

    private:
        uint8_t m_pin;
        int16_t m_lastSwitchState;
        int16_t m_switchState;
        int32_t m_lastDebounceTime;
        int32_t m_debounceDelay;
    };
}// namespace Devices

#endif// EXP_02_SWITCH_H