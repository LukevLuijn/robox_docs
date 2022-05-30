#ifndef EXP_02_MOTOR
#define EXP_02_MOTOR

#include "Limit.h"
#include <AccelStepper.h>

namespace Devices
{
    enum class MotorState_e : uint8_t;
    enum class HomingState_e : uint8_t;

    class Motor : public AccelStepper
    {
    public:
        Motor(uint8_t step, uint8_t dir, uint8_t enb, uint8_t hall, uint8_t microstepping, float reduction,
              bool inverted = false);
        virtual ~Motor() = default;

        void Start();
        void Run();

        void MoveDegrees(float degrees);
        void RunDegrees(float degrees);
        
        void MoveToAngle(float angle);
        void RunToAngle(float angle);

        float GetCurrentAngle();
        float GetDegreesToTarget();

        uint32_t GetStepsPerRevolution();
        uint8_t GetMicrostepping();
        bool HomingComplete();

    private:
        void HomeMotor(float defaultSpeed);

    private:
        uint8_t m_limit_pin;
        Limit m_limit;

        uint8_t m_microstepping;
        uint32_t m_stepsPerRevoltion;
        float m_stepAngle;

        MotorState_e m_motorState;
        bool m_homingComplete;
    };

    enum class MotorState_e : uint8_t
    {
        HOMING = 0,
        IDLE = 1,
        DISABLED = 2,
    };
}// namespace Devices

#endif// EXP_02_MOTOR
