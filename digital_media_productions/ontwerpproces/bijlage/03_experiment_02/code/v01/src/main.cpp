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

struct StageLocation {
    ArmLocation inital;
    ArmLocation trigger;
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
    SINGLE_FIRST_90 = 0,
    SINGLE_FIRST_180 = 1,
    SINGLE_FIRST_270 = 2,
    SINGLE_SECOND_90 = 3,
    SINGLE_SECOND_180 = 4,
    // SINGLE_SECOND_270 = 5, // error
    BOTH_90 = 5,
    BOTH_180 = 6,
    BOTH_270 = 7,
};

std::vector<String> locationNames{
        "FIRST_90",
        "FIRST_180",
        "FIRST_270",
        "SECOND_90",
        "SECOND_180",
        // "SECOND_270", // error
        "BOTH_90",
        "BOTH_180",
        "BOTH_270",
};

std::vector<ArmLocation> locations{{90, -90}, {180, -90}, {270, -90}, {0, 0}, {0, 90}, {90, 0}, {180, 90}, {270, 180}};

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

    LEDRed.On();
    LEDGreen.On();

    while (!Button.Triggered())
    {
        delay(10);
    }

    LEDRed.Off();
    LEDGreen.Off();

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
    LEDGreen.Off();

    for (size_t position = 0; position < locations.size(); ++position)
    {
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

            while (!Button.Triggered())
            {
                delay(10);
            }
            LEDGreen.Off();
        }
    }
}

void RunToLocation(ArmLocation location)
{
    m1.RunToAngle(location.m_angleMotor1 + ((GRIPPER_OFFSET) ? OFFSET_DEGREES : 0));
    m2.RunToAngle(location.m_angleMotor2);
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