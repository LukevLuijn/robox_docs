//
// Created by luke on 20-05-22.
//

#include "RobotDrawPanel.h"
#include "String.h"

#include "wx/dc.h"
#include "wx/sizer.h"

#define TO_RADIANS(a) (a * M_PI / 180)// convert radians to degrees
#define TO_DEGREES(a) (a * 180 / M_PI)// convert degrees to radians

namespace Frame
{
    /** ========================================================== **/
    /** ROBOT DRAW PANEL--------------------------ROBOT DRAW PANEL **/
    /** ========================================================== **/

    RobotDrawPanel::RobotDrawPanel(wxWindow* parent, int32_t* sizes)
        : DrawPanel(parent), m_initialized(false), m_selected(false), m_previewIK(3, sizes), m_shadowIK(3, sizes)
    {
        InitializeFrame();

        m_sizes[0] = static_cast<float>(sizes[0]) * 0.5f;
        m_sizes[1] = static_cast<float>(sizes[1]) * 0.5f;

        m_currentPosition[0] = static_cast<float>(TO_RADIANS(-90));
        m_currentPosition[1] = 0;

        m_previewIK.SetTolerance(0.01f);
        m_shadowIK.SetTolerance(0.01f);

        float rAngles[] = {0, 0, 0};
        int32_t scaledSizes[] = {static_cast<int32_t>(m_sizes[0]), static_cast<int32_t>(m_sizes[1])};

        m_previewIK.SetJoints(rAngles, scaledSizes);
        UpdateJoints(m_previewChain);

        m_shadowIK.SetJoints(rAngles, scaledSizes);
        UpdateJoints(m_shadowChain);
    }
    void RobotDrawPanel::UpdateShadow(const std::array<double, 2>& angles)
    {
        float rAngles[] = {
                m_shadowIK.GetAngle(0),
                static_cast<float>(TO_RADIANS(angles[0])),// - m_currentPosition[0] + TO_RADIANS(m_staticOffset)),
                static_cast<float>(TO_RADIANS(angles[1])),
        };

        int32_t sizes[] = {static_cast<int32_t>(m_sizes[0]), static_cast<int32_t>(m_sizes[1])};
        m_shadowIK.SetJoints(rAngles, sizes);

        UpdateJoints(m_shadowChain);
        PainNow();
    }
    void RobotDrawPanel::SetAngles(const std::array<double, 2>& angles)
    {
        float rAngles[] = {
                m_previewIK.GetAngle(0),
                static_cast<float>(TO_RADIANS(angles[0]) - m_currentPosition[0] + TO_RADIANS(m_staticOffset)),
                static_cast<float>(TO_RADIANS(angles[1])),
        };

        int32_t sizes[] = {static_cast<int32_t>(m_sizes[0]), static_cast<int32_t>(m_sizes[1])};
        m_previewIK.SetJoints(rAngles, sizes);

        m_positionBuffer[0] = rAngles[1];
        m_positionBuffer[1] = rAngles[2];

        UpdateJoints(m_previewChain);
        UpdateOverlay();
        PainNow();
    }
    std::array<double, 2> RobotDrawPanel::GetAngles()
    {
        std::array<double, 2> array{
                TO_DEGREES(m_positionBuffer[0]),
                TO_DEGREES(m_positionBuffer[1]),
        };
        return array;
    }
    wxPoint RobotDrawPanel::GetPosition()
    {
        auto pY = static_cast<int32_t>(m_previewIK.GetY(2) / 0.5f);
        auto pX = static_cast<int32_t>(m_previewIK.GetX(2) / 0.5f);
        return wxPoint(pX, pY);
    }
    void RobotDrawPanel::Start()
    {
        if (!m_initialized)
        {
            SetBackgroundColour(BACKGROUND);

            m_offset[0] = (GetSize().x) / 2;
            m_offset[1] = static_cast<int32_t>(m_sizes[1] * 1.2);

            m_previewChain.base.x = m_offset[0];
            m_previewChain.base.y = m_offset[1];
            m_previewChain.mid.x = m_offset[0];
            m_previewChain.mid.y = static_cast<int32_t>(m_offset[1] + m_sizes[0]);
            m_previewChain.end.x = m_offset[0];
            m_previewChain.end.y = static_cast<int32_t>(m_offset[1] + (m_sizes[0] + m_sizes[1]));

            m_shadowChain = m_previewChain;

            float angles[] = {0, 0};
            int32_t sizes[] = {static_cast<int32_t>(m_sizes[0]), static_cast<int32_t>(m_sizes[1])};
            m_previewIK.SetJoints(angles, sizes);
            m_shadowIK.SetJoints(angles, sizes);

            m_initialized = true;
        }
    }
    float RobotDrawPanel::GetDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
    {
        auto val1 = static_cast<float>(x1 - x2);
        auto val2 = static_cast<float>(y1 - y2);

        return std::sqrt((val1 * val1) + (val2 * val2));
    }
    float RobotDrawPanel::GetAngle(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
    {
        double deltaY = (y2 - y1);
        double deltaX = (x2 - x1);
        double radians = atan2(deltaY, deltaX);

        return static_cast<float>(radians);
    }
    void RobotDrawPanel::UpdateJoints(Chain& chain)
    {
        chain.base.x = static_cast<int32_t>(m_previewIK.GetX(0)) + m_offset[0];
        chain.base.y = static_cast<int32_t>(m_previewIK.GetY(0)) + m_offset[1];
        chain.mid.x = static_cast<int32_t>(m_previewIK.GetX(1)) + m_offset[0];
        chain.mid.y = static_cast<int32_t>(m_previewIK.GetY(1)) + m_offset[1];
        chain.end.x = static_cast<int32_t>(m_previewIK.GetX(2)) + m_offset[0];
        chain.end.y = static_cast<int32_t>(m_previewIK.GetY(2)) + m_offset[1];
    }
    void RobotDrawPanel::UpdateAngles(std::array<double, 2> angles)
    {
        float rAngles[] = {
                static_cast<float>(TO_RADIANS(angles[0])),
                static_cast<float>(TO_RADIANS(angles[0])),
                static_cast<float>(TO_RADIANS(angles[1])),
        };
        int32_t sizes[] = {static_cast<int32_t>(m_sizes[0]), static_cast<int32_t>(m_sizes[1])};
        m_previewIK.SetJoints(rAngles, sizes);
    }
    void RobotDrawPanel::UpdateOverlay()
    {
        const float fieldX = m_previewIK.GetX(2) / 0.5f;
        const float fieldY = m_previewIK.GetY(2) / 0.5f;
        m_overlayPanel->SetFields(fieldX, fieldY);
        Layout();
    }
    void RobotDrawPanel::Render(wxDC& dc)
    {
        Start();
        dc.Clear();

        RenderRobot(dc, m_shadowChain, SHADOW, ACCENT);
        RenderRobot(dc, m_previewChain, DEFAULT, (m_selected) ? SELECTED : ACCENT);

        m_overlayPanel->UpdateOverlay();
    }
    void RobotDrawPanel::RenderRobot(wxDC& dc, const Chain& chain, const wxColor& color, const wxColor& selected)
    {
        dc.SetPen(wxPen(ACCENT, 8));

        dc.DrawLine(chain.base, chain.mid);
        dc.DrawLine(chain.mid, chain.end);

        dc.SetPen(wxPen(color, 4));

        dc.DrawLine(chain.base, chain.mid);
        dc.DrawLine(chain.mid, chain.end);

        dc.SetBrush(wxBrush(color));
        dc.SetPen(wxPen(ACCENT, 2));

        dc.DrawCircle(chain.base, 10);
        dc.DrawCircle(chain.mid, 10);

        dc.SetPen(wxPen(selected, 2));
        dc.DrawCircle(chain.end, 10);
    }
    void RobotDrawPanel::OnLeftDown(wxMouseEvent& event)
    {
        double x2 = std::pow((static_cast<double>(event.m_x) - m_previewChain.end.x), 2);
        double y2 = std::pow((static_cast<double>(event.m_y) - m_previewChain.end.y), 2);
        double r2 = 10 * 10;
        if ((x2 + y2) < r2)
        {
            m_selected = true;
            PainNow();
        }
        event.Skip();
    }
    void RobotDrawPanel::OnLeftUp(wxMouseEvent& event)
    {
        if (m_selected)
        {
            m_selected = false;
            PainNow();

            wxPostEvent(GetParent(), event);
        }
        event.Skip();
    }
    void RobotDrawPanel::OnMotion(wxMouseEvent& event)
    {
        if (m_selected)
        {
            auto targetX = event.m_x;
            auto targetY = event.m_y;

            // mouse outside max position
            if (GetDistance(targetX, targetY, m_offset[0], m_offset[1]) > (m_sizes[0] + m_sizes[1]))
            {
                auto radians = static_cast<float>(atan2(targetY - m_offset[1], targetX - m_offset[0]));
                auto radius = (m_sizes[0] + m_sizes[1]);

                targetX = static_cast<int>(radius * cos(radians) + m_offset[0]);
                targetY = static_cast<int>(radius * sin(radians) + m_offset[1]);
            }

            auto targetPosX = static_cast<float>(targetX - m_offset[0]);
            auto targetPosY = static_cast<float>(targetY - m_offset[1]);

            int32_t sizes[] = {static_cast<int32_t>(m_sizes[0]), static_cast<int32_t>(m_sizes[1])};
            if (!m_previewIK.Solve(targetPosX, targetPosY, sizes))
            {
                // if there was no solve, don't update locations and angles.
                return;
            }
            double placeholderAngle = m_previewIK.GetAngle(0);
            placeholderAngle = TO_DEGREES(placeholderAngle);

            if (placeholderAngle < 0 && placeholderAngle >= -90)// right side border reached
            {
                int32_t centerX = m_offset[0] + sizes[0];
                int32_t centerY = m_offset[1];

                double angle1 = TO_DEGREES(m_previewIK.GetAngle(1));
                double angle0 = 0.5;

                if ((event.m_y < m_offset[1]) && (GetDistance(event.m_x, event.m_y, centerX, centerY) > m_sizes[1]))
                {
                    angle1 = GetAngle(event.m_x, event.m_y, centerX, centerY);
                    angle1 += -M_PI;
                    angle1 = TO_DEGREES(angle1);
                }

                UpdateAngles(std::array<double, 2>{angle0, angle1});
                m_currentPosition[0] = static_cast<float>(m_previewIK.GetAngle(0) - TO_RADIANS(90));
                m_currentPosition[1] = m_previewIK.GetAngle(2);
                m_staticOffset = 0;
            }
            else if (placeholderAngle < -90 && placeholderAngle >= -180)// left side border reached
            {
                int32_t centerX = m_offset[0] - sizes[0];
                int32_t centerY = m_offset[1];

                double angle1 = TO_DEGREES(m_previewIK.GetAngle(1));
                double angle0 = 90;

                if ((event.m_y < m_offset[1]) && (GetDistance(event.m_x, event.m_y, centerX, centerY) > m_sizes[1]))
                {
                    angle1 = GetAngle(event.m_x, event.m_y, centerX, centerY);
                    angle1 += -2 * M_PI;
                    angle1 = TO_DEGREES(angle1);
                }

                UpdateAngles(std::array<double, 2>{angle0, angle1});
                m_currentPosition[0] = static_cast<float>(m_previewIK.GetAngle(0));
                m_currentPosition[1] = m_previewIK.GetAngle(2);
                m_staticOffset = TO_DEGREES(m_currentPosition[0]);
            }
            else// no border reached, update normal
            {
                m_currentPosition[0] = static_cast<float>(m_previewIK.GetAngle(0) - TO_RADIANS(90));
                m_currentPosition[1] = m_previewIK.GetAngle(1);
                m_staticOffset = 0;
            }

            m_positionBuffer = m_currentPosition;

            UpdateJoints(m_previewChain);
            UpdateOverlay();
            PainNow();

            event.SetId(0); // let parent now the event is coming from here.
            wxPostEvent(GetParent(), event);
        }
    }
    void RobotDrawPanel::InitializeFrame()
    {
        wxBoxSizer* bSizer14;
        bSizer14 = new wxBoxSizer(wxHORIZONTAL);
        m_overlayPanel = new Overlay(this);
        bSizer14->Add(m_overlayPanel, 0, wxALIGN_BOTTOM, 5);
        SetSizer(bSizer14);
        Layout();
        bSizer14->Fit(this);
    }

    /** ========================================================== **/
    /** OVERLAY--------------------------------------------OVERLAY **/
    /** ========================================================== **/

    void Overlay::SetX(float value)
    {
        m_textValueX->SetLabel(Utils::String::ToString(value, 2));
        Layout();
    }
    void Overlay::SetY(float value)
    {
        m_textValueY->SetLabel(Utils::String::ToString(value, 2));
        Layout();
    }
    void Overlay::SetFields(float fieldX, float fieldY)
    {
        m_textValueX->SetLabel(Utils::String::ToString(fieldX, 2));
        m_textValueY->SetLabel(Utils::String::ToString(fieldY, 2));
        Layout();
    }
    float Overlay::GetX() const
    {
        return std::stof(m_textValueX->GetLabel().ToStdString());
    }
    float Overlay::GetY() const
    {
        return std::stof(m_textValueY->GetLabel().ToStdString());
    }
    void Overlay::UpdateOverlay()
    {
        Refresh();
        Update();
    }
    void Overlay::InitializeFrame()
    {
        SetForegroundColour(wxColour{255, 255, 255});

        wxFlexGridSizer* fgSizer8;
        fgSizer8 = new wxFlexGridSizer(2, 3, 0, 0);
        fgSizer8->SetFlexibleDirection(wxBOTH);
        fgSizer8->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

        m_textX = new wxStaticText(this, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textX->Wrap(-1);
        fgSizer8->Add(m_textX, 0, wxALL, 5);

        m_textValueX = new wxStaticText(this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0);
        m_textValueX->Wrap(-1);
        fgSizer8->Add(m_textValueX, 0, wxTOP | wxBOTTOM | wxLEFT, 5);

        m_iconX = new wxStaticText(this, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconX->Wrap(-1);
        fgSizer8->Add(m_iconX, 0, wxTOP | wxBOTTOM | wxRIGHT, 5);

        m_textY = new wxStaticText(this, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0);
        m_textY->Wrap(-1);
        fgSizer8->Add(m_textY, 0, wxALL, 5);

        m_textValueY = new wxStaticText(this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0);
        m_textValueY->Wrap(-1);
        fgSizer8->Add(m_textValueY, 0, wxTOP | wxBOTTOM | wxLEFT, 5);

        m_iconY = new wxStaticText(this, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0);
        m_iconY->Wrap(-1);
        fgSizer8->Add(m_iconY, 0, wxTOP | wxBOTTOM | wxRIGHT, 5);

        SetSizer(fgSizer8);
        Layout();
        fgSizer8->Fit(this);
    }


}// namespace Frame


//
//
//
//namespace Frame
//{
//    // ==========================================================
//    // OVERLAY--------------------------------------------OVERLAY
//    // ==========================================================
//
//    void Overlay::SetX(float value)
//    {
//        m_textValueX->SetLabel(Utils::String::ToString(value, 2));
//        Refresh();
//        Update();
//        Layout();
//    }
//    void Overlay::SetY(float value)
//    {
//        m_textValueY->SetLabel(Utils::String::ToString(value, 2));
//        Refresh();
//        Update();
//        Layout();
//    }
//    float Overlay::GetX() const
//    {
//        return std::stof(m_textValueX->GetLabel().ToStdString());
//    }
//    float Overlay::GetY() const
//    {
//        return std::stof(m_textValueY->GetLabel().ToStdString());
//    }
//    void Overlay::InitializeFrame()
//    {
//        SetForegroundColour(wxColour{255, 255, 255});
//
//        wxFlexGridSizer* fgSizer8;
//        fgSizer8 = new wxFlexGridSizer(2, 3, 0, 0);
//        fgSizer8->SetFlexibleDirection(wxBOTH);
//        fgSizer8->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
//
//        m_textX = new wxStaticText(this, wxID_ANY, wxT("X:"), wxDefaultPosition, wxDefaultSize, 0);
//        m_textX->Wrap(-1);
//        fgSizer8->Add(m_textX, 0, wxALL, 5);
//
//        m_textValueX = new wxStaticText(this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0);
//        m_textValueX->Wrap(-1);
//        fgSizer8->Add(m_textValueX, 0, wxTOP | wxBOTTOM | wxLEFT, 5);
//
//        m_iconX = new wxStaticText(this, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0);
//        m_iconX->Wrap(-1);
//        fgSizer8->Add(m_iconX, 0, wxTOP | wxBOTTOM | wxRIGHT, 5);
//
//        m_textY = new wxStaticText(this, wxID_ANY, wxT("Y:"), wxDefaultPosition, wxDefaultSize, 0);
//        m_textY->Wrap(-1);
//        fgSizer8->Add(m_textY, 0, wxALL, 5);
//
//        m_textValueY = new wxStaticText(this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0);
//        m_textValueY->Wrap(-1);
//        fgSizer8->Add(m_textValueY, 0, wxTOP | wxBOTTOM | wxLEFT, 5);
//
//        m_iconY = new wxStaticText(this, wxID_ANY, wxT("mm"), wxDefaultPosition, wxDefaultSize, 0);
//        m_iconY->Wrap(-1);
//        fgSizer8->Add(m_iconY, 0, wxTOP | wxBOTTOM | wxRIGHT, 5);
//
//        SetSizer(fgSizer8);
//        Layout();
//        fgSizer8->Fit(this);
//    }
//
//    // ==========================================================
//    // DRAWABLE JOINT------------------------------DRAWABLE JOINT
//    // ==========================================================
//
//    bool DrawableJoint::MouseInside(int32_t mouseX, int32_t mouseY) const
//    {
//        return (std::pow((static_cast<float>(mouseX) - m_position[0]), 2) +
//                        std::pow((static_cast<float>(mouseY) - m_position[1]), 2) <
//                std::pow(m_radius, 2));
//    }
//    void DrawableJoint::DrawJoint(wxDC& dc)
//    {
//        const wxColour accent = (m_selected) ? m_colors[(uint8_t) RobotColors_e::SELECTED_COLOR]
//                                             : m_colors[(uint8_t) RobotColors_e::ACCENT_COLOR];
//        const wxPoint location(static_cast<int32_t>(m_position[0]), static_cast<int32_t>(m_position[1]));
//
//        dc.SetBrush(m_colors[(uint8_t) RobotColors_e::BASE_COLOR]);
//        dc.SetPen(wxPen(accent, 2));
//        dc.DrawCircle(location, m_radius);
//    }
//
//    // ==========================================================
//    // DRAWABLE ROBOT------------------------------DRAWABLE ROBOT
//    // ==========================================================
//
//    void DrawableRobot::Initialize(wxPanel* parent)
//    {
//        m_zeroOffset[0] = static_cast<float>(parent->GetSize().x) * 0.5f;
//        m_zeroOffset[1] = static_cast<float>(m_lengths[1] * 1.2);
//
//        m_joints[0].m_position = Position(m_zeroOffset[0], m_zeroOffset[1]);
//        m_joints[1].m_position =
//                Position(m_joints[0].m_position[0], m_joints[0].m_position[1] + static_cast<float>(m_lengths[0]));
//        m_joints[2].m_position =
//                Position(m_joints[1].m_position[0], m_joints[1].m_position[1] + static_cast<float>(m_lengths[1]));
//        m_joints[0].m_grounded = true;
//        m_previewIK.SetTolerance(0.01f);
//    }
//    bool DrawableRobot::MouseReleaseEvent()
//    {
//        if (m_joints[2].m_selected)
//        {
//            m_joints[2].m_selected = false;
//            return true;
//        }
//        return false;
//    }
//    bool DrawableRobot::MouseClickEvent(wxMouseEvent& event)
//    {
//        m_joints[2].m_selected = m_joints[2].MouseInside(event.m_x, event.m_y);
//        return m_joints[2].m_selected;
//    }
//    bool DrawableRobot::MouseMoveEvent(wxMouseEvent& event)
//    {
//        if (m_joints[2].m_selected)
//        {
//            Position newPosition(static_cast<float>(event.m_x), static_cast<float>(event.m_y));
//            float radius = (static_cast<float>(m_lengths[0] + m_lengths[1]));
//
//            if (GetDistance(newPosition, m_zeroOffset) >= radius)
//            {
//                float radians = atan2(static_cast<float>(event.m_y) - m_zeroOffset[1],
//                                      static_cast<float>(event.m_x) - m_zeroOffset[0]);
//                newPosition[0] = radius * cos(radians) + m_zeroOffset[0];
//                newPosition[1] = radius * sin(radians) + m_zeroOffset[1];
//            }
//
//            m_previewIK.Solve(newPosition[0] - m_zeroOffset[0], newPosition[1] - m_zeroOffset[1], m_lengths);
//            Position pos1(m_previewIK.GetX(1) + m_zeroOffset[0], m_previewIK.GetY(1) + m_zeroOffset[1]);
//            Position pos2(m_previewIK.GetX(2) + m_zeroOffset[0], m_previewIK.GetY(2) + m_zeroOffset[1]);
//            m_joints[1].m_position = pos1;
//            m_joints[2].m_position = pos2;
//
//            if (!(m_previewIK.GetAngle(0) >= 0 && m_previewIK.GetAngle(0) <= M_PI))
//            {
//                std::cout << "out of bounds" << std::endl;// out of bounds
//
//            }
////            else
////            {
////                m_previewIK.Solve(newPosition[0] - m_zeroOffset[0], newPosition[1] - m_zeroOffset[1], m_lengths);
////                Position pos1(m_previewIK.GetX(1) + m_zeroOffset[0], m_previewIK.GetY(1) + m_zeroOffset[1]);
////                Position pos2(m_previewIK.GetX(2) + m_zeroOffset[0], m_previewIK.GetY(2) + m_zeroOffset[1]);
////                m_joints[1].m_position = pos1;
////                m_joints[2].m_position = pos2;
////            }
//
//
//
//
//            std::cout <<"A0: "<< Utils::String::ToString(m_previewIK.GetAngle(0), 3) << "\t("<< ((m_previewIK.GetAngle(0) * 180 / M_PI) -90) << ")" << std::endl;
//            std::cout <<"A1: "<< Utils::String::ToString(m_previewIK.GetAngle(1), 3) << "\t("<< ((m_previewIK.GetAngle(1) * 180 / M_PI) -90) << ")" << std::endl;
//
//            //            if (pos1[1] <= m_zeroOffset[1])
//            //            {
//            //                pos1 = m_joints[1].m_position;
//            //                const auto x = static_cast<float>(m_lengths[1] * cos(GetRadians(pos1, newPosition) / 180 * M_PI) + pos1[0]);
//            //                const auto y = static_cast<float>(m_lengths[1] * sin(GetRadians(pos1, newPosition) / 180 * M_PI) + pos1[1]);
//            //                pos2 = Position(x, y);
//            //            }
//            //            m_joints[1].m_position = pos1;
//            //            m_joints[2].m_position = pos2;
//            return true;
//        }
//        return false;
//    }
//    void DrawableRobot::DrawRobot(wxDC& dc)
//    {
//        const wxPoint j0((int32_t) m_joints[0].m_position[0], (int32_t) m_joints[0].m_position[1]);
//        const wxPoint j1((int32_t) m_joints[1].m_position[0], (int32_t) m_joints[1].m_position[1]);
//        const wxPoint j2((int32_t) m_joints[2].m_position[0], (int32_t) m_joints[2].m_position[1]);
//
//        dc.SetPen(wxPen(m_colors[(uint8_t) RobotColors_e::ACCENT_COLOR], 8));
//
//        dc.DrawLine(j0, j1);
//        dc.DrawLine(j1, j2);
//
//        dc.SetPen(wxPen(m_colors[(uint8_t) RobotColors_e::BASE_COLOR], 4));
//
//        dc.DrawLine(j0, j1);
//        dc.DrawLine(j1, j2);
//
//        std::for_each(m_joints.begin(), m_joints.end(), [&dc](DrawableJoint& joint) {
//            joint.DrawJoint(dc);
//        });
//    }
//    void DrawableRobot::SetAngles(float* angles)
//    {
//        m_previewIK.SetJoints(angles, m_lengths);
//    }
//    void DrawableRobot::SetAngle(uint8_t index, float angle)
//    {
//        float angles[] = {m_previewIK.GetAngle(0), m_previewIK.GetAngle(1), m_previewIK.GetAngle(2)};
//        angles[index + 1] = static_cast<float>(-angle * M_PI / 180);
//
//        m_previewIK.SetJoints(angles, m_lengths);
//
//        for (size_t i = 1; i < m_joints.size(); ++i)
//        {
//            float posX = m_previewIK.GetX((int32_t) i) + m_zeroOffset[0];
//            float posY = m_previewIK.GetY((int32_t) i) + m_zeroOffset[1];
//            Position newPos(posX, posY);
//
//            m_joints[i].m_position = newPos;
//        }
//    }
//    void DrawableRobot::SetColors(const std::array<wxColour, 3>& colors)
//    {
//        m_colors = colors;
//
//        for (auto& joint : m_joints)
//        {
//            joint.m_colors = m_colors;
//        }
//    }
//    float DrawableRobot::GetDistance(const Position& posA, const Position& posB)
//    {
//        auto value = static_cast<float>(std::sqrt(std::pow(posA[0] - posB[0], 2) + std::pow(posA[1] - posB[1], 2)));
//        return value;
//    }
//    Position DrawableRobot::GetPosition()
//    {
//        return Position(m_previewIK.GetX(2), m_previewIK.GetY(2));
//    }
//
//    // ==========================================================
//    // ROBOT DRAW PANEL--------------------------ROBOT DRAW PANEL
//    // ==========================================================
//
//    RobotDrawPanel::RobotDrawPanel(wxWindow* parent, int32_t segmentSizes[2])
//        : DrawPanel(parent), m_scaling(.5f), m_preview(segmentSizes, m_scaling), m_shadow(segmentSizes, m_scaling),
//          m_initialSetup(false)
//    {
//        InitializeFrame();
//    }
//    void RobotDrawPanel::SetActualPosition(const std::array<float, 3>& angles)
//    {
//        float pAngles[] = {angles[0], angles[1], angles[2]};
//        m_shadow.SetAngles(pAngles);
//    }
//    void RobotDrawPanel::SetPreviewAngle(uint8_t index, float angle)
//    {
//        m_preview.SetAngle(index, angle);
//    }
//
//    void RobotDrawPanel::Start()
//    {
//        if (!m_initialSetup)
//        {
//            m_preview.Initialize(this);
//            m_shadow.Initialize(this);
//
//            std::array<wxColour, 3> previewColors;
//            previewColors[(uint8_t) RobotColors_e::ACCENT_COLOR] = wxColour{0, 0, 0};
//            previewColors[(uint8_t) RobotColors_e::BASE_COLOR] = wxColour{255, 255, 255};
//            previewColors[(uint8_t) RobotColors_e::SELECTED_COLOR] = wxColour{255, 0, 0};
//
//            m_preview.SetColors(previewColors);
//
//            std::array<wxColour, 3> shadowColors;
//            shadowColors[(uint8_t) RobotColors_e::ACCENT_COLOR] = wxColour{0, 0, 0};
//            shadowColors[(uint8_t) RobotColors_e::BASE_COLOR] = wxColour{120, 120, 120};
//            shadowColors[(uint8_t) RobotColors_e::SELECTED_COLOR] = wxColour{255, 0, 0};
//
//            m_shadow.SetColors(shadowColors);
//            m_initialSetup = true;
//        }
//    }
//    void RobotDrawPanel::Render(wxDC& dc)
//    {
//        dc.Clear();
//        Start();
//        SetBackgroundColour(BACKGROUND);
//
//        m_shadow.DrawRobot(dc);
//        m_preview.DrawRobot(dc);
//
//        m_overlayPanel->Refresh();
//        m_overlayPanel->Update();
//    }
//    void RobotDrawPanel::OnLeftDown(wxMouseEvent& event)
//    {
//        if (m_preview.MouseClickEvent(event))
//        {
//            PainNow();
//        }
//        event.Skip();
//    }
//    void RobotDrawPanel::OnLeftUp(wxMouseEvent& event)
//    {
//        if (m_preview.MouseReleaseEvent())
//        {
//            PainNow();
//        }
//        event.Skip();
//    }
//    void RobotDrawPanel::OnMotion(wxMouseEvent& event)
//    {
//        if (m_preview.MouseMoveEvent(event))
//        {
//            //            float angles [] = {static_cast<float>((event.m_x/5)),static_cast<float>((event.m_y/5))};
//            //            m_shadow.SetAngles(angles);
//
//            Position newPos = m_preview.GetPosition();
//            m_overlayPanel->SetX(newPos[0] / m_scaling);
//            m_overlayPanel->SetY(newPos[1] / m_scaling);
//            Layout();
//            PainNow();
//        }
//        event.Skip();
//    }
//    void RobotDrawPanel::OnMouseWheel(wxMouseEvent& event)
//    {
//        // TODO adjust height
//
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
//        event.Skip();
//    }
//    void RobotDrawPanel::InitializeFrame()
//    {
//        wxBoxSizer* bSizer14;
//        bSizer14 = new wxBoxSizer(wxHORIZONTAL);
//        m_overlayPanel = new Overlay(this);
//        bSizer14->Add(m_overlayPanel, 0, wxALIGN_BOTTOM, 5);
//        SetSizer(bSizer14);
//        Layout();
//        bSizer14->Fit(this);
//    }
//}// namespace Frame
