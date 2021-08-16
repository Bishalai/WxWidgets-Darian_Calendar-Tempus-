/*

//---------------------------------------------------------------------------------------------------//

-----------------wxTEMP1 for the first template for the darian calendar-------------------------------------

--Done By Bishal Khand Thakuri AKA IchigoIchie and the group Tempus- AADARSH - BISHAL - KAUSHAL

//-------------------------------------------------------------------------------------------------------//

*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
// main window od the app
#include "MainWindow.h"


BEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(wxID_EXIT, MainWindow::onQuit)
EVT_CLOSE(MainWindow::onClose)
END_EVENT_TABLE()







MainWindow::MainWindow(wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name) :
    wxFrame(parent, id, title, pos, size, style, name)
{
    SetIcon(Icon_xpm);

    SetMinSize(wxSize(700,500));

    SetMaxSize(wxSize(1000, 700));

    //--set date, time to now===================//
    g_dt_now.set_now();

    d_dt_now.set_now();
    //-----------------------------------------------//

    //-------------------------------------------------------------------------------------------------------//
    //menubar--------------------------------------------------------------------------------------------//
    wxMenuBar* menuBar = new wxMenuBar();

    //Home menu in menubar
    wxMenu* HomeMenu = new wxMenu();
    menuBar->Append(HomeMenu, _("&Home"));//& for the acceleratot, can use alt fun

    //wxmenu item

    //home menu items

    //georgian menu item
    wxBitmap GeorgianBmp(Georgian_xpm);
    wxMenuItem* GeorgianItem = HomeMenu->Append(wxID_ANY, _("&Georgian"));
    GeorgianItem->SetBitmap(GeorgianBmp);
    Bind(wxEVT_MENU, &MainWindow::onGeorgian, this, GeorgianItem->GetId());

    //darian menu item
    wxBitmap DarianBmp(Darian_xpm);
    wxMenuItem* DarianItem = HomeMenu->Append(wxID_ANY, _("&Darian"));
    DarianItem->SetBitmap(DarianBmp);
    Bind(wxEVT_MENU, &MainWindow::onDarian, this, DarianItem->GetId());

    HomeMenu->AppendSeparator();

    //quititem
    wxMenuItem* quitItem = new wxMenuItem(HomeMenu, wxID_EXIT);
    quitItem->SetBitmap(wxArtProvider::GetBitmap("wxART_QUIT"));
    HomeMenu->Append(quitItem);


    //options menu in menubar
    wxMenu* optionsMenu = new wxMenu();
    menuBar->Append(optionsMenu, _("&Options"));

    //setdate
    wxBitmap DateBmp(Date_xpm);
    wxMenuItem* setDate = optionsMenu->Append(wxID_ANY, _("&Set Date"));
    setDate->SetBitmap(DateBmp);
    Bind(wxEVT_MENU, &MainWindow::onsetDate, this, setDate->GetId());

    //set time
    wxBitmap TimeBmp(Time_xpm);
    wxMenuItem* setTime = optionsMenu->Append(wxID_ANY, _("&Set Time"));
    setTime->SetBitmap(TimeBmp);
    Bind(wxEVT_MENU, &MainWindow::onsetTime, this, setTime->GetId());

    optionsMenu->AppendSeparator();

    //view submenu in options
    wxMenu* viewsubMenu = new wxMenu();


    //for year view
    wxBitmap YearBmp(Year_xpm);
    wxMenuItem* switchToYear = viewsubMenu->Append(wxID_ANY, _("&To Year"));
    switchToYear->SetBitmap(YearBmp);
    Bind(wxEVT_MENU, &MainWindow::onswitchYear, this, switchToYear->GetId());

    //month view
    wxBitmap MonthBmp(Month_xpm);
    wxMenuItem* switchToMonth = viewsubMenu->Append(wxID_ANY, _("&To Months"));
    switchToMonth->SetBitmap(MonthBmp);
    Bind(wxEVT_MENU, &MainWindow::onswitchMonth, this, switchToMonth->GetId());

    optionsMenu->AppendSubMenu(viewsubMenu, _("Switch Views"));

    //help menu in menubar
    wxMenu* helpMenu = new wxMenu();
    menuBar->Append(helpMenu, _("&Help"));

    //help item
    wxMenuItem* aboutItem = helpMenu->Append(wxID_ABOUT);
    aboutItem->SetBitmap(wxArtProvider::GetBitmap("wxART_TIP",  wxART_OTHER, wxSize(16, 16))); //, wxART_OTHER, wxSize(16, 16)
    Bind(wxEVT_MENU, &MainWindow::onAbout, this, aboutItem->GetId());

    //set the Menu
    SetMenuBar(menuBar);

    //---------------------------------------------------------------------------------------------------------//

    //========================================================================================================//
    //toolbar setup
    wxToolBar* toolBar = CreateToolBar();

    //georgian tool
    toolBar->AddTool(GeorgianItem->GetId(), _("Georgian Calendar"), GeorgianItem->GetBitmap(), _("Switch to Georgian Calendar"));

    //darian tool
    toolBar->AddTool(DarianItem->GetId(), _("Darian Calendar"), DarianItem->GetBitmap(), _("Switch to Darian Calendar"));

    toolBar->AddSeparator();

    //month view tool
    toolBar->AddTool(switchToMonth->GetId(), _("Months View"), switchToMonth->GetBitmap(), _("Switch to Months view"));

    //year view tool
    toolBar->AddTool(switchToYear->GetId(), _("Year view"), switchToYear->GetBitmap(), _("Switch to Year View"));

    toolBar->AddSeparator();

    //date set date tool
    toolBar->AddTool(setDate->GetId(), _("setDate"), setDate->GetBitmap(), _("Set the date"));

    //time set time tool
    toolBar->AddTool(setTime->GetId(), _("setTime"), setTime->GetBitmap(), _("Set the time"));

    toolBar->AddSeparator();

    //quit tool
    toolBar->AddTool(wxID_EXIT, _("QUIT"), wxArtProvider::GetBitmap("wxART_QUIT"), _("Quit"));

    toolBar->AddSeparator();
    toolBar->AddStretchableSpace();

    //help tool
    toolBar->AddTool(aboutItem->GetId(), _("About"), aboutItem->GetBitmap(), _("About"));

    toolBar->Realize();


    //--------------------------------------------------------------------------------------------------//
    //======================================================================================================//

    //Sizers
    
    Sizer->Layout();
    
    //wxSizer* cal_sizer = new wxBoxSizer(wxHORIZONTAL);

    //panel
  
    
    panel_left->SetBackgroundColour(wxColor(100, 150, 200));    

    panel_right->SetBackgroundColour(wxColor(200, 150, 100));


    wxButton* prevButton = new wxButton(panel_left, wxID_ANY, "Prev", wxPoint(appwinsize.GetWidth() - 75, 0), wxDefaultSize);
    prevButton->Bind(wxEVT_BUTTON, &MainWindow::onPrevButton, this);

    wxButton* nextButton = new wxButton(panel_right, wxID_ANY, " Next ", wxPoint(0, 0), wxDefaultSize);
    nextButton->Bind(wxEVT_BUTTON, &MainWindow::onNextButton, this);

   //

    //adding quotes box






    // display value of date, time, season---------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------------------------------//

    wxStaticText* text_ofdate1 = new wxStaticText(panel_left, wxID_ANY, "Date:", wxPoint(10, 60));
    wxStaticText* text_oftime = new wxStaticText(panel_left, wxID_ANY, "Time:", wxPoint(10, 90));

    wxStaticText* text_ofseason = new wxStaticText(panel_left, wxID_ANY, "Season :", wxPoint(10, 120));

    // variable depending upon the calendar status------------------------------------------------------------//

    if (cal_status == 0)// gregorian
    {
        wxString g_date_year = wxString::Format(wxT("%i"), g_dt_now.get_year());
        wxString g_date_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
        wxString g_date_day = wxString::Format(wxT("%i"), g_dt_now.get_day());
        wxString g_date_temp = g_date_day + " " + g_date_month + " " + g_date_year;

        wxTextCtrl* g_date_text = new wxTextCtrl(panel_left, -1, g_date_temp, wxPoint(60, 60), wxDefaultSize, wxTE_READONLY);
        dateup = g_date_text;

        wxString g_time_hour = wxString::Format(wxT("%i"), g_dt_now.get_hour());
        wxString g_time_minute = wxString::Format(wxT("%i"), g_dt_now.get_minute());
        wxString g_time_seconds = wxString::Format(wxT("%i"), g_dt_now.get_seconds());
        wxString g_time_temp = g_time_hour + " : " + g_time_minute + " : " + g_time_seconds;

        wxTextCtrl* g_time_text = new wxTextCtrl(panel_left, wxID_ANY, g_time_temp, wxPoint(60, 90), wxDefaultSize, wxTE_READONLY);
        secup = g_time_text;


        wxTextCtrl* g_season = new wxTextCtrl(panel_left, -1, g_dt_now.get_season_name(), wxPoint(60, 120), wxDefaultSize, wxTE_READONLY);
        seasonup = g_season;

    }
    else
    {
        wxString d_date_year = wxString::Format(wxT("%i"), d_dt_now.get_year());
        wxString d_date_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
        wxString d_date_sol = wxString::Format(wxT("%i"), d_dt_now.get_sol());
        wxString d_date_temp = d_date_sol + " " + d_date_month + " " + d_date_year;

        wxTextCtrl* d_date_text = new wxTextCtrl(panel_left, wxTE_READONLY, d_date_temp, wxPoint(60, 60), wxDefaultSize, wxTE_READONLY);
        dateup = d_date_text;

        wxString d_time_hour = wxString::Format(wxT("%i"), d_dt_now.get_hour());
        wxString d_time_minute = wxString::Format(wxT("%i"), d_dt_now.get_minute());
        wxString d_time_seconds = wxString::Format(wxT("%i"), d_dt_now.get_seconds());
        wxString d_time_temp = d_time_hour + " : " + d_time_minute + " : " + d_time_seconds;

        wxTextCtrl* d_time_text = new wxTextCtrl(panel_left, wxID_ANY, d_time_temp, wxPoint(60, 90), wxDefaultSize, wxTE_READONLY);
        secup = d_time_text;


        wxTextCtrl* d_season = new wxTextCtrl(panel_left, wxTE_READONLY, d_dt_now.get_season_name(), wxPoint(60, 120), wxDefaultSize, wxTE_READONLY);
        seasonup = d_season;
    }

    //--------------------------------------------------------------------------------------------------------------/
    //-------------------------------------------------------------------------------------------------------------//

    
    Sizer->Add(panel_left, 0, wxEXPAND );
    
    Sizer->Add(panel_g_month, 2, wxEXPAND );
    Sizer->Add(panel_g_year, 2, wxEXPAND );
    Sizer->Add(panel_d_month, 2, wxEXPAND);
    Sizer->Add(panel_d_year, 2, wxEXPAND );
    
    display_g_month();
    
    Sizer->Add(panel_right, 0, wxEXPAND);

    //sizer_top->Add(panel_topright, 4, wxEXPAND | wxRIGHT, 5);

    //sizer_top->Add(panel_rightbottom, 2, wxEXPAND | wxTOP | wxRIGHT, 5);
    //Sizer->Add(sizer_top, 1, wxEXPAND | wxLEFT, 5);



    //-----------------------------------------------------------------------------------------------/


    //setting sizer
    SetSizerAndFit(Sizer);


    MainWindow::Refresh();
    Sizer->Layout();
    
    //------------------------------------------------------------------------------------------//

    //statusbar
    wxDateTime dt = wxDateTime::Now();
    const int status_size = 3;
    wxStatusBar* statusBar = CreateStatusBar(status_size);
    statusBar->SetStatusText(_("Ready!"), 0);
    statusBar->SetStatusText(_(dt.FormatDate()), 1);
    statusBar->SetStatusText(_("Tempus!"), 2);
    int status_width[status_size] = { -4,-4,-1 };
    statusBar->SetStatusWidths(status_size, status_width);

    wxTimer* sectimer = new wxTimer(this);
    Bind(wxEVT_TIMER, &MainWindow::OnTimer, this, sectimer->GetId());
    sectimer->Start(1000);

    

}

///----------------------------------------------------------------------------------------------------------//
//================================================ FUNCTIONS ===================================================/
//---------------------------------------------------------------------------------------------------------------//



//------------------------------------gregorian calendar-----------------------------------//


//-------------display funtions-------------------------------------------------------//
void MainWindow::display_g_month()
{
    //------------------------------ month  view-----------------------------------------------///
   
    panel_g_month->SetBackgroundColour(wxColor(100, 100, 150));
    //clearing the gridsizer
    gs_g_month->Clear(1);

    int gs_count = 0;// to remove the unused or gs error

    //the top row

    gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
    gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
    gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);

    wxString year_count = wxString::Format(wxT("%i"), g_dt_now.get_year());
    wxString year_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
    wxString header_year = year_month + " " + year_count;
    gs_g_month->Add(new wxButton(panel_g_month, -1, header_year), 1, wxEXPAND);

    gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
    gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
    gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);


    //for the weekday names

    for (int i = 1; i <= 7;i++)
    {
        wxString weekday_count = wxString::Format(wxT("%s"), g_dt_now.get_input_week_name(i));
        gs_g_month->Add(new wxButton(panel_g_month, -1, weekday_count), 1, wxEXPAND);
    }

    // the total cell used = 14
    gs_count = 14;

    //week days 


    for (int j = 0; j < g_dt_now.get_firstday_month(); j++)
    {
        gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
        gs_count++;
    }

    for (int i = 1; i <= g_dt_now.get_no_of_days_in_month(); i++)
    {
        wxString day_count = wxString::Format(wxT("%i"), i);
        gs_g_month->Add(new wxButton(panel_g_month, this->GetId(), day_count), 0, wxEXPAND);
        gs_count++;
    }

    for ( gs_count; gs_count < 56; gs_count++)
    {
        gs_g_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
    }

    //calling gs
    panel_g_month->SetSizerAndFit(gs_g_month);

    panel_d_month->Show(0);
    panel_d_year->Show(0);
    panel_g_month->Show(1);
    panel_g_year->Show(0);
    
};


void MainWindow::display_g_year()
{
    //---------------------------year view for gregorian-----------------------------------//

    panel_g_year->SetBackgroundColour(wxColor(100, 150, 100));


    // clearing gs
    gs_g_year->Clear(1);

    ///for the top row

        gs_g_year->Add(new wxStaticText(panel_g_year, -1, wxT("")), 0, wxEXPAND);

        wxString year_count = wxString::Format(wxT("%i"), g_dt_now.get_year());
        wxString year_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
        wxString header_year = year_month + " " + year_count;
        gs_g_year->Add(new wxButton(panel_g_year, -1, header_year), 1, wxEXPAND);

        gs_g_year->Add(new wxStaticText(panel_g_year, -1, wxT("")), 0, wxEXPAND);

        /// for the months

        for (int i = 1; i <= g_dt_now.get_no_of_months(); i++)
        {
            wxString day_count = wxString::Format(wxT("%s"), g_dt_now.get_input_month_name(i));
            gs_g_year->Add(new wxButton(panel_g_year, this->GetId(), day_count), 0, wxEXPAND);
        }

    //calling gs
        panel_g_year->SetSizerAndFit(gs_g_year);

        panel_d_month->Show(0);
        panel_d_year->Show(0);
        panel_g_month->Show(0);
        panel_g_year->Show(1);

};

//------------------------------for darian views-----------------------------------------//


void MainWindow::display_d_month()
{

    //--------------------------------month vew darian-----------------------------------------//


    panel_d_month->SetBackgroundColour(wxColor(100, 100, 150));
    //clearing the gridsizer
    gs_d_month->Clear(1);

    //the top row

    //counter to reduce error
    int gs_count = 0;

    gs_d_month->Add(new wxStaticText(panel_d_month, -1, wxT("")), 0, wxEXPAND);
    gs_d_month->Add(new wxStaticText(panel_d_month, -1, wxT("")), 0, wxEXPAND);
    gs_d_month->Add(new wxStaticText(panel_d_month, -1, wxT("")), 0, wxEXPAND);

    wxString year_count = wxString::Format(wxT("%i"), d_dt_now.get_year());
    wxString year_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
    wxString header_year = year_month + " " + year_count;
    gs_d_month->Add(new wxButton(panel_d_month, -1, header_year), 1, wxEXPAND);

    gs_d_month->Add(new wxStaticText(panel_d_month, -1, wxT("")), 0, wxEXPAND);
    gs_d_month->Add(new wxStaticText(panel_d_month, -1, wxT("")), 0, wxEXPAND);
    gs_d_month->Add(new wxStaticText(panel_d_month, -1, wxT("")), 0, wxEXPAND);

    //weekdays

    for (int i = 1; i <= 7;i++)
    {
        wxString weekday_count = wxString::Format(wxT("%s"), d_dt_now.get_input_week_name(i));
        gs_d_month->Add(new wxButton(panel_d_month, -1, weekday_count), 1, wxEXPAND);
    }

    //total cells used;
    gs_count = 14;

    //days

    for (int i = 1; i <= d_dt_now.get_no_of_days_in_month(); i++)
    {
        wxString day_count = wxString::Format(wxT("%i"), i);
        gs_d_month->Add(new wxButton(panel_d_month, this->GetId(), day_count), 0, wxEXPAND);
        gs_count++;
    }

    //error reducer taking extra cells
    for ( gs_count; gs_count < 42; gs_count++)
    {
        gs_d_month->Add(new wxStaticText(panel_g_month, -1, wxT("")), 0, wxEXPAND);
    }


    //calling gs
    panel_d_month->SetSizerAndFit(gs_d_month);

    panel_d_month->Show(1);
    panel_d_year->Show(0);
    panel_g_month->Show(0);
    panel_g_year->Show(0);

};


void MainWindow::display_d_year()
{ //---------------------------year view for darian-----------------------------------//

    panel_d_year->SetBackgroundColour(wxColor(100, 150, 100));

    gs_d_year->Clear(1);

    //first row

    gs_d_year->Add(new wxStaticText(panel_d_year, -1, wxT("")), 0, wxEXPAND);

    wxString year_count = wxString::Format(wxT("%i"), d_dt_now.get_year());
    wxString year_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
    wxString header_year = year_month + " " + year_count;
    gs_d_year->Add(new wxButton(panel_d_year, -1, header_year), 1, wxEXPAND);

    gs_d_year->Add(new wxStaticText(panel_d_year, -1, wxT("")), 0, wxEXPAND);

    // month names

    for (int i = 1; i <= d_dt_now.get_no_of_months(); i++)
    {
        wxString day_count = wxString::Format(wxT("%s"), d_dt_now.get_input_month_name(i));
        gs_d_year->Add(new wxButton(panel_d_year, this->GetId(), day_count), 0, wxEXPAND);
    }
    panel_d_year->SetSizerAndFit(gs_d_year);

    panel_d_month->Show(0);
    panel_d_year->Show(1);
    panel_g_month->Show(0);
    panel_g_year->Show(0);

};


///-------------------------------------------------------------------------------------------------------------//#
//--------------------------------------------------------------------------------------------------------------//


//-------------------- timer to update the second in the calendar---------------------------------------------//


void MainWindow::OnTimer(wxTimerEvent& event)
{
    if (cal_status == 0)
    {
        g_dt_now.increase();

        wxString g_time_hour = wxString::Format(wxT("%i"), g_dt_now.get_hour());
        wxString g_time_minute = wxString::Format(wxT("%i"), g_dt_now.get_minute());
        wxString g_time_seconds = wxString::Format(wxT("%i"), g_dt_now.get_seconds());
        wxString g_time_temp = g_time_hour + " : " + g_time_minute + " : " + g_time_seconds;
        secup->ChangeValue(g_time_temp);
    }
    else
    {
        d_dt_now.increase();

        wxString d_time_hour = wxString::Format(wxT("%i"), d_dt_now.get_hour());
        wxString d_time_minute = wxString::Format(wxT("%i"), d_dt_now.get_minute());
        wxString d_time_seconds = wxString::Format(wxT("%i"), d_dt_now.get_seconds());
        wxString d_time_temp = d_time_hour + " : " + d_time_minute + " : " + d_time_seconds;
        secup->ChangeValue(d_time_temp);
    }

    MainWindow::Update();
};



//  --------------------------------------------------------------------------------------------------//
//====================================================================================================//



//---------------------------functions for event handling------------------------------------------------//


void MainWindow::onGeorgian(wxCommandEvent& event)
{
    // error for now when converting from darian to gregorian

   /* if (cal_status == 1)
    {
        Gregorian_DateTime g_dt_now_temp = d_dt_now.convert_to_Gregorian();

        g_dt_now.set_date(g_dt_now_temp.get_year(), g_dt_now_temp.get_month(), g_dt_now_temp.get_day());

        g_dt_now.set_time(g_dt_now_temp.get_hour(), g_dt_now_temp.get_minute(), g_dt_now_temp.get_seconds());

    }
    */

    if (view_status == 0)// if it is in month view, switch to monh view else year view
    {
        display_g_month();

        panel_d_month->Show(0);
        panel_d_year->Show(0);
        panel_g_month->Show(1);
        panel_g_year->Show(0);
    }
    else
    {
        display_g_year();

        panel_d_month->Show(0);
        panel_d_year->Show(0);
        panel_g_month->Show(0);
        panel_g_year->Show(1);
    }
    // to update the name of the date and season
    wxString g_date_year = wxString::Format(wxT("%i"), g_dt_now.get_year());
    wxString g_date_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
    wxString g_date_day = wxString::Format(wxT("%i"), g_dt_now.get_day());
    wxString g_date_temp = g_date_day + " " + g_date_month + " " + g_date_year;
    dateup->ChangeValue(g_date_temp);

    seasonup->ChangeValue(g_dt_now.get_season_name());

    MainWindow::Refresh();
    MainWindow::Update();

    Sizer->Layout();

    cal_status = 0; //the current status changed to gregorian

    //wxMessageBox("set to Georgian Calendar");

   // PushStatusText(_("Set to Gregorian Calendar"));
   // wxSleep(1);
   // PopStatusText();
};




