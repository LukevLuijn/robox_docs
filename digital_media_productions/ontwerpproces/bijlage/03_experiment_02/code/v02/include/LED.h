#ifndef EXP_02_LED_H
#define EXP_02_LED_H

#include <Arduino.h>

namespace Devices
{
    enum class LEDStates_e : uint8_t;

    class LED
    {
    public:
        LED(uint8_t pin);
        virtual ~LED() = default;

        void Start();
        void Run();

        void Blink(uint16_t interval);

        void On();
        void On(uint32_t time);

        void Off();
    private:
        bool Timer(uint32_t& time, uint32_t interval);
        void WriteLED(LEDStates_e state);

    private:
        uint8_t m_pin;
        LEDStates_e m_state;
        LEDStates_e m_blinkState;

        uint32_t m_blinkTime;
        uint32_t m_blinkInterval;
        uint32_t m_offTimer;
    };

    enum class LEDStates_e : uint8_t
    {
        ON = 0,
        ON_TIME = 1,
        OFF = 2,
        BLINK = 3,
    };
}// namespace Devices

#endif// EXP_02_LED_H