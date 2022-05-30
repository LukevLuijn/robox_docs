// ======================================
// Filename:
//   Game.h
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

#ifndef ROBOX_STATE_MACHINE_TEST_GAME_H
#define ROBOX_STATE_MACHINE_TEST_GAME_H

#include "Context.h"
#include "Dice.h"

class Game : public StateMachine::Context
{
public:
    Game() = default;
    ~Game() override = default;

    /**
     * @brief Start the game.
     * 
     */
    void Play();
    /**
     * @brief Trigger dice objects to generate a number.
     * 
     */
    void ThrowDice();

private:
    Dice m_diceA, m_diceB;
};

#endif// ROBOX_STATE_MACHINE_TEST_GAME_H