#pragma once
#include"CalDateTime.h"


class Gregorian_DateTime : public CalDateTime
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

	const int g_months_size[13] =
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

	//returns no of days in month
	int get_no_of_days_in_month();


	// return first day of the month's weekday value; sunday, mondayand so on. till 7
	string get_firstday_month();

	// other functions

	//returns 1 if leap year and 0 if not
	bool check_leap_year();

	//chanegs the month value
	void next_month();
	void previous_month();


	// conversion functions;

	Darian_Date_Time convert_to_darian();




	//destructor
	~Gregorian_DateTime();


};


Gregorian_DateTime::Gregorian_DateTime()
{
	// when first constructed set default values to 2000/1/1 00:00:01's 
	g_hour = 0;
	g_minute = 0;
	g_seconds = 1;

	g_year = 2000;
	g_month = 1;
	g_day = 1;
};



///set function

//set date
void Gregorian_DateTime::set_date(int yr, int mon, int day)
{
	set_year(yr);
	set_month(mon);
	set_day(day);
};

//set time
void Gregorian_DateTime::set_time(int hr, int min, int sec) 
{
	set_hour(hr);
	set_minute(min);
	set_seconds(sec);
};




// set year
void Gregorian_DateTime::set_year(int y)
{
	if (y > 3000) //to reduce bugs and error
	{
		g_year = 3000;
	}
	else if (y < 2000)
	{
		g_year = 2000;
	}
	else
	{
		g_year = y;
	}
};

// set month
void Gregorian_DateTime::set_month(int m) 
{
	if (m < 1)
	{
		g_month = 1;
	}
	else if (m > 12)
	{
		g_month = 24;
	}
	else
	{
		g_month = m;
	}
};

// set day
void Gregorian_DateTime::set_day(int d) 
{
	if (d < 1)
	{
		g_day = 1;
	}
	else if (check_leap_year() &&  g_month == 2)
	{
		if (d > (g_months_size[2] + 1))
		{
			g_day = g_months_size[2] + 1;
		}
		else
		{
			g_day = d;
		}
	}
	else if (d > g_months_size[g_month])
	{
		g_day = g_months_size[g_month];
	}
	else 
	{
		g_day = d;
	}
};

// set hour
void Gregorian_DateTime::set_hour(int h) 
{
	if (h < 0)
	{
		g_hour = 0;
	}
	else if (h >= 24)
	{
		g_hour = 23;
	}
	else
	{
		g_hour = h;
	}
};

// set minute
void Gregorian_DateTime::set_minute(int m) 
{
	if (m < 0)
	{
		g_minute= 0;
	}
	else if (m >= 60)
	{
		g_minute = 59;
	}
	else
	{
		g_minute = m;
	}
};

//set seconds
void Gregorian_DateTime::set_seconds(int s) 
{
	if (s < 0)
	{
		g_seconds = 0;
	}
	else if (s >= 60)
	{
		g_seconds = 59;
	}
	else
	{
		g_seconds = s;
	}
};


//set date time to current date and time taken from the gregorian one and then converted
void Gregorian_DateTime::set_now()
{
	wxDateTime dt_now = wxDateTime::Now();
	int   hour = static_cast<int>(dt_now.GetHour());
	int   minute = static_cast<int>(dt_now.GetMinute());
	int   seconds = static_cast<int>(dt_now.GetSecond());

	int year = static_cast<int>(dt_now.GetYear());
	int day = static_cast<int>(dt_now.GetDay());

	int daysofyear = static_cast<int>(dt_now.GetDayOfYear());// 1-366

	//since wxdatetime dont give month num, we find it out using days of year
	int i = 1;
	if (dt_now.IsLeapYear && daysofyear > 60)
	{
		daysofyear -= 1;
	}

	do
	{
		daysofyear -= g_months_size[i];
		i++;
	} while (daysofyear >= g_months_size[i]);

	int month = i;
	set_date(year, month, day);
	set_time(hour, minute, seconds);
};

/// get functions
// return hour
int Gregorian_DateTime::get_hour()
{
	return g_hour;
};
// return minute
int Gregorian_DateTime::get_minute()
{
	return g_minute;
};
// return seconds
int Gregorian_DateTime::get_seconds()
{
	return g_seconds;
};
// return year
int Gregorian_DateTime::get_year()
{
	return g_year;
};
// return month
int Gregorian_DateTime::get_month() 
{
	return g_month;
};

// return day
int Gregorian_DateTime::get_day()
{
	return g_day;
};

