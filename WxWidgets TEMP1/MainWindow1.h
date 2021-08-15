#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma once



#include"MainWindow.h"



#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow1 : public wxFrame
{
public:
    MainWindow1(wxWindow* parent,
        wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE,
        const wxString& name = wxASCII_STR(wxFrameNameStr));

    ~MainWindow1();

    void onGeorgian(wxCommandEvent& event);
    void onDarian(wxCommandEvent& event);
    void onQuit(wxCommandEvent& event);
    void onHelp(wxCommandEvent& event);
    void onsetDate(wxCommandEvent& event);
    void onsetTime(wxCommandEvent& event);
    void onswitchYear(wxCommandEvent& event);
    void onswitchMonth(wxCommandEvent& event);

    void OnTimer(wxTimerEvent& event);

    void onClose(wxCloseEvent& event);

    DECLARE_EVENT_TABLE()

};



