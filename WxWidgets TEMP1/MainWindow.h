#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<wx/wxprec.h>
#include<wx/timer.h>
#include<string>

#include <wx/artprov.h>


#include "Georgian.xpm"
#include "Darian.xpm"
#include "Month.xpm"
#include "Year.xpm"
#include "Icon.xpm"
#include "Date.xpm"
#include "Time.xpm"
#include<wx/display.h>
#include "CalDateTime.h"
//#include "Gregorian_DateTime.h"


#include"id.h"



#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class Gregorian_DateTime;

class Darian_Date_Time;

class MainWindow : public wxFrame
{
private:

    // defult is months view in gregorian
    //0 of for gregorian, 1 for darian
    bool cal_status = 0;
    // 0 for months and 1 for year view
    bool view_status = 0;


    //----------------------------------------date time objects ----------------------------------------------//
    Gregorian_DateTime g_dt_now;
    

    Darian_Date_Time d_dt_now;
    

    wxTextCtrl* secup;
    wxTextCtrl* dateup;
    wxTextCtrl* seasonup;
    //------------------------------------------------------------------------------------------------////

    ////sizers base

    wxSizer* Sizer = new wxBoxSizer(wxHORIZONTAL);


    //side sizer
    wxSizer* sizer_top = new wxBoxSizer(wxVERTICAL);


    //gridsizers

    wxGridSizer* gs_g_year = new wxGridSizer(5, 3, cellsize);
    wxGridSizer* gs_d_year = new wxGridSizer(9, 3, cellsize);
    wxGridSizer* gs_g_month = new wxGridSizer(8, 7, cellsize);//56 total cells
    wxGridSizer* gs_d_month = new wxGridSizer(6, 7, cellsize);//42 total cells



    //wxsize
    wxDisplay win_display;
    wxRect win_screen = win_display.GetClientArea();
    wxSize appwinsize = wxSize(win_screen.GetWidth() / 8, win_screen.GetHeight() / 8);
    wxSize appwinsizebot = wxSize(appwinsize.GetWidth(), appwinsize.GetHeight() / 3);
    wxSize calsize = wxSize(appwinsize.GetWidth() / 2, appwinsize.GetHeight() / 2);
    wxSize cellsize = wxSize(calsize.GetWidth() / 20, calsize.GetHeight() / 7);

    wxSize cellmonthsize = wxSize(calsize.GetWidth() / 10, calsize.GetHeight() / 5);

    //panels

    wxPanel* panel_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));

    wxPanel* panel_g_month = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));

    wxPanel* panel_g_year = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));

    wxPanel* panel_d_month = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));

    wxPanel* panel_d_year = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));



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


        //for display
        void display_g_month();
        void display_g_year();
        void display_d_month();
        void display_d_year();



        void OnTimer(wxTimerEvent& event);
        
        void onClose(wxCloseEvent& event);

        DECLARE_EVENT_TABLE()
        
};

