


#include "setDateDialog.h"


setDateDialog::setDateDialog(wxWindow* parent, wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    SetIcon(Date_xpm);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);


    // add the message
    wxBoxSizer* msgsizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* msglabel = new wxStaticText(this, wxID_ANY, _(
        "Enter the value of the Year, Month and the day in the\n boxes below:"));
    //msglabel->SetMinSize(wxSize(50, msglabel->GetMinSize().y));
    msgsizer->Add(msglabel);

    mainSizer->Add(msgsizer, 0, wxEXPAND | wxALL, 5);

    // create year field

    wxBoxSizer* yearsizer = new wxBoxSizer(wxHORIZONTAL);

    // year label
    wxStaticText* yearlabel = new wxStaticText(this, wxID_ANY, _("Year:"));
    yearlabel->SetMinSize(wxSize(50, yearlabel->GetMinSize().y));
    yearsizer->Add(yearlabel);


    yearBox = new wxTextCtrl(this, wxID_ANY);
    yearsizer->Add(yearBox, 1);

    mainSizer->Add(yearsizer, 0, wxEXPAND | wxALL, 5);
    
    //for month label

    wxBoxSizer* monthsizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* monthlabel = new wxStaticText(this, wxID_ANY, _("Month:"));
    monthlabel->SetMinSize(wxSize(50, monthlabel->GetMinSize().y));
    monthsizer->Add(monthlabel);


    monthBox = new wxTextCtrl(this, wxID_ANY);
    monthsizer->Add(monthBox, 1);

    mainSizer->Add(monthsizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);


    //fo day labels

    wxBoxSizer* daysizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* daylabel = new wxStaticText(this, wxID_ANY, _("Day:"));
    daylabel->SetMinSize(wxSize(50, daylabel->GetMinSize().y));
    daysizer->Add(daylabel);


    dayBox = new wxTextCtrl(this, wxID_ANY);
    daysizer->Add(dayBox, 1);

    mainSizer->Add(daysizer, 0, wxEXPAND | wxALL, 5);

    
    //Create Buttons

    wxSizer* buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer,0, wxALIGN_RIGHT | wxBOTTOM, 5 );

    //error label
    wxBoxSizer* errsizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* errlabel = new wxStaticText(this, wxID_ANY, _(
        " - If the entered day is invalid, it will automatically be\n set to the last day or the first day of the month"));
    //msglabel->SetMinSize(wxSize(50, msglabel->GetMinSize().y));
    errsizer->Add(errlabel);

    mainSizer->Add(errsizer, 0, wxEXPAND | wxALL, 5);


    //Sizer sets

    SetSizer(mainSizer);

    SetMinSize(wxSize(300, 100));

    Fit();

    
}



setDateDialog::~setDateDialog()
{

};