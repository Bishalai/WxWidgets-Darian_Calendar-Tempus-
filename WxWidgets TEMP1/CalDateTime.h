#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string>
#include "datetime.h"
#include "Gregorian_DateTime.h"


using namespace std;




class Gregorian_DateTime;


// class dor darian calendar
class Darian_Date_Time 
{
protected:
	// reqired constants

	const float d_sol_day_ratio = 24.65979; //24 hours to 24 hours 39 minutes 35.244 seconds

	const float d_sols_per_year = 668.6; //sols in a year, taking  the 10 years has 6686 sols method

	const float d_sols_from_start = 138920.13356; //sols passed from 1609, start of darian calendar to 2000,1,1

	// the basic datetime members
	int d_year;
	int d_month;
	int d_sol;
	int d_hour;
	int d_minute;
	int d_seconds;

	//array for the month names
	const string d_months_name[25] = {
		"KEKW",
		"Sagittarius",
		"Dhanus",
		"Capricornus",
		"Makara",
		"Aquarius",
		"Khumba",
		"Pisces",
		"Mina",
		"Aries",
		"Mesha",
		"Taurus",
		"Mishabha",
		"Gemini",
		"Mithuna",
		"Cancer",
		"Karka",
		"Leo",
		"Simha",
		"Virgo",
		"Kanya",
		"Libra",
		"Tula",
		"Scorpius",
		"Vrishika"
	};

	// array for names in a week
	const string d_week_days[8] = {
		"POG",
		"Solis",
		"Lunae",
		"Martis",
		"Mercurii",
		"Jovis",
		"Veneris",
		"Saturni"
	};

	//array for months size
	const int d_months_size[25] = { 0,
		28, 28, 28, 28, 28, 27,
		28, 28, 28, 28, 28, 27,
		28, 28, 28, 28, 28, 27,
		28, 28, 28, 28, 28, 27,
	};

	//array to store seasons name
	const string d_seasons_name[5] = {
		"",
		"Winter",
		"Autumn",
		"Summer",
		"Spring"
	};
	const int g_months_size[13] =
	{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

public:

	//..constructor
	Darian_Date_Time();

	// set functions defined within class

	//set date
	void set_date(int yr, int mon, int day);

	//set time
	void set_time(int hr, int min, int sec);


	//set date time to current date and time taken from the gregorian one and then converted
	void set_now();

	// set the value for the basic memebers
	void set_year(int y);
	void set_month(int m);
	void set_sol(int d);
	void set_hour(int h);
	void set_minute(int m) ;
	void set_seconds(int s);


	//get functions

	//basic memebers
	int get_hour();
	int get_minute();
	int get_seconds();
	int get_year();
	int get_month();
	int get_sol();

	// get for other fucntions

	//season_name
	string get_season_name();
	//month name
	string get_month_name();
	//weekday name like solis, lunae, etc
	string get_weekday_name();

	//returns no of sols in month
	int get_no_of_days_in_month();


	// return first day of the month's weekday value; solis, lunae and so on. till 7
	string get_firstday_month();

	// other functions

	//returns 1 if leap year and 0 if not
	bool check_leap_year();

	//chanegs the month value
	void next_month();
	void previous_month();


	// get the no of months
	int get_no_of_months();

	// conversion functions;
	Gregorian_DateTime convert_to_Gregorian();



	//..destructor
	~Darian_Date_Time();

};




