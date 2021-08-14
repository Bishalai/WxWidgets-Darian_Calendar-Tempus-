#define _CRT_SECURE_NO_WARNINGS
// main window od the app
#include "MainWindow.h"


BEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_MENU(wxID_EXIT, MainWindow::onQuit)
EVT_CLOSE(MainWindow::onClose)
END_EVENT_TABLE()


static int cal_status = 1;// of for gregorian, 1 for darian
static int view_status = 0;// 0 for months and 1 for year view


//----------------------------------------date time objects ----------------------------------------------//
Gregorian_DateTime dt_now1;
Gregorian_DateTime *dt_now = &dt_now1;

Darian_Date_Time d_dt_now1;
Darian_Date_Time *d_dt_now =&d_dt_now1;

wxTextCtrl* secup;
//------------------------------------------------------------------------------------------------////




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

    SetMaxSize(wxSize(1000, 600));

    //--set date, time to now===================//
    dt_now->set_now();
    
    d_dt_now->set_now();
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
    wxMenuItem* GeorgianItem =  HomeMenu->Append(wxID_ANY, _("&Georgian\tCtrl+X"));
    GeorgianItem->SetBitmap(GeorgianBmp);
    Bind(wxEVT_MENU, &MainWindow::onGeorgian, this, GeorgianItem->GetId());

    //darian menu item
    wxBitmap DarianBmp(Darian_xpm);
    wxMenuItem* DarianItem = HomeMenu->Append(wxID_ANY, _("&Darian\tCtrl+C"));
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
    wxMenuItem* setDate = optionsMenu->Append(wxID_ANY, _("&Set Date\tCtrl+D"));
    setDate->SetBitmap(DateBmp);
    Bind(wxEVT_MENU, &MainWindow::onsetDate, this, setDate->GetId());

    //set time
    wxBitmap TimeBmp(Time_xpm);
    wxMenuItem* setTime= optionsMenu->Append(wxID_ANY, _("&Set Time\tCtrl+T"));
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

    optionsMenu->AppendSubMenu(viewsubMenu, _("Switch Views\tCtrl+S"));

    //help menu in menubar
    wxMenu* helpMenu = new wxMenu();
    menuBar->Append(helpMenu, _("&Help"));

    //help item
    wxMenuItem* helpItem = helpMenu->Append(wxID_HELP);
    helpItem->SetBitmap(wxArtProvider::GetBitmap("wxART_HELP", wxART_OTHER, wxSize(16,16)));
    Bind(wxEVT_MENU, &MainWindow::onHelp, this, helpItem->GetId());

    //set the Menu
    SetMenuBar(menuBar);

    //---------------------------------------------------------------------------------------------------------//

    //========================================================================================================//
    //toolbar setup
    wxToolBar* toolBar = CreateToolBar();

    //georgian tool
    toolBar->AddTool(GeorgianItem->GetId(), _("Georgian Calendar"),GeorgianItem->GetBitmap() ,_("Switch to Georgian Calendar"));

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
    toolBar->AddTool(wxID_EXIT, _("QUIT"), wxArtProvider::GetBitmap("wxART_QUIT"),_("Quit"));

    toolBar->AddSeparator();
    toolBar->AddStretchableSpace();

    //help tool
    toolBar->AddTool(helpItem->GetId(), _("Help"), helpItem->GetBitmap() , _("Help"));

    toolBar->Realize();
    

    //--------------------------------------------------------------------------------------------------//
    //======================================================================================================//

    //Sizers
    wxSizer* Sizer = new wxBoxSizer(wxHORIZONTAL);
    wxSizer* sizer_top = new wxBoxSizer(wxVERTICAL);
    //wxSizer* cal_sizer = new wxBoxSizer(wxHORIZONTAL);

    //panel
    wxDisplay win_display;
    wxRect win_screen = win_display.GetClientArea();
    wxSize appwinsize = wxSize(win_screen.GetWidth() / 8, win_screen.GetHeight() / 8);
    wxSize appwinsizebot = wxSize(appwinsize.GetWidth(), appwinsize.GetHeight() / 3);

 

    wxPanel* panel_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
    panel_left->SetBackgroundColour(wxColor(100, 150, 200));

    wxPanel* panel_lefttop = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
    panel_lefttop->SetBackgroundColour(wxColor(100, 100, 150));

    wxButton* prevbutton = new wxButton(panel_left, wxID_ANY, "prev", wxPoint(appwinsize.GetWidth()-60, 0), wxDefaultSize);

    //wxBitmap bitmap;
    //bitmap.LoadFile("‪D:\Photos\Messenger\123.jpeg", wxBITMAP_TYPE_JPEG);                                        //  //bitmapbutton didnt load :/
    //wxBitmapButton* button12 = new wxBitmapButton(panel_left, -1, bitmap, wxPoint(0, 0), wxSize(50, 50), 0);


   
    // display value of date, time, season---------------------------------------------------------------------------//
    //--------------------------------------------------------------------------------------------------------------//

    wxStaticText* text_ofdate1 = new wxStaticText(panel_left, wxID_ANY, "Date:", wxPoint(20, 80));
    wxStaticText* text_oftime = new wxStaticText(panel_left, wxID_ANY, "Time:", wxPoint(20, 120));

    wxStaticText* text_ofseason = new wxStaticText(panel_left, wxID_ANY, "Season :", wxPoint(20, 160));

    // variable depending upon the calendar status------------------------------------------------------------//
    
    if (cal_status == 0)// gregorian
    {
        wxString g_date_year = wxString::Format(wxT("%i"), dt_now->get_year());
        wxString g_date_month = wxString::Format(wxT("%s"), dt_now->get_month_name());
        wxString g_date_day = wxString::Format(wxT("%i"), dt_now->get_day());
        wxString g_date_temp = g_date_day + " " + g_date_month + " " + g_date_year;

        wxStaticText* g_date_text = new wxStaticText(panel_left, wxID_ANY, g_date_temp, wxPoint(80, 80));

        wxString g_time_hour = wxString::Format(wxT("%i"), dt_now->get_hour());
        wxString g_time_minute = wxString::Format(wxT("%i"), dt_now->get_minute());
        wxString g_time_seconds = wxString::Format(wxT("%i"), dt_now->get_seconds());
        wxString g_time_temp = g_time_hour + " : " + g_time_minute + " : " + g_time_seconds;

        wxTextCtrl* g_time_text = new wxTextCtrl(panel_left, wxID_ANY, g_time_temp, wxPoint(80, 120));
        secup = g_time_text;


        wxStaticText* g_season = new wxStaticText(panel_left, wxID_ANY, dt_now->get_season_name(), wxPoint(80, 160));
    }
    else
    {
        wxString d_date_year = wxString::Format(wxT("%i"), d_dt_now->get_year());
        wxString d_date_month = wxString::Format(wxT("%s"), d_dt_now->get_month_name());
        wxString d_date_sol = wxString::Format(wxT("%i"), d_dt_now->get_sol());
        wxString d_date_temp = d_date_sol + " " + d_date_month + " " + d_date_year;

        wxStaticText* d_date_text = new wxStaticText(panel_left, wxID_ANY, d_date_temp, wxPoint(80, 80));

        wxString d_time_hour = wxString::Format(wxT("%i"), d_dt_now->get_hour());
        wxString d_time_minute = wxString::Format(wxT("%i"), d_dt_now->get_minute());
        wxString d_time_seconds = wxString::Format(wxT("%i"), d_dt_now->get_seconds());
        wxString d_time_temp = d_time_hour + " : " + d_time_minute + " : " + d_time_seconds;

        wxTextCtrl* d_time_text = new wxTextCtrl(panel_left, wxID_ANY, d_time_temp, wxPoint(80, 120));
        secup = d_time_text;


        wxStaticText* d_season = new wxStaticText(panel_left, wxID_ANY, d_dt_now->get_season_name(), wxPoint(80, 160));

    }

    //--------------------------------------------------------------------------------------------------------------/
    //-------------------------------------------------------------------------------------------------------------//


    wxPanel* panel_rightbottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
    panel_rightbottom->SetBackgroundColour(wxColor(150, 100, 100));
    wxButton* bottonarightbottom = new wxButton(panel_rightbottom, wxID_ANY, "to do list (opt)", wxPoint(40, 0), wxDefaultSize);

    wxPanel* panel_topright = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
    panel_topright->SetBackgroundColour(wxColor(100, 150, 100));
    wxButton* toprightbottom1 = new wxButton(panel_topright, wxID_ANY, " Next ", wxPoint(0, 0), wxDefaultSize);

    //bitmapbutton didnt load :/

    wxStaticText* calander_checkbox = new wxStaticText(panel_topright, wxID_ANY, "calander", wxPoint(20, 40));
    wxCheckBox* checkbox1 = new wxCheckBox(panel_topright, wxID_ANY, wxT("Georgian"), wxPoint(20, 60), wxDefaultSize);
    checkbox1->SetValue(true);
    wxCheckBox* checkbox2 = new wxCheckBox(panel_topright, wxID_ANY, wxT("Darian"), wxPoint(20, 80), wxDefaultSize);
    checkbox2->SetValue(false);

    wxStaticText* view_checkbox = new wxStaticText(panel_topright, wxID_ANY, "view", wxPoint(20, 100));
    wxCheckBox* checkbox3 = new wxCheckBox(panel_topright, wxID_ANY, wxT("month"), wxPoint(20, 120), wxDefaultSize);
    checkbox3->SetValue(true);
    wxCheckBox* checkbox4 = new wxCheckBox(panel_topright, wxID_ANY, wxT("year"), wxPoint(20, 140), wxDefaultSize);
    checkbox4->SetValue(false);

    Sizer->Add(panel_left, 1, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 5);
    Sizer->Add(panel_lefttop, 3, wxEXPAND | wxTOP, 5);
    sizer_top->Add(panel_topright, 4, wxEXPAND | wxRIGHT, 5);

    sizer_top->Add(panel_rightbottom, 2, wxEXPAND | wxTOP | wxRIGHT, 5);
    Sizer->Add(sizer_top, 1, wxEXPAND | wxLEFT, 5);



    wxSize calsize = wxSize(appwinsize.GetWidth() / 2, appwinsize.GetHeight() / 2);
    wxSize cellsize = wxSize(calsize.GetWidth() / 20, calsize.GetHeight() / 7);

    wxSize cellmonthsize = wxSize(calsize.GetWidth() / 10, calsize.GetHeight() / 5);


    wxGridSizer* gs = new wxGridSizer(5, 3, cellsize);;

    //------------------------------------gregorian calendar-----------------------------------//
    //---------------------------year view for gregorian-----------------------------------//

    if (cal_status == 0 && view_status == 1)
    {
        gs = new wxGridSizer(5, 3, cellsize);


        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

        wxString year_count = wxString::Format(wxT("%i"), dt_now->get_year());
        wxString year_month = wxString::Format(wxT("%s"), dt_now->get_month_name());
        wxString header_year = year_month + " " + year_count;
        gs->Add(new wxButton(panel_lefttop, -1, header_year), 1, wxEXPAND);

        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);


        for (int i = 1; i <= dt_now->get_no_of_months(); i++)
        {
            wxString day_count = wxString::Format(wxT("%s"), dt_now->get_input_month_name(i));
            gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
        }

    }
    
     //------------------------------ month  view-----------------------------------------------///
    else if (cal_status == 0 && view_status == 0)
    {
        gs = new wxGridSizer(6, 7, cellsize);

        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

        wxString year_count = wxString::Format(wxT("%i"), dt_now->get_year());
        wxString year_month = wxString::Format(wxT("%s"), dt_now->get_month_name());
        wxString header_year = year_month + " " + year_count;
        gs->Add(new wxButton(panel_lefttop, -1, header_year), 1, wxEXPAND);

        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        
        
        for (int i = 1; i <= 7;i++)
        {
            wxString weekday_count = wxString::Format(wxT("%s"), dt_now->get_input_week_name(i));
            gs->Add(new wxButton(panel_lefttop, -1, weekday_count), 1, wxEXPAND);
        }



        for (int j = 0; j < dt_now->get_firstday_month(); j++)
        {
            gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        }

        for (int i = 1; i <= dt_now->get_no_of_days_in_month(); i++)
        {
            wxString day_count = wxString::Format(wxT("%i"), i);
            gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
        }

    }

    //------------------------------for darian views-----------------------------------------//

    //---------------------------year view for darian-----------------------------------//

    else if (cal_status == 1 && view_status == 1)
    {
        gs = new wxGridSizer(9, 3, cellsize);


        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

        wxString year_count = wxString::Format(wxT("%i"), d_dt_now->get_year());
        wxString year_month = wxString::Format(wxT("%s"), d_dt_now->get_month_name());
        wxString header_year = year_month + " " + year_count;
        gs->Add(new wxButton(panel_lefttop, -1, header_year), 1, wxEXPAND);

        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);


        for (int i = 1; i <= d_dt_now->get_no_of_months(); i++)
        {
            wxString day_count = wxString::Format(wxT("%s"), d_dt_now->get_input_month_name(i));
            gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
        }

    }


    //--------------------------------month vew darian-----------------------------------------//


    else if (cal_status == 1 && view_status == 0)
    {
        gs = new wxGridSizer(6, 7, cellsize);

        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

        wxString year_count = wxString::Format(wxT("%i"), d_dt_now->get_year());
        wxString year_month = wxString::Format(wxT("%s"), d_dt_now->get_month_name());
        wxString header_year = year_month + " " + year_count;
        gs->Add(new wxButton(panel_lefttop, -1, header_year), 1, wxEXPAND);

        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);


        for (int i = 1; i <= 7;i++)
        {
            wxString weekday_count = wxString::Format(wxT("%s"), d_dt_now->get_input_week_name(i));
            gs->Add(new wxButton(panel_lefttop, -1, weekday_count), 1, wxEXPAND);
        }
        


    

        for (int i = 1; i <= d_dt_now->get_no_of_days_in_month(); i++)
        {
            wxString day_count = wxString::Format(wxT("%i"), i);
            gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
        }

    }




    //-----------------------------------------------------------------------------------------------//

    //calling gs:
    panel_lefttop->SetSizerAndFit(gs);



    //setting sizer
    SetSizerAndFit(Sizer);


    //------------------------------------------------------------------------------------------//
    
    //statusbar
    wxDateTime dt = wxDateTime::Now();
    const int status_size = 3;
    wxStatusBar* statusBar = CreateStatusBar(status_size);
    statusBar->SetStatusText(_("Ready!"),0);
    statusBar->SetStatusText(_(dt.FormatDate()),1);
    statusBar->SetStatusText(_("Tempus!"),2);
    int status_width[status_size] = {-4,-4,-1};
    statusBar->SetStatusWidths(status_size, status_width);
    
    wxTimer* sectimer = new wxTimer(this);
    Bind (wxEVT_TIMER, &MainWindow::OnTimer,this, sectimer->GetId());
    sectimer->Start(1000);

}


