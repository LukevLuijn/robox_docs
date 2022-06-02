
#include "Switch.h"

namespace Devices
{
    Switch::Switch(uint8_t pin) : m_pin(pin)
    {
    }
    void Switch::Start()
    {
        pinMode(m_pin, INPUT);
    }
    bool Switch::Triggered()
    {
        bool isTriggered = false;
        int16_t reading = digitalRead(m_pin);
        if (reading != m_lastSwitchState)
        {
            m_lastDebounceTime = millis();
        }

        if ((millis() - m_lastDebounceTime) > m_debounceDelay)
        {
            if (reading != m_switchState)
            {
                m_switchState = reading;
                if (m_switchState == LOW)
                {
                    isTriggered = true;
                }
            }
        }
        m_lastSwitchState = reading;
        return isTriggered;
    }
}// namespace Devices