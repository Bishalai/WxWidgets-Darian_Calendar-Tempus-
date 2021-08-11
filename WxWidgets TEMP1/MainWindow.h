#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<wx/wxprec.h>
#include<string>
#include"datetime.h"
#include <wx/artprov.h>
#include "datetime.h"
#include "Georgian.xpm"
#include "Darian.xpm"
#include "Month.xpm"
#include "Year.xpm"
#include "Icon.xpm"
#include "Date.xpm"
#include "Time.xpm"
#include<wx/display.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow : public wxFrame
{
public:
    MainWindow(wxWindow* parent,
        wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE,
        const wxString& name = wxASCII_STR(wxFrameNameStr));

        ~MainWindow();

        void onGeorgian(wxCommandEvent& event);
        void onDarian(wxCommandEvent& event);
        void onQuit(wxCommandEvent& event);
        void onHelp(wxCommandEvent& event);
        void onsetDate(wxCommandEvent& event);
        void onsetTime(wxCommandEvent& event);
        void onswitchYear(wxCommandEvent& event);
        void onswitchMonth(wxCommandEvent& event);
        
        void onClose(wxCloseEvent& event);

        DECLARE_EVENT_TABLE()

};

