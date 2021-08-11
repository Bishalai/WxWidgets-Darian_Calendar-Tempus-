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


    //Sizers
    wxBoxSizer* Sizer = new wxBoxSizer(wxHORIZONTAL);

    //panel
    wxDisplay win_display;
    wxRect win_screen = win_display.GetClientArea();
    wxSize appwinsize = wxSize (win_screen.GetWidth()/8,win_screen.GetHeight()/4);
    wxSize appwinsizebot = wxSize(appwinsize.GetWidth(),appwinsize.GetHeight()/2);
    
    //below are the height and width modifiers
    //int winsizeHeightInc = win_screen.GetHeight() / 3;
    //int winsizeWidthInc = win_screen.GetWidth() / 1.5;
    //winsize.IncBy(winsizeWidthInc, winsizeHeightInc);


    //first panel
    wxPanel* panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize);
    panel_top->SetBackgroundColour(wxColor(200, 100, 100));
    Sizer->Add (panel_top, 2, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 5);

    //second panel
    wxPanel* panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsizebot );
    panel_bottom->SetBackgroundColour(wxColor(100,100,200));
    Sizer->Add(panel_bottom,1,wxEXPAND | wxALL,5);
    
    //size of calendar days button
    wxSize calsize = wxSize(appwinsize.GetWidth() /2, appwinsize.GetHeight() /2);

    //sizer for cal
    wxSizer* cal_sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel* panel_cal = new wxPanel(panel_top, wxID_ANY, wxDefaultPosition , calsize);
    panel_cal->SetBackgroundColour(wxColor(100, 150, 100));
    
    cal_sizer->Add(panel_cal, 0, wxALIGN_CENTER  | wxALL , 5);

    wxSize cellsize = wxSize(calsize.GetWidth()/7,calsize.GetHeight()/7);
    wxGridSizer* gs = new wxGridSizer(6,7,cellsize);

    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Sun")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Mon")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Tue")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Wed")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Thu")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Fri")), 0, wxEXPAND);
    gs->Add(new wxButton(panel_cal, panel_cal->GetId(), _("Sat")), 0, wxEXPAND);
    gs->Add(new wxStaticText(panel_cal, panel_cal->GetId(), wxT("")), 0, wxEXPAND);
    gs->Add(new wxStaticText(panel_cal, panel_cal->GetId(), wxT("")), 0, wxEXPAND);

    for (int i = 1; i < 30; i++)
    {
        wxString day_count = wxString::Format(wxT("%i"), i);
        gs->Add(new wxButton (panel_cal, panel_cal->GetId(), day_count), 0, wxEXPAND);
    }

    //buttons:
    
    
    
    //calling em sizers
    panel_cal->SetSizerAndFit(gs);
    panel_top->SetSizer(cal_sizer);


    //setting sizer
    SetSizerAndFit(Sizer);

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