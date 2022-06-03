// ======================================
// Filename:
//   LED.cpp
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Device control; LED.
// ======================================

#include "LED.h"
#include "Time.h"

namespace
{
    #define LED_BREATHE_SMOOTHNESS 500.0f
}

namespace Device
{
    LED::LED(uint8_t pin)
        : m_pin(pin), m_state(LEDState::OFF), m_timer(0), m_interval(0), m_brightness(0), m_maxBrightness(255),
          m_breatheWave(Waveform::GAUSSIAN), m_breatheIndex(0)
    {
    }
    void LED::Start()
    {
        pinMode(m_pin, OUTPUT);
    }
    void LED::Run()
    {
        if (Utils::Timer(m_timer, m_interval) && m_interval > 0)
        {
            switch (m_state)
            {
                case LEDState::FADE_ON:
                    Fade(m_breatheWave);
                    if (m_breatheIndex >= (LED_BREATHE_SMOOTHNESS / 2))
                    {
                        m_interval = 0;
                        m_state = LEDState::ON;
                    }
                    break;
                case LEDState::FADE_OFF:
                    Fade(m_breatheWave);
                    if (m_breatheIndex >= LED_BREATHE_SMOOTHNESS)
                    {
                        m_interval = 0;
                        m_state = LEDState::OFF;
                    }
                    break;
                case LEDState::BLINK:
                    m_brightness = (m_brightness != 0) ? 0 : m_maxBrightness;
                    WriteLED(m_brightness);
                    break;
                case LEDState::BREATHE:
                    Fade(m_breatheWave);
                    break;
                case LEDState::ON: Off(); break;
                case LEDState::OFF:
                default:
                    break;
            }
        }
    }
    void LED::On(uint32_t time)
    {
        m_state = LEDState::ON;
        WriteLED(m_maxBrightness);

        m_interval = time;
        m_timer = millis();
    }
    void LED::Off()
    {
        m_state = LEDState::OFF;
        WriteLED(0);
    }
    void LED::FadeOn(uint32_t time, Waveform wave)
    {
        m_state = LEDState::FADE_ON;

        m_breatheWave = wave;
        m_interval = max(time, (LED_BREATHE_SMOOTHNESS / 2)) / (LED_BREATHE_SMOOTHNESS / 2);
        m_breatheIndex = 0;
    }
    void LED::FadeOff(uint32_t time, Waveform wave)
    {
        m_state = LEDState::FADE_OFF;

        m_breatheWave = wave;
        m_interval = max(time, (LED_BREATHE_SMOOTHNESS / 2)) / (LED_BREATHE_SMOOTHNESS / 2);
        m_breatheIndex = LED_BREATHE_SMOOTHNESS / 2;
    }
    void LED::Blink(uint32_t interval)
    {
        m_state = LEDState::BLINK;

        m_timer = millis();
        m_brightness = (m_brightness > 0) ? 0 : m_maxBrightness;
        WriteLED(m_brightness);
        m_interval = interval;
    }
    void LED::Breathe(uint32_t interval, Waveform wave)
    {
        m_state = LEDState::BREATHE;
        m_breatheWave = wave;
        m_interval = max(interval, LED_BREATHE_SMOOTHNESS) / LED_BREATHE_SMOOTHNESS;
    }
    void LED::SetMaxBrightness(uint8_t brightness)
    {
        m_maxBrightness = brightness;

        if (m_brightness >= m_maxBrightness)
        {
            m_brightness = m_maxBrightness;
            WriteLED(m_brightness);
        }
    }
    // https://makersportal.com/blog/2020/3/27/simple-breathing-led-in-arduino
    void LED::Fade(Waveform wave)
    {
        float value = 0;
        switch (wave)
        {
            case Waveform::GAUSSIAN:
                value = m_maxBrightness *
                        (exp(-(pow(((m_breatheIndex / LED_BREATHE_SMOOTHNESS) - BETA) / GAMMA, 2.0)) / 2.0));
                break;
            case Waveform::CIRCULAR:
                value = m_maxBrightness *
                        sqrt(1.0 - pow(abs((2.0 * (m_breatheIndex / LED_BREATHE_SMOOTHNESS)) - 1.0), 2.0));
                break;
            case Waveform::TRIANGLE:
                value = m_maxBrightness * (1.0 - abs((2.0 * (m_breatheIndex / LED_BREATHE_SMOOTHNESS)) - 1.0));
                break;
            default:
                break;
        }
        m_brightness = (uint8_t) value;
        WriteLED(m_brightness);
        m_breatheIndex = (m_breatheIndex >= LED_BREATHE_SMOOTHNESS) ? 0 : m_breatheIndex + 1;
    }
    void LED::WriteLED(uint8_t value)
    {
        analogWrite(m_pin, value);
    }
}// namespace Device