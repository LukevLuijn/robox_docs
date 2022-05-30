//
// Created by luke on 06-05-22.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "ManualCtrl.h"

class MainApplication : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MainApplication);

bool MainApplication::OnInit()
{
    auto* frame = new Frame::ManualCtrl(nullptr);
    frame->Show(true);
    return true;
}

BEGIN_EVENT_TABLE(Frame::DrawPanel, wxPanel)
                EVT_PAINT(DrawPanel::PaintEvent)
END_EVENT_TABLE()
