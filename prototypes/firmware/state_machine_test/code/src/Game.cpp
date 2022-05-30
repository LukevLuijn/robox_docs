// ======================================
// Filename:
//   Game.cpp
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Game instance.
// ======================================

#include "Game.h"
#include "ConcreteStates.h"

void Game::Play()
{
    auto start = std::make_shared<StartState>(*this);
    SetCurrentState(start);
}

void Game::ThrowDice()
{
    m_diceA.Roll();
    m_diceB.Roll();

    StateMachine::Event event(static_cast<uint16_t>(m_diceA + m_diceB), 0);
    ScheduleEvent(event);
}