// ======================================
// Filename:
//   ConcreteStates.cpp
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Concrete states.
// ======================================

#include "ConcreteStates.h"
#include "LED.h"
#include "Logger.h"
#include "config.h"

#include <memory>

namespace
{
    Device::LED LEDRed(5);
    Device::LED LEDGreen(7);
    Device::LED LEDBlue(9);
}// namespace

// ===========================================================
//                         STATE START
// ===========================================================
bool StartState::HandleEvent(const Event& event, Context& context)
{
    if (event.GetId() == 2)
    {
        Utils::Logger::PrintTransition(event.GetId(), "START", "LOSE");

        auto state = std::make_shared<LoseState>(m_game);
        context.SetCurrentState(state);
        return true;
    }
    else if (event.GetId() == 12)
    {
        Utils::Logger::PrintTransition(event.GetId(), "START", "WIN");

        auto state = std::make_shared<WinState>(m_game);
        context.SetCurrentState(state);
        return true;
    }
    else
    {
        Utils::Logger::PrintTransition(event.GetId(), "START", "AGAIN");

        auto state = std::make_shared<AgainState>(m_game);
        context.SetCurrentState(state);
        return true;
    }
}
void StartState::EntryAction()
{
    LEDRed.On();
    LEDGreen.On();
    LEDBlue.On();
}
void StartState::DoActivity()
{
    m_game.ThrowDice();
}
void StartState::ExitAction()
{
    LEDRed.Off();
    LEDGreen.Off();
    LEDBlue.Off();
}
// ===========================================================
//                         STATE WIN
// ===========================================================
bool WinState::HandleEvent(const Event& event, Context& context)
{
    (void) event;
    (void) context;
    return true;
}
void WinState::EntryAction()
{
    LEDGreen.On();
}
void WinState::DoActivity()
{
}
void WinState::ExitAction()
{
    LEDGreen.Off();
}
// ===========================================================
//                         STATE LOSE
// ===========================================================
bool LoseState::HandleEvent(const Event& event, Context& context)
{
    (void) event;
    (void) context;
    return true;
}
void LoseState::EntryAction()
{
    LEDRed.On();
}
void LoseState::DoActivity()
{
}
void LoseState::ExitAction()
{
    LEDRed.Off();
}
// ===========================================================
//                         STATE AGAIN
// ===========================================================
bool AgainState::HandleEvent(const Event& event, Context& context)
{
    if (event.GetId() == 2)
    {
        Utils::Logger::PrintTransition(event.GetId(), "AGAIN", "LOSE");

        auto state = std::make_shared<LoseState>(m_game);
        context.SetCurrentState(state);
        return true;
    }
    else if (event.GetId() == 12)
    {
        Utils::Logger::PrintTransition(event.GetId(), "AGAIN", "WIN");

        auto state = std::make_shared<WinState>(m_game);
        context.SetCurrentState(state);
        return true;
    }
    else
    {
        Utils::Logger::PrintTransition(event.GetId(), "AGAIN", "AGAIN");

        auto state = std::make_shared<AgainState>(m_game);
        context.SetCurrentState(state);
        return true;
    }
}
void AgainState::EntryAction()
{
}
void AgainState::DoActivity()
{
    LEDBlue.On();
    delay(GLOBAL_DELAY/2);
    LEDBlue.Off();
    delay(GLOBAL_DELAY/2);

    m_game.ThrowDice();
}
void AgainState::ExitAction()
{
}