void MainWindow::onDarian(wxCommandEvent& event)
{
    if (cal_status == 0)
    {
        Darian_Date_Time d_dt_now_temp = g_dt_now.convert_to_darian();

        d_dt_now.set_date(d_dt_now_temp.get_year(), d_dt_now_temp.get_month(), d_dt_now_temp.get_sol());

        d_dt_now.set_time(d_dt_now_temp.get_hour(), d_dt_now_temp.get_minute(), d_dt_now_temp.get_seconds());

    }


    if (view_status == 0)//if it is in month view when switching use month view else year view
    {
        display_d_month();

        panel_d_month->Show(1);
        panel_d_year->Show(0);
        panel_g_month->Show(0);
        panel_g_year->Show(0);
    }
    else
    {
        display_d_year();

        panel_d_month->Show(0);
        panel_d_year->Show(1);
        panel_g_month->Show(0);
        panel_g_year->Show(0);
    }

    // update the date and season
    wxString d_date_year = wxString::Format(wxT("%i"), d_dt_now.get_year());
    wxString d_date_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
    wxString d_date_sol = wxString::Format(wxT("%i"), d_dt_now.get_sol());
    wxString d_date_temp = d_date_sol + " " + d_date_month + " " + d_date_year;

    dateup->ChangeValue(d_date_temp);

    seasonup->ChangeValue(d_dt_now.get_season_name());


    MainWindow::Refresh();
    MainWindow::Update();

    Sizer->Layout();

    cal_status = 1;// the current cal_status changed to darian;


    //wxMessageBox("set to Darian Calendar");
   // PushStatusText(_("Set to Darian Calendar"));
   // wxSleep(1);
   // PopStatusText();
};


