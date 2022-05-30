//
// Created by luke on 16-05-22.
//

#ifndef ROBOX_USER_INTERFACE_SCROLLEDLOGWINDOW_H
#define ROBOX_USER_INTERFACE_SCROLLEDLOGWINDOW_H

#include <vector>

#include "ConcreteMessagePanels.h"
#include "msg_protocol.h"
#include "wx/scrolwin.h"

namespace Widgets
{
    class ScrolledLogWindow : public wxScrolledWindow
    {
    public:
        explicit ScrolledLogWindow(wxWindow* parent)
            : wxScrolledWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL)
        {
            Init();
        }
        ~ScrolledLogWindow() override = default;

        static void AddMessage(const Utils::LogMessage& message, bool isReinstatement = false);

        static void ToggleError();
        static void ToggleWarning();
        static void ToggleInfo();
        static void ToggleDebug();
        static void ClearPanel();

    private:
        static void ToggleType(VerbosityType_e type);
        void Init();

    private:
        static wxBoxSizer* m_sizer;
        static std::vector<Utils::LogMessage> m_backup;
        static std::array<bool ,4> m_verbosity;
    };
}// namespace Base


#endif//ROBOX_USER_INTERFACE_SCROLLEDLOGWINDOW_H
