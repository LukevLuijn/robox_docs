// ======================================
// Filename:
//   ConcreteStates.h
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

#ifndef ROBOX_STATE_MACHINE_TEST_CONCRETE_STATES
#define ROBOX_STATE_MACHINE_TEST_CONCRETE_STATES

#include <Arduino.h>

#include "Game.h"
#include "State.h"

using StateMachine::Context;
using StateMachine::Event;

class GameState : public StateMachine::State
{
public:
    ~GameState() override = default;

protected:
    GameState(Game& game, String name) : State(name), m_game(game)
    {
    }

protected:
    Game& m_game;
};

class StartState : public GameState
{
public:
    explicit StartState(Game& game) : GameState(game, "START")
    {
    }
    ~StartState() override = default;

    bool HandleEvent(const Event& event, Context& context) override;
    void EntryAction() override;
    void DoActivity() override;
    void ExitAction() override;
};

class WinState : public GameState
{
public:
    explicit WinState(Game& game) : GameState(game, "WIN")
    {
    }
    ~WinState() override = default;

    bool HandleEvent(const Event& event, Context& context) override;
    void EntryAction() override;
    void DoActivity() override;
    void ExitAction() override;
};

class LoseState : public GameState
{
public:
    explicit LoseState(Game& game) : GameState(game, "LOSE")
    {
    }
    ~LoseState() override = default;

    bool HandleEvent(const Event& event, Context& context) override;
    void EntryAction() override;
    void DoActivity() override;
    void ExitAction() override;
};

class AgainState : public GameState
{
public:
    explicit AgainState(Game& game) : GameState(game, "AGAIN")
    {
    }
    ~AgainState() override = default;

    bool HandleEvent(const Event& event, Context& context) override;
    void EntryAction() override;
    void DoActivity() override;
    void ExitAction() override;
};

#endif// ROBOX_STATE_MACHINE_TEST_CONCRETE_STATES