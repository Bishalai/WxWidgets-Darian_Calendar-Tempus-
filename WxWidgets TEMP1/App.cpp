/*

//---------------------------------------------------------------------------------------------------//

-----------------wxTEMP1 for the first template for the darian calendar-------------------------------------

--Done By Bishal Khand Thakuri AKA IchigoIchie and the group Tempus

//-------------------------------------------------------------------------------------------------------//

*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "App.h"

#include"MainWindow.h"




App::App()
{

}

bool App::OnInit()
{
	
	if (!wxApp::OnInit())
		return false;

	MainWindow* main = new MainWindow(nullptr, window::id::MAINWINDOW, _("DARIAN CALENDAR"));
	main->Show();
	

	return true;
}

IMPLEMENT_APP(App); //Main

App::~App()
{

};

//Tempus