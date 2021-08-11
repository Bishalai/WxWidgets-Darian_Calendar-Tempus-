#pragma once

#include<string>
#include "MainWindow.h"
#include "Gregorian_DateTime.h"


using namespace std;


class CalDateTime
{
public:

	// abstract class for datetime
};


// class dor darian calendar
class Darian_Date_Time : public CalDateTime
{
protected:
	// reqired constants

	const float d_sol_year_ratio = 24.68979; //24 hours to 24 hours 39 minutes 35.244 seconds

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


	// conversion functions;




	//..destructor
	~Darian_Date_Time();

};

// first doing set functions:



Darian_Date_Time::Darian_Date_Time()
{
	// when first constructed set default values to 2000/1/1 00:00:01's darian counterpart
	d_hour = 3;
	d_minute = 12;
	d_seconds = 20;

	d_year = 207;
	d_month = 19;
	d_sol = 22;

}

void Darian_Date_Time::set_year(int y) {
	if (y > 739) //to reduce bugs and error
	{
		d_year = 739;
	}
	else if (y < 207)
	{
		d_year = 207;
	}
	else
	{
		d_year = y;
	}
};


//for darian month
void Darian_Date_Time::set_month(int m) {
	if (m < 1)
	{
		d_month = 1;
	}
	else if (m > 24)
	{
		d_month = 24;
	}
	else
	{
		d_month = m;
	}
};

// for darian day
void Darian_Date_Time::set_sol(int d)
{
	if(d<1)
	{
		d_sol = 1;
	}
	else if (check_leap_year() && d_month%6 == 0)
	{
		if (d > (d_months_size[d_month] + 1))
		{
			d_sol = d_months_size[d_month] + 1;
		}
		else
		{
			d_sol = d;
		}
	}
	else if (d > d_months_size[d_month])
	{
		d_sol = d_months_size[d_month];
	}
	else 
	{
		d_sol = d;
	}
	
};


//for darian hour
void Darian_Date_Time::set_hour(int h)
{
	if (h < 0)
	{
		d_hour = 0;
	}
	else if (h > 24)
	{
		d_hour = 24;
	}
	else
	{
		d_hour = h;
	}
};

// a darian day has 24hr 39 minutes 35 seconds so extra conditions
//for darian minute
void Darian_Date_Time::set_minute(int m)
{
	if (d_hour != 24)
	{
		if (m < 0)
		{
			d_minute = 0;
		}
		else if (m > 59)
		{
			d_minute = 59;
		}
		else
		{
			d_minute = m;
		}
	}
	else
	{
		if (m < 0)
		{
			d_minute = 0;
		}
		else if (m > 39)
		{
			d_minute = 39;
		}
		else
		{
			d_minute = m;
		}
	}
};


// for darian seconds
void Darian_Date_Time::set_seconds(int s)
{
	if (d_hour != 24 && d_minute != 39)
	{
		if (s < 0)
		{
			d_seconds = 0;
		}
		else if (s > 59)
		{
			d_seconds = 59;
		}
		else
		{
			d_seconds = s;
		}
	}
	else
	{
		if (s < 0)
		{
			d_seconds = 0;
		}
		else if (s > 35)
		{
			d_seconds = 35;
		}
		else
		{
			d_seconds = s;
		}
	}
};


//set date
void Darian_Date_Time::set_date(int yr, int mon, int day)
{
	set_year(yr);
	set_month(mon);
	set_sol(day);
};

//set time
void Darian_Date_Time::set_time(int hr, int min, int sec)
{
	set_hour(hr);
	set_minute(min);
	set_seconds(sec);
};



//get functions now defined
int Darian_Date_Time::get_hour()
{
	return d_hour;
};
int Darian_Date_Time::get_minute()
{
	return d_minute;
};
int Darian_Date_Time::get_seconds()
{
	return d_seconds;
};
int Darian_Date_Time::get_year()
{
	return d_year;
};
int Darian_Date_Time::get_month()
{
	return d_month;
};
int Darian_Date_Time::get_sol()
{
	return d_sol;
};



//season_name
string Darian_Date_Time::get_season_name()
{
	if (d_month >= 1 && d_month <= 6)
	{
		return d_seasons_name[1];
	}
	else if (d_month >= 7 && d_month <= 12)
	{
		return d_seasons_name[2];
	}
	else if (d_month >= 13 && d_month <= 18)
	{
		return d_seasons_name[3];
	}
	else if (d_month >= 19 && d_month <= 24)
	{
		return d_seasons_name[4];
	}
};
//month name
string Darian_Date_Time::get_month_name()
{
	return d_months_name[d_month];

};
//weekday name like solis, lunae, etc
string Darian_Date_Time::get_weekday_name()
{
	int week_id = d_sol % 7;
	week_id;
	if (week_id != 0)
	{
		return d_week_days[week_id];
	}
	else
	{
		return d_week_days[7];
	}
};

//returns no of sols in month
int Darian_Date_Time::get_no_of_days_in_month()
{
	if (check_leap_year && d_month%6 == 0)
	{
		return d_months_size[d_month] + 1;
	}
	else
	{
		return d_months_size[d_month];
	}

};


// return first day of the month's weekday value; solis, lunae and so on. till 7
string Darian_Date_Time::get_firstday_month()
{
	return d_week_days[1];
};




// check for leap year
bool Darian_Date_Time::check_leap_year()
{
	if (d_year % 2 != 0)
	{
		return true;
	}
	else if(  d_year%10 == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}

};


//chanegs the month value
void Darian_Date_Time::next_month()
{
	int d_month_next = d_month + 1;
	if (d_month_next > 24)
	{
		set_year(d_year + 1);
		set_month(1);
		set_sol(d_sol);
	}
	else
	{
		set_month(d_month + 1);
		set_sol(d_sol);
	}

};
void Darian_Date_Time::previous_month()
{
	int d_month_prev = d_month -1;
	if (d_month_prev < 1)
	{
		set_year(d_year - 1);
		set_month(24);
		set_sol(d_sol);
	}
	else
	{
		set_month(d_month - 1);
		set_sol(d_sol);
	}
};


Darian_Date_Time::~Darian_Date_Time()
{

}


