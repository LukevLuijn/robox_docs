//
// Created by luke on 16-05-22.
//

#ifndef ROBOX_USER_INTERFACE_LOGPANEL_H
#define ROBOX_USER_INTERFACE_LOGPANEL_H

#include "ScrolledLogWindow.h"

#include <wx/statline.h>
#include <wx/tglbtn.h>

namespace Widgets
{
    class LogPanel : public wxPanel
    {
    public:
        LogPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL)
        {
            Init();
            Connect();
        }
        ~LogPanel() override
        {
            Disconnect();
        }

    protected:
        virtual void OnClickToggleApplication(wxCommandEvent& event);
        virtual void OnClickToggleFirmware(wxCommandEvent& event);
        virtual void OnClickClear(wxCommandEvent& event);
        virtual void OnToggleVerbosityError(wxCommandEvent& event);
        virtual void OnToggleVerbosityWarning(wxCommandEvent& event);
        virtual void OnToggleVerbosityInfo(wxCommandEvent& event);
        virtual void OnToggleVerbosityDebug(wxCommandEvent& event);

    private:
        void Init();
        void Connect();
        void Disconnect();

    private:
        const wxSize IMAGE_SIZE = wxSize(32,32);

        wxPanel* m_panel2;
        wxPanel* m_panel49;
        wxPanel* m_verbosityPanel;

        wxButton* m_buttonApplication;
        wxButton* m_buttonFirmware;
        wxButton* m_buttonClear;

        wxBitmapToggleButton* m_buttonVerbosityError;
        wxBitmapToggleButton* m_buttonVerbosityWarning;
        wxBitmapToggleButton* m_buttonVerbosityInfo;
        wxBitmapToggleButton* m_buttonVerbosityDebug;

        wxStaticLine* m_staticLine3;
        wxStaticLine* m_staticLine4;

        ScrolledLogWindow* m_logWindow;
    };
}// namespace Widgets

#endif//ROBOX_USER_INTERFACE_LOGPANEL_H
