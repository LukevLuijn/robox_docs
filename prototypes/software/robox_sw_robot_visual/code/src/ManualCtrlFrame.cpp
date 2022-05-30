//
// Created by luke on 20-05-22.
//

#include "ManualCtrlFrame.h"
#include "RobotDrawPanel.h"

namespace Frame
{
    ManualCtrlFrame::ManualCtrlFrame(wxWindow* parent)
        : wxDialog(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(500, 500), wxDEFAULT_DIALOG_STYLE)
    {
        InitializeFrame();
        ConnectEvents();
    }
    ManualCtrlFrame::~ManualCtrlFrame()
    {
        DisconnectEvents();
    }
    void ManualCtrlFrame::OnKillFocusSpeed(wxFocusEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnKillFocusAccel(wxFocusEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnKillFocusZ(wxFocusEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnKillFocusA1(wxFocusEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnKillFocusA2(wxFocusEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnKillFocusA3(wxFocusEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextEnterSpeed(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextEnterAccel(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextEnterZ(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextEnterA1(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextEnterA2(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextEnterA3(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextMaxLenSpeed(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextMaxLenAccel(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextMaxLenZ(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextMaxLenA1(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextMaxLenA2(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnTextMaxLenA3(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderReleaseSpeed(wxScrollEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderReleaseAccel(wxScrollEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderReleaseZ(wxScrollEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderReleaseA1(wxScrollEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderReleaseA2(wxScrollEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderReleaseA3(wxScrollEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderSpeed(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderAccel(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderZ(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderA1(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderA2(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnSliderA3(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnToggleGrip01(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnToggleGrip02(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::OnToggleAuto(wxCommandEvent& event)
    {
        event.Skip();
    }
    void ManualCtrlFrame::InitializeFrame()
    {
        this->SetSizeHints(wxDefaultSize, wxDefaultSize);

        wxBoxSizer* bSizer12;
        bSizer12 = new wxBoxSizer(wxVERTICAL);

        m_configPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxFlexGridSizer* fgSizer3;
        fgSizer3 = new wxFlexGridSizer(2, 4, 0, 0);
        fgSizer3->AddGrowableCol(3);
        fgSizer3->SetFlexibleDirection(wxBOTH);
        fgSizer3->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

        m_textSpeed = new wxStaticText(m_configPanel, wxID_ANY, wxT("A1:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textSpeed->Wrap(-1);
        fgSizer3->Add(m_textSpeed, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        m_textCtrlSpeed = new wxTextCtrl(m_configPanel,
                                         wxID_ANY,
                                         wxEmptyString,
                                         wxDefaultPosition,
                                         wxDefaultSize,
                                         wxTE_PROCESS_ENTER);
        fgSizer3->Add(m_textCtrlSpeed, 0, wxALL, 5);

        m_iconSpeed = new wxStaticText(m_configPanel, wxID_ANY, wxT("degrees"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconSpeed->Wrap(-1);
        fgSizer3->Add(m_iconSpeed, 0, wxALIGN_CENTER_VERTICAL | wxTOP | wxBOTTOM | wxRIGHT, 5);

        m_sliderSpeed = new wxSlider(m_configPanel,
                                     wxID_ANY,
                                     0,
                                     -9000,
                                     9000,
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     wxSL_HORIZONTAL);
        fgSizer3->Add(m_sliderSpeed, 0, wxALL | wxEXPAND, 5);

        m_textAccel = new wxStaticText(m_configPanel, wxID_ANY, wxT("A2:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textAccel->Wrap(-1);
        fgSizer3->Add(m_textAccel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        m_textCtrlAccel = new wxTextCtrl(m_configPanel,
                                         wxID_ANY,
                                         wxEmptyString,
                                         wxDefaultPosition,
                                         wxDefaultSize,
                                         wxTE_PROCESS_ENTER);
        fgSizer3->Add(m_textCtrlAccel, 0, wxALL, 5);

        m_iconAccel = new wxStaticText(m_configPanel, wxID_ANY, wxT("degrees"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconAccel->Wrap(-1);
        fgSizer3->Add(m_iconAccel, 0, wxALIGN_CENTER_VERTICAL | wxTOP | wxBOTTOM | wxRIGHT, 5);

        m_sliderAccel = new wxSlider(m_configPanel,
                                     wxID_ANY,
                                     0,
                                     -36000,
                                     36000,
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     wxSL_HORIZONTAL);
        fgSizer3->Add(m_sliderAccel, 0, wxALL | wxEXPAND, 5);


        m_configPanel->SetSizer(fgSizer3);
        m_configPanel->Layout();
        fgSizer3->Fit(m_configPanel);
        bSizer12->Add(m_configPanel, 0, wxEXPAND, 5);

        m_line0 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
        bSizer12->Add(m_line0, 0, wxEXPAND | wxALL, 5);

        m_togglePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxBoxSizer* bSizer3;
        bSizer3 = new wxBoxSizer(wxHORIZONTAL);

        m_toggleBtn1 =
                new wxToggleButton(m_togglePanel, wxID_ANY, wxT("Gripper 01"), wxDefaultPosition, wxDefaultSize, 0);
        bSizer3->Add(m_toggleBtn1, 0, wxALL, 5);

        m_toggleBtn2 =
                new wxToggleButton(m_togglePanel, wxID_ANY, wxT("Gripper 02"), wxDefaultPosition, wxDefaultSize, 0);
        bSizer3->Add(m_toggleBtn2, 0, wxALL, 5);

        m_line1 = new wxStaticLine(m_togglePanel,
                                   wxID_ANY,
                                   wxDefaultPosition,
                                   wxDefaultSize,
                                   wxLI_HORIZONTAL | wxLI_VERTICAL);
        bSizer3->Add(m_line1, 0, wxEXPAND | wxALL, 5);

        m_toggleBtn3 =
                new wxToggleButton(m_togglePanel, wxID_ANY, wxT("Automatic run"), wxDefaultPosition, wxDefaultSize, 0);
        bSizer3->Add(m_toggleBtn3, 1, wxALL, 5);


        m_togglePanel->SetSizer(bSizer3);
        m_togglePanel->Layout();
        bSizer3->Fit(m_togglePanel);
        bSizer12->Add(m_togglePanel, 0, wxEXPAND, 5);

        m_line2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
        bSizer12->Add(m_line2, 0, wxEXPAND | wxALL, 5);

        m_positionPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
        wxFlexGridSizer* fgSizer6;
        fgSizer6 = new wxFlexGridSizer(4, 4, 0, 0);
        fgSizer6->AddGrowableCol(3);
        fgSizer6->SetFlexibleDirection(wxBOTH);
        fgSizer6->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

        m_textZ = new wxStaticText(m_positionPanel, wxID_ANY, wxT("Z:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textZ->Wrap(-1);
        fgSizer6->Add(m_textZ, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        m_textCtrlZ = new wxTextCtrl(m_positionPanel,
                                     wxID_ANY,
                                     wxEmptyString,
                                     wxDefaultPosition,
                                     wxDefaultSize,
                                     wxTE_PROCESS_ENTER);
        fgSizer6->Add(m_textCtrlZ, 0, wxALL, 5);

        m_iconZ = new wxStaticText(m_positionPanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconZ->Wrap(-1);
        fgSizer6->Add(m_iconZ, 0, wxALIGN_CENTER_VERTICAL | wxTOP | wxBOTTOM | wxRIGHT, 5);

        m_sliderZ =
                new wxSlider(m_positionPanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
        fgSizer6->Add(m_sliderZ, 0, wxALL | wxEXPAND, 5);

        m_textA1 = new wxStaticText(m_positionPanel, wxID_ANY, wxT("A1:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textA1->Wrap(-1);
        fgSizer6->Add(m_textA1, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        m_textCtrlA1 = new wxTextCtrl(m_positionPanel,
                                      wxID_ANY,
                                      wxEmptyString,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      wxTE_PROCESS_ENTER);
        fgSizer6->Add(m_textCtrlA1, 0, wxALL, 5);

        m_iconA1 = new wxStaticText(m_positionPanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconA1->Wrap(-1);
        fgSizer6->Add(m_iconA1, 0, wxALIGN_CENTER_VERTICAL | wxTOP | wxBOTTOM | wxRIGHT, 5);

        m_sliderA1 =
                new wxSlider(m_positionPanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
        fgSizer6->Add(m_sliderA1, 0, wxALL | wxEXPAND, 5);

        m_textA2 = new wxStaticText(m_positionPanel, wxID_ANY, wxT("A2:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textA2->Wrap(-1);
        fgSizer6->Add(m_textA2, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        m_textCtrlA2 = new wxTextCtrl(m_positionPanel,
                                      wxID_ANY,
                                      wxEmptyString,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      wxTE_PROCESS_ENTER);
        fgSizer6->Add(m_textCtrlA2, 0, wxALL, 5);

        m_iconA2 = new wxStaticText(m_positionPanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconA2->Wrap(-1);
        fgSizer6->Add(m_iconA2, 0, wxTOP | wxBOTTOM | wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);

        m_sliderA2 =
                new wxSlider(m_positionPanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
        fgSizer6->Add(m_sliderA2, 0, wxALL | wxEXPAND, 5);

        m_textA3 = new wxStaticText(m_positionPanel, wxID_ANY, wxT("A3:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textA3->Wrap(-1);
        fgSizer6->Add(m_textA3, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

        m_textCtrlA3 = new wxTextCtrl(m_positionPanel,
                                      wxID_ANY,
                                      wxEmptyString,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      wxTE_PROCESS_ENTER);
        fgSizer6->Add(m_textCtrlA3, 0, wxALL, 5);

        m_iconA3 = new wxStaticText(m_positionPanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconA3->Wrap(-1);
        fgSizer6->Add(m_iconA3, 0, wxTOP | wxBOTTOM | wxRIGHT | wxALIGN_CENTER_VERTICAL, 5);

        m_sliderA3 =
                new wxSlider(m_positionPanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
        fgSizer6->Add(m_sliderA3, 0, wxALL | wxEXPAND, 5);


        m_positionPanel->SetSizer(fgSizer6);
        m_positionPanel->Layout();
        fgSizer6->Fit(m_positionPanel);
        bSizer12->Add(m_positionPanel, 0, wxEXPAND, 5);



        int32_t sizes [] = {240, 150};
        m_drawPanel = new RobotDrawPanel(this, sizes);

        bSizer12->Add(m_drawPanel, 1, wxEXPAND | wxALL, 5);

        this->SetSizer(bSizer12);
        this->Layout();

        this->Centre(wxBOTH);

//        m_configPanel->Hide();
        m_togglePanel->Hide();
        m_positionPanel->Hide();
    }
    void ManualCtrlFrame::ConnectEvents()
    {
        m_textCtrlSpeed->Connect(wxEVT_KILL_FOCUS,
                                 wxFocusEventHandler(ManualCtrlFrame::OnKillFocusSpeed),
                                 nullptr,
                                 this);
        m_textCtrlSpeed->Connect(wxEVT_COMMAND_TEXT_ENTER,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextEnterSpeed),
                                 nullptr,
                                 this);
        m_textCtrlSpeed->Connect(wxEVT_COMMAND_TEXT_MAXLEN,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenSpeed),
                                 nullptr,
                                 this);
        m_sliderSpeed->Connect(wxEVT_SCROLL_THUMBRELEASE,
                               wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseSpeed),
                               nullptr,
                               this);
        m_sliderSpeed->Connect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderSpeed), nullptr, this);
        m_textCtrlAccel->Connect(wxEVT_KILL_FOCUS,
                                 wxFocusEventHandler(ManualCtrlFrame::OnKillFocusAccel),
                                 nullptr,
                                 this);
        m_textCtrlAccel->Connect(wxEVT_COMMAND_TEXT_ENTER,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextEnterAccel),
                                 nullptr,
                                 this);
        m_textCtrlAccel->Connect(wxEVT_COMMAND_TEXT_MAXLEN,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenAccel),
                                 nullptr,
                                 this);
        m_sliderAccel->Connect(wxEVT_SCROLL_THUMBRELEASE,
                               wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseAccel),
                               nullptr,
                               this);
        m_sliderAccel->Connect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderAccel), nullptr, this);
        m_toggleBtn1->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
                              wxCommandEventHandler(ManualCtrlFrame::OnToggleGrip01),
                              nullptr,
                              this);
        m_toggleBtn2->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
                              wxCommandEventHandler(ManualCtrlFrame::OnToggleGrip02),
                              nullptr,
                              this);
        m_toggleBtn3->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
                              wxCommandEventHandler(ManualCtrlFrame::OnToggleAuto),
                              nullptr,
                              this);
        m_textCtrlZ->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusZ), nullptr, this);
        m_textCtrlZ->Connect(wxEVT_COMMAND_TEXT_ENTER,
                             wxCommandEventHandler(ManualCtrlFrame::OnTextEnterZ),
                             nullptr,
                             this);
        m_textCtrlZ->Connect(wxEVT_COMMAND_TEXT_MAXLEN,
                             wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenZ),
                             nullptr,
                             this);
        m_sliderZ->Connect(wxEVT_SCROLL_THUMBRELEASE,
                           wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseZ),
                           nullptr,
                           this);
        m_sliderZ->Connect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderZ), nullptr, this);
        m_textCtrlA1->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusA1), nullptr, this);
        m_textCtrlA1->Connect(wxEVT_COMMAND_TEXT_ENTER,
                              wxCommandEventHandler(ManualCtrlFrame::OnTextEnterA1),
                              nullptr,
                              this);
        m_textCtrlA1->Connect(wxEVT_COMMAND_TEXT_MAXLEN,
                              wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenA1),
                              nullptr,
                              this);
        m_sliderA1->Connect(wxEVT_SCROLL_THUMBRELEASE,
                            wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseA1),
                            nullptr,
                            this);
        m_sliderA1->Connect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderA1), nullptr, this);
        m_textCtrlA2->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusA2), nullptr, this);
        m_textCtrlA2->Connect(wxEVT_COMMAND_TEXT_ENTER,
                              wxCommandEventHandler(ManualCtrlFrame::OnTextEnterA2),
                              nullptr,
                              this);
        m_textCtrlA2->Connect(wxEVT_COMMAND_TEXT_MAXLEN,
                              wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenA2),
                              nullptr,
                              this);
        m_sliderA2->Connect(wxEVT_SCROLL_THUMBRELEASE,
                            wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseA2),
                            nullptr,
                            this);
        m_sliderA2->Connect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderA2), nullptr, this);
        m_textCtrlA3->Connect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusA3), nullptr, this);
        m_textCtrlA3->Connect(wxEVT_COMMAND_TEXT_ENTER,
                              wxCommandEventHandler(ManualCtrlFrame::OnTextEnterA3),
                              nullptr,
                              this);
        m_textCtrlA3->Connect(wxEVT_COMMAND_TEXT_MAXLEN,
                              wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenA3),
                              nullptr,
                              this);
        m_sliderA3->Connect(wxEVT_SCROLL_THUMBRELEASE,
                            wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseA3),
                            nullptr,
                            this);
        m_sliderA3->Connect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderA3), nullptr, this);

        this->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(ManualCtrlFrame::OnMouseRelease), nullptr, this);
        this->Connect(wxEVT_MOTION, wxMouseEventHandler(ManualCtrlFrame::OnMouseMotion), nullptr, this);

    }
    void ManualCtrlFrame::DisconnectEvents()
    {
        m_textCtrlSpeed->Disconnect(wxEVT_KILL_FOCUS,
                                    wxFocusEventHandler(ManualCtrlFrame::OnKillFocusSpeed),
                                    nullptr,
                                    this);
        m_textCtrlSpeed->Disconnect(wxEVT_COMMAND_TEXT_ENTER,
                                    wxCommandEventHandler(ManualCtrlFrame::OnTextEnterSpeed),
                                    nullptr,
                                    this);
        m_textCtrlSpeed->Disconnect(wxEVT_COMMAND_TEXT_MAXLEN,
                                    wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenSpeed),
                                    nullptr,
                                    this);
        m_sliderSpeed->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                                  wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseSpeed),
                                  nullptr,
                                  this);
        m_sliderSpeed->Disconnect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderSpeed), nullptr, this);
        m_textCtrlAccel->Disconnect(wxEVT_KILL_FOCUS,
                                    wxFocusEventHandler(ManualCtrlFrame::OnKillFocusAccel),
                                    nullptr,
                                    this);
        m_textCtrlAccel->Disconnect(wxEVT_COMMAND_TEXT_ENTER,
                                    wxCommandEventHandler(ManualCtrlFrame::OnTextEnterAccel),
                                    nullptr,
                                    this);
        m_textCtrlAccel->Disconnect(wxEVT_COMMAND_TEXT_MAXLEN,
                                    wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenAccel),
                                    nullptr,
                                    this);
        m_sliderAccel->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                                  wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseAccel),
                                  nullptr,
                                  this);
        m_sliderAccel->Disconnect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderAccel), nullptr, this);
        m_toggleBtn1->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
                                 wxCommandEventHandler(ManualCtrlFrame::OnToggleGrip01),
                                 nullptr,
                                 this);
        m_toggleBtn2->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
                                 wxCommandEventHandler(ManualCtrlFrame::OnToggleGrip02),
                                 nullptr,
                                 this);
        m_toggleBtn3->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,
                                 wxCommandEventHandler(ManualCtrlFrame::OnToggleAuto),
                                 nullptr,
                                 this);
        m_textCtrlZ->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusZ), nullptr, this);
        m_textCtrlZ->Disconnect(wxEVT_COMMAND_TEXT_ENTER,
                                wxCommandEventHandler(ManualCtrlFrame::OnTextEnterZ),
                                nullptr,
                                this);
        m_textCtrlZ->Disconnect(wxEVT_COMMAND_TEXT_MAXLEN,
                                wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenZ),
                                nullptr,
                                this);
        m_sliderZ->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                              wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseZ),
                              nullptr,
                              this);
        m_sliderZ->Disconnect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderZ), nullptr, this);
        m_textCtrlA1->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusA1), nullptr, this);
        m_textCtrlA1->Disconnect(wxEVT_COMMAND_TEXT_ENTER,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextEnterA1),
                                 nullptr,
                                 this);
        m_textCtrlA1->Disconnect(wxEVT_COMMAND_TEXT_MAXLEN,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenA1),
                                 nullptr,
                                 this);
        m_sliderA1->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                               wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseA1),
                               nullptr,
                               this);
        m_sliderA1->Disconnect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderA1), nullptr, this);
        m_textCtrlA2->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusA2), nullptr, this);
        m_textCtrlA2->Disconnect(wxEVT_COMMAND_TEXT_ENTER,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextEnterA2),
                                 nullptr,
                                 this);
        m_textCtrlA2->Disconnect(wxEVT_COMMAND_TEXT_MAXLEN,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenA2),
                                 nullptr,
                                 this);
        m_sliderA2->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                               wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseA2),
                               nullptr,
                               this);
        m_sliderA2->Disconnect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderA2), nullptr, this);
        m_textCtrlA3->Disconnect(wxEVT_KILL_FOCUS, wxFocusEventHandler(ManualCtrlFrame::OnKillFocusA3), nullptr, this);
        m_textCtrlA3->Disconnect(wxEVT_COMMAND_TEXT_ENTER,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextEnterA3),
                                 nullptr,
                                 this);
        m_textCtrlA3->Disconnect(wxEVT_COMMAND_TEXT_MAXLEN,
                                 wxCommandEventHandler(ManualCtrlFrame::OnTextMaxLenA3),
                                 nullptr,
                                 this);
        m_sliderA3->Disconnect(wxEVT_SCROLL_THUMBRELEASE,
                               wxScrollEventHandler(ManualCtrlFrame::OnSliderReleaseA3),
                               nullptr,
                               this);
        m_sliderA3->Disconnect(wxEVT_SLIDER, wxCommandEventHandler(ManualCtrlFrame::OnSliderA3), nullptr, this);

        this->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(ManualCtrlFrame::OnMouseRelease), nullptr, this);
        this->Disconnect(wxEVT_MOTION, wxMouseEventHandler(ManualCtrlFrame::OnMouseMotion), nullptr, this);
    }
}// namespace Frame