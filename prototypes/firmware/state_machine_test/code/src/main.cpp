// ======================================
// Filename:
//   main.cpp
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   main application
// ======================================

#include <Arduino.h>

#include "Game.h"
#include "Switch.h"

#include "ConcreteStates.h"
#include "config.h"

Device::Switch button(BUTTON_PIN);

void RunGame();

void setup()
{
    Serial.begin(9600);
    delay(1000);

    Serial.println("Hello world");
}
void loop()
{
  RunGame();
}

void RunGame()
{
    while (!button.Trigger())
    {
        // wait for user..
        delay(20);
    }

    Serial.println("Game start");

    Game game;
    game.Play();
    String won = "WIN", lost = "LOSE";
    for (;;)
    {
        game.HandleEventList();
        if (game.GetCurrentState()->GetName().equals(won))
        {
            Serial.println("WON!");
            break;
        }
        else if (game.GetCurrentState()->GetName().equals(lost))
        {
            Serial.println("LOST!");
            break;
        }
    }
}