#include "setTimeDialog.h"

BEGIN_EVENT_TABLE(setTimeDialog, wxDialog)

EVT_UPDATE_UI(wxID_OK, setTimeDialog::onUpdateOk)

END_EVENT_TABLE()


setTimeDialog::setTimeDialog(wxWindow* parent, wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name) :
    wxDialog(parent, id, title, pos, size, style, name)
{
    SetIcon(Time_xpm);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);


    // add the message
    wxBoxSizer* msgsizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* msglabel = new wxStaticText(this, wxID_ANY, _(
        "Enter the value of the Hour, Minute and seconds in the\n boxes below:"));
    //msglabel->SetMinSize(wxSize(50, msglabel->GetMinSize().y));
    msgsizer->Add(msglabel);

    mainSizer->Add(msgsizer, 0, wxEXPAND | wxALL, 5);

    // create year field

    wxBoxSizer* hoursizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* hourlabel = new wxStaticText(this, wxID_ANY, _("Hour:"));
    hourlabel->SetMinSize(wxSize(50, hourlabel->GetMinSize().y));
    hoursizer->Add(hourlabel);


    hourBox = new wxTextCtrl(this, wxID_ANY);
    hourBox->SetValidator(wxIntegerValidator<int>(&hour));

    hoursizer->Add(hourBox, 1);

    mainSizer->Add(hoursizer, 0, wxEXPAND | wxALL, 5);

    //for month field

    wxBoxSizer* minutesizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* minutelabel = new wxStaticText(this, wxID_ANY, _("Minute:"));
    minutelabel->SetMinSize(wxSize(50, minutelabel->GetMinSize().y));
    minutesizer->Add(minutelabel);

    minuteBox = new wxTextCtrl(this, wxID_ANY);
    minuteBox->SetValidator(wxIntegerValidator<int>(&minute));


    minutesizer->Add(minuteBox, 1);

    mainSizer->Add(minutesizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);



    //fo day field

    wxBoxSizer* secondssizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* secondslabel = new wxStaticText(this, wxID_ANY, _("Seconds:"));
    secondslabel->SetMinSize(wxSize(50, secondslabel->GetMinSize().y));
    secondssizer->Add(secondslabel);


    secondsBox = new wxTextCtrl(this, wxID_ANY);

    secondsBox->SetValidator(wxIntegerValidator<int>(&seconds));

    secondssizer->Add(secondsBox, 1);

    mainSizer->Add(secondssizer, 0, wxEXPAND | wxALL, 5);


    //Create Buttons

    wxSizer* buttonSizer = CreateButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxBOTTOM, 5);

    //error label
    wxBoxSizer* errsizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText* errlabel = new wxStaticText(this, wxID_ANY, _(
        " - If the entered time is invalid, it will automatically be\n set to the default max or the min value of the time."));
    //msglabel->SetMinSize(wxSize(50, msglabel->GetMinSize().y));
    errsizer->Add(errlabel);

    mainSizer->Add(errsizer, 0, wxEXPAND | wxALL, 5);


    //Sizer sets

    SetSizer(mainSizer);

    SetMinSize(wxSize(300, 100));

    Fit();



}


void setTimeDialog::onUpdateOk(wxUpdateUIEvent& event)
{
    event.Enable(false);

    if (!hourBox->GetValue().empty())
    {
        if (!minuteBox->GetValue().empty())
        {

            if (!secondsBox->GetValue().empty())
            {
                event.Enable(true);
            }


        }
    }
};


setTimeDialog::~setTimeDialog()
{

};