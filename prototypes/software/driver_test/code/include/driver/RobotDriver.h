//
// Created by luke on 14-05-22.
//

#ifndef ROBOX_UI_LOW_LEVEL_DRIVER_H
#define ROBOX_UI_LOW_LEVEL_DRIVER_H

#include <string>

#include "SerialDriver.h"
#include "DataManager.h"
#include "msg_protocol.h"

namespace Driver
{
    class RobotDriver : public SerialDriver
    {
    private:
        typedef std::array<float, 4> MoveArray;
        typedef std::array<float, 4> SpeedArray;
        typedef std::array<float, 4> AccelArray;
        typedef std::array<bool, 4> VerbArray;
        typedef std::array<float, 4> IdlePositions;

    public:
        RobotDriver(const std::string& port, uint16_t baud);
        ~RobotDriver() override;

    public:
        void MoveRobotInverse(const MoveArray& position);
        void MoveRobotForward(const MoveArray& angles);
        void MoveRobotGripper(uint8_t gripper01, uint8_t gripper02);

        void StartRobot();
        void PauseRobot(uint32_t time);
        void StopRobot();
        void EmergencyStop();

        void SetSpeedAccel(float speed, float accel);
        void SetSpeedAccel(const SpeedArray& speeds, const AccelArray& accelerations);
        void SetVerbosity(const VerbArray& verbs);
        void SetFrameOffset(float frameOffset);
        void SetGripperOffset(float gripperOffset);
        void SetIdlePositions(const IdlePositions& idlePositions);

        void UpdateDynamicData();
        void UpdateStaticData();
        void UpdateRunTimeData();

    private:
        static void ReadMessage(const char* data, unsigned int len);
        static std::string CreateParamString(const MoveArray& array);
        static std::string CreateMessageHeader(MessageType_e type, uint8_t index);
    public:
        static DataManager m_dataManager;
    };
}// namespace Driver

#endif//ROBOX_UI_LOW_LEVEL_DRIVER_H
