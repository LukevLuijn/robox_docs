#include <Arduino.h>

#include "AxialActuator.h"
#include "HallSensor.h"
#include "LinearActuator.h"

#include "config.h"

Device::LinearActuator motor0(MOTOR_STP_0, MOTOR_DIR_0, MOTOR_ENB_0, HALL_SENSOR_0, Device::Microstepping_e::MS3200,
                              1.0f, false);
Device::AxialActuator motor1(MOTOR_STP_1, MOTOR_DIR_1, MOTOR_ENB_1, HALL_SENSOR_1, Device::Microstepping_e::MS3200,
                             7.2f, false, Device::HomingStyle_e::DOUBLE_MAGNET);
Device::AxialActuator motor2(MOTOR_STP_2, MOTOR_DIR_2, MOTOR_ENB_2, HALL_SENSOR_2, Device::Microstepping_e::MS3200,
                             7.2f, false, Device::HomingStyle_e::SINGLE_MAGNET);
Device::AxialActuator motor3(MOTOR_STP_3, MOTOR_DIR_3, MOTOR_ENB_3, HALL_SENSOR_3, Device::Microstepping_e::MS3200,
                             7.2f, false, Device::HomingStyle_e::SINGLE_MAGNET);

void setup()
{
    Serial.begin(9600);
    delay(1000);

    Serial.println("Hello world");

    motor0.Start();
    motor0.HomingSequence(MAX_SPEED_SEGMENT_00, MAX_ACCEL_SEGMENT_00);

    motor1.Start();
    motor1.HomingSequence(MAX_SPEED_SEGMENT_01, MAX_ACCEL_SEGMENT_01);

    motor2.Start();
    motor2.HomingSequence(MAX_SPEED_SEGMENT_02, MAX_ACCEL_SEGMENT_02);

    motor3.Start();
    motor3.HomingSequence(MAX_SPEED_SEGMENT_03, MAX_ACCEL_SEGMENT_03);

    motor0.disableOutputs();
    motor1.disableOutputs();
    motor2.disableOutputs();
    motor3.disableOutputs();
}

void loop()
{
}