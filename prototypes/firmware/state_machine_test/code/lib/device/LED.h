// ======================================
// Filename:
//   LED.h
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

#ifndef ROBOX_STATE_MACHINE_TEST_DEVICE_LED_H
#define ROBOX_STATE_MACHINE_TEST_DEVICE_LED_H

#include <Arduino.h>

namespace Device
{
    enum class LEDState : uint8_t
    {
        ON = 0,
        OFF = 1,
        FADE_ON = 2,
        FADE_OFF = 3,
        BLINK = 4,
        BREATHE = 5,
    };

    enum class Waveform : uint8_t
    {
        GAUSSIAN = 0,
        CIRCULAR = 1,
        TRIANGLE = 2,
    };

    class LED
    {
    public:
        LED(uint8_t pin);
        virtual ~LED() = default;

        /**
         * @brief Start LED device.
         * 
         */
        void Start();
        /**
         * @brief Run LED device.
         * 
         */
        void Run();
        /**
         * @brief Turn LED on.
         * 
         * @param time If not zero, the led will turn off after this time in MS.
         */
        void On(uint32_t time = 0);
        /**
         * @brief Turn LED off.
         * 
         */
        void Off();
        /**
         * @brief Blink LED.
         * 
         * @param interval Interval to blink with.
         */
        void Blink(uint32_t interval);
        /**
         * @brief Fade LED on.
         * 
         * @param time Time in MS to fully turn on LED.
         * @param wave Wave type to fade with.
         */
        void FadeOn(uint32_t time, Waveform wave = Waveform::GAUSSIAN);
        /**
         * @brief Fade LED off.
         * 
         * @param time Time in MS to fully turn off LED.
         * @param wave Wave type to fade with.
         */
        void FadeOff(uint32_t time, Waveform wave = Waveform::GAUSSIAN);
        /**
         * @brief Breathe LED.
         * 
         * @param interval  Time in MS to breathe in (fadeOn) and breathe out (fadeOff).
         * @param wave      Wave type to breathe with.
         */
        void Breathe(uint32_t interval, Waveform wave = Waveform::GAUSSIAN);
        /**
         * @brief Set the max brightness of LED
         * 
         * @param brightness [1 - 255] max brightness.
         */
        void SetMaxBrightness(uint8_t brightness);

    private:
        void Fade(Waveform wave);
        void WriteLED(uint8_t value);

    private:
        const float GAMMA = 0.14f;
        const float BETA = 0.5f;

        uint8_t m_pin;
        LEDState m_state;

        uint32_t m_timer;
        uint32_t m_interval;

        uint8_t m_brightness;
        uint8_t m_maxBrightness;

        Waveform m_breatheWave;
        uint16_t m_breatheIndex;
        uint32_t m_deadline;
    };
}// namespace Device

#endif// ROBOX_STATE_MACHINE_TEST_DEVICE_LED_H