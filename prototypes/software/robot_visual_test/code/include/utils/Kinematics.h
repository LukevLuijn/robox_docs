//
// Created by luke on 20-05-22.
// https://github.com/henriksod/Fabrik2DArduino
//

#ifndef ROBOT_VISUAL_KINEMATICS_H
#define ROBOT_VISUAL_KINEMATICS_H

namespace Utils
{
    class Kinematics
    {
    private:
        typedef struct {
            float x;
            float y;
            float angle;
        } Joint;
        typedef struct {
            Joint* joints;
            float z;
            float angle;
        } Chain;

    public:
        Kinematics(int numJoints, int* lengths);
        bool Solve(float x, float y, const int* lengths, int maxIter = 1000);

        float GetX(int joint);
        float GetY(int joint);
        float GetAngle(int joint);
        void SetTolerance(float tolerance);
        void SetJoints(const float* angles, const int* length);

    private:
        static float Distance(float x1, float y1, float x2, float y2);
        void CreateChain(const int* lengths);

    private:
        int m_numJoints;
        float m_tolerance;
        Chain* m_chain{};
    };
}// namespace Utils

#endif//ROBOT_VISUAL_KINEMATICS_H
