#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"CalDateTime.h"
using namespace std;

class Darian_Date_Time;
class Gregorian_DateTime;

class Gregorian_DateTime 
{
protected:
	// reqired constants

	const float g_sol_day_ratio = 24.65979; //24 hours to 24 hours 39 minutes 35.244 seconds

	const float g_sols_per_year = 668.6; //sols in a year, taking  the 10 years has 6686 sols method

	const float g_sols_from_start = 138920.13356; //sols passed from 1609, start of darian calendar to 2000,1,1

	// the basic datetime members
	int g_year;
	int g_month;
	int g_day;
	int g_hour;
	int g_minute;
	int g_seconds;

	const string g_months_name[13] = {
		"LUL",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	
	};

	const string g_week_days[8] =
	{
		"Paiomon",
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};

	int g_months_size[13] =
	{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	const string g_seasons_name[5] = {
		"",
		"Winter",
		"Spring",
		"Summer",
		"Autumn"
	};

	// required array for darian conversion
	const int d_months_size[25] = { 0,
		28, 28, 28, 28, 28, 27,
		28, 28, 28, 28, 28, 27,
		28, 28, 28, 28, 28, 27,
		28, 28, 28, 28, 28, 27,
	};

public:

	// constructor
	Gregorian_DateTime();


	//set date
	void set_date(int yr, int mon, int day);

	//set time
	void set_time(int hr, int min, int sec);


	//set date time to current date and time taken from the gregorian one and then converted
	void set_now();

	// set the value for the basic memebers
	// set year
	void set_year(int y);
	// set month
	void set_month(int m);
	// set day
	void set_day(int d);
	// set hour
	void set_hour(int h);
	// set minute
	void set_minute(int m);
	// set seconds
	void set_seconds(int s);


	//get functions

	//basic memebers
	// return hour
	int get_hour();
	// return minute
	int get_minute();
	// return seconds
	int get_seconds();
	// return year
	int get_year();
	// return month
	int get_month();
	// return day
	int get_day();

	// get for other fucntions

	//season_name
	string get_season_name();
	//month name
	string get_month_name();
	//weekday name like sunday, monday, etc
	string get_weekday_name();

	//get corresponding input month name
	string get_input_month_name(int n);

	//get corresponding input week name
	string get_input_week_name(int n);
	

	//returns no of days in month
	int get_no_of_days_in_month();

	//no of months
	int get_no_of_months();


	// return first day of the month's weekday value; sunday, mondayand so on. till 7
	int get_firstday_month();

	// other functions

	//returns 1 if leap year and 0 if not
	bool check_leap_year();

	//chanegs the month value
	void next_month();
	void previous_month();


	// conversion functions;

	Darian_Date_Time convert_to_darian();

	// increase by a second
	void increase();


	//destructor
	~Gregorian_DateTime();


};


