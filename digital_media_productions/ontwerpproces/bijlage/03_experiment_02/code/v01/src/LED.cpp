
#include "LED.h"

namespace Devices
{
    LED::LED(uint8_t pin) : m_pin(pin)
    {
    }
    void LED::Start()
    {
        pinMode(m_pin, OUTPUT);
    }
    void LED::Run()
    {
        switch (m_state)
        {
            case LEDStates_e::BLINK:
                if (Timer(m_blinkTime, m_blinkInterval))
                {
                    WriteLED(m_blinkState);
                    m_blinkState = (m_blinkState == LEDStates_e::ON) ? LEDStates_e::OFF : LEDStates_e::ON;
                }
                break;
            case LEDStates_e::ON_TIME:
                if (millis() >= m_offTimer)
                {
                    Off();
                }
            case LEDStates_e::ON:
            case LEDStates_e::OFF:
            default:
                break;
        }
    }
    void LED::Blink(uint16_t interval)
    {
        m_state = LEDStates_e::BLINK;

        m_blinkState = m_state;
        m_blinkInterval = interval;
        m_blinkTime = millis();
    }
    void LED::On()
    {
        m_state = LEDStates_e::ON;
        WriteLED(m_state);
    }
    void LED::On(uint32_t time)
    {
        m_state = LEDStates_e::ON_TIME;
        WriteLED(LEDStates_e::ON);
        m_offTimer = millis() + time;
    }
    void LED::Off()
    {
        m_state = LEDStates_e::OFF;
        WriteLED(m_state);
    }
    bool LED::Timer(uint32_t& time, uint32_t interval)
    {
        if (millis() - time >= interval)
        {
            time = millis();
            return true;
        }
        return false;
    }
    void LED::WriteLED(LEDStates_e state)
    {
        digitalWrite(m_pin, (state == LEDStates_e::ON) ? HIGH : LOW);
    }


}// namespace Devices