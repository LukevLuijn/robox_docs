///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* m_mainFrameSizer;
	m_mainFrameSizer = new wxBoxSizer( wxHORIZONTAL );

	m_selectorPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_selectorSizer;
	m_selectorSizer = new wxBoxSizer( wxVERTICAL );

	m_selectorWindow = new wxScrolledWindow( m_selectorPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_selectorWindow->SetScrollRate( 5, 5 );
	wxBoxSizer* m_selectorWindowSizer;
	m_selectorWindowSizer = new wxBoxSizer( wxVERTICAL );

	m_selectorBaseTitle = new wxStaticText( m_selectorWindow, wxID_ANY, wxT("Base"), wxDefaultPosition, wxDefaultSize, 0 );
	m_selectorBaseTitle->Wrap( -1 );
	m_selectorWindowSizer->Add( m_selectorBaseTitle, 0, wxALL, 5 );

	m_baseLine = new wxStaticLine( m_selectorWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_selectorWindowSizer->Add( m_baseLine, 0, wxEXPAND | wxALL, 5 );

	m_buttonSelectorControl = new wxButton( m_selectorWindow, wxID_ANY, wxT("Control"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxBU_LEFT );
	m_selectorWindowSizer->Add( m_buttonSelectorControl, 0, wxALL, 5 );

	m_buttonSelectorLog = new wxButton( m_selectorWindow, wxID_ANY, wxT("Log"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxBU_LEFT );
	m_selectorWindowSizer->Add( m_buttonSelectorLog, 0, wxALL, 5 );

	m_buttonSelectorInfo = new wxButton( m_selectorWindow, wxID_ANY, wxT("Info"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE|wxBU_LEFT );
	m_selectorWindowSizer->Add( m_buttonSelectorInfo, 0, wxALL, 5 );

	m_selectorAdditionalTitle = new wxStaticText( m_selectorWindow, wxID_ANY, wxT("Additional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_selectorAdditionalTitle->Wrap( -1 );
	m_selectorWindowSizer->Add( m_selectorAdditionalTitle, 0, wxALL|wxEXPAND, 5 );

	m_additionalLine = new wxStaticLine( m_selectorWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_selectorWindowSizer->Add( m_additionalLine, 0, wxEXPAND | wxALL, 5 );

	m_buttonSelectorBKE = new wxButton( m_selectorWindow, wxID_ANY, wxT("BKE control"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	m_selectorWindowSizer->Add( m_buttonSelectorBKE, 0, wxALL, 5 );


	m_selectorWindow->SetSizer( m_selectorWindowSizer );
	m_selectorWindow->Layout();
	m_selectorWindowSizer->Fit( m_selectorWindow );
	m_selectorSizer->Add( m_selectorWindow, 1, wxALL|wxEXPAND, 5 );

	m_selectorWindowLine = new wxStaticLine( m_selectorPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_selectorSizer->Add( m_selectorWindowLine, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* m_prioButtonsSizer;
	m_prioButtonsSizer = new wxBoxSizer( wxVERTICAL );

	m_buttonPrioPlay = new wxButton( m_selectorPanel, wxID_ANY, wxT("PLAY"), wxDefaultPosition, wxDefaultSize, 0 );
	m_prioButtonsSizer->Add( m_buttonPrioPlay, 1, wxALL|wxEXPAND, 5 );

	m_buttonPrioPause = new wxButton( m_selectorPanel, wxID_ANY, wxT("PAUSE"), wxDefaultPosition, wxDefaultSize, 0 );
	m_prioButtonsSizer->Add( m_buttonPrioPause, 1, wxALL|wxEXPAND, 5 );

	m_buttonPrioStop = new wxButton( m_selectorPanel, wxID_ANY, wxT("STOP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_prioButtonsSizer->Add( m_buttonPrioStop, 1, wxALL|wxEXPAND/*|wxALIGN_CENTER_HORIZONTAL*/, 5 );


	m_selectorSizer->Add( m_prioButtonsSizer, 1, wxEXPAND, 5 );


	m_selectorPanel->SetSizer( m_selectorSizer );
	m_selectorPanel->Layout();
	m_selectorSizer->Fit( m_selectorPanel );
	m_mainFrameSizer->Add( m_selectorPanel, 0, wxALL|wxEXPAND, 5 );

	m_selectorLine = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	m_mainFrameSizer->Add( m_selectorLine, 0, wxEXPAND | wxALL, 5 );

	m_controlPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_controlPanelSizer;
	m_controlPanelSizer = new wxBoxSizer( wxHORIZONTAL );

	m_controlPanelLeft = new wxPanel( m_controlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_controlPanelLeftSizer;
	m_controlPanelLeftSizer = new wxBoxSizer( wxVERTICAL );

	m_controlTitlePanel = new wxPanel( m_controlPanelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_controlTitleSizer;
	m_controlTitleSizer = new wxBoxSizer( wxHORIZONTAL );

	m_controlPanelTitle = new wxStaticText( m_controlTitlePanel, wxID_ANY, wxT("Control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_controlPanelTitle->Wrap( -1 );
	m_controlTitleSizer->Add( m_controlPanelTitle, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonManualControl = new wxButton( m_controlTitlePanel, wxID_ANY, wxT("Manual"), wxDefaultPosition, wxDefaultSize, 0 );
	m_controlTitleSizer->Add( m_buttonManualControl, 0, wxALL, 5 );

	m_buttonKeyboardControl = new wxButton( m_controlTitlePanel, wxID_ANY, wxT("Keyboard"), wxDefaultPosition, wxDefaultSize, 0 );
	m_controlTitleSizer->Add( m_buttonKeyboardControl, 0, wxALL, 5 );


	m_controlTitlePanel->SetSizer( m_controlTitleSizer );
	m_controlTitlePanel->Layout();
	m_controlTitleSizer->Fit( m_controlTitlePanel );
	m_controlPanelLeftSizer->Add( m_controlTitlePanel, 0, wxEXPAND, 5 );

	m_controlTitlePanelLine = new wxStaticLine( m_controlPanelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_controlPanelLeftSizer->Add( m_controlTitlePanelLine, 0, wxEXPAND | wxALL, 5 );

	m_staticControlPanel = new wxPanel( m_controlPanelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_staticControlSizer;
	m_staticControlSizer = new wxBoxSizer( wxHORIZONTAL );

	m_buttonStaticRun = new wxButton( m_staticControlPanel, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_staticControlSizer->Add( m_buttonStaticRun, 1, wxALL, 5 );

	m_buttonStaticSave = new wxButton( m_staticControlPanel, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_staticControlSizer->Add( m_buttonStaticSave, 1, wxALL, 5 );

	m_buttonStaticHome = new wxButton( m_staticControlPanel, wxID_ANY, wxT("Home"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_staticControlSizer->Add( m_buttonStaticHome, 1, wxALL, 5 );


	m_staticControlPanel->SetSizer( m_staticControlSizer );
	m_staticControlPanel->Layout();
	m_staticControlSizer->Fit( m_staticControlPanel );
	m_controlPanelLeftSizer->Add( m_staticControlPanel, 0, wxEXPAND, 5 );

	m_staticControlLine = new wxStaticLine( m_controlPanelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_controlPanelLeftSizer->Add( m_staticControlLine, 0, wxEXPAND | wxALL, 5 );

	m_manualControlPanel = new wxPanel( m_controlPanelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_manualControlPanel->Hide();

	wxBoxSizer* m_manualControlSizer;
	m_manualControlSizer = new wxBoxSizer( wxVERTICAL );

	m_variablePanel = new wxPanel( m_manualControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* m_variableSizer;
	m_variableSizer = new wxFlexGridSizer( 10, 4, 0, 0 );
	m_variableSizer->AddGrowableCol( 3 );
	m_variableSizer->SetFlexibleDirection( wxBOTH );
	m_variableSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_textSpeed0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSpeed0->Wrap( -1 );
	m_variableSizer->Add( m_textSpeed0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldSpeed0 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,  wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldSpeed0, 0, wxALL, 5 );

	m_iconSpeed0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconSpeed0->Wrap( -1 );
	m_variableSizer->Add( m_iconSpeed0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderSpeed0 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderSpeed0, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textAccel0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("Accel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textAccel0->Wrap( -1 );
	m_variableSizer->Add( m_textAccel0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldAccel0 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldAccel0, 0, wxALL, 5 );

	m_iconAccel0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconAccel0->Wrap( -1 );
	m_variableSizer->Add( m_iconAccel0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderAccel0 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderAccel0, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textStep0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("Step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textStep0->Wrap( -1 );
	m_variableSizer->Add( m_textStep0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldStep0 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldStep0, 0, wxALL, 5 );

	m_iconStep0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconStep0->Wrap( -1 );
	m_variableSizer->Add( m_iconStep0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderStep0 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderStep0, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textJoint0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("J0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textJoint0->Wrap( -1 );
	m_variableSizer->Add( m_textJoint0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldJoint0 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldJoint0, 0, wxALL, 5 );

	m_iconJoint0 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconJoint0->Wrap( -1 );
	m_variableSizer->Add( m_iconJoint0, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderJoint0 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderJoint0, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textJoint1 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("J1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textJoint1->Wrap( -1 );
	m_variableSizer->Add( m_textJoint1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldJoint1 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldJoint1, 0, wxALL, 5 );

	m_iconJoint1 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconJoint1->Wrap( -1 );
	m_variableSizer->Add( m_iconJoint1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderJoint1 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderJoint1, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textJoint2 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("J2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textJoint2->Wrap( -1 );
	m_variableSizer->Add( m_textJoint2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldJoint2 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldJoint2, 0, wxALL, 5 );

	m_iconJoint2 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconJoint2->Wrap( -1 );
	m_variableSizer->Add( m_iconJoint2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderJoint2 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderJoint2, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textJoint3 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("J3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textJoint3->Wrap( -1 );
	m_variableSizer->Add( m_textJoint3, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldJoint3 = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldJoint3, 0, wxALL, 5 );

	m_iconJoint3 = new wxStaticText( m_variablePanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconJoint3->Wrap( -1 );
	m_variableSizer->Add( m_iconJoint3, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderJoint3 = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderJoint3, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textX = new wxStaticText( m_variablePanel, wxID_ANY, wxT("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textX->Wrap( -1 );
	m_variableSizer->Add( m_textX, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_fieldX = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldX, 0, wxALL, 5 );

	m_iconX = new wxStaticText( m_variablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconX->Wrap( -1 );
	m_variableSizer->Add( m_iconX, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderX = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderX, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textY = new wxStaticText( m_variablePanel, wxID_ANY, wxT("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textY->Wrap( -1 );
	m_variableSizer->Add( m_textY, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

	m_fieldY = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldY, 0, wxALL, 5 );

	m_iconY = new wxStaticText( m_variablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconY->Wrap( -1 );
	m_variableSizer->Add( m_iconY, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderY = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderY, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_textZ = new wxStaticText( m_variablePanel, wxID_ANY, wxT("Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textZ->Wrap( -1 );
	m_variableSizer->Add( m_textZ, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

	m_fieldZ = new wxTextCtrl( m_variablePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_variableSizer->Add( m_fieldZ, 0, wxALL, 5 );

	m_iconZ = new wxStaticText( m_variablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_iconZ->Wrap( -1 );
	m_variableSizer->Add( m_iconZ, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_sliderZ = new wxSlider( m_variablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_variableSizer->Add( m_sliderZ, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	m_variablePanel->SetSizer( m_variableSizer );
	m_variablePanel->Layout();
	m_variableSizer->Fit( m_variablePanel );
	m_manualControlSizer->Add( m_variablePanel, 1, wxEXPAND, 5 );

	m_variableLine = new wxStaticLine( m_manualControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_manualControlSizer->Add( m_variableLine, 0, wxEXPAND | wxALL, 5 );

	m_gripperPanel = new wxPanel( m_manualControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_gripperSizer;
	m_gripperSizer = new wxBoxSizer( wxHORIZONTAL );

	m_textGripperState = new wxStaticText( m_gripperPanel, wxID_ANY, wxT("Gripper state"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textGripperState->Wrap( -1 );
	m_gripperSizer->Add( m_textGripperState, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonGripperOn = new wxButton( m_gripperPanel, wxID_ANY, wxT("On"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_gripperSizer->Add( m_buttonGripperOn, 0, wxALL|wxEXPAND, 5 );

	m_buttonGripperOff = new wxButton( m_gripperPanel, wxID_ANY, wxT("Off"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_gripperSizer->Add( m_buttonGripperOff, 0, wxALL|wxEXPAND, 5 );


	m_gripperPanel->SetSizer( m_gripperSizer );
	m_gripperPanel->Layout();
	m_gripperSizer->Fit( m_gripperPanel );
	m_manualControlSizer->Add( m_gripperPanel, 1, wxEXPAND, 5 );


	m_manualControlPanel->SetSizer( m_manualControlSizer );
	m_manualControlPanel->Layout();
	m_manualControlSizer->Fit( m_manualControlPanel );
	m_controlPanelLeftSizer->Add( m_manualControlPanel, 1, wxEXPAND, 5 );

	m_keyboardControlPanel = new wxPanel( m_controlPanelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_keyboardControlSizer;
	m_keyboardControlSizer = new wxBoxSizer( wxVERTICAL );

	m_kbVariablePanel = new wxPanel( m_keyboardControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* m_kbVariableSizer;
	m_kbVariableSizer = new wxFlexGridSizer( 3, 4, 0, 0 );
	m_kbVariableSizer->AddGrowableCol( 3 );
	m_kbVariableSizer->SetFlexibleDirection( wxBOTH );
	m_kbVariableSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_kbTextSpeed = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbTextSpeed->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbTextSpeed, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_kbValueSpeed = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueSpeed->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbValueSpeed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_kbIconSpeed = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconSpeed->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbIconSpeed, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );

	m_kbSliderSpeed = new wxSlider( m_kbVariablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_kbVariableSizer->Add( m_kbSliderSpeed, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_kbTextAccel = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("Accel:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbTextAccel->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbTextAccel, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_kbValueAccel = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueAccel->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbValueAccel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_kbIconAccel = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconAccel->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbIconAccel, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );

	m_kbSliderAccel = new wxSlider( m_kbVariablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_kbVariableSizer->Add( m_kbSliderAccel, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_kbTextStep = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("Step:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbTextStep->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbTextStep, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_kbValueStep = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueStep->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbValueStep, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_kbIconStep = new wxStaticText( m_kbVariablePanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconStep->Wrap( -1 );
	m_kbVariableSizer->Add( m_kbIconStep, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );

	m_kbSliderStep = new wxSlider( m_kbVariablePanel, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_kbVariableSizer->Add( m_kbSliderStep, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	m_kbVariablePanel->SetSizer( m_kbVariableSizer );
	m_kbVariablePanel->Layout();
	m_kbVariableSizer->Fit( m_kbVariablePanel );
	m_keyboardControlSizer->Add( m_kbVariablePanel, 0, wxEXPAND, 5 );

	m_kbVariableLine = new wxStaticLine( m_keyboardControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_keyboardControlSizer->Add( m_kbVariableLine, 0, wxEXPAND | wxALL, 5 );

	m_kbPosPanel = new wxPanel( m_keyboardControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_kbPosSizer;
	m_kbPosSizer = new wxBoxSizer( wxVERTICAL );

	m_kbPosTitlePanel = new wxPanel( m_kbPosPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_kbPosTitleSizer;
	m_kbPosTitleSizer = new wxBoxSizer( wxVERTICAL );

	m_kbTextPosTitle = new wxStaticText( m_kbPosTitlePanel, wxID_ANY, wxT("Position and angles"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbTextPosTitle->Wrap( -1 );
	m_kbPosTitleSizer->Add( m_kbTextPosTitle, 0, wxALL, 5 );


	m_kbPosTitlePanel->SetSizer( m_kbPosTitleSizer );
	m_kbPosTitlePanel->Layout();
	m_kbPosTitleSizer->Fit( m_kbPosTitlePanel );
	m_kbPosSizer->Add( m_kbPosTitlePanel, 0, wxEXPAND, 5 );

	m_kbPosTitleLine = new wxStaticLine( m_kbPosPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_kbPosSizer->Add( m_kbPosTitleLine, 0, wxEXPAND | wxALL, 5 );

	m_kbPosVariablePanel = new wxPanel( m_kbPosPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* m_kbPosVariableSizer;
	m_kbPosVariableSizer = new wxFlexGridSizer( 4, 6, 0, 0 );
	m_kbPosVariableSizer->AddGrowableCol( 2 );
	m_kbPosVariableSizer->AddGrowableCol( 5 );
	m_kbPosVariableSizer->AddGrowableRow( 0 );
	m_kbPosVariableSizer->AddGrowableRow( 1 );
	m_kbPosVariableSizer->AddGrowableRow( 2 );
	m_kbPosVariableSizer->AddGrowableRow( 3 );
	m_kbPosVariableSizer->SetFlexibleDirection( wxBOTH );
	m_kbPosVariableSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_kbNameJoint0 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("J0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameJoint0->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameJoint0, 0, wxALL, 5 );

	m_kbValueJoint0 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueJoint0->Wrap( -1 );
	m_kbValueJoint0->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_kbPosVariableSizer->Add( m_kbValueJoint0, 0, wxALL, 5 );

	m_kbIconJoint0 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconJoint0->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconJoint0, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameVarX = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameVarX->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameVarX, 0, wxALL, 5 );

	m_kbValueVarX = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueVarX->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueVarX, 0, wxALL, 5 );

	m_kbIconVarX = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconVarX->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconVarX, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameJoint1 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("J1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameJoint1->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameJoint1, 0, wxALL, 5 );

	m_kbValueJoint1 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueJoint1->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueJoint1, 0, wxALL, 5 );

	m_kbIconJoint1 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconJoint1->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconJoint1, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameVarY = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameVarY->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameVarY, 0, wxALL, 5 );

	m_kbValueVarY = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueVarY->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueVarY, 0, wxALL, 5 );

	m_kbIconVarY = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconVarY->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconVarY, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameJoint2 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("J2:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameJoint2->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameJoint2, 0, wxALL, 5 );

	m_kbValueJoint2 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueJoint2->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueJoint2, 0, wxALL, 5 );

	m_kbIconJoint2 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconJoint2->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconJoint2, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameVarZ = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameVarZ->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameVarZ, 0, wxALL, 5 );

	m_kbValueVarZ = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueVarZ->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueVarZ, 0, wxALL, 5 );

	m_kbIconVarZ = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconVarZ->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconVarZ, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameJoint3 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("J3:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameJoint3->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameJoint3, 0, wxALL, 5 );

	m_kbValueJoint3 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueJoint3->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueJoint3, 0, wxALL, 5 );

	m_kbIconJoint3 = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("°"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbIconJoint3->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbIconJoint3, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_kbNameVarG = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("G:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbNameVarG->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbNameVarG, 0, wxALL, 5 );

	m_kbValueVarG = new wxStaticText( m_kbPosVariablePanel, wxID_ANY, wxT("Active"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbValueVarG->Wrap( -1 );
	m_kbPosVariableSizer->Add( m_kbValueVarG, 0, wxALL, 5 );


	m_kbPosVariablePanel->SetSizer( m_kbPosVariableSizer );
	m_kbPosVariablePanel->Layout();
	m_kbPosVariableSizer->Fit( m_kbPosVariablePanel );
	m_kbPosSizer->Add( m_kbPosVariablePanel, 1, wxEXPAND, 5 );


	m_kbPosPanel->SetSizer( m_kbPosSizer );
	m_kbPosPanel->Layout();
	m_kbPosSizer->Fit( m_kbPosPanel );
	m_keyboardControlSizer->Add( m_kbPosPanel, 1, wxEXPAND, 5 );

	m_kbPosLine = new wxStaticLine( m_keyboardControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_keyboardControlSizer->Add( m_kbPosLine, 0, wxEXPAND | wxALL, 5 );

	m_kbControlsPanel = new wxPanel( m_keyboardControlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_kbControlsSizer;
	m_kbControlsSizer = new wxBoxSizer( wxVERTICAL );

	m_kbControlsTitlePanel = new wxPanel( m_kbControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_kbControlsTitleSizer;
	m_kbControlsTitleSizer = new wxBoxSizer( wxHORIZONTAL );

	m_kbControlsTitle = new wxStaticText( m_kbControlsTitlePanel, wxID_ANY, wxT("Keyboard controls"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_kbControlsTitle->Wrap( -1 );
	m_kbControlsTitleSizer->Add( m_kbControlsTitle, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	m_kbControlsTitlePanel->SetSizer( m_kbControlsTitleSizer );
	m_kbControlsTitlePanel->Layout();
	m_kbControlsTitleSizer->Fit( m_kbControlsTitlePanel );
	m_kbControlsSizer->Add( m_kbControlsTitlePanel, 0, wxEXPAND, 5 );

	m_kbControlsLine = new wxStaticLine( m_kbControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_kbControlsSizer->Add( m_kbControlsLine, 0, wxEXPAND | wxALL, 5 );

	m_kbActualControlsPanel = new wxPanel( m_kbControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* m_kbActualControlsSizer;
	m_kbActualControlsSizer = new wxFlexGridSizer( 4, 2, 0, 0 );
	m_kbActualControlsSizer->AddGrowableCol( 1 );
	m_kbActualControlsSizer->SetFlexibleDirection( wxBOTH );
	m_kbActualControlsSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_kbControlsTextXY = new wxStaticText( m_kbActualControlsPanel, wxID_ANY, wxT("XY-Movement"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsTextXY->Wrap( -1 );
	m_kbActualControlsSizer->Add( m_kbControlsTextXY, 0, wxALL, 5 );

	m_kbControlsXYIconPanel = new wxPanel( m_kbActualControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* m_kbControlsXYIconSizer;
	m_kbControlsXYIconSizer = new wxGridSizer( 0, 4, 0, 0 );

	m_kbControlsW = new wxStaticBitmap( m_kbControlsXYIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsXYIconSizer->Add( m_kbControlsW, 0, wxALL|wxEXPAND, 5 );

	m_kbControlsA = new wxStaticBitmap( m_kbControlsXYIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsXYIconSizer->Add( m_kbControlsA, 0, wxALL|wxEXPAND, 5 );

	m_kbControlsS = new wxStaticBitmap( m_kbControlsXYIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsXYIconSizer->Add( m_kbControlsS, 0, wxALL|wxEXPAND, 5 );

	m_kbControlsD = new wxStaticBitmap( m_kbControlsXYIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsXYIconSizer->Add( m_kbControlsD, 0, wxALL|wxEXPAND, 5 );


	m_kbControlsXYIconPanel->SetSizer( m_kbControlsXYIconSizer );
	m_kbControlsXYIconPanel->Layout();
	m_kbControlsXYIconSizer->Fit( m_kbControlsXYIconPanel );
	m_kbActualControlsSizer->Add( m_kbControlsXYIconPanel, 1, wxEXPAND|wxLEFT, 5 );

	m_kbControlsTextZ = new wxStaticText( m_kbActualControlsPanel, wxID_ANY, wxT("Z-Movement"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsTextZ->Wrap( -1 );
	m_kbActualControlsSizer->Add( m_kbControlsTextZ, 0, wxALL, 5 );

	m_kbControlsZIconPanel = new wxPanel( m_kbActualControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* m_kbControlsZIconSizer;
	m_kbControlsZIconSizer = new wxGridSizer( 0, 2, 0, 0 );

	m_kbControlsArrowUp = new wxStaticBitmap( m_kbControlsZIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsZIconSizer->Add( m_kbControlsArrowUp, 0, wxALL|wxEXPAND, 5 );

	m_kbControlsArrowDown = new wxStaticBitmap( m_kbControlsZIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsZIconSizer->Add( m_kbControlsArrowDown, 0, wxALL|wxEXPAND, 5 );


	m_kbControlsZIconPanel->SetSizer( m_kbControlsZIconSizer );
	m_kbControlsZIconPanel->Layout();
	m_kbControlsZIconSizer->Fit( m_kbControlsZIconPanel );
	m_kbActualControlsSizer->Add( m_kbControlsZIconPanel, 1, wxEXPAND|wxLEFT, 5 );

	m_kbControlsTextStep = new wxStaticText( m_kbActualControlsPanel, wxID_ANY, wxT("In/decrease step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsTextStep->Wrap( -1 );
	m_kbActualControlsSizer->Add( m_kbControlsTextStep, 0, wxALL, 5 );

	m_kbControlsStepIconPanel = new wxPanel( m_kbActualControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* m_kbControlsStepIconSizer;
	m_kbControlsStepIconSizer = new wxGridSizer( 0, 2, 0, 0 );

	m_kbControlsPlus = new wxStaticBitmap( m_kbControlsStepIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsStepIconSizer->Add( m_kbControlsPlus, 0, wxALL|wxEXPAND, 5 );

	m_kbControlsMin = new wxStaticBitmap( m_kbControlsStepIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsStepIconSizer->Add( m_kbControlsMin, 0, wxALL|wxEXPAND, 5 );


	m_kbControlsStepIconPanel->SetSizer( m_kbControlsStepIconSizer );
	m_kbControlsStepIconPanel->Layout();
	m_kbControlsStepIconSizer->Fit( m_kbControlsStepIconPanel );
	m_kbActualControlsSizer->Add( m_kbControlsStepIconPanel, 1, wxEXPAND|wxLEFT, 5 );

	m_kbControlsTextSpeed = new wxStaticText( m_kbActualControlsPanel, wxID_ANY, wxT("Speed select"), wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsTextSpeed->Wrap( -1 );
	m_kbActualControlsSizer->Add( m_kbControlsTextSpeed, 0, wxALL, 5 );

	m_kbControlsSpeedIconPanel = new wxPanel( m_kbActualControlsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* m_kbControlsSpeedIconSizer;
	m_kbControlsSpeedIconSizer = new wxGridSizer( 0, 2, 0, 0 );

	m_kbControlsZero = new wxStaticBitmap( m_kbControlsSpeedIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsSpeedIconSizer->Add( m_kbControlsZero, 0, wxALL|wxEXPAND, 5 );

	m_kbControlsNine = new wxStaticBitmap( m_kbControlsSpeedIconPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_kbControlsSpeedIconSizer->Add( m_kbControlsNine, 0, wxALL|wxEXPAND, 5 );


	m_kbControlsSpeedIconPanel->SetSizer( m_kbControlsSpeedIconSizer );
	m_kbControlsSpeedIconPanel->Layout();
	m_kbControlsSpeedIconSizer->Fit( m_kbControlsSpeedIconPanel );
	m_kbActualControlsSizer->Add( m_kbControlsSpeedIconPanel, 1, wxEXPAND|wxLEFT, 5 );


	m_kbActualControlsPanel->SetSizer( m_kbActualControlsSizer );
	m_kbActualControlsPanel->Layout();
	m_kbActualControlsSizer->Fit( m_kbActualControlsPanel );
	m_kbControlsSizer->Add( m_kbActualControlsPanel, 1, wxEXPAND, 5 );


	m_kbControlsPanel->SetSizer( m_kbControlsSizer );
	m_kbControlsPanel->Layout();
	m_kbControlsSizer->Fit( m_kbControlsPanel );
	m_keyboardControlSizer->Add( m_kbControlsPanel, 1, wxEXPAND, 5 );


	m_keyboardControlPanel->SetSizer( m_keyboardControlSizer );
	m_keyboardControlPanel->Layout();
	m_keyboardControlSizer->Fit( m_keyboardControlPanel );
	m_controlPanelLeftSizer->Add( m_keyboardControlPanel, 1, wxEXPAND, 5 );


	m_controlPanelLeft->SetSizer( m_controlPanelLeftSizer );
	m_controlPanelLeft->Layout();
	m_controlPanelLeftSizer->Fit( m_controlPanelLeft );
	m_controlPanelSizer->Add( m_controlPanelLeft, 1, wxALL, 5 );

	m_controlPanelLeftLine = new wxStaticLine( m_controlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	m_controlPanelSizer->Add( m_controlPanelLeftLine, 0, wxEXPAND | wxALL, 5 );

	m_sequenceMenuPanel = new wxPanel( m_controlPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_sequenceMenuSizer;
	m_sequenceMenuSizer = new wxBoxSizer( wxVERTICAL );

	m_smTitlePanel = new wxPanel( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smTitleSizer;
	m_smTitleSizer = new wxBoxSizer( wxHORIZONTAL );

	m_smTitleText = new wxStaticText( m_smTitlePanel, wxID_ANY, wxT("Sequence menu"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smTitleText->Wrap( -1 );
	m_smTitleSizer->Add( m_smTitleText, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonNewSequence = new wxButton( m_smTitlePanel, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smTitleSizer->Add( m_buttonNewSequence, 0, wxALL, 5 );


	m_smTitlePanel->SetSizer( m_smTitleSizer );
	m_smTitlePanel->Layout();
	m_smTitleSizer->Fit( m_smTitlePanel );
	m_sequenceMenuSizer->Add( m_smTitlePanel, 0, wxEXPAND, 5 );

	m_smTitleLine = new wxStaticLine( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_sequenceMenuSizer->Add( m_smTitleLine, 0, wxEXPAND | wxALL, 5 );

	m_smSelectPanel = new wxPanel( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smSelectSizer;
	m_smSelectSizer = new wxBoxSizer( wxHORIZONTAL );

	m_sequenceSelectScrolledPanel = new wxScrolledWindow( m_smSelectPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_sequenceSelectScrolledPanel->SetScrollRate( 5, 5 );
	wxBoxSizer* m_sequenceSelectScrolledSizer;
	m_sequenceSelectScrolledSizer = new wxBoxSizer( wxVERTICAL );

	m_tmp_sequence_01 = new wxButton( m_sequenceSelectScrolledPanel, wxID_ANY, wxT("tmp_sequence_01"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	m_sequenceSelectScrolledSizer->Add( m_tmp_sequence_01, 0, wxALL, 5 );

	m_tmp_sequence_02 = new wxButton( m_sequenceSelectScrolledPanel, wxID_ANY, wxT("tmp_sequence_02"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	m_sequenceSelectScrolledSizer->Add( m_tmp_sequence_02, 0, wxALL, 5 );


	m_sequenceSelectScrolledPanel->SetSizer( m_sequenceSelectScrolledSizer );
	m_sequenceSelectScrolledPanel->Layout();
	m_sequenceSelectScrolledSizer->Fit( m_sequenceSelectScrolledPanel );
	m_smSelectSizer->Add( m_sequenceSelectScrolledPanel, 1, wxEXPAND | wxALL, 5 );

	m_sequenceSelectLine = new wxStaticLine( m_smSelectPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	m_smSelectSizer->Add( m_sequenceSelectLine, 0, wxEXPAND | wxALL, 5 );

	m_smMoveSelectPanel = new wxPanel( m_smSelectPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smMoveSelectSizer;
	m_smMoveSelectSizer = new wxBoxSizer( wxVERTICAL );

	m_smSequenceNamePanel = new wxPanel( m_smMoveSelectPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smSequenceNameSizer;
	m_smSequenceNameSizer = new wxBoxSizer( wxHORIZONTAL );

	m_smSequenceName = new wxStaticText( m_smSequenceNamePanel, wxID_ANY, wxT("seq name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smSequenceName->Wrap( 10 );
	m_smSequenceNameSizer->Add( m_smSequenceName, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonSequenceNameEdit = new wxButton( m_smSequenceNamePanel, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smSequenceNameSizer->Add( m_buttonSequenceNameEdit, 0, wxALL, 5 );


	m_smSequenceNamePanel->SetSizer( m_smSequenceNameSizer );
	m_smSequenceNamePanel->Layout();
	m_smSequenceNameSizer->Fit( m_smSequenceNamePanel );
	m_smMoveSelectSizer->Add( m_smSequenceNamePanel, 0, wxEXPAND, 5 );

	m_smSequenceNameLine = new wxStaticLine( m_smMoveSelectPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_smMoveSelectSizer->Add( m_smSequenceNameLine, 0, wxEXPAND | wxALL, 5 );

	m_smSequenceMovesPanel = new wxScrolledWindow( m_smMoveSelectPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_smSequenceMovesPanel->SetScrollRate( 5, 5 );
	wxBoxSizer* smSequenceMovesSizer;
	smSequenceMovesSizer = new wxBoxSizer( wxVERTICAL );

	tmp_move_01 = new wxButton( m_smSequenceMovesPanel, wxID_ANY, wxT("tmp_move_01"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	smSequenceMovesSizer->Add( tmp_move_01, 0, wxALL, 5 );

	tmp_move_02 = new wxButton( m_smSequenceMovesPanel, wxID_ANY, wxT("tmp_move_02"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	smSequenceMovesSizer->Add( tmp_move_02, 0, wxALL, 5 );


	m_smSequenceMovesPanel->SetSizer( smSequenceMovesSizer );
	m_smSequenceMovesPanel->Layout();
	smSequenceMovesSizer->Fit( m_smSequenceMovesPanel );
	m_smMoveSelectSizer->Add( m_smSequenceMovesPanel, 1, wxEXPAND | wxALL, 5 );


	m_smMoveSelectPanel->SetSizer( m_smMoveSelectSizer );
	m_smMoveSelectPanel->Layout();
	m_smMoveSelectSizer->Fit( m_smMoveSelectPanel );
	m_smSelectSizer->Add( m_smMoveSelectPanel, 1, wxEXPAND, 5 );


	m_smSelectPanel->SetSizer( m_smSelectSizer );
	m_smSelectPanel->Layout();
	m_smSelectSizer->Fit( m_smSelectPanel );
	m_sequenceMenuSizer->Add( m_smSelectPanel, 1, wxEXPAND, 5 );

	m_smSelectLine = new wxStaticLine( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_sequenceMenuSizer->Add( m_smSelectLine, 0, wxEXPAND | wxALL, 5 );

	m_smSelectControlPanel = new wxPanel( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smSelectControlSizer;
	m_smSelectControlSizer = new wxBoxSizer( wxHORIZONTAL );

	m_buttonRunSequence = new wxButton( m_smSelectControlPanel, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smSelectControlSizer->Add( m_buttonRunSequence, 1, wxALL, 5 );

	m_buttonLoopSequence = new wxButton( m_smSelectControlPanel, wxID_ANY, wxT("Loop"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smSelectControlSizer->Add( m_buttonLoopSequence, 1, wxALL, 5 );

	m_buttonDeleteSequence = new wxButton( m_smSelectControlPanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smSelectControlSizer->Add( m_buttonDeleteSequence, 1, wxALL, 5 );


	m_smSelectControlPanel->SetSizer( m_smSelectControlSizer );
	m_smSelectControlPanel->Layout();
	m_smSelectControlSizer->Fit( m_smSelectControlPanel );
	m_sequenceMenuSizer->Add( m_smSelectControlPanel, 0, wxEXPAND, 5 );

	m_smSelectControlLine = new wxStaticLine( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_sequenceMenuSizer->Add( m_smSelectControlLine, 0, wxEXPAND | wxALL, 5 );

	m_smMoveTitlePanel = new wxPanel( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smMoveTitleSizer;
	m_smMoveTitleSizer = new wxBoxSizer( wxHORIZONTAL );

	m_smMoveTitle = new wxStaticText( m_smMoveTitlePanel, wxID_ANY, wxT("tmp_move_01"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveTitle->Wrap( -1 );
	m_smMoveTitleSizer->Add( m_smMoveTitle, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonEditMoveTitle = new wxButton( m_smMoveTitlePanel, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smMoveTitleSizer->Add( m_buttonEditMoveTitle, 0, wxALL, 5 );


	m_smMoveTitlePanel->SetSizer( m_smMoveTitleSizer );
	m_smMoveTitlePanel->Layout();
	m_smMoveTitleSizer->Fit( m_smMoveTitlePanel );
	m_sequenceMenuSizer->Add( m_smMoveTitlePanel, 0, wxEXPAND, 5 );

	m_smMoveTitleLine = new wxStaticLine( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_sequenceMenuSizer->Add( m_smMoveTitleLine, 0, wxEXPAND | wxALL, 5 );

	m_smMoveVariablePanel = new wxPanel( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smMoveVariableSizer;
	m_smMoveVariableSizer = new wxBoxSizer( wxHORIZONTAL );

	m_smMoveVarLeftPanel = new wxPanel( m_smMoveVariablePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* m_smMoveVarLeftSizer;
	m_smMoveVarLeftSizer = new wxFlexGridSizer( 3, 3, 0, 0 );
	m_smMoveVarLeftSizer->SetFlexibleDirection( wxBOTH );
	m_smMoveVarLeftSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_smMoveVarTextSpeed = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarTextSpeed->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarTextSpeed, 0, wxALL, 5 );

	m_smMoveVarValueSpeed = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarValueSpeed->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarValueSpeed, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_smMoveVarIconSpeed = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarIconSpeed->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarIconSpeed, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_smMoveVarTextAccel = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("Accel:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarTextAccel->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarTextAccel, 0, wxALL, 5 );

	m_smMoveVarValueAccel = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarValueAccel->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarValueAccel, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_smMoveVarIconAccel = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarIconAccel->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarIconAccel, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_smMoveVarTextGripper = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("Gripper:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarTextGripper->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarTextGripper, 0, wxALL, 5 );

	m_smMoveVarValueGripper = new wxStaticText( m_smMoveVarLeftPanel, wxID_ANY, wxT("Active"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarValueGripper->Wrap( -1 );
	m_smMoveVarLeftSizer->Add( m_smMoveVarValueGripper, 0, wxALL, 5 );


	m_smMoveVarLeftPanel->SetSizer( m_smMoveVarLeftSizer );
	m_smMoveVarLeftPanel->Layout();
	m_smMoveVarLeftSizer->Fit( m_smMoveVarLeftPanel );
	m_smMoveVariableSizer->Add( m_smMoveVarLeftPanel, 1, wxEXPAND, 5 );

	m_smMoveVarLeftLine = new wxStaticLine( m_smMoveVariablePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	m_smMoveVariableSizer->Add( m_smMoveVarLeftLine, 0, wxEXPAND | wxALL, 5 );

	m_smMoveVarRightPanel = new wxPanel( m_smMoveVariablePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* m_smMoveVarRightSizer;
	m_smMoveVarRightSizer = new wxFlexGridSizer( 3, 3, 0, 0 );
	m_smMoveVarRightSizer->SetFlexibleDirection( wxBOTH );
	m_smMoveVarRightSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_smMoveVarTextX = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarTextX->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarTextX, 0, wxALL, 5 );

	m_smMoveVarValueX = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarValueX->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarValueX, 0, wxALL, 5 );

	m_smMoveVarIconX = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarIconX->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarIconX, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_smMoveVarTextY = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarTextY->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarTextY, 0, wxALL, 5 );

	m_smMoveVarValueY = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarValueY->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarValueY, 0, wxALL, 5 );

	m_smMoveVarIconY = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarIconY->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarIconY, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );

	m_smMoveVarTextZ = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarTextZ->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarTextZ, 0, wxALL, 5 );

	m_smMoveVarValueZ = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("100.00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarValueZ->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarValueZ, 0, wxALL, 5 );

	m_smMoveVarIconZ = new wxStaticText( m_smMoveVarRightPanel, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_smMoveVarIconZ->Wrap( -1 );
	m_smMoveVarRightSizer->Add( m_smMoveVarIconZ, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );


	m_smMoveVarRightPanel->SetSizer( m_smMoveVarRightSizer );
	m_smMoveVarRightPanel->Layout();
	m_smMoveVarRightSizer->Fit( m_smMoveVarRightPanel );
	m_smMoveVariableSizer->Add( m_smMoveVarRightPanel, 1, wxEXPAND, 5 );


	m_smMoveVariablePanel->SetSizer( m_smMoveVariableSizer );
	m_smMoveVariablePanel->Layout();
	m_smMoveVariableSizer->Fit( m_smMoveVariablePanel );
	m_sequenceMenuSizer->Add( m_smMoveVariablePanel, 0, wxEXPAND, 5 );

	m_smMoveVariableLine = new wxStaticLine( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_sequenceMenuSizer->Add( m_smMoveVariableLine, 0, wxEXPAND | wxALL, 5 );

	m_smMoveControlPanel = new wxPanel( m_sequenceMenuPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* m_smMoveControlSizer;
	m_smMoveControlSizer = new wxBoxSizer( wxHORIZONTAL );

	m_smButtonGoToPosition = new wxButton( m_smMoveControlPanel, wxID_ANY, wxT("Go to"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smMoveControlSizer->Add( m_smButtonGoToPosition, 1, wxALL, 5 );

	m_smButtonEditMove = new wxButton( m_smMoveControlPanel, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smMoveControlSizer->Add( m_smButtonEditMove, 1, wxALL, 5 );

	m_smButtonDeleteMove = new wxButton( m_smMoveControlPanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	m_smMoveControlSizer->Add( m_smButtonDeleteMove, 1, wxALL, 5 );


	m_smMoveControlPanel->SetSizer( m_smMoveControlSizer );
	m_smMoveControlPanel->Layout();
	m_smMoveControlSizer->Fit( m_smMoveControlPanel );
	m_sequenceMenuSizer->Add( m_smMoveControlPanel, 0, wxEXPAND, 5 );


	m_sequenceMenuPanel->SetSizer( m_sequenceMenuSizer );
	m_sequenceMenuPanel->Layout();
	m_sequenceMenuSizer->Fit( m_sequenceMenuPanel );
	m_controlPanelSizer->Add( m_sequenceMenuPanel, 1, wxEXPAND | wxALL, 5 );


	m_controlPanel->SetSizer( m_controlPanelSizer );
	m_controlPanel->Layout();
	m_controlPanelSizer->Fit( m_controlPanel );
	m_mainFrameSizer->Add( m_controlPanel, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( m_mainFrameSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_buttonSelectorControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlPage ), NULL, this );
	m_buttonSelectorLog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickLogPage ), NULL, this );
	m_buttonSelectorInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickInfoPage ), NULL, this );
	m_buttonSelectorBKE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickBKEControlPage ), NULL, this );
	m_buttonPrioPlay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickPrioPLAY ), NULL, this );
	m_buttonPrioPause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickPrioPAUSE ), NULL, this );
	m_buttonPrioStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickPrioSTOP ), NULL, this );
	m_buttonManualControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlManual ), NULL, this );
	m_buttonKeyboardControl->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlKeyboard ), NULL, this );
	m_buttonStaticRun->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlRunPosition ), NULL, this );
	m_buttonStaticSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlSavePosition ), NULL, this );
	m_buttonStaticHome->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlHomePosition ), NULL, this );
	m_fieldSpeed0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualSpeed ), NULL, this );
	m_fieldSpeed0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualSpeed ), NULL, this );
	m_sliderSpeed0->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualSpeed ), NULL, this );
	m_fieldAccel0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualAccel ), NULL, this );
	m_fieldAccel0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualAccel ), NULL, this );
	m_sliderAccel0->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualAccel ), NULL, this );
	m_fieldStep0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualStep ), NULL, this );
	m_fieldStep0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualStep ), NULL, this );
	m_sliderStep0->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualStep ), NULL, this );
	m_fieldJoint0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint0 ), NULL, this );
	m_fieldJoint0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint0 ), NULL, this );
	m_sliderJoint0->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint0 ), NULL, this );
	m_fieldJoint1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint1 ), NULL, this );
	m_fieldJoint1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint1 ), NULL, this );
	m_sliderJoint1->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint1 ), NULL, this );
	m_fieldJoint2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint2 ), NULL, this );
	m_fieldJoint2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint2 ), NULL, this );
	m_sliderJoint2->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint2 ), NULL, this );
	m_fieldJoint3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint3 ), NULL, this );
	m_fieldJoint3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint3 ), NULL, this );
	m_sliderJoint3->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint3 ), NULL, this );
	m_fieldX->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualVarX ), NULL, this );
	m_fieldX->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualVarX ), NULL, this );
	m_sliderX->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualVarX ), NULL, this );
	m_fieldY->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualVarY ), NULL, this );
	m_fieldY->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualVarY ), NULL, this );
	m_sliderY->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualVarY ), NULL, this );
	m_fieldZ->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualVarZ ), NULL, this );
	m_fieldZ->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualVarZ ), NULL, this );
	m_sliderZ->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualVarZ ), NULL, this );
	m_buttonGripperOn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickManualGripperOn ), NULL, this );
	m_buttonGripperOff->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickManualGripperOff ), NULL, this );
	m_kbSliderSpeed->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderKeyboardSpeed ), NULL, this );
	m_kbSliderAccel->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderKeuboardAccel ), NULL, this );
	m_kbSliderStep->Connect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderKeyboardStep ), NULL, this );
	m_buttonNewSequence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickNewSequence ), NULL, this );
	m_buttonSequenceNameEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickEditSequenceTitle ), NULL, this );
	m_buttonRunSequence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickRunSequence ), NULL, this );
	m_buttonLoopSequence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickLoopSequence ), NULL, this );
	m_buttonDeleteSequence->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickDeleteSequence ), NULL, this );
	m_buttonEditMoveTitle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickEditMoveTitle ), NULL, this );
	m_smButtonGoToPosition->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickGoToMove ), NULL, this );
	m_smButtonEditMove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickEditMove ), NULL, this );
	m_smButtonDeleteMove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickDeleteMove ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_buttonSelectorControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlPage ), NULL, this );
	m_buttonSelectorLog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickLogPage ), NULL, this );
	m_buttonSelectorInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickInfoPage ), NULL, this );
	m_buttonSelectorBKE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickBKEControlPage ), NULL, this );
	m_buttonPrioPlay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickPrioPLAY ), NULL, this );
	m_buttonPrioPause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickPrioPAUSE ), NULL, this );
	m_buttonPrioStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickPrioSTOP ), NULL, this );
	m_buttonManualControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlManual ), NULL, this );
	m_buttonKeyboardControl->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlKeyboard ), NULL, this );
	m_buttonStaticRun->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlRunPosition ), NULL, this );
	m_buttonStaticSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlSavePosition ), NULL, this );
	m_buttonStaticHome->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickControlHomePosition ), NULL, this );
	m_fieldSpeed0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualSpeed ), NULL, this );
	m_fieldSpeed0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualSpeed ), NULL, this );
	m_sliderSpeed0->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualSpeed ), NULL, this );
	m_fieldAccel0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualAccel ), NULL, this );
	m_fieldAccel0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualAccel ), NULL, this );
	m_sliderAccel0->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualAccel ), NULL, this );
	m_fieldStep0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualStep ), NULL, this );
	m_fieldStep0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualStep ), NULL, this );
	m_sliderStep0->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualStep ), NULL, this );
	m_fieldJoint0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint0 ), NULL, this );
	m_fieldJoint0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint0 ), NULL, this );
	m_sliderJoint0->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint0 ), NULL, this );
	m_fieldJoint1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint1 ), NULL, this );
	m_fieldJoint1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint1 ), NULL, this );
	m_sliderJoint1->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint1 ), NULL, this );
	m_fieldJoint2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint2 ), NULL, this );
	m_fieldJoint2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint2 ), NULL, this );
	m_sliderJoint2->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint2 ), NULL, this );
	m_fieldJoint3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualJoint3 ), NULL, this );
	m_fieldJoint3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualJoint3 ), NULL, this );
	m_sliderJoint3->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualJoint3 ), NULL, this );
	m_fieldX->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualVarX ), NULL, this );
	m_fieldX->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualVarX ), NULL, this );
	m_sliderX->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualVarX ), NULL, this );
	m_fieldY->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualVarY ), NULL, this );
	m_fieldY->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualVarY ), NULL, this );
	m_sliderY->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualVarY ), NULL, this );
	m_fieldZ->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MainFrame::OnTextManualVarZ ), NULL, this );
	m_fieldZ->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnTextEnterManualVarZ ), NULL, this );
	m_sliderZ->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderManualVarZ ), NULL, this );
	m_buttonGripperOn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickManualGripperOn ), NULL, this );
	m_buttonGripperOff->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickManualGripperOff ), NULL, this );
	m_kbSliderSpeed->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderKeyboardSpeed ), NULL, this );
	m_kbSliderAccel->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderKeuboardAccel ), NULL, this );
	m_kbSliderStep->Disconnect( wxEVT_SLIDER, wxCommandEventHandler( MainFrame::OnSliderKeyboardStep ), NULL, this );
	m_buttonNewSequence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickNewSequence ), NULL, this );
	m_buttonSequenceNameEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickEditSequenceTitle ), NULL, this );
	m_buttonRunSequence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickRunSequence ), NULL, this );
	m_buttonLoopSequence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickLoopSequence ), NULL, this );
	m_buttonDeleteSequence->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickDeleteSequence ), NULL, this );
	m_buttonEditMoveTitle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickEditMoveTitle ), NULL, this );
	m_smButtonGoToPosition->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickGoToMove ), NULL, this );
	m_smButtonEditMove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickEditMove ), NULL, this );
	m_smButtonDeleteMove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickDeleteMove ), NULL, this );

}