//season_name
string Gregorian_DateTime::get_season_name()
{
	if (g_month == 12 || g_month == 1 || g_month == 2)
	{
		return g_seasons_name[1];
	}
	else if (g_month >= 3 && g_month <= 5)
	{
		return g_seasons_name[2];
	}
	else if (g_month >= 6 && g_month <= 8)
	{
		return g_seasons_name[3];
	}
	else
	{
		return g_seasons_name[4];
	}

};
//month name
string Gregorian_DateTime::get_month_name() 
{
	return g_months_name[g_month];
};
//weekday name like sunday, monday, etc
string Gregorian_DateTime::get_weekday_name()
{
	int week_id = 7;
	week_id = week_id + g_day +(g_year - 2000)*365 + ((g_year - 2000) / 4);
		/// basically take count for changing weekday as it shifts by one/365 every year and by 2 for leap year, 
		//saturday - 7 for 2000 and basically add days for the months now.
	for (int i = 1; i < g_month; i++)
	{
		week_id += g_months_size[g_month];
	}
	week_id = week_id % 7;
	if (week_id != 0)
	{
		return g_week_days[week_id];
	}
	else
	{
		return g_week_days[7];
	}
};

//returns no of days in month
int Gregorian_DateTime::get_no_of_days_in_month() 
{
	if(check_leap_year()&& g_month==2)
	{
		return 29;
	}
	else
	{
		return g_months_size[g_month];
	}
};


// return first day of the month's weekday value; sunday, mondayand so on. till 7
string Gregorian_DateTime::get_firstday_month() 
{
	Gregorian_DateTime first_day_temp;
	first_day_temp.set_date(g_year, g_month, 1);
	return first_day_temp.get_weekday_name();
};



// as it says check leap year
bool Gregorian_DateTime::check_leap_year()
{
	if (g_year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};

//chanegs the month value
// change tp nect month
void Gregorian_DateTime::next_month()
{
	int g_month_next = g_month + 1;
	if (g_month_next > 12)
	{
		set_year(g_year + 1);
		set_month(1);
		set_day(g_day);
	}
	else
	{
		set_month(g_month + 1);
		set_day(g_day);
	}
};

// change to previous month
void Gregorian_DateTime::previous_month()
{
	int g_month_prev = g_month - 1;
	if (g_month_prev < 1)
	{
		set_year(g_year - 1);
		set_month(12);
		set_day(g_day);
	}
	else
	{
		set_month(g_month - 1);
		set_day(g_day);
	}
};



// conversion functions

Darian_Date_Time Gregorian_DateTime::convert_to_darian()
{
	Darian_Date_Time dt_temp;

	// convertinf them to hours span from 2000/1/1 0:00:01

	float totaldayshours;

	totaldayshours = ((g_year - 2000) * 365 + (g_year - 2000) / 4 + g_day -1 ) * 24; 
	// heere, accounting for years , leap years, day of the month

	for (int i = 1; i < g_month; i++) // for adding months passed
	{
		totaldayshours += (g_months_size[g_month])*24;
	}
	// for small time in a day
	totaldayshours += g_hour + (g_minute / 60) + (g_seconds / 360);

	// converting to sols days
	float totalsoldays = (totaldayshours / g_sol_day_ratio) + g_sols_from_start;

	// converting it into sol year
	float totalsolyear = totalsoldays / g_sols_per_year;

	//converting sol year to int
	int solyear = static_cast<int>(totalsolyear);

	// converting it into sols
	float totalsoldays = (totalsolyear - solyear) * 668.6;

	// converting to int
	int soldays = static_cast<int>(totalsoldays);

	// converting to hours of a sol
	float totalsolhour = (totalsoldays - soldays) * g_sol_day_ratio;

	int solhour = static_cast<int>(totalsolhour);

	float totalsolmin = (totalsolhour - solhour) * 60;

	int solmin = static_cast<int>(totalsolmin);

	float totalsolsec = (totalsolmin - solmin) * 60;

	int solsec = static_cast<int>(totalsolsec);
	
	
	int d_hour = solhour;// d_ to signify our d_value or final value
	
	int d_min = solmin;
	int d_sec = solsec;

	dt_temp.set_time(d_hour, d_min, d_sec);
	
	int i = 1;	// this to get the months of the darian calendar
	do
	{
		totalsoldays -= d_months_size[i];
		i++;
	} while (totalsoldays > d_months_size[i] );

	int d_month = i;
	int d_year = solyear;

	// to convert the daysofyear to day
	for (int j = 1; j < d_month; j++)
	{
		soldays -= d_months_size[j];
	}
	int d_day = soldays;

	dt_temp.set_date(d_year, d_month, d_day);

	return dt_temp;

};



Gregorian_DateTime::~Gregorian_DateTime()
{

};