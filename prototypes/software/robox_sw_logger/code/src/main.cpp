//
// Created by luke on 06-05-22.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"

class MainApplication : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MainApplication);

bool MainApplication::OnInit()
{
    auto* frame = new MainFrame(nullptr);
    frame->Show(true);
    return true;
}