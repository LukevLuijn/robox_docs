//
// Created by luke on 21-05-22.
//

#ifndef ROBOT_VISUAL_MANUALCTRL_H
#define ROBOT_VISUAL_MANUALCTRL_H

#include "FrameInterface.h"
#include "ManualCtrlFrame.h"

namespace Frame
{
    enum class Fields_e : uint8_t;

    class ManualCtrl : public /*IFrame,*/ ManualCtrlFrame
    {
    public:
        explicit ManualCtrl(wxWindow* parent);
        ~ManualCtrl() override = default;

    private:
        bool OnTextEnter(wxTextCtrl* textCtrl, wxSlider* slider, float& value, Fields_e field);
        static void OnSliderMove(wxTextCtrl* textCtrl, wxSlider* slider);
        void UpdateDrawPanel();

        void OnTextEnterSpeed(wxCommandEvent& event) override;
        void OnTextEnterAccel(wxCommandEvent& event) override;
        void OnTextMaxLenSpeed(wxCommandEvent& event) override;
        void OnTextMaxLenAccel(wxCommandEvent& event) override;
        void OnSliderReleaseSpeed(wxScrollEvent& event) override;
        void OnSliderReleaseAccel(wxScrollEvent& event) override;
        void OnSliderSpeed(wxCommandEvent& event) override;
        void OnSliderAccel(wxCommandEvent& event) override;

        void OnMouseRelease(wxMouseEvent& event) override;
        void OnMouseMotion(wxMouseEvent& event) override;

    private:
        std::array<std::pair<float,float>, 6> m_outerFieldValues;
    };

    enum class Fields_e : uint8_t
    {
        FIELD_SPEED = 0,
        FIELD_ACCEL = 1,
    };
}// namespace Frame

#endif//ROBOT_VISUAL_MANUALCTRL_H
