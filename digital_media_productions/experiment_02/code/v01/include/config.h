#ifndef EXP_02_CONFIG_H
#define EXP_02_CONFIG_H

// =========================== //
//      PIN CONFIGURATION      //
// =========================== //

#define M1_STP 8 // Motor 01 step pin
#define M1_DIR 9 // Motor 01 direction pin
#define M1_ENB 10// Motor 01 enable pin

#define M2_STP 5// Motor 02 step pin
#define M2_DIR 6// Motor 02 direction pin
#define M2_ENB 7// Motor 02 enable pin

#define M3_STP 0// Motor 03 step pin
#define M3_DIR 0// Motor 03 direction pin
#define M3_ENB 0// Motor 03 enable pin

#define M4_STP 0// Motor 04 step pin
#define M4_DIR 0// Motor 04 direction pin
#define M4_ENB 0// Motor 04 enable pin

#define M5_STP 0// Motor 05 step pin
#define M5_DIR 0// Motor 05 direction pin
#define M5_ENB 0// Motor 05 enable pin

#define M1_HALL 2// hall effect sensor 01 pin
#define M2_HALL 3// hall effect sensor 02 pin
#define M3_HALL 0// hall effect sensor 03 pin
#define M4_HALL 0// hall effect sensor 04 pin
#define M5_HALL 0// hall effect sensor 05 pin

#define LED_01 19// LED 01 pin
#define LED_02 18// LED 02 pin

#define BUTTON_01 22// Button 01 pin

// =========================== //
//    GENERAL CONFIGURATION    //
// =========================== //

#define M1_MICROSTEPPING 8// Microstepping configuration motor 01 (steps multiplier)
#define M2_MICROSTEPPING 8// Microstepping configuration motor 02 (steps multiplier)
#define M3_MICROSTEPPING 0// Microstepping configuration motor 03 (steps multiplier)
#define M4_MICROSTEPPING 0// Microstepping configuration motor 04 (steps multiplier)
#define M5_MICROSTEPPING 0// Microstepping configuration motor 05 (steps multiplier)

#define M1_MECHANICAL_REDUCTION 7.2f// Mechanical reduction motor 01
#define M2_MECHANICAL_REDUCTION 7.2f// Mechanical reduction motor 02
#define M3_MECHANICAL_REDUCTION 0.0f// Mechanical reduction motor 03
#define M4_MECHANICAL_REDUCTION 0.0f// Mechanical reduction motor 04
#define M5_MECHANICAL_REDUCTION 0.0f// Mechanical reduction motor 05

#define MIN_PULSE_WIDTH 5               // Minimal pulse width
#define DEFAULT_STEPS_PER_REVOLUTION 200// Default steps per revolution (1.8 degrees)

#endif// EXP_02_CONFIG_H