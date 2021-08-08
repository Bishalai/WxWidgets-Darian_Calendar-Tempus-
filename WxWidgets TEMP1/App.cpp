#include "App.h"
#include"id.h"
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