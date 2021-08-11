#pragma once
#include "wx/wx.h"
#include<cstring>
class darianMain:public wxFrame
{
public:
	darianMain();
	~darianMain();
public: 

	
	 int nfieldWidth = 7;
	int nfieldHeight = 7;
	wxButton** btn;     //Array of pointter to buttons
	wxButton *button1 = nullptr;
	wxButton* butt = nullptr;

	//void OnButtonClicked(wxCommandEvent& evt); 
	


	
	wxDECLARE_EVENT_TABLE();

};


