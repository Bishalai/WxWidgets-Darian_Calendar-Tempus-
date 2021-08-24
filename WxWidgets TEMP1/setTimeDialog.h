#pragma once
#include "Time.xpm"
#include"setDateDialog.h"

class setTimeDialog:
    public wxDialog
{

private:

    void onUpdateOk(wxUpdateUIEvent& event);


    wxTextCtrl* hourBox = nullptr;
    wxTextCtrl* minuteBox = nullptr;
    wxTextCtrl* secondsBox = nullptr;


    int hour = 0;
    int minute = 0;
    int seconds = 1;

public:

    setTimeDialog(wxWindow* parent, wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE,
        const wxString& name = wxASCII_STR(wxDialogNameStr));

    virtual ~setTimeDialog();

    int gethour() { return hour; }
    int getminute() { return minute; }
    int getseconds() { return seconds; }
    
    void sethour(int hr) { hour = hr; }
    void setminute(int min) { minute  = min; }
    void setseconds(int sec) { seconds = sec; }
    

    DECLARE_EVENT_TABLE()
};

//Tempus