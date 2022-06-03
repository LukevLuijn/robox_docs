//
// Created by luke on 20-05-22.
//

#ifndef ROBOT_VISUAL_ROBOTDRAWPANEL_H
#define ROBOT_VISUAL_ROBOTDRAWPANEL_H

#include "DrawPanel.h"
#include "Kinematics.h"
#include "Point.h"

#include "wx/stattext.h"


namespace Frame
{
    class Overlay : public wxPanel
    {
    public:
        explicit Overlay(wxWindow* parent)
            : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL)
        {
            InitializeFrame();
        }
        ~Overlay() override = default;

        void SetX(float value);
        void SetY(float value);
        void SetFields(float fieldX, float fieldY);
        [[nodiscard]] float GetX() const;
        [[nodiscard]] float GetY() const;

        void UpdateOverlay();

    private:
        void InitializeFrame();

    private:
        wxStaticText* m_textX{};
        wxStaticText* m_textValueX{};
        wxStaticText* m_iconX{};
        wxStaticText* m_textY{};
        wxStaticText* m_textValueY{};
        wxStaticText* m_iconY{};
    };

    struct Joint {
        double x, y;
    };

    struct Chain {
        wxPoint base, mid, end;
        double angle0{}, angle1{};
    };

    class RobotDrawPanel : public DrawPanel
    {
    private:
    public:
        RobotDrawPanel(wxWindow* parent, int32_t* sizes);
        ~RobotDrawPanel() override = default;

        void UpdateShadow(const std::array<double, 2>& angles);
        void SetAngles(const std::array<double, 2>& angles);
        std::array<double, 2> GetAngles();
        wxPoint GetPosition();

    private:
        void Start();
        static float GetDistance(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
        static float GetAngle(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
        void UpdateJoints(Chain& chain);
        void UpdateAngles(std::array<double, 2> angles);
        void UpdateOverlay();

    private:
        void Render(wxDC& dc) override;

        void RenderRobot(wxDC& dc, const Chain& chain, const wxColor& color, const wxColor& selected);

        void OnLeftDown(wxMouseEvent& event) override;
        void OnLeftUp(wxMouseEvent& event) override;
        void OnMotion(wxMouseEvent& event) override;

        void InitializeFrame();

    private:
        bool m_initialized, m_selected;

        Overlay* m_overlayPanel{};

        std::array<double, 2> m_sizes{};
        std::array<int32_t, 2> m_offset{};
        Utils::Kinematics m_previewIK;
        Utils::Kinematics m_shadowIK;
        Chain m_previewChain;
        Chain m_shadowChain;

        std::array<float, 2> m_currentPosition{};
        std::array<float, 2> m_positionBuffer{};

        const wxColor BACKGROUND = {80, 80, 80};
        const wxColor SELECTED = {255, 0, 0};
        const wxColor DEFAULT = {255, 255, 255};
        const wxColor SHADOW = {100, 100, 100};
        const wxColor ACCENT = {0, 0, 0};

        double m_staticOffset{};
    };


}// namespace Frame


//namespace Frame
//{
//    typedef Utils::Point<float, 2> Position;
//
//    class Overlay : public wxPanel
//    {
//    public:
//        explicit Overlay(wxWindow* parent)
//            : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL)
//        {
//            InitializeFrame();
//        }
//        ~Overlay() override = default;
//
//        void SetX(float value);
//        void SetY(float value);
//        [[nodiscard]] float GetX() const;
//        [[nodiscard]] float GetY() const;
//
//    private:
//        void InitializeFrame();
//
//    private:
//        wxStaticText* m_textX{};
//        wxStaticText* m_textValueX{};
//        wxStaticText* m_iconX{};
//        wxStaticText* m_textY{};
//        wxStaticText* m_textValueY{};
//        wxStaticText* m_iconY{};
//    };
//
//    struct DrawableJoint {
//    public:
//        [[nodiscard]] bool MouseInside(int32_t mouseX, int32_t mouseY) const;
//        void DrawJoint(wxDC& dc);
//
//    public:
//        Position m_position;
//        int32_t m_radius = 10;
//        bool m_selected = false;
//        bool m_grounded = false;
//        std::array<wxColour, 3> m_colors;
//    };
//
//    struct DrawableRobot
//    {
//    public:
//        DrawableRobot(int32_t lengths [], float scaling) : m_kinematics(3, lengths)
//        {
//            m_lengths[0] = static_cast<int32_t>((float)lengths[0] * scaling);
//            m_lengths[1] = static_cast<int32_t>((float)lengths[1] * scaling);
//        }
//
//        void Initialize(wxPanel* parent);
//
//        bool MouseReleaseEvent();
//        bool MouseClickEvent(wxMouseEvent& event);
//        bool MouseMoveEvent(wxMouseEvent& event);
//
//        void DrawRobot(wxDC& dc);
//        void SetAngles(float* angles);
//        void SetAngle(uint8_t index, float angle);
//        void SetColors(const std::array<wxColour, 3>& colors);
//        static float GetDistance(const Position& posA, const Position& posB);
//
//        Position GetPosition();
//
//    private:
//        Utils::Kinematics m_kinematics;
//        int32_t m_lengths [2]{};
//        std::array<DrawableJoint, 3> m_joints{};
//        std::array<wxColour, 3> m_colors{};
//        Position m_zeroOffset{};
//    };

//    enum class IKResult_e : uint8_t;
//
//    class RobotDrawPanel : public DrawPanel
//    {
//    private:
//        struct WorldBone {
//            double x, y, angle, cosAngle, sinAngle;
//        };
//        struct Bone {
//            double x, y,angle;
//        };
//
//    public:
//        RobotDrawPanel(wxWindow* parent, std::array<double, 2> sizes);
//        ~RobotDrawPanel() override = default;
//
//        void SetAngles(std::array<double, 2> angles);
//        std::array<double, 2> GetAngles();
//
//    private:
//        void Start();
//        void Render(wxDC& dc) override;
//        static double SimplifyAngle(double angle);
//        IKResult_e Calculate(std::array<Bone, 2>& bones, std::array<double, 2> angles, double distance);
//        IKResult_e Calculate(std::array<Bone, 2>& bones, double tX, double tY, double distance);
//
//        bool Calculate2(double& angle1, double& angle2, bool solvePosAngle2, double length1, double length2, double targetX, double targetY);
//
//
//        void InitializeFrame();
//
//        void OnLeftDown(wxMouseEvent& event) override;
//        void OnLeftUp(wxMouseEvent& event) override;
//        void OnMotion(wxMouseEvent& event) override;
//
//    private:
//        const double TOLERANCE = 1;
//        const double SCALING = 0.7;
//
//        bool m_initialComplete{};
//        bool m_selected{};
//        std::array<Bone, 2> m_bones{};
//        std::array<double, 2> m_target{};
//
//        std::array<double, 2> m_offset{};
//        std::array<double, 2> m_sizes;
//
//        Overlay* m_overlayPanel{};
//
//    };
//
//    enum class IKResult_e : uint8_t
//    {
//        SUCCESS = 0,
//        PROCESSING = 1,
//        FAILURE = 2,
//    };


//    public:
//        explicit RobotDrawPanel(wxWindow* parent, int32_t segmentSizes [2]);
//        ~RobotDrawPanel() override = default;
//
//        void SetActualPosition(const std::array<float, 3>& angles);
//        void SetPreviewAngle(uint8_t index, float angle);
//
//    private:
//        void Render(wxDC& dc) override;
//        void Start();
//
//    private:
//        void OnLeftDown(wxMouseEvent& event) override;
//        void OnLeftUp(wxMouseEvent& event) override;
//        void OnMotion(wxMouseEvent& event) override;
//        void OnMouseWheel(wxMouseEvent& event) override;
//        void InitializeFrame();
//
//    private:
//        float m_scaling;
//        DrawableRobot m_preview;
//        DrawableRobot m_shadow;
//
//        const wxColour BACKGROUND = {80, 80, 80};
//        Overlay* m_overlayPanel{};
//        bool m_initialSetup;
//    };

//    enum class RobotColors_e
//    {
//        ACCENT_COLOR = 0,
//        BASE_COLOR = 1,
//        SELECTED_COLOR = 2,
//    };
//}// namespace Frame

#endif//ROBOT_VISUAL_ROBOTDRAWPANEL_H
