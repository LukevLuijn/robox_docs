#ifndef ROBOX_CONTROLLER_MSG_PROTOCOL_H
#define ROBOX_CONTROLLER_MSG_PROTOCOL_H

#include <cstdint>

enum class MessageType_e : int8_t
{
    MOVE = 'M',
    STOP = 'E',
    DATA = 'D',
    CONF = 'C',
    UNDEFINED = 0,
};
enum class MoveType_e : uint8_t
{
    INVERSE = 0,
    FORWARD = 1,
    HARDWARE = 2,
};
enum class StopType_e : uint8_t
{
    PAUSE = 0,
    STOP = 1,
    ESTOP = 2,
};
enum class DataType_e : uint8_t
{
    POSITION = 0,
    CONFIG = 1,
};
enum class ConfigType_e : uint8_t
{
    MOVEMENT = 0,
    G_OFFSET = 1,
    F_OFFSET = 2,
};

#endif// ROBOX_CONTROLLER_MSG_PROTOCOL_H