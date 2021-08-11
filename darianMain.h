

#pragma once
#include "wx/wx.h"
#include<cstring>
#include<wx/display.h>
#include <wx/bmpbuttn.h>
#include <wx/stattext.h>
#include "wx/checkbox.h"
#include "wx/bmpbuttn.h"



#pragma once /////////////////////////

#include<wx/wxprec.h>
#include<string>
//#include"datetime.h"
#include <wx/artprov.h>
//#include "datetime.h"
#include "Georgian.xpm"
#include "Darian.xpm"
#include "Month.xpm"
#include "Year.xpm"
#include "Icon.xpm"
#include "Date.xpm"
#include "Time.xpm"
#include<wx/display.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif ///////////////////





class darianMain :public wxFrame
{
public:
	darianMain();
	~darianMain();
public:


	int nfieldWidth = 7;
	int nfieldHeight = 7;
	wxButton** btn;     //Array of pointter to buttons
	//wxButton* button1 ;
	wxButton* butt ;








	///////////////////////////

	void onGeorgian(wxCommandEvent& event);
	void onDarian(wxCommandEvent& event);
	void onQuit(wxCommandEvent& event);
	void onHelp(wxCommandEvent& event);
	void onsetDate(wxCommandEvent& event);
	void onsetTime(wxCommandEvent& event);
	void onswitchYear(wxCommandEvent& event);
	void onswitchMonth(wxCommandEvent& event);

	void onClose(wxCloseEvent& event);

	////////////////////////////////////////////


	wxDECLARE_EVENT_TABLE();

};




