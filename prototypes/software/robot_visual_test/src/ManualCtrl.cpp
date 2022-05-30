//
// Created by luke on 21-05-22.
//

#include "ManualCtrl.h"
#include "String.h"

namespace Frame
{
    ManualCtrl::ManualCtrl(wxWindow* parent) : /*IFrame(parent),*/ ManualCtrlFrame(parent)
    {
        m_outerFieldValues[(size_t) Fields_e::FIELD_SPEED].first = -90.f;
        m_outerFieldValues[(size_t) Fields_e::FIELD_SPEED].second = 90.f;

        m_outerFieldValues[(size_t) Fields_e::FIELD_ACCEL].first = -360.f;
        m_outerFieldValues[(size_t) Fields_e::FIELD_ACCEL].second = 360.f;
    }
    bool ManualCtrl::OnTextEnter(wxTextCtrl* textCtrl, wxSlider* slider, float& value, Fields_e field)
    {
        float min = m_outerFieldValues[(size_t) field].first;
        float max = m_outerFieldValues[(size_t) field].second;
        std::string textValue = textCtrl->GetValue().ToStdString();

        if (!Utils::String::ValidateNumber(value, textValue, min, max))
        {
            textCtrl->SetForegroundColour(wxColour(255, 0, 0));
        }
        else
        {
            textCtrl->SetForegroundColour(wxColour(0, 0, 0));
            textCtrl->SetValue(Utils::String::ToString(value));
            slider->SetValue(static_cast<int32_t>(value * 100));
            return true;
        }
        return false;
    }
    void ManualCtrl::OnSliderMove(wxTextCtrl* textCtrl, wxSlider* slider)
    {
        auto value = static_cast<float>(slider->GetValue()) / 100;
        textCtrl->SetValue(Utils::String::ToString(value, 2));
    }
    void ManualCtrl::UpdateDrawPanel()
    {
        std::array<double, 2> angles = m_drawPanel->GetAngles();
        if (Utils::String::ToString(angles[0], 2) != m_textCtrlSpeed->GetValue().ToStdString() ||
            Utils::String::ToString(angles[1], 2) != m_textCtrlAccel->GetValue().ToStdString())
        {
            double speed = 0;
            double accel = 0;

            try
            {
                speed = std::stod(m_textCtrlSpeed->GetValue().ToStdString());
                accel = std::stod(m_textCtrlAccel->GetValue().ToStdString());
            }
            catch (...)
            {
                // ignore..
            }
            std::array<double, 2> newAngles = {speed, accel};
            m_drawPanel->SetAngles(newAngles);
        }
    }
    void ManualCtrl::OnTextEnterSpeed(wxCommandEvent& event)
    {
        float value = 0.f;
        if (OnTextEnter(m_textCtrlSpeed, m_sliderSpeed, value, Fields_e::FIELD_SPEED))
        {
            UpdateDrawPanel();
            // Driver::RobotController::GetInstance().SetNewPositionA0(value);
        }
        event.Skip();
    }
    void ManualCtrl::OnTextEnterAccel(wxCommandEvent& event)
    {
        float value = 0.f;
        if (OnTextEnter(m_textCtrlAccel, m_sliderAccel, value, Fields_e::FIELD_ACCEL))
        {
            UpdateDrawPanel();
            // Driver::RobotController::GetInstance().SetNewPositionA0(value);
        }
        event.Skip();
    }
    void ManualCtrl::OnTextMaxLenSpeed(wxCommandEvent& event)
    {
        //        WARNING("Max amount of characters reached.", "6");
        event.Skip();
    }
    void ManualCtrl::OnTextMaxLenAccel(wxCommandEvent& event)
    {
        //        WARNING("Max amount of characters reached.", "6");
        event.Skip();
    }
    void ManualCtrl::OnSliderReleaseSpeed(wxScrollEvent& event)
    {
        wxCommandEvent commandEvent(wxEVT_COMMAND_TEXT_ENTER);
        OnTextEnterSpeed(commandEvent);
        event.Skip();
    }
    void ManualCtrl::OnSliderReleaseAccel(wxScrollEvent& event)
    {
        wxCommandEvent commandEvent(wxEVT_COMMAND_TEXT_ENTER);
        OnTextEnterAccel(commandEvent);
        event.Skip();
    }
    void ManualCtrl::OnSliderSpeed(wxCommandEvent& event)
    {
        OnSliderMove(m_textCtrlSpeed, m_sliderSpeed);

        std::array<double, 2> angles = {
                static_cast<double>(m_sliderSpeed->GetValue()) / 100,
                static_cast<double>(m_sliderAccel->GetValue()) / 100,
        };
        m_drawPanel->SetAngles(angles);

        event.Skip();
    }
    void ManualCtrl::OnSliderAccel(wxCommandEvent& event)
    {
        OnSliderMove(m_textCtrlAccel, m_sliderAccel);

        std::array<double, 2> angles = {
                static_cast<double>(m_sliderSpeed->GetValue()) / 100,
                static_cast<double>(m_sliderAccel->GetValue()) / 100,
        };
        m_drawPanel->SetAngles(angles);

        event.Skip();
    }
    void ManualCtrl::OnMouseRelease(wxMouseEvent& event)
    {
        std::array<double, 2> angles = m_drawPanel->GetAngles();

        m_textCtrlSpeed->SetValue(Utils::String::ToString(angles[0], 2));
        m_textCtrlAccel->SetValue(Utils::String::ToString(angles[1], 2));

        wxCommandEvent commandEvent(wxEVT_COMMAND_TEXT_ENTER);
        OnTextEnterSpeed(commandEvent);
        OnTextEnterAccel(commandEvent);

        m_sliderSpeed->Refresh();
        m_sliderAccel->Refresh();

        Refresh();
        Update();

        event.Skip();
    }
    void ManualCtrl::OnMouseMotion(wxMouseEvent& event)
    {
        if (event.GetId() == 0)
        {
            std::array<double, 2> angles = m_drawPanel->GetAngles();

            m_sliderSpeed->SetValue(static_cast<int32_t>(angles[0]) * 100);
            m_sliderAccel->SetValue(static_cast<int32_t>(angles[1]) * 100);

            OnSliderMove(m_textCtrlSpeed, m_sliderSpeed);
            OnSliderMove(m_textCtrlAccel, m_sliderAccel);

            m_sliderSpeed->Refresh();
            m_sliderAccel->Refresh();

            Refresh();
            Update();
        }
        event.Skip();
    }


}// namespace Frame
