//
// Created by luke on 20-05-22.
//

#ifndef ROBOT_VISUAL_MANUALCTRLFRAME_H
#define ROBOT_VISUAL_MANUALCTRLFRAME_H

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/tglbtn.h>

#include "RobotDrawPanel.h"

namespace Frame
{
    class ManualCtrlFrame : public wxDialog
    {
    public:
        explicit ManualCtrlFrame( wxWindow* parent);
        ~ManualCtrlFrame() override;

    protected:
        virtual void OnKillFocusSpeed( wxFocusEvent& event );
        virtual void OnKillFocusAccel( wxFocusEvent& event );
        virtual void OnKillFocusZ( wxFocusEvent& event );
        virtual void OnKillFocusA1( wxFocusEvent& event );
        virtual void OnKillFocusA2( wxFocusEvent& event );
        virtual void OnKillFocusA3( wxFocusEvent& event );
        virtual void OnTextEnterSpeed( wxCommandEvent& event );
        virtual void OnTextEnterAccel( wxCommandEvent& event );
        virtual void OnTextEnterZ( wxCommandEvent& event );
        virtual void OnTextEnterA1( wxCommandEvent& event );
        virtual void OnTextEnterA2( wxCommandEvent& event );
        virtual void OnTextEnterA3( wxCommandEvent& event );
        virtual void OnTextMaxLenSpeed( wxCommandEvent& event );
        virtual void OnTextMaxLenAccel( wxCommandEvent& event );
        virtual void OnTextMaxLenZ( wxCommandEvent& event );
        virtual void OnTextMaxLenA1( wxCommandEvent& event );
        virtual void OnTextMaxLenA2( wxCommandEvent& event );
        virtual void OnTextMaxLenA3( wxCommandEvent& event );
        virtual void OnSliderReleaseSpeed( wxScrollEvent& event );
        virtual void OnSliderReleaseAccel( wxScrollEvent& event );
        virtual void OnSliderReleaseZ( wxScrollEvent& event );
        virtual void OnSliderReleaseA1( wxScrollEvent& event );
        virtual void OnSliderReleaseA2( wxScrollEvent& event );
        virtual void OnSliderReleaseA3( wxScrollEvent& event );
        virtual void OnSliderSpeed( wxCommandEvent& event );
        virtual void OnSliderAccel( wxCommandEvent& event );
        virtual void OnSliderZ( wxCommandEvent& event );
        virtual void OnSliderA1( wxCommandEvent& event );
        virtual void OnSliderA2( wxCommandEvent& event );
        virtual void OnSliderA3( wxCommandEvent& event );
        virtual void OnToggleGrip01( wxCommandEvent& event );
        virtual void OnToggleGrip02( wxCommandEvent& event );
        virtual void OnToggleAuto( wxCommandEvent& event );
        virtual void OnMouseRelease(wxMouseEvent& event)
        {
            std::cout << "mouse release" << std::endl;
            event.Skip();
        }
        virtual void OnMouseMotion(wxMouseEvent& event)
        {
            std::cout << "mouse move" << std::endl;
            event.Skip();
        }

    private:
        void InitializeFrame();
        void ConnectEvents();
        void DisconnectEvents();

    protected:
        RobotDrawPanel* m_drawPanel;

        wxPanel* m_configPanel;
        wxPanel* m_togglePanel;
        wxPanel* m_positionPanel;

        wxStaticText* m_textSpeed;
        wxStaticText* m_textAccel;
        wxStaticText* m_textZ;
        wxStaticText* m_textA1;
        wxStaticText* m_textA2;
        wxStaticText* m_textA3;

        wxStaticText* m_iconSpeed;
        wxStaticText* m_iconAccel;
        wxStaticText* m_iconZ;
        wxStaticText* m_iconA1;
        wxStaticText* m_iconA2;
        wxStaticText* m_iconA3;

        wxTextCtrl* m_textCtrlSpeed;
        wxTextCtrl* m_textCtrlAccel;
        wxTextCtrl* m_textCtrlZ;
        wxTextCtrl* m_textCtrlA1;
        wxTextCtrl* m_textCtrlA2;
        wxTextCtrl* m_textCtrlA3;

        wxSlider* m_sliderSpeed;
        wxSlider* m_sliderAccel;
        wxSlider* m_sliderZ;
        wxSlider* m_sliderA1;
        wxSlider* m_sliderA2;
        wxSlider* m_sliderA3;

        wxToggleButton* m_toggleBtn1;
        wxToggleButton* m_toggleBtn2;
        wxToggleButton* m_toggleBtn3;

        wxStaticLine* m_line0;
        wxStaticLine* m_line1;
        wxStaticLine* m_line2;

    };

}


#endif//ROBOT_VISUAL_MANUALCTRLFRAME_H
