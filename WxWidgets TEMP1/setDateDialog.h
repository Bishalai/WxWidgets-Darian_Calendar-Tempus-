
#pragma once
//#include "C:\wxWidgets-3.1.5\include\wx\univ\dialog.h"
#include<wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Date.xpm"

class setDateDialog :
    public wxDialog
{

public:

    setDateDialog(wxWindow* parent, wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE,
        const wxString& name = wxASCII_STR(wxDialogNameStr));

    virtual ~setDateDialog();


    int getyear() { return year; }
    int getmonth() { return month; }
    int getday() { return day; }

    /*
    int gethour() { return hour; }
    int getminute() { return minute; }
    int getseconds() { return seconds; }
    */

    void setyear(int yr) { year = yr; }
    void setmonth(int mn) { month = mn; }
    void setday(int day) { day = day; }

    /*
    void sethour(int hr) { hour = hr; }
    void setminute(int min) { minute  = min; }
    void setseconds(int sec) { seconds = sec; }
    */

private:

    wxTextCtrl* yearBox = nullptr;
    wxTextCtrl* monthBox = nullptr;
    wxTextCtrl* dayBox = nullptr;


    int year = 2021;
    int month = 9;
    int day = 6;

    /*
    int hour = 0;
    int minute = 0;
    int seconds = 1;
    */


};

