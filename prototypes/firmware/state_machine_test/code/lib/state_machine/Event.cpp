// ======================================
// Filename:
//   Event.cpp
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

#include "Event.h"

namespace StateMachine
{
    Event::Event(uint16_t id, uint16_t previousState) : m_id(id), m_previousState(previousState)
    {
    }
    Event& Event::operator=(const Event& other)
    {
        if (this != &other)
        {
            m_id = other.m_id;
            m_previousState = other.m_previousState;
        }
        return *this;
    }
    uint16_t Event::GetId() const
    {
        return m_id;
    }
    uint16_t Event::GetPreviousState() const
    {
        return m_previousState;
    }
}// namespace StateMachine