void MainWindow::onswitchYear(wxCommandEvent& event)
{
    if (cal_status == 0) // if it is gregorian use gregorian else use darian
    {
        display_g_year();

        panel_d_month->Show(0);
        panel_d_year->Show(0);
        panel_g_month->Show(0);
        panel_g_year->Show(1);
    }
    else
    {
        display_d_year();

        panel_d_month->Show(0);
        panel_d_year->Show(1);
        panel_g_month->Show(0);
        panel_g_year->Show(0);
    }

    MainWindow::Refresh();
    MainWindow::Update();

    Sizer->Layout();

    view_status = 1; // current view status changed to year

    //wxMessageBox("Year View");
  //  PushStatusText(_("Year View Set"));
    //wxSleep(1);
   // PopStatusText();
};

void MainWindow::onswitchMonth(wxCommandEvent& event)
{
    if (cal_status == 0)//cal_status if gregorian, shows in gregorian else in darian
    {
        display_g_month();

        panel_d_month->Show(0);
        panel_d_year->Show(0);
        panel_g_month->Show(1);
        panel_g_year->Show(0);
    }
    else
    {
        display_d_month();

        panel_d_month->Show(1);
        panel_d_year->Show(0);
        panel_g_month->Show(0);
        panel_g_year->Show(0);

    }

    MainWindow::Refresh();
    MainWindow::Update();

    Sizer->Layout();

    view_status = 0;//view status updated to month

    //wxMessageBox("Month View");
    //PushStatusText(_("Month View Set"));
    //wxSleep(1);

//    PopStatusText();
};


