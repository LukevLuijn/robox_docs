// ======================================
// Filename:
//   State.h
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   State machine State class.
// ======================================

#ifndef ROBOX_STATE_MACHINE_TEST_STATE_MACHINE_STATE_H
#define ROBOX_STATE_MACHINE_TEST_STATE_MACHINE_STATE_H

#include <Arduino.h>

#include "Event.h"

namespace StateMachine
{
    class Context;

    class State
    {
    public:
        State(String name) : m_name(name) {}
        State(const State& state) = delete;
        virtual ~State() = default;

        /**
         * @brief Pure virtual, handles given event based on context.
         * 
         * @param event     Event to handle.
         * @param context   Context to base event on.
         * @return true     If event was handled.
         * @return false    If event was not handled.
         */
        virtual bool HandleEvent(const Event& event, Context& context) = 0;
        /**
         * @brief Pure virtual, Action to perform after state transition.
         * 
         */
        virtual void EntryAction() = 0;
        /**
         * @brief Pure virtual, Activity to perform while state is active.
         * 
         */
        virtual void DoActivity() = 0;
        /**
         * @brief Pure virtual, Action to perform before state transition.
         * 
         */
        virtual void ExitAction() = 0;
        /**
         * @brief Get the Name of state.
         * 
         * @return String Name of the state.
         */
        String GetName() const
        {
            return m_name;
        }

    protected:
        String m_name;
    };
}// namespace StateMachine

#endif// ROBOX_STATE_MACHINE_TEST_STATE_MACHINE_STATE_H