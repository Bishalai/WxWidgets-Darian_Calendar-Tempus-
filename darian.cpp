#include "darian.h"
#include "wx/setup.h"

#define _CRT_SECURE_NO_WARNINGS
//#include "App.h"
//#include"id.h"



wxIMPLEMENT_APP(darian);    //program entry
darian::darian()
{
}
darian::~darian()
{

}
bool darian::OnInit()
{
	m_frame1 = new darianMain();
	m_frame1->Show();
	return true;
}
