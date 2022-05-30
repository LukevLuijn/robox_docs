
#include "MainFrame.h"
#include "Logger.h"


MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size,
                     long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer(wxHORIZONTAL);
    m_mainPanel = new Widgets::LogPanel(this);
    bSizer21->Add(m_mainPanel, 1, wxEXPAND | wxALL, 5);
    this->SetSizer(bSizer21);
    this->Layout();
    this->Centre(wxBOTH);
}
