//
// Created by luke on 16-05-22.
//

#include "LogPanel.h"
#include "Logger.h"
#include "Bitmap.h"

namespace Widgets
{
    void LogPanel::OnToggleVerbosityError(wxCommandEvent& event)
    {
        Widgets::ScrolledLogWindow::ToggleError();
        event.Skip();
    }
    void LogPanel::OnToggleVerbosityWarning(wxCommandEvent& event)
    {
        Widgets::ScrolledLogWindow::ToggleWarning();
        event.Skip();

    }
    void LogPanel::OnToggleVerbosityInfo(wxCommandEvent& event)
    {
        Widgets::ScrolledLogWindow::ToggleInfo();
        event.Skip();

    }
    void LogPanel::OnToggleVerbosityDebug(wxCommandEvent& event)
    {
        Widgets::ScrolledLogWindow::ToggleDebug();
        event.Skip();

    }
    void LogPanel::OnClickToggleApplication(wxCommandEvent& event)
    {
        std::vector<std::string> vec = {"one", "two", "three", "four"};

        ERROR("Error message");
        WARNING("Warning message", vec);
        INFO("Info message");
        DEBUG("Debug message", vec);
        event.Skip();

    }
    void LogPanel::OnClickToggleFirmware(wxCommandEvent& event)
    {
        std::vector<uint16_t> vec = {1,2,3,4};

        ERROR("Error message");
        WARNING("Warning message", vec);
        INFO("Info message");
        DEBUG("Debug message", vec);
        event.Skip();

    }
    void LogPanel::OnClickClear(wxCommandEvent& event)
    {
        Widgets::ScrolledLogWindow::ClearPanel();
        event.Skip();
    }
    void LogPanel::Init()
    {
        wxBoxSizer* bSizer1;
        bSizer1 = new wxBoxSizer(wxVERTICAL);

        m_panel49 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxBoxSizer* bSizer49;
        bSizer49 = new wxBoxSizer(wxHORIZONTAL);

        m_buttonApplication = new wxButton(m_panel49, wxID_ANY, wxT("App"), wxDefaultPosition, wxDefaultSize, 0);
        bSizer49->Add(m_buttonApplication, 1, wxALL, 5);

        m_buttonFirmware = new wxButton(m_panel49, wxID_ANY, wxT("Robot"), wxDefaultPosition, wxDefaultSize, 0);
        bSizer49->Add(m_buttonFirmware, 1, wxALL, 5);

        m_buttonClear = new wxButton(m_panel49, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0);
        bSizer49->Add(m_buttonClear, 1, wxALL, 5);

        m_panel49->SetSizer(bSizer49);
        m_panel49->Layout();
        bSizer49->Fit(m_panel49);
        bSizer1->Add(m_panel49, 0, wxEXPAND | wxTOP | wxBOTTOM, 5);

        m_staticLine4 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
        bSizer1->Add(m_staticLine4, 0, wxEXPAND | wxALL, 5);

        m_verbosityPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxBoxSizer* bSizer2;
        bSizer2 = new wxBoxSizer(wxHORIZONTAL);

        m_buttonVerbosityError = new wxBitmapToggleButton(m_verbosityPanel,
                                                    wxID_ANY,
                                                    Utils::Bitmap::CreateBitmap("error.png", IMAGE_SIZE),
                                                    wxDefaultPosition,
                                                    wxDefaultSize,
                                                    wxBU_AUTODRAW | 0);
        bSizer2->Add(m_buttonVerbosityError, 1, wxALL, 5);
        m_buttonVerbosityError->SetValue( true );

        m_buttonVerbosityWarning = new wxBitmapToggleButton(m_verbosityPanel,
                                                      wxID_ANY,
                                                            Utils::Bitmap::CreateBitmap("warning.png", IMAGE_SIZE),
                                                      wxDefaultPosition,
                                                      wxDefaultSize,
                                                      wxBU_AUTODRAW | 0);
        bSizer2->Add(m_buttonVerbosityWarning, 1, wxALL, 5);
        m_buttonVerbosityWarning->SetValue( true );

        m_buttonVerbosityInfo = new wxBitmapToggleButton(m_verbosityPanel,
                                                   wxID_ANY,
                                                         Utils::Bitmap::CreateBitmap("info.png", IMAGE_SIZE),
                                                   wxDefaultPosition,
                                                   wxDefaultSize,
                                                   wxBU_AUTODRAW | 0);
        bSizer2->Add(m_buttonVerbosityInfo, 1, wxALL, 5);
        m_buttonVerbosityInfo->SetValue( true );


        m_buttonVerbosityDebug = new wxBitmapToggleButton(m_verbosityPanel,
                                                    wxID_ANY,
                                                          Utils::Bitmap::CreateBitmap("debug.png", IMAGE_SIZE),
                                                    wxDefaultPosition,
                                                    wxDefaultSize,
                                                    wxBU_AUTODRAW | 0);
        bSizer2->Add(m_buttonVerbosityDebug, 1, wxALL, 5);
        m_buttonVerbosityDebug->SetValue( false );

        m_verbosityPanel->SetSizer(bSizer2);
        m_verbosityPanel->Layout();
        bSizer2->Fit(m_verbosityPanel);
        bSizer1->Add(m_verbosityPanel, 0, wxEXPAND, 5);

        m_staticLine3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
        bSizer1->Add(m_staticLine3, 0, wxEXPAND | wxALL, 5);

        m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxBoxSizer* bSizer3;
        bSizer3 = new wxBoxSizer(wxVERTICAL);

        m_logWindow = new Widgets::ScrolledLogWindow(m_panel2);
        bSizer3->Add(m_logWindow, 1, wxEXPAND, 5);

        m_panel2->SetSizer(bSizer3);
        m_panel2->Layout();
        bSizer3->Fit(m_panel2);
        bSizer1->Add(m_panel2, 1, wxEXPAND | wxALL, 5);

        SetSizer(bSizer1);
        Layout();
        bSizer1->Fit(this);
    }
    void LogPanel::Connect()
    {
        m_buttonApplication->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                     wxCommandEventHandler(LogPanel::OnClickToggleApplication),
                                     nullptr,
                                     this);
        m_buttonFirmware->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                  wxCommandEventHandler(LogPanel::OnClickToggleFirmware),
                                  nullptr,
                                  this);
        m_buttonClear->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                               wxCommandEventHandler(LogPanel::OnClickClear),
                               nullptr,
                               this);

        m_buttonVerbosityError->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityError ), nullptr, this);
        m_buttonVerbosityWarning->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityWarning ), nullptr, this);
        m_buttonVerbosityInfo->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityInfo ), nullptr, this);
        m_buttonVerbosityDebug->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityDebug ), nullptr, this);
    }
    void LogPanel::Disconnect()
    {
        m_buttonApplication->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                        wxCommandEventHandler(LogPanel::OnClickToggleApplication),
                                        nullptr,
                                        this);
        m_buttonFirmware->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                     wxCommandEventHandler(LogPanel::OnClickToggleFirmware),
                                     nullptr,
                                     this);
        m_buttonClear->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                  wxCommandEventHandler(LogPanel::OnClickClear),
                                  nullptr,
                                  this);

        m_buttonVerbosityError->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityError ), nullptr, this);
        m_buttonVerbosityWarning->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityWarning ), nullptr, this);
        m_buttonVerbosityInfo->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityInfo ), nullptr, this);
        m_buttonVerbosityDebug->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( LogPanel::OnToggleVerbosityDebug ), nullptr, this);
    }
}// namespace Widgets