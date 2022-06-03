// ======================================
// Filename:
//   Event.h
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   State machine Event class.
// ======================================

#ifndef ROBOX_STATE_MACHINE_TEST_STATE_MACHINE_EVENT_H
#define ROBOX_STATE_MACHINE_TEST_STATE_MACHINE_EVENT_H

#include <cstdint>

namespace StateMachine
{
    class Event
    {
    public:
        explicit Event(uint16_t id, uint16_t previousState);
        Event(const Event& other) = default;
        virtual ~Event() = default;

        /**
         * @brief Assignment operator, assign new event to this instance.
         * 
         * @param other     Other event to assign to this one.
         * @return Event&   Newly assigned event.
         */
        Event& operator=(const Event& other);
        /**
         * @brief Get the Id of this event.
         * 
         * @return uint16_t The Id.
         */
        uint16_t GetId() const;
        /**
         * @brief Get the Previous State of this event.
         * 
         * @return uint16_t the previous state.
         */
        uint16_t GetPreviousState() const;

    private:
        uint16_t m_id;
        uint16_t m_previousState;
    };
}// namespace StateMachine

#endif// ROBOX_STATE_MACHINE_TEST_STATE_MACHINE_EVENT_H