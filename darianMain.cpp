#include "darianMain.h"

wxBEGIN_EVENT_TABLE(darianMain, wxFrame) // macros to bind the buttons events
//EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

darianMain::darianMain() :wxFrame(nullptr, wxID_ANY, "Calander", wxPoint(50, 50), wxSize(400, 300))
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
	wxMenuItem* GeorgianItem = HomeMenu->Append(wxID_ANY, _("&Georgian\tCtrl+X"));
	GeorgianItem->SetBitmap(GeorgianBmp);
	Bind(wxEVT_MENU, &darianMain::onGeorgian, this, GeorgianItem->GetId());

	//darian menu item
	wxBitmap DarianBmp(Darian_xpm);
	wxMenuItem* DarianItem = HomeMenu->Append(wxID_ANY, _("&Darian\tCtrl+C"));
	DarianItem->SetBitmap(DarianBmp);
	Bind(wxEVT_MENU, &darianMain::onDarian, this, DarianItem->GetId());

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
	Bind(wxEVT_MENU, &darianMain::onsetDate, this, setDate->GetId());

	//set time
	wxBitmap TimeBmp(Time_xpm);
	wxMenuItem* setTime = optionsMenu->Append(wxID_ANY, _("&Set Time\tCtrl+T"));
	setTime->SetBitmap(TimeBmp);
	Bind(wxEVT_MENU, &darianMain::onsetTime, this, setTime->GetId());

	optionsMenu->AppendSeparator();

	//view submenu in options
	wxMenu* viewsubMenu = new wxMenu();


	//for year view
	wxBitmap YearBmp(Year_xpm);
	wxMenuItem* switchToYear = viewsubMenu->Append(wxID_ANY, _("&To Year"));
	switchToYear->SetBitmap(YearBmp);
	Bind(wxEVT_MENU, &darianMain::onswitchYear, this, switchToYear->GetId());

	//month view
	wxBitmap MonthBmp(Month_xpm);
	wxMenuItem* switchToMonth = viewsubMenu->Append(wxID_ANY, _("&To Months"));
	switchToMonth->SetBitmap(MonthBmp);
	Bind(wxEVT_MENU, &darianMain::onswitchMonth, this, switchToMonth->GetId());

	optionsMenu->AppendSubMenu(viewsubMenu, _("Switch Views\tCtrl+S"));

	//help menu in menubar
	wxMenu* helpMenu = new wxMenu();
	menuBar->Append(helpMenu, _("&Help"));

	//help item
	wxMenuItem* helpItem = helpMenu->Append(wxID_HELP);
	helpItem->SetBitmap(wxArtProvider::GetBitmap("wxART_HELP", wxART_OTHER, wxSize(16, 16)));
	Bind(wxEVT_MENU, &darianMain::onHelp, this, helpItem->GetId());

	//set the Menu
	SetMenuBar(menuBar);

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
	toolBar->AddTool(helpItem->GetId(), _("Help"), helpItem->GetBitmap(), _("Help"));

	toolBar->Realize();

	/*
	   btn = new wxButton * [nfieldWidth * nfieldHeight];
	   wxGridSizer* grid = new wxGridSizer(nfieldWidth, nfieldHeight,0, 0);
	   for (int i = 0; i < nfieldWidth; i++)
	   {
		   for (int j=0; j<nfieldHeight; j++)
		   {
			   btn[j * nfieldHeight + i]= new wxButton(this, 10000 + (j * nfieldWidth + i));
			   grid->Add(btn[j * nfieldWidth + i], 1, wxEXPAND | wxALL);

		   }
	   }

	   this->SetSizer(grid);
	   grid->Layout();
		*/
		/*

		wxPanel* panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
		panel_top->SetBackgroundColour(wxColor(100, 120, 200));

		wxPanel* panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
		panel_bottom->SetBackgroundColour(wxColor(100, 300, 100));

		wxPanel* panel_topright = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
		panel_topright->SetBackgroundColour(wxColor(100, 120, 200));

		wxPanel* panel_topleft = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
		panel_topleft->SetBackgroundColour(wxColor(100, 120, 200));

		wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
		sizer->Add(panel_top, 5, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);


		wxSizer* sizer_top = new wxBoxSizer(wxHORIZONTAL);
		sizer_top->Add(panel_topleft, 1, wxEXPAND, 0);
		sizer_top->Add(panel_topright, 1, wxEXPAND, 0);

		 sizer->Add(panel_bottom, 1, wxEXPAND | wxALL, 10);

		wxSizer* sizer_bottom = new wxBoxSizer(wxVERTICAL);
		wxSizer* sizer_centering = new wxBoxSizer(wxHORIZONTAL);

		button1 = new wxButton(panel_top, wxID_ANY, wxT("prev"), wxPoint(0, 70), wxSize(60, 20));
		butt = new wxButton(panel_top, wxID_ANY, "next", wxPoint(70, 70), wxSize(60, 20));
		butt->SetParent(panel_top);

		sizer_bottom->Add(sizer_centering, 1, wxALIGN_CENTER);
		panel_bottom->SetSizerAndFit(sizer_bottom);


		btn = new wxButton * [nfieldWidth * nfieldHeight];
		wxGridSizer* grid = new wxGridSizer(nfieldWidth, nfieldHeight, 2.5, 2.50);
		for (int i = 0; i < nfieldWidth; i++)
		{
			for (int j = 0; j < nfieldHeight; j++)
			{
				btn[j * nfieldHeight + i] = new wxButton(panel_topright, 10000 + (j * nfieldWidth + i));
				grid->Add(btn[j * nfieldWidth + i], 1, wxEXPAND | wxRight);

			}
		}

		panel_topright->SetSizer(grid);
		grid->Layout();

		this->SetSizerAndFit(sizer);

		*/





	

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
	panel_left->SetBackgroundColour(wxColor(100,150,200));

	wxPanel* panel_lefttop = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
	panel_lefttop->SetBackgroundColour(wxColor(0, 0, 0));

	wxButton* prevbutton = new wxButton(panel_left, wxID_ANY, "prev", wxPoint(120, 0), wxDefaultSize);

	//wxBitmap bitmap;
	//bitmap.LoadFile("‪D:\Photos\Messenger\123.jpeg", wxBITMAP_TYPE_JPEG);                                        //  //bitmapbutton didnt load :/
	//wxBitmapButton* button12 = new wxBitmapButton(panel_left, -1, bitmap, wxPoint(0, 0), wxSize(50, 50), 0);


	wxStaticText* text_ofdate1 = new wxStaticText(panel_left, wxID_ANY, "DATE :", wxPoint(20, 80));
	wxStaticText* text_oftime = new wxStaticText(panel_left, wxID_ANY, "TIME :", wxPoint(20, 120));
	wxStaticText* text_ofseason = new wxStaticText(panel_left, wxID_ANY, "Season :", wxPoint(20, 160));

	wxPanel* panel_rightbottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
	panel_rightbottom->SetBackgroundColour(wxColor(0, 0,0));
	wxButton* bottonarightbottom = new wxButton(panel_rightbottom, wxID_ANY, "to do list (opt)", wxPoint(40,0), wxDefaultSize);

	wxPanel* panel_topright = new wxPanel(this, wxID_ANY, wxDefaultPosition, appwinsize, wxTAB_TRAVERSAL, _("Top"));
	panel_topright->SetBackgroundColour(wxColor(100, 100, 110));
	wxButton* toprightbottom1 = new wxButton(panel_topright, wxID_ANY, " Next ", wxPoint(0, 0), wxDefaultSize);

	  //bitmapbutton didnt load :/

	wxStaticText* calander_checkbox = new wxStaticText(panel_topright, wxID_ANY, "calander", wxPoint(20, 60));
    wxCheckBox* checkbox1 = new wxCheckBox(panel_topright, wxID_ANY, wxT("Georgian"), wxPoint(20,80), wxDefaultSize); 
	checkbox1->SetValue(true);
    wxCheckBox* checkbox2 = new wxCheckBox(panel_topright, wxID_ANY, wxT("Darian"), wxPoint(20,100), wxDefaultSize);
	checkbox2->SetValue(true);

	wxStaticText* view_checkbox = new wxStaticText(panel_topright, wxID_ANY, "view", wxPoint(20, 140));
	wxCheckBox* checkbox3 = new wxCheckBox(panel_topright, wxID_ANY, wxT("month"), wxPoint(20, 160), wxDefaultSize);
	checkbox3->SetValue(true);
	wxCheckBox* checkbox4 = new wxCheckBox(panel_topright, wxID_ANY, wxT("year"), wxPoint(20, 180), wxDefaultSize);
	checkbox4->SetValue(true);

	Sizer->Add(panel_left, 1, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 5);
	Sizer->Add(panel_lefttop, 3, wxEXPAND | wxTOP ,5);
	sizer_top->Add(panel_topright, 4, wxEXPAND  | wxRIGHT, 5);

	sizer_top->Add(panel_rightbottom, 2, wxEXPAND | wxTOP | wxRIGHT, 5);
    Sizer->Add(sizer_top, 1, wxEXPAND | wxLEFT, 5);


	
	wxSize calsize = wxSize(appwinsize.GetWidth() / 2, appwinsize.GetHeight() / 2);
	wxSize cellsize = wxSize(calsize.GetWidth() / 20, calsize.GetHeight() / 7);

	wxMessageDialog* dial = new wxMessageDialog(NULL, wxT("you are totally fucked mf!!"), wxT("hahahahahahahahahah"), wxOK | wxICON_ERROR);

	dial->ShowModal();
	
	// month  view 
	
	wxGridSizer* gs = new wxGridSizer(6, 7, cellsize);
	

	gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
	gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
	gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

	gs->Add(new wxButton(panel_lefttop, -1, _("month,year ")), 1, wxEXPAND);

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
	gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);
	gs->Add(new wxStaticText(panel_lefttop, -1, wxT("")), 0, wxEXPAND);

	for (int i = 1; i < 30; i++)
	{
		wxString day_count = wxString::Format(wxT("%i"), i);
		gs->Add(new wxButton(panel_lefttop, this->GetId(), day_count), 0, wxEXPAND);
	}
	//buttons:
	panel_lefttop->SetSizerAndFit(gs);

	

	/**
	//for year view (georgian)
	wxSize cellsizeyearviewGeorgian = wxSize(calsize.GetWidth() / 20, calsize.GetHeight() / 7);
	wxGridSizer* gs1 = new wxGridSizer(3, 4, cellsizeyearviewGeorgian);

	gs1->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);
	gs1->Add(new wxButton(panel_lefttop, 0, _("year show")), 1, wxEXPAND);
	gs1->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);
	

	
	for (int j = 1; j < 13; j++)                                            //import months name from datetime class(georgian)
	{
		wxString georgianmonth_count = wxString::Format(wxT("%j"), j);
		gs1->Add(new wxButton(panel_lefttop, this->GetId(), georgianmonth_count), 0, wxEXPAND);
	}
    //buttons:
	panel_lefttop->SetSizerAndFit(gs1);

*/

	/**
	
		//year view for Darian:
	wxSize cellsizeyearviewDarian = wxSize(calsize.GetWidth() / 2, calsize.GetHeight() / 7);
	wxGridSizer* gs2 = new wxGridSizer(5, 7, cellsizeyearviewDarian);

	gs2->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);
	gs2->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);
	gs2->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);

	gs2->Add(new wxButton(panel_lefttop, 0, _("like 2007")), 1, wxEXPAND);
	gs2->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);
	gs2->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);
	gs2->Add(new wxStaticText(panel_lefttop, 0, wxT("")), 0, wxEXPAND);


	for (int k = 1; k < 25; k++)                                            //import monrhs name from datetime class(darian)
	{
		wxString Darianmonth_count = wxString::Format(wxT("%k"), k);
		gs2->Add(new wxButton(panel_lefttop, this->GetId(), Darianmonth_count), 0, wxEXPAND);
	}

	//buttons:
	panel_lefttop->SetSizerAndFit(gs2);

	*/



    //setting sizer
	SetSizerAndFit(Sizer);


	//statusbar
	wxDateTime dt = wxDateTime::Now();
	const int status_size = 3;
	wxStatusBar* statusBar = CreateStatusBar(status_size);
	statusBar->SetStatusText(_("Ready!"), 0);
	statusBar->SetStatusText(_(dt.FormatDate()), 1);
	statusBar->SetStatusText(_("Tempus!"), 2);
	int status_width[status_size] = { -4,-4,-1 };
	statusBar->SetStatusWidths(status_size, status_width);
}


darianMain::~darianMain()
{
	delete[] btn;


}