///////////--------------------------------------------------------------------------------//////


//==========Buttons Functions============================================----------------------//

//----------------------------------------------------------------------------------------------//

void MainWindow::onPrevButton(wxCommandEvent& event)
{

    if (cal_status == 0 && view_status==0)//to get the view and the calendar
    {
        g_dt_now.previous_month();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_g_month();

    
    }
    else if (cal_status == 1 && view_status == 0)
    {


        d_dt_now.previous_month();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_d_month();


    }
    else if (cal_status == 0 && view_status == 1)
    {

        g_dt_now.previous_year();
        
        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();
        display_g_year();

    }
    else if (cal_status == 1 && view_status == 1)
    {

        d_dt_now.previous_year();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_d_year();

        
    }


    // to update the name of the date and season
    if (cal_status == 0)
    {
        wxString g_date_year = wxString::Format(wxT("%i"), g_dt_now.get_year());
        wxString g_date_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
        wxString g_date_day = wxString::Format(wxT("%i"), g_dt_now.get_day());
        wxString g_date_temp = g_date_day + " " + g_date_month + " " + g_date_year;
        dateup->ChangeValue(g_date_temp);

        seasonup->ChangeValue(g_dt_now.get_season_name());
    }
    else
    {
        wxString d_date_year = wxString::Format(wxT("%i"), d_dt_now.get_year());
        wxString d_date_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
        wxString d_date_sol = wxString::Format(wxT("%i"), d_dt_now.get_sol());
        wxString d_date_temp = d_date_sol + " " + d_date_month + " " + d_date_year;

        dateup->ChangeValue(d_date_temp);

        seasonup->ChangeValue(d_dt_now.get_season_name());
    }

    MainWindow::Refresh();
    MainWindow::Update();

    Sizer->Layout();

    //wxMessageBox(_("prevbutton called"));

    //PushStatusText(_("Previous Button Clicked!"));
    //wxSleep(1);

    //PopStatusText();


};


