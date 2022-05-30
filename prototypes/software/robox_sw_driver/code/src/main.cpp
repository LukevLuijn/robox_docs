//
// Created by luke on 06-05-22.
//

#include "Logger.h"
#include "RobotDriver.h"

int main(int argc, char* argv[])
{
    (void) argc; (void) argv;

    Driver::RobotDriver driver("/dev/ttyACM0", 9600);

    driver.StartRobot();

    driver.MoveRobotForward(std::array<float, 4> {350, 90, 90, 90});

    driver.UpdateRunTimeData();
    driver.UpdateDynamicData();
    driver.UpdateStaticData();

    std::this_thread::sleep_for(std::chrono::milliseconds (1000));

    driver.StopRobot();

    driver.UpdateRunTimeData();
    std::this_thread::sleep_for(std::chrono::milliseconds (1000));

    return 0;
}
