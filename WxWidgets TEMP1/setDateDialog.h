
#pragma once
//#include "C:\wxWidgets-3.1.5\include\wx\univ\dialog.h"
#include<wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Date.xpm"
#include<wx/valgen.h>
#include<wx/valnum.h>

class setDateDialog :
    public wxDialog
{

private:

    void onUpdateOk(wxUpdateUIEvent& event);


    wxTextCtrl* yearBox = nullptr;
    wxTextCtrl* monthBox = nullptr;
    wxTextCtrl* dayBox = nullptr;

   // wxChoice* monthchoice = nullptr;

    int year = 2000;
    int month = 6;
    int day = 1;

public:

    setDateDialog(wxWindow* parent, wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE,
        const wxString& name = wxASCII_STR(wxDialogNameStr));



    int getyear() { return year; }
    int getmonth() { return month; }
    int getday() { return day; }



    void setyear(int yr) { year = yr; }
    void setmonth(int mn) { month = mn; }
    void setday(int dy) { day = dy; }

    virtual ~setDateDialog();

    DECLARE_EVENT_TABLE()
};

