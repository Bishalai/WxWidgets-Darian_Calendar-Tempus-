// main window od the app
#include "MainWindow.h"
#include <wx/artprov.h>
#include "datetime.h"
#include "Georgian.xpm"
#include "Darian.xpm"
#include "Month.xpm"
#include "Year.xpm"
#include "Icon.xpm"

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
    wxMenuItem* GeorgianItem =  HomeMenu->Append(wxID_ANY, _("&Georgian\tCtrl+X"));
    Bind(wxEVT_MENU, &MainWindow::onGeorgian, this, GeorgianItem->GetId());

    wxMenuItem* DarianItem = HomeMenu->Append(wxID_ANY, _("&Darian\tCtrl+C"));
    Bind(wxEVT_MENU, &MainWindow::onDarian, this, DarianItem->GetId());

    HomeMenu->AppendSeparator();

    wxMenuItem* quitItem = new wxMenuItem(HomeMenu, wxID_EXIT);
    quitItem->SetBitmap(wxArtProvider::GetBitmap("wxART_QUIT"));
    HomeMenu->Append(quitItem);
    
                                          
    //options menu in menubar
    wxMenu* optionsMenu = new wxMenu();
    menuBar->Append(optionsMenu, _("&Options"));

    //setdate
    wxMenuItem* setDate = optionsMenu->Append(wxID_ANY, _("&Set Date\tCtrl+D"));
    Bind(wxEVT_MENU, &MainWindow::onsetDate, this, setDate->GetId());

    //set time
    wxMenuItem* setTime= optionsMenu->Append(wxID_ANY, _("&Set Time\tCtrl+T"));
    Bind(wxEVT_MENU, &MainWindow::onsetTime, this, setTime->GetId());

    optionsMenu->AppendSeparator();
    
    //view submenu in options
    wxMenu* viewsubMenu = new wxMenu();
    //wxMenuItem* switchToCentury = viewsubMenu->Append(wxID_ANY, _("&To Century"));
    //for year view
    wxMenuItem* switchToYear = viewsubMenu->Append(wxID_ANY, _("&To Year"));
    Bind(wxEVT_MENU, &MainWindow::onswitchYear, this, switchToYear->GetId());

    wxMenuItem* switchToMonth = viewsubMenu->Append(wxID_ANY, _("&To Months"));
    Bind(wxEVT_MENU, &MainWindow::onswitchMonth, this, switchToMonth->GetId());

    optionsMenu->AppendSubMenu(viewsubMenu, _("Switch Views\tCtrl+S"));

    //help menu in menubar
    wxMenu* helpMenu = new wxMenu();
    menuBar->Append(helpMenu, _("&Help"));
    wxMenuItem* helpItem = helpMenu->Append(wxID_ANY, _("&Help\tCtrl+H"));
    Bind(wxEVT_MENU, &MainWindow::onHelp, this, helpItem->GetId());

    //set the Menu
    SetMenuBar(menuBar);

    //toolbar setup
    wxToolBar* toolBar = CreateToolBar();
    wxBitmap GeorgianBmp(Georgian_xpm);
    toolBar->AddTool(GeorgianItem->GetId(), _("Georgian Calendar"),GeorgianBmp ,_("Switch to Georgian Calendar"));
    wxBitmap DarianBmp(Darian_xpm);
    toolBar->AddTool(DarianItem->GetId(), _("Georgian Calendar"), DarianBmp, _("Switch to Darian Calendar"));
    wxBitmap MonthBmp(Month_xpm);
    toolBar->AddTool(switchToMonth->GetId(), _("Months View"), MonthBmp, _("Switch to Months view"));
    wxBitmap YearBmp(Year_xpm);
    toolBar->AddTool(switchToYear->GetId(), _("Year view"), YearBmp, _("Switch to Year View"));


    
    toolBar->AddTool(wxID_EXIT, _("QUIT"), wxArtProvider::GetBitmap("wxART_QUIT"),_("Quit"));
    toolBar->Realize();

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

    wxSleep(5);

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

    wxSleep(5);

    PopStatusText();
};

void MainWindow::onsetDate(wxCommandEvent& event)
{
    wxMessageBox("set date");
    PushStatusText(_("date set"));

    wxSleep(5);

    PopStatusText();
};

void MainWindow::onsetTime(wxCommandEvent& event)
{
    wxMessageBox("set time");
    PushStatusText(_("time set"));

    wxSleep(5);

    PopStatusText();
};

void MainWindow::onswitchYear (wxCommandEvent& event)
{
    wxMessageBox("Year View");
    PushStatusText(_("Year View Set"));

    wxSleep(5);

    PopStatusText();
};

void MainWindow::onswitchMonth(wxCommandEvent& event)
{
    wxMessageBox("Month View");
    PushStatusText(_("Month View Set"));

    wxSleep(5);

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