void MainWindow::OnTimer(wxTimerEvent& event)
{
    if (cal_status == 0)
    {
        dt_now->increase();
        
        wxString g_time_hour = wxString::Format(wxT("%i"), dt_now->get_hour());
        wxString g_time_minute = wxString::Format(wxT("%i"), dt_now->get_minute());
        wxString g_time_seconds = wxString::Format(wxT("%i"), dt_now->get_seconds());
        wxString g_time_temp = g_time_hour + " : " + g_time_minute + " : " + g_time_seconds;
        secup->ChangeValue(g_time_temp);
    }
    else
    {
        d_dt_now->increase();

        wxString d_time_hour = wxString::Format(wxT("%i"), d_dt_now->get_hour());
        wxString d_time_minute = wxString::Format(wxT("%i"), d_dt_now->get_minute());
        wxString d_time_seconds = wxString::Format(wxT("%i"), d_dt_now->get_seconds());
        wxString d_time_temp = d_time_hour + " : " + d_time_minute + " : " + d_time_seconds;
        secup->ChangeValue(d_time_temp);
    }
   
    MainWindow::Update();
};





void MainWindow::onGeorgian(wxCommandEvent& event)
{
    wxMessageBox("set to Georgian Calendar");

    PushStatusText(_("Set to Gregorian Calendar"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onHelp(wxCommandEvent& event)
{
    wxMessageBox("Help Menu");
    
};

void MainWindow::onDarian(wxCommandEvent& event)
{
    wxMessageBox("set to Darian Calendar");
    PushStatusText(_("Set to Darian Calendar"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onsetDate(wxCommandEvent& event)
{
    wxMessageBox("set date");
    PushStatusText(_("date set"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onsetTime(wxCommandEvent& event)
{
    wxMessageBox("set time");
    PushStatusText(_("time set"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onswitchYear (wxCommandEvent& event)
{
    wxMessageBox("Year View");
    PushStatusText(_("Year View Set"));
    wxSleep(1);
    PopStatusText();
};

void MainWindow::onswitchMonth(wxCommandEvent& event)
{
    wxMessageBox("Month View");
    PushStatusText(_("Month View Set"));
    wxSleep(1);

    PopStatusText();
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
        if(answer!=wxYES)
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

