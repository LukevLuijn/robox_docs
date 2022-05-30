//
// Created by luke on 17-05-22.
//

#ifndef ROBOX_UI_TESTS_FRAMEINTERFACE_H
#define ROBOX_UI_TESTS_FRAMEINTERFACE_H

#include "wx/panel.h"
#include "msg_protocol.h"

namespace Frame
{
    class IFrame : public wxPanel
    {
    public:
        explicit IFrame(wxWindow* parent) : wxPanel(parent) {}
        ~IFrame() override = default;

        virtual wxPanel* GetPanel() = 0;
        virtual void UpdateData(DataType_e responseType) = 0;
        virtual void ResetPanel() = 0;
    };

    enum class FrameTypes_e : uint8_t
    {
        MANUAL_CTRL = 0,
        KEYBOARD_CTRL = 1,
        BKE_CTRL = 2,
        SETTINGS = 3,
        ABOUT = 4,
    };
}// namespace Frame

#endif//ROBOX_UI_TESTS_FRAMEINTERFACE_H
