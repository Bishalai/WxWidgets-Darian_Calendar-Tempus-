#define _CRT_SECURE_NO_WARNINGS
// main window od the app
#include "MainWindow.h"


BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(wxID_EXIT , MainWindow::onQuit)
    EVT_CLOSE(MainWindow::onClose)
END_EVENT_TABLE()

MainWindow:: MainWindow(wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos ,
    const wxSize& size ,
    long style ,
    const wxString& name):
    wxFrame(parent, id, title, pos, size, style, name)
{
    SetIcon(Icon_xpm);
    
    SetMaxSize(wxSize(1000, 600));

    Gregorian_DateTime dt_now;
    //dt_now.set_now();
    dt_now.set_date(2021, 5, 2);


    //menubar
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

    //Sizers
    wxSizer* Sizer = new wxBoxSizer(wxHORIZONTAL);
    wxSizer* sizer_top = new wxBoxSizer(wxVERTICAL);
    //wxSizer* cal_sizer = new wxBoxSizer(wxHORIZONTAL);

    //panel
    wxDisplay win_display;
    wxRect win_screen = win_display.GetClientArea();
    wxSize appwinsize = wxSize(win_screen.GetWidth() / 8, win_screen.GetHeight() / 8);
    wxSize appwinsizebot = wxSize(appwinsize.GetWidth(), appwinsize.GetHeight() / 3);

    //below are the height and width modifiers
    //int winsizeHeightInc = win_screen.GetHeight() / 3;
    //int winsizeWidthInc = win_screen.GetWidth() / 1.5;
    //winsize.IncBy(winsizeWidthInc, winsizeHeightInc);

    wxPanel* panel_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
    panel_left->SetBackgroundColour(wxColor(100, 150, 200));

    wxPanel* panel_lefttop = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
    panel_lefttop->SetBackgroundColour(wxColor(100, 100, 150));

    wxButton* prevbutton = new wxButton(panel_left, wxID_ANY, "prev", wxPoint(appwinsize.GetWidth()-70, 0), wxDefaultSize);

    //wxBitmap bitmap;
    //bitmap.LoadFile("‪D:\Photos\Messenger\123.jpeg", wxBITMAP_TYPE_JPEG);                                        //  //bitmapbutton didnt load :/
    //wxBitmapButton* button12 = new wxBitmapButton(panel_left, -1, bitmap, wxPoint(0, 0), wxSize(50, 50), 0);


    wxStaticText* text_ofdate1 = new wxStaticText(panel_left, wxID_ANY, "DATE :", wxPoint(appwinsize.GetWidth() / 12, appwinsize.GetHeight() / 8));
    wxStaticText* text_oftime = new wxStaticText(panel_left, wxID_ANY, "TIME :", wxPoint(20, 120));
    wxStaticText* season = new wxStaticText(panel_left, wxID_ANY, dt_now.get_season_name(), wxPoint(80, 160));
    wxStaticText* text_ofseason = new wxStaticText(panel_left, wxID_ANY, "Season :", wxPoint(20, 160));

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

   


    //year view

    wxGridSizer* gs = new wxGridSizer(4,3, cellsize);
    
   
    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

    wxString year_count = wxString::Format(wxT("%i"),dt_now.get_year());
    gs->Add(new wxButton(panel_lefttop, -1, year_count), 1, wxEXPAND);

    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
    

    for (int i = 1; i <= dt_now.get_no_of_months(); i++)
    {
        wxString day_count = wxString::Format(wxT("%s"), dt_now.get_input_month_name(i) );
        gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
    }


    /*
     // month  view
    wxGridSizer* gs = new wxGridSizer(6, 7, cellsize);

    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

    gs->Add(new wxButton(panel_lefttop, -1, _(dt_now.get_month_name())), 1, wxEXPAND);

    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

    gs->Add(new wxButton(panel_lefttop, -1, _("Sun")), 1, wxEXPAND);
    gs->Add(new wxButton(panel_lefttop, -1, _("Mon")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_lefttop, -1, _("Tue")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_lefttop, -1, _("Wed")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_lefttop, -1, _("Thu")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_lefttop, -1, _("Fri")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_lefttop, -1, _("Sat")), 0, wxEXPAND);
    
    
    
    for (int j = 0; j < dt_now.get_firstday_month(); j++)
    {
        gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
    }

    for (int i = 1; i <= dt_now.get_no_of_days_in_month(); i++)
    {
        wxString day_count = wxString::Format(wxT("%i"), i);
        gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
    }
    */
    
    //buttons:
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
    

}

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