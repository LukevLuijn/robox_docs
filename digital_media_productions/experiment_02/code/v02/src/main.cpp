#include <Arduino.h>
#include <vector>

#include "LED.h"
#include "Motor.h"
#include "Switch.h"
#include "config.h"

struct ArmLocation {
    float m_angleMotor1;
    float m_angleMotor2;
};

#define GRIPPER_OFFSET true
#define OFFSET_DEGREES -30

Devices::Motor m1(M1_STP, M1_DIR, M1_ENB, M1_HALL, M1_MICROSTEPPING, M1_MECHANICAL_REDUCTION, true);
Devices::Motor m2(M2_STP, M2_DIR, M2_ENB, M2_HALL, M2_MICROSTEPPING, M2_MECHANICAL_REDUCTION, false);

Devices::LED LEDGreen(LED_01);
Devices::LED LEDRed(LED_02);

Devices::Switch Button(BUTTON_01);

ArmLocation triggerAngle{0, -90};

enum class Locations_e : uint8_t
{
    FIRST_75 = 0,
    FIRST_150 = 1,
    FIRST_225 = 2,
    SECOND_75 = 3,
    SECOND_150 = 4,
    SECOND_225 = 5,
    BOTH_75 = 6,
    BOTH_150 = 7,
    BOTH_225 = 8,
};

std::vector<String> locationNames{
        "FIRST_75",
        "FIRST_150",
        "FIRST_225",
        "SECOND_75",
        "SECOND_150",
        "SECOND_225",
        "BOTH_75",
        "BOTH_150",
        "BOTH_225",
};

std::vector<ArmLocation> locations{
        {75, -90}, // FIRST_75
        {150, -90},// FIRST_150
        {225, -90},// FIRST_225
        {0, -15},  // SECOND_75
        {0, 60},   // SECOND_150
        {0, 135},  // SECOND_225
        {75, -15}, // BOTH_75
        {150, 60}, // BOTH_150
        {225, 135},// BOTH_225
};


const uint16_t BASE_SPEED = 200;// 60 RPM
const uint16_t MULTIPLIER = M1_MICROSTEPPING;

std::vector<uint32_t> speeds{
        (BASE_SPEED / 4) * MULTIPLIER,
        (BASE_SPEED / 2) * MULTIPLIER,
        (BASE_SPEED * 1) * MULTIPLIER,
        (BASE_SPEED * 2) * MULTIPLIER,
};

#define SAMPLE_SIZE 3

void RunExperiment();
void RunToLocation(ArmLocation location);
void MoveToLocation(ArmLocation location);

enum class ExperimentStage_e : uint8_t
{
    INITIAL = 0,
    STAGE_01 = 1,
    STAGE_02 = 2,
    STAGE_03 = 3,
    FINAL = 4,
};

ExperimentStage_e stage = ExperimentStage_e::INITIAL;
uint32_t previous;


void setup()
{
    Serial.begin(9600);
    delay(1000);

    Serial.println("program start");

    LEDGreen.Start();
    LEDRed.Start();

    Button.Start();

    m1.Start();
    m1.RunDegrees(150);

    while (m1.distanceToGo() != 0)
    {
        m1.Run();
    }

    m2.Start();

    Serial.println("setup complete");

    RunExperiment();
    MoveToLocation({0, 0});

    m1.disableOutputs();
    m2.disableOutputs();

    Serial.println("program complete");
}

void loop()
{
}

void RunExperiment()
{
    LEDRed.On();
    LEDGreen.On();

    for (size_t position = 0; position < locations.size(); ++position)
    {
        if (static_cast<Locations_e>(position) == Locations_e::FIRST_75 ||
            static_cast<Locations_e>(position) == Locations_e::SECOND_75 ||
            static_cast<Locations_e>(position) == Locations_e::BOTH_75)
        {
            MoveToLocation({0, 0});

            LEDRed.Blink(200);
            LEDGreen.Blink(200);

            m1.setMaxSpeed(speeds[0]);
            m2.setMaxSpeed(speeds[0]);

            m1.setAcceleration(speeds[0] * 2);
            m2.setAcceleration(speeds[0] * 2);

            MoveToLocation(triggerAngle);
            while (!Button.Triggered())
            {
                LEDRed.Run();
                LEDGreen.Run();
            }
            LEDRed.On();
            LEDGreen.Off();
        }
        LEDGreen.Off();

        for (size_t speed = 0; speed < speeds.size(); ++speed)
        {
            m1.setMaxSpeed(speeds[speed]);
            m2.setMaxSpeed(speeds[speed]);

            m1.setAcceleration(speeds[speed] * 2);
            m2.setAcceleration(speeds[speed] * 2);

            Serial.print(locationNames[position]);
            Serial.print("\t SPEED: ");
            Serial.print(speeds[speed]);

            for (size_t sample = 0; sample < SAMPLE_SIZE; ++sample)
            {
                MoveToLocation(locations[position]);
                delay(500);
                MoveToLocation(triggerAngle);

                LEDRed.Off();
                LEDGreen.On();

                Serial.print(".");

                delay(3000);

                LEDRed.On();
                LEDGreen.Off();
            }

            LEDRed.On();
            LEDGreen.On();
            Serial.println(" done");

            delay(3000);
        }
    }
}

void MoveToLocation(ArmLocation location)
{
    m1.MoveToAngle(location.m_angleMotor1 + ((GRIPPER_OFFSET) ? OFFSET_DEGREES : 0));
    m2.MoveToAngle(location.m_angleMotor2);

    while (m1.distanceToGo() != 0 || m2.distanceToGo() != 0)
    {
        m1.Run();
        m2.Run();
    }
}