
#include <Arduino.h>
#include <Encoder.h>

#define STP 2
#define DIR 3
#define ENB 4

#define HAL 5
#define BTN 6
#define LED 13

#define ENC_A 10
#define ENC_B 9

// const uint32_t MICROSTEPPING = 64;
// const uint32_t MICROSTEPPING = 32;
// const uint32_t MICROSTEPPING = 16;
// const uint32_t MICROSTEPPING = 8;
// const uint32_t MICROSTEPPING = 4;
const uint32_t MICROSTEPPING = 2;

bool LimitSwitchTrigger();
void MakeManySteps(uint32_t steps, uint32_t delay, bool forwards);
void MakeSingleStep(uint32_t delay, bool forwards);
uint32_t GetSpeedDelay(double roundsPerMinute);

void HomeStepper();
void ExecuteTest(uint8_t sampleSize, uint8_t index);
void TestCycle();
bool Timer(uint32_t& time, uint32_t interval);

Encoder encoder(ENC_A, ENC_B);

bool positionReached = false;

const uint32_t DEFAULT_SPR = 200;
const uint32_t STEP_PER_REV = DEFAULT_SPR * MICROSTEPPING;
const uint32_t STEP_HIGH_US = 5;

bool m_forwards = true;
int32_t position = 0;

int16_t lastSwitchState;
int16_t switchState;
int32_t lastDebounceTime;
int32_t debounceDelay;

const uint8_t N_SPEED = 6;
const float HOMING_SPEED = 150.0f;
const float SPEEDS[N_SPEED] = {10.0f, 20.0f, 40.0f, 60.0f, 80.0f, 100.0f};

uint8_t speedIndex = 0;
bool nextStage = false;

uint32_t LEDTimer = 0;
bool LEDState = LOW;

void ButtonISR()
{
    nextStage = true;
}

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(HAL, INPUT);

    Serial.begin(9600);
    delay(1000);

    pinMode(STP, OUTPUT);
    pinMode(DIR, OUTPUT);
    pinMode(ENB, OUTPUT);

    digitalWrite(ENB, LOW);
    digitalWrite(LED, LOW);

    attachInterrupt(digitalPinToInterrupt(BTN), ButtonISR, CHANGE);
    
    TestCycle();
    digitalWrite(ENB, LOW);
}

void loop()
{
}

void TestCycle()
{
    for (size_t i = 5; i < N_SPEED; ++i)
    {
        nextStage = false;
        while (!nextStage)
        {
            if (Timer(LEDTimer, 250))
            {
                digitalWrite(LED, LEDState);
                LEDState = !LEDState;
            }
        }
        digitalWrite(ENB, HIGH);
        ExecuteTest(3, i);
        digitalWrite(ENB, LOW);
    }
}

void ExecuteTest(uint8_t sampleSize, uint8_t index)
{
    const uint32_t STEPS_TILL_SCALE = 112 * MICROSTEPPING - (2*MICROSTEPPING)+20;
    const uint32_t STEPS_FOR_WEIGHT = 4 * MICROSTEPPING;
    const uint32_t BACKUP_STEPS = 450 * MICROSTEPPING;

    const float speedDelay = GetSpeedDelay(SPEEDS[index]);
    const float backupSpeedDelay = GetSpeedDelay(300);

    for (size_t i = 0; i < sampleSize; ++i)
    {
        Serial.print("homing motor..\t\t");
        HomeStepper();

        Serial.println("complete.");

        Serial.print("starting test [");
        Serial.print(i);
        Serial.print("]..\t");

        delay(200);

        MakeManySteps(STEPS_TILL_SCALE + STEPS_FOR_WEIGHT, speedDelay, true);

        Serial.println("complete.");
        delay(3000);

        digitalWrite(DIR, !m_forwards);

        MakeManySteps(STEPS_FOR_WEIGHT * 2, GetSpeedDelay(SPEEDS[1]), false);
        delay(200);
        MakeManySteps(BACKUP_STEPS, backupSpeedDelay, false);
        delay(200);
    }
}

void MakeSingleStep(uint32_t delay, bool forwards)
{
    digitalWrite(DIR, forwards);

    digitalWrite(STP, HIGH);
    delayMicroseconds(STEP_HIGH_US);
    digitalWrite(STP, LOW);
    delayMicroseconds(delay);

    position += (forwards) ? 1 : -1;
}
void MakeManySteps(uint32_t steps, uint32_t delay, bool forwards)
{
    for (size_t i = 0; i < steps; ++i)
    {
        MakeSingleStep(delay, forwards);
    }
}
bool LimitSwitchTrigger()
{
    bool isTriggered = false;
    int16_t reading = digitalRead(HAL);
    if (reading != lastSwitchState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (reading != switchState)
        {
            switchState = reading;
            if (switchState == LOW)
            {
                isTriggered = true;
            }
        }
    }
    lastSwitchState = reading;
    return isTriggered;
}
void HomeStepper()
{
    auto FindLimit = [](uint32_t speedDelay, bool forwards) -> int32_t {
        while (!LimitSwitchTrigger())
        {
            MakeSingleStep(speedDelay, forwards);
        }
        return position;
    };

    const uint32_t HOMING_SPEEDS[] = {GetSpeedDelay(HOMING_SPEED),
                                      GetSpeedDelay(HOMING_SPEED / 2),
                                      GetSpeedDelay(HOMING_SPEED / 12)};

    FindLimit(HOMING_SPEEDS[0], true);

    MakeManySteps(STEP_PER_REV / 4, HOMING_SPEEDS[1], false);

    int32_t trigger01 = FindLimit(HOMING_SPEEDS[2], true);

    MakeManySteps(STEP_PER_REV / 4, HOMING_SPEEDS[1], true);
    int32_t trigger02 = FindLimit(HOMING_SPEEDS[2], false);

    int32_t diff = (trigger02 - trigger01) / 2;
    MakeManySteps(diff, HOMING_SPEEDS[0], false);
    position = 0;

    Serial.print(trigger01);
    Serial.print(", ");
    Serial.print(trigger02);
    Serial.print(", ");
    Serial.println(diff);
}
uint32_t GetSpeedDelay(double RPM)
{
    double RPS = RPM / 60;                        // rotations per second
    double SPS = RPS * STEP_PER_REV;              // steps per second
    double slack = 1000000 - (SPS * STEP_HIGH_US);// time slack
    double speedDelay = slack / SPS;              // additional delay per step
    return speedDelay;
}

bool Timer(uint32_t& time, uint32_t interval)
{
    if (millis() - time >= interval)
    {
        time = millis();
        return true;
    }
    return false;
}