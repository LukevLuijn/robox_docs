#ifndef EXP_02_LIMIT_H
#define EXP_02_LIMIT_H

#include <Arduino.h>

namespace Devices
{
    class Limit
    {
    public:
        Limit(uint8_t pin);
        virtual ~Limit() = default;

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

#endif// EXP_02_LIMIT_H