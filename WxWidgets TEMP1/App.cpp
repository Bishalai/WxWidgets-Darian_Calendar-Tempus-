#define _CRT_SECURE_NO_WARNINGS
#include "App.h"

#include"MainWindow.h"


IMPLEMENT_APP(App); //Main

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

App::~App()
{

};