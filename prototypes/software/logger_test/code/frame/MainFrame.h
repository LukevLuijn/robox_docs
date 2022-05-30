#pragma once

#include "LogPanel.h"

class MainFrame : public wxFrame
{
public:
    explicit MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Robox test log output",
                       const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300, 600),
                       long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
    ~MainFrame() override = default;

protected:
    Widgets::LogPanel* m_mainPanel;
};
