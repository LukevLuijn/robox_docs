#ifndef __robox_control_guiMainFrame__
#define __robox_control_guiMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "MainFrame.h"

//// end generated include

/** Implementing MainFrame */
class MainApp : public MainFrame
{
	protected:
		// Handlers for MainFrame events.
		void OnClickControlPage( wxCommandEvent& event ) override;
		void OnClickLogPage( wxCommandEvent& event ) override;
		void OnClickInfoPage( wxCommandEvent& event ) override;
		void OnClickBKEControlPage( wxCommandEvent& event ) override;
		void OnClickPrioPLAY( wxCommandEvent& event ) override;
		void OnClickPrioPAUSE( wxCommandEvent& event ) override;
		void OnClickPrioSTOP( wxCommandEvent& event ) override;
		void OnClickControlManual( wxCommandEvent& event ) override;
		void OnClickControlKeyboard( wxCommandEvent& event ) override;
		void OnClickControlRunPosition( wxCommandEvent& event ) override;
		void OnClickControlSavePosition( wxCommandEvent& event ) override;
		void OnClickControlHomePosition( wxCommandEvent& event ) override;
		void OnTextManualSpeed( wxCommandEvent& event ) override;
		void OnTextEnterManualSpeed( wxCommandEvent& event ) override;
		void OnSliderManualSpeed( wxCommandEvent& event ) override;
		void OnTextManualAccel( wxCommandEvent& event ) override;
		void OnTextEnterManualAccel( wxCommandEvent& event ) override;
		void OnSliderManualAccel( wxCommandEvent& event ) override;
		void OnTextManualStep( wxCommandEvent& event ) override;
		void OnTextEnterManualStep( wxCommandEvent& event ) override;
		void OnSliderManualStep( wxCommandEvent& event ) override;
		void OnTextManualJoint0( wxCommandEvent& event ) override;
		void OnTextEnterManualJoint0( wxCommandEvent& event ) override;
		void OnSliderManualJoint0( wxCommandEvent& event ) override;
		void OnTextManualJoint1( wxCommandEvent& event ) override;
		void OnTextEnterManualJoint1( wxCommandEvent& event ) override;
		void OnSliderManualJoint1( wxCommandEvent& event ) override;
		void OnTextManualJoint2( wxCommandEvent& event ) override;
		void OnTextEnterManualJoint2( wxCommandEvent& event ) override;
		void OnSliderManualJoint2( wxCommandEvent& event ) override;
		void OnTextManualJoint3( wxCommandEvent& event ) override;
		void OnTextEnterManualJoint3( wxCommandEvent& event ) override;
		void OnSliderManualJoint3( wxCommandEvent& event ) override;
		void OnTextManualVarX( wxCommandEvent& event ) override;
		void OnTextEnterManualVarX( wxCommandEvent& event ) override;
		void OnSliderManualVarX( wxCommandEvent& event ) override;
		void OnTextManualVarY( wxCommandEvent& event ) override;
		void OnTextEnterManualVarY( wxCommandEvent& event ) override;
		void OnSliderManualVarY( wxCommandEvent& event ) override;
		void OnTextManualVarZ( wxCommandEvent& event ) override;
		void OnTextEnterManualVarZ( wxCommandEvent& event ) override;
		void OnSliderManualVarZ( wxCommandEvent& event ) override;
		void OnClickManualGripperOn( wxCommandEvent& event ) override;
		void OnClickManualGripperOff( wxCommandEvent& event ) override;
		void OnSliderKeyboardSpeed( wxCommandEvent& event ) override;
		void OnSliderKeuboardAccel( wxCommandEvent& event ) override;
		void OnSliderKeyboardStep( wxCommandEvent& event ) override;
		void OnClickNewSequence( wxCommandEvent& event ) override;
		void OnClickEditSequenceTitle( wxCommandEvent& event ) override;
		void OnClickRunSequence( wxCommandEvent& event ) override;
		void OnClickLoopSequence( wxCommandEvent& event ) override;
		void OnClickDeleteSequence( wxCommandEvent& event ) override;
		void OnClickEditMoveTitle( wxCommandEvent& event ) override;
		void OnClickGoToMove( wxCommandEvent& event ) override;
		void OnClickEditMove( wxCommandEvent& event ) override;
		void OnClickDeleteMove( wxCommandEvent& event ) override;
	public:
		/** Constructor */
        MainApp( wxWindow* parent );
	//// end generated class members

};

#endif // __robox_control_guiMainFrame__
