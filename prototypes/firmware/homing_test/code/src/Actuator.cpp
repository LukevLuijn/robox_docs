
#include "Actuator.h"

namespace
{
#define DEFAULT_STEPS_PER_REVOLUTION 200
#define DRIVER_MIN_PULSE_WIDTH 5
}// namespace

namespace Device
{
    Actuator::Actuator(uint8_t stp, uint8_t dir, uint8_t enb, Microstepping_e microstepping, float reduction,
                       bool inverted)
        : AccelStepper(AccelStepper::DRIVER, stp, dir), m_microstepping(microstepping)
    {
        m_stepsPerRevolution = DEFAULT_STEPS_PER_REVOLUTION * (uint8_t) m_microstepping * reduction;

        setEnablePin(enb);
        setMinPulseWidth(DRIVER_MIN_PULSE_WIDTH);
        disableOutputs();
        setPinsInverted(inverted, false, false);
    }
    void Actuator::Start()
    {
        enableOutputs();
    }
    void Actuator::Run()
    {
        run();
    }
}// namespace Device