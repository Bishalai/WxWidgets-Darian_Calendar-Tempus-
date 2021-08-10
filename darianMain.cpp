#include "darianMain.h"
wxBEGIN_EVENT_TABLE(darianMain,wxFrame) // macros to bind the buttons events
//EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()
 


darianMain::darianMain() :wxFrame(nullptr, wxID_ANY, "Calander", wxPoint(50, 50), wxSize(800, 600))
{
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
	
	wxPanel* panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel_top->SetBackgroundColour(wxColor(100, 120, 200));

	wxPanel* panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel_bottom->SetBackgroundColour(wxColor(100, 300, 100));


	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(panel_top, 1, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);
	sizer->Add(panel_bottom, 2, wxEXPAND | wxALL, 10);

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
			btn[j * nfieldHeight + i] = new wxButton(panel_top, 10000 + (j * nfieldWidth + i));
			grid->Add(btn[j * nfieldWidth + i], 1, wxEXPAND | wxRight);

		}
	}

	panel_top->SetSizer(grid);
	grid->Layout();

	this->SetSizerAndFit(sizer);


	
	
}
darianMain::~darianMain()
{
	 delete []btn;


}