void MainWindow::onNextButton(wxCommandEvent& event)
{

    if (cal_status == 0 && view_status == 0)//to get the view and the calendar
    {
        g_dt_now.next_month();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_g_month();

    }
    else if (cal_status == 1 && view_status == 0)
    {
        d_dt_now.next_month();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_d_month();


    }
    else if (cal_status == 0 && view_status == 1)
    {
        g_dt_now.next_year();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_g_year();

    }
    else if (cal_status == 1 && view_status == 1)
    {

        d_dt_now.next_year();

        panel_d_month->Hide();
        panel_d_year->Hide();
        panel_g_month->Hide();
        panel_g_year->Hide();

        display_d_year();


    }
    if (cal_status == 0)
    {
        wxString g_date_year = wxString::Format(wxT("%i"), g_dt_now.get_year());
        wxString g_date_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
        wxString g_date_day = wxString::Format(wxT("%i"), g_dt_now.get_day());
        wxString g_date_temp = g_date_day + " " + g_date_month + " " + g_date_year;
        dateup->ChangeValue(g_date_temp);

        seasonup->ChangeValue(g_dt_now.get_season_name());
    }
    else
    {
        wxString d_date_year = wxString::Format(wxT("%i"), d_dt_now.get_year());
        wxString d_date_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
        wxString d_date_sol = wxString::Format(wxT("%i"), d_dt_now.get_sol());
        wxString d_date_temp = d_date_sol + " " + d_date_month + " " + d_date_year;

        dateup->ChangeValue(d_date_temp);

        seasonup->ChangeValue(d_dt_now.get_season_name());
    }


    MainWindow::Refresh();
    MainWindow::Update();

    Sizer->Layout();

    //wxMessageBox(_("nextbutton called"));

   // PushStatusText(_("Next Button Clicked!"));
  //  wxSleep(1);

//    PopStatusText();

};


