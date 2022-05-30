
#include "HallSensor.h"

namespace Device
{
    HallSensor::HallSensor(uint8_t pin) : m_pin(pin)
    {
    }
    void HallSensor::Start()
    {
        pinMode(m_pin, INPUT);
    }
    bool HallSensor::Trigger()
    {
        bool isTriggered = false;
        int16_t reading = digitalRead(m_pin);
        if (reading != m_lastSwitchState)
        {
            m_lastDebounceTime = millis();
        }

        if ((static_cast<int32_t>(millis()) - m_lastDebounceTime) > m_debounceDelay)
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
    uint8_t HallSensor::Raw()
    {
        return digitalRead(m_pin);
    }
}// namespace Device