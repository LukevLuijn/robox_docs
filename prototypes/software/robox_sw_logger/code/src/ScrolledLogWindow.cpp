//
// Created by luke on 16-05-22.
//

#include "ScrolledLogWindow.h"

namespace Widgets
{
    namespace
    {
#define MAX_BUFFER_SIZE 50
    }

    /*static*/ wxBoxSizer* ScrolledLogWindow::m_sizer = new wxBoxSizer(wxVERTICAL);
    /*static*/ std::array<bool, 4> ScrolledLogWindow::m_verbosity = {true, true, true, false};
    /*static*/ std::vector<Utils::LogMessage> ScrolledLogWindow::m_backup;


    void ScrolledLogWindow::AddMessage(const Utils::LogMessage& message, bool isReinstatement)
    {

        switch (message.m_verbosityType)
        {
            case VerbosityType_e::ERROR:
            {
                auto* panel = new PanelError(m_sizer->GetContainingWindow(), message);
                panel->Show(m_verbosity[static_cast<size_t>(VerbosityType_e::ERROR)]);
                m_sizer->Insert(0, panel, 0, wxEXPAND | wxTOP | wxBOTTOM, 5);
            }
            break;
            case VerbosityType_e::WARNING:
            {
                auto* panel = new PanelWarning(m_sizer->GetContainingWindow(), message);
                panel->Show(m_verbosity[static_cast<size_t>(VerbosityType_e::WARNING)]);
                m_sizer->Insert(0, panel, 0, wxEXPAND | wxTOP | wxBOTTOM, 5);
            }
            break;
            case VerbosityType_e::INFO:
            {
                auto* panel = new PanelInfo(m_sizer->GetContainingWindow(), message);
                panel->Show(m_verbosity[static_cast<size_t>(VerbosityType_e::INFO)]);
                m_sizer->Insert(0, panel, 0, wxEXPAND | wxTOP | wxBOTTOM, 5);
            }
            break;
            case VerbosityType_e::DEBUG:
            {
                auto* panel = new PanelDebug(m_sizer->GetContainingWindow(), message);
                panel->Show(m_verbosity[static_cast<size_t>(VerbosityType_e::DEBUG)]);
                m_sizer->Insert(0, panel, 0, wxEXPAND | wxTOP | wxBOTTOM, 5);
            }
            break;
            case VerbosityType_e::TRANS:
            {
                auto* panel = new PanelTransition(m_sizer->GetContainingWindow(), message);
                panel->Show(m_verbosity[static_cast<size_t>(VerbosityType_e::INFO)]);
                m_sizer->Insert(0, panel, 0, wxEXPAND | wxTOP | wxBOTTOM, 5);
            }
            break;
        }
        if (!isReinstatement)
        {
            m_backup.insert(m_backup.begin(), message);
            m_sizer->Layout();
            m_sizer->FitInside(m_sizer->GetContainingWindow());
            m_sizer->GetContainingWindow()->Update();

            if (m_backup.size() > MAX_BUFFER_SIZE)
            {
                m_sizer->GetChildren().pop_back();
                m_backup.pop_back();
            }
        }
    }
    void ScrolledLogWindow::ToggleError()
    {
        ToggleType(VerbosityType_e::ERROR);
    }
    void ScrolledLogWindow::ToggleWarning()
    {
        ToggleType(VerbosityType_e::WARNING);
    }
    void ScrolledLogWindow::ToggleInfo()
    {
        ToggleType(VerbosityType_e::INFO);
    }
    void ScrolledLogWindow::ToggleDebug()
    {
        ToggleType(VerbosityType_e::DEBUG);
    }
    void ScrolledLogWindow::ClearPanel()
    {
        m_sizer->DeleteWindows();
        m_sizer->GetContainingWindow()->Update();
        m_backup.clear();
    }
    void ScrolledLogWindow::Init()
    {
        m_sizer = new wxBoxSizer(wxVERTICAL);

        SetScrollRate(5, 5);
        SetSizer(m_sizer);
        Layout();
    }
    void ScrolledLogWindow::ToggleType(VerbosityType_e type)
    {
        m_verbosity[static_cast<size_t>(type)] = !m_verbosity[static_cast<size_t>(type)];
        m_sizer->DeleteWindows();

        for (const auto& child : m_backup)
        {
            if (child.m_verbosityType == type)
            {
                if (m_verbosity[static_cast<size_t>(type)])
                {
                    AddMessage(child, true);
                }
            }
            else
            {
                if (m_verbosity[static_cast<size_t>(child.m_verbosityType)])
                {
                    AddMessage(child, true);
                }
            }
        }
        m_sizer->Layout();
        m_sizer->FitInside(m_sizer->GetContainingWindow());
        m_sizer->GetContainingWindow()->Update();
    }

}// namespace Widgets