void MainWindow::onsetTime(wxCommandEvent& event)
{

    //for gregorian
    if (cal_status == 0)
    {
        setTimeDialog* dlg_g_time = new setTimeDialog(this, wxID_ANY, _("Set Time"));

        dlg_g_time->sethour(g_dt_now.get_hour());
        dlg_g_time->setminute(g_dt_now.get_minute());
        dlg_g_time->setseconds(g_dt_now.get_seconds());

        dlg_g_time->ShowModal();

       

        dlg_g_time->Destroy();

        g_dt_now.set_time(dlg_g_time->gethour(), dlg_g_time->getminute(), dlg_g_time->getseconds());

        if (view_status == 0)// if it is in month view, switch to monh view else year view
        {
            display_g_month();

            panel_d_month->Show(0);
            panel_d_year->Show(0);
            panel_g_month->Show(1);
            panel_g_year->Show(0);
        }
        else
        {
            display_g_year();

            panel_d_month->Show(0);
            panel_d_year->Show(0);
            panel_g_month->Show(0);
            panel_g_year->Show(1);
        }
        
        MainWindow::Refresh();
        MainWindow::Update();

        Sizer->Layout();
    }
    else
    {
        setTimeDialog* dlg_d_time = new setTimeDialog(this, wxID_ANY, _("Set Time"));

        dlg_d_time->sethour(d_dt_now.get_hour());
        dlg_d_time->setminute(d_dt_now.get_minute());
        dlg_d_time->setseconds(d_dt_now.get_seconds());

        dlg_d_time->ShowModal();



        dlg_d_time->Destroy();

        d_dt_now.set_time(dlg_d_time->gethour(), dlg_d_time->getminute(), dlg_d_time->getseconds());


        if (view_status == 0)//if it is in month view when switching use month view else year view
        {
            display_d_month();

            panel_d_month->Show(1);
            panel_d_year->Show(0);
            panel_g_month->Show(0);
            panel_g_year->Show(0);
        }
        else
        {
            display_d_year();

            panel_d_month->Show(0);
            panel_d_year->Show(1);
            panel_g_month->Show(0);
            panel_g_year->Show(0);
        }


        

        MainWindow::Refresh();
        MainWindow::Update();

        Sizer->Layout();

    }
    
    PushStatusText(_("Time set"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onsetDate(wxCommandEvent& event)
{


    //for gregorian
    if (cal_status == 0)
    {
        setDateDialog* dlg_g_date = new setDateDialog(this, wxID_ANY, _("Set Date"));

        dlg_g_date->setyear(g_dt_now.get_year());
        dlg_g_date->setmonth(g_dt_now.get_month());
        dlg_g_date->setday(g_dt_now.get_day());

        dlg_g_date->ShowModal();



        dlg_g_date->Destroy();

        g_dt_now.set_date(dlg_g_date->getyear(), dlg_g_date->getmonth(), dlg_g_date->getday());

        if (view_status == 0)// if it is in month view, switch to monh view else year view
        {
            display_g_month();

            panel_d_month->Show(0);
            panel_d_year->Show(0);
            panel_g_month->Show(1);
            panel_g_year->Show(0);
        }
        else
        {
            display_g_year();

            panel_d_month->Show(0);
            panel_d_year->Show(0);
            panel_g_month->Show(0);
            panel_g_year->Show(1);
        }
        // to update the name of the date and season
        wxString g_date_year = wxString::Format(wxT("%i"), g_dt_now.get_year());
        wxString g_date_month = wxString::Format(wxT("%s"), g_dt_now.get_month_name());
        wxString g_date_day = wxString::Format(wxT("%i"), g_dt_now.get_day());
        wxString g_date_temp = g_date_day + " " + g_date_month + " " + g_date_year;
        dateup->ChangeValue(g_date_temp);

        seasonup->ChangeValue(g_dt_now.get_season_name());

        MainWindow::Refresh();
        MainWindow::Update();

        Sizer->Layout();
    }
    else
    {
        setDateDialog* dlg_d_date = new setDateDialog(this, wxID_ANY, _("Set Date"));

        dlg_d_date->setyear(d_dt_now.get_year());
        dlg_d_date->setmonth(d_dt_now.get_month());
        dlg_d_date->setday(d_dt_now.get_sol());

        dlg_d_date->ShowModal();

        d_dt_now.set_date(dlg_d_date->getyear(), dlg_d_date->getmonth(), dlg_d_date->getday());

        dlg_d_date->Destroy();

        if (view_status == 0)//if it is in month view when switching use month view else year view
        {
            display_d_month();

            panel_d_month->Show(1);
            panel_d_year->Show(0);
            panel_g_month->Show(0);
            panel_g_year->Show(0);
        }
        else
        {
            display_d_year();

            panel_d_month->Show(0);
            panel_d_year->Show(1);
            panel_g_month->Show(0);
            panel_g_year->Show(0);
        }

        // update the date and season
        wxString d_date_year = wxString::Format(wxT("%i"), d_dt_now.get_year());
        wxString d_date_month = wxString::Format(wxT("%s"), d_dt_now.get_month_name());
        wxString d_date_sol = wxString::Format(wxT("%i"), d_dt_now.get_sol());
        wxString d_date_temp = d_date_sol + " " + d_date_month + " " + d_date_year;

        dateup->ChangeValue(d_date_temp);

        seasonup->ChangeValue(d_dt_now.get_season_name());


        MainWindow::Refresh();
        MainWindow::Update();

        Sizer->Layout();

    }



    //wxMessageBox("Set time");
    PushStatusText(_("Date set"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onAbout(wxCommandEvent& event)
{
    wxMessageBox("About Section\n-- Darian Calendar \n------A calendar made with the concept of Darian Calendar, a Calendar proposed for Mars\n  ---- Integrated with the familiar Gregorian Calendar\n \n ---Made by Tempus---\n-Bishal076bct018 \n-Kaushal076bct030 \n-Aadarsh076bct002");


};



void MainWindow::onQuit(wxCommandEvent& event)
{
    //wxMessageBox("Quit Called");
    bool veto = Close();
};

void MainWindow::onClose(wxCloseEvent& event)
{

    if (event.CanVeto())
    {
        int answer = wxMessageBox(_("Do you wanna quit?"), _("Confirm?"), wxYES_NO);
        if (answer != wxYES)
        {
            event.Veto();
            return;
        }
    };

    Destroy();

};


MainWindow::~MainWindow()
{
}
