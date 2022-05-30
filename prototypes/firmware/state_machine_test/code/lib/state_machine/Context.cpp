// ======================================
// Filename:
//   Context.cpp
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   State machine context class.
// ======================================

#include "Context.h"

namespace StateMachine
{
    void Context::ScheduleEvent(const Event& event)
    {
        m_events.push(event);
    }
    const std::shared_ptr<State>& Context::GetCurrentState() const
    {
        return m_currentState;
    }
    void Context::SetCurrentState(const std::shared_ptr<State>& state)
    {
        if (m_currentState)
        {
            m_currentState->ExitAction();
        }

        m_currentState = state;
        m_currentState-> EntryAction();
    }
    void Context::HandleEventList()
    {
        if (!m_events.empty())
        {
            Event event = m_events.front();
            m_events.pop();
            m_currentState->HandleEvent(event, *this);
        }
        m_currentState->DoActivity();
    }
}// namespace StateMachine