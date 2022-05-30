///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/slider.h>
#include <wx/statbmp.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxPanel* m_selectorPanel;
		wxScrolledWindow* m_selectorWindow;
		wxStaticText* m_selectorBaseTitle;
		wxStaticLine* m_baseLine;
		wxButton* m_buttonSelectorControl;
		wxButton* m_buttonSelectorLog;
		wxButton* m_buttonSelectorInfo;
		wxStaticText* m_selectorAdditionalTitle;
		wxStaticLine* m_additionalLine;
		wxButton* m_buttonSelectorBKE;
		wxStaticLine* m_selectorWindowLine;
		wxButton* m_buttonPrioPlay;
		wxButton* m_buttonPrioPause;
		wxButton* m_buttonPrioStop;
		wxStaticLine* m_selectorLine;
		wxPanel* m_controlPanel;
		wxPanel* m_controlPanelLeft;
		wxPanel* m_controlTitlePanel;
		wxStaticText* m_controlPanelTitle;
		wxButton* m_buttonManualControl;
		wxButton* m_buttonKeyboardControl;
		wxStaticLine* m_controlTitlePanelLine;
		wxPanel* m_staticControlPanel;
		wxButton* m_buttonStaticRun;
		wxButton* m_buttonStaticSave;
		wxButton* m_buttonStaticHome;
		wxStaticLine* m_staticControlLine;
		wxPanel* m_manualControlPanel;
		wxPanel* m_variablePanel;
		wxStaticText* m_textSpeed0;
		wxTextCtrl* m_fieldSpeed0;
		wxStaticText* m_iconSpeed0;
		wxSlider* m_sliderSpeed0;
		wxStaticText* m_textAccel0;
		wxTextCtrl* m_fieldAccel0;
		wxStaticText* m_iconAccel0;
		wxSlider* m_sliderAccel0;
		wxStaticText* m_textStep0;
		wxTextCtrl* m_fieldStep0;
		wxStaticText* m_iconStep0;
		wxSlider* m_sliderStep0;
		wxStaticText* m_textJoint0;
		wxTextCtrl* m_fieldJoint0;
		wxStaticText* m_iconJoint0;
		wxSlider* m_sliderJoint0;
		wxStaticText* m_textJoint1;
		wxTextCtrl* m_fieldJoint1;
		wxStaticText* m_iconJoint1;
		wxSlider* m_sliderJoint1;
		wxStaticText* m_textJoint2;
		wxTextCtrl* m_fieldJoint2;
		wxStaticText* m_iconJoint2;
		wxSlider* m_sliderJoint2;
		wxStaticText* m_textJoint3;
		wxTextCtrl* m_fieldJoint3;
		wxStaticText* m_iconJoint3;
		wxSlider* m_sliderJoint3;
		wxStaticText* m_textX;
		wxTextCtrl* m_fieldX;
		wxStaticText* m_iconX;
		wxSlider* m_sliderX;
		wxStaticText* m_textY;
		wxTextCtrl* m_fieldY;
		wxStaticText* m_iconY;
		wxSlider* m_sliderY;
		wxStaticText* m_textZ;
		wxTextCtrl* m_fieldZ;
		wxStaticText* m_iconZ;
		wxSlider* m_sliderZ;
		wxStaticLine* m_variableLine;
		wxPanel* m_gripperPanel;
		wxStaticText* m_textGripperState;
		wxButton* m_buttonGripperOn;
		wxButton* m_buttonGripperOff;
		wxPanel* m_keyboardControlPanel;
		wxPanel* m_kbVariablePanel;
		wxStaticText* m_kbTextSpeed;
		wxStaticText* m_kbValueSpeed;
		wxStaticText* m_kbIconSpeed;
		wxSlider* m_kbSliderSpeed;
		wxStaticText* m_kbTextAccel;
		wxStaticText* m_kbValueAccel;
		wxStaticText* m_kbIconAccel;
		wxSlider* m_kbSliderAccel;
		wxStaticText* m_kbTextStep;
		wxStaticText* m_kbValueStep;
		wxStaticText* m_kbIconStep;
		wxSlider* m_kbSliderStep;
		wxStaticLine* m_kbVariableLine;
		wxPanel* m_kbPosPanel;
		wxPanel* m_kbPosTitlePanel;
		wxStaticText* m_kbTextPosTitle;
		wxStaticLine* m_kbPosTitleLine;
		wxPanel* m_kbPosVariablePanel;
		wxStaticText* m_kbNameJoint0;
		wxStaticText* m_kbValueJoint0;
		wxStaticText* m_kbIconJoint0;
		wxStaticText* m_kbNameVarX;
		wxStaticText* m_kbValueVarX;
		wxStaticText* m_kbIconVarX;
		wxStaticText* m_kbNameJoint1;
		wxStaticText* m_kbValueJoint1;
		wxStaticText* m_kbIconJoint1;
		wxStaticText* m_kbNameVarY;
		wxStaticText* m_kbValueVarY;
		wxStaticText* m_kbIconVarY;
		wxStaticText* m_kbNameJoint2;
		wxStaticText* m_kbValueJoint2;
		wxStaticText* m_kbIconJoint2;
		wxStaticText* m_kbNameVarZ;
		wxStaticText* m_kbValueVarZ;
		wxStaticText* m_kbIconVarZ;
		wxStaticText* m_kbNameJoint3;
		wxStaticText* m_kbValueJoint3;
		wxStaticText* m_kbIconJoint3;
		wxStaticText* m_kbNameVarG;
		wxStaticText* m_kbValueVarG;
		wxStaticLine* m_kbPosLine;
		wxPanel* m_kbControlsPanel;
		wxPanel* m_kbControlsTitlePanel;
		wxStaticText* m_kbControlsTitle;
		wxStaticLine* m_kbControlsLine;
		wxPanel* m_kbActualControlsPanel;
		wxStaticText* m_kbControlsTextXY;
		wxPanel* m_kbControlsXYIconPanel;
		wxStaticBitmap* m_kbControlsW;
		wxStaticBitmap* m_kbControlsA;
		wxStaticBitmap* m_kbControlsS;
		wxStaticBitmap* m_kbControlsD;
		wxStaticText* m_kbControlsTextZ;
		wxPanel* m_kbControlsZIconPanel;
		wxStaticBitmap* m_kbControlsArrowUp;
		wxStaticBitmap* m_kbControlsArrowDown;
		wxStaticText* m_kbControlsTextStep;
		wxPanel* m_kbControlsStepIconPanel;
		wxStaticBitmap* m_kbControlsPlus;
		wxStaticBitmap* m_kbControlsMin;
		wxStaticText* m_kbControlsTextSpeed;
		wxPanel* m_kbControlsSpeedIconPanel;
		wxStaticBitmap* m_kbControlsZero;
		wxStaticBitmap* m_kbControlsNine;
		wxStaticLine* m_controlPanelLeftLine;
		wxPanel* m_sequenceMenuPanel;
		wxPanel* m_smTitlePanel;
		wxStaticText* m_smTitleText;
		wxButton* m_buttonNewSequence;
		wxStaticLine* m_smTitleLine;
		wxPanel* m_smSelectPanel;
		wxScrolledWindow* m_sequenceSelectScrolledPanel;
		wxButton* m_tmp_sequence_01;
		wxButton* m_tmp_sequence_02;
		wxStaticLine* m_sequenceSelectLine;
		wxPanel* m_smMoveSelectPanel;
		wxPanel* m_smSequenceNamePanel;
		wxStaticText* m_smSequenceName;
		wxButton* m_buttonSequenceNameEdit;
		wxStaticLine* m_smSequenceNameLine;
		wxScrolledWindow* m_smSequenceMovesPanel;
		wxButton* tmp_move_01;
		wxButton* tmp_move_02;
		wxStaticLine* m_smSelectLine;
		wxPanel* m_smSelectControlPanel;
		wxButton* m_buttonRunSequence;
		wxButton* m_buttonLoopSequence;
		wxButton* m_buttonDeleteSequence;
		wxStaticLine* m_smSelectControlLine;
		wxPanel* m_smMoveTitlePanel;
		wxStaticText* m_smMoveTitle;
		wxButton* m_buttonEditMoveTitle;
		wxStaticLine* m_smMoveTitleLine;
		wxPanel* m_smMoveVariablePanel;
		wxPanel* m_smMoveVarLeftPanel;
		wxStaticText* m_smMoveVarTextSpeed;
		wxStaticText* m_smMoveVarValueSpeed;
		wxStaticText* m_smMoveVarIconSpeed;
		wxStaticText* m_smMoveVarTextAccel;
		wxStaticText* m_smMoveVarValueAccel;
		wxStaticText* m_smMoveVarIconAccel;
		wxStaticText* m_smMoveVarTextGripper;
		wxStaticText* m_smMoveVarValueGripper;
		wxStaticLine* m_smMoveVarLeftLine;
		wxPanel* m_smMoveVarRightPanel;
		wxStaticText* m_smMoveVarTextX;
		wxStaticText* m_smMoveVarValueX;
		wxStaticText* m_smMoveVarIconX;
		wxStaticText* m_smMoveVarTextY;
		wxStaticText* m_smMoveVarValueY;
		wxStaticText* m_smMoveVarIconY;
		wxStaticText* m_smMoveVarTextZ;
		wxStaticText* m_smMoveVarValueZ;
		wxStaticText* m_smMoveVarIconZ;
		wxStaticLine* m_smMoveVariableLine;
		wxPanel* m_smMoveControlPanel;
		wxButton* m_smButtonGoToPosition;
		wxButton* m_smButtonEditMove;
		wxButton* m_smButtonDeleteMove;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickControlPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickLogPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickInfoPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBKEControlPage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickPrioPLAY( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickPrioPAUSE( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickPrioSTOP( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickControlManual( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickControlKeyboard( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickControlRunPosition( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickControlSavePosition( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickControlHomePosition( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualSpeed( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualSpeed( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualSpeed( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualAccel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualAccel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualAccel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualStep( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualStep( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualStep( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualJoint0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualJoint0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualJoint0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualJoint1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualJoint1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualJoint1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualJoint2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualJoint2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualJoint2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualJoint3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualJoint3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualJoint3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualVarX( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualVarX( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualVarX( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualVarY( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualVarY( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualVarY( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextManualVarZ( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTextEnterManualVarZ( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderManualVarZ( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickManualGripperOn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickManualGripperOff( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderKeyboardSpeed( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderKeuboardAccel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderKeyboardStep( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickNewSequence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditSequenceTitle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickRunSequence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickLoopSequence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDeleteSequence( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditMoveTitle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGoToMove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditMove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDeleteMove( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

