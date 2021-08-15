#include "CalDateTime.h"

class Darian_Date_Time;

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
	if (d < 1)
	{
		d_sol = 1;
	}
	else if (check_leap_year() && d_month % 6 == 0)
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


// set date time to current date and time taken from the gregorian one and then converted
void Darian_Date_Time::set_now()
{
	Gregorian_DateTime dt_now;
	dt_now.set_now();

	Darian_Date_Time dt_temp = dt_now.convert_to_darian();

	set_time(dt_temp.get_hour(), dt_temp.get_minute(), dt_temp.get_seconds());
	set_date(dt_temp.get_year(), dt_temp.get_month(), dt_temp.get_sol());

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
	if (check_leap_year() && d_month % 6 == 0)
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
	else if (d_year % 10 == 0)
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
	int d_month_prev = d_month - 1;
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



// conversion function darian to gregorian
Gregorian_DateTime Darian_Date_Time::convert_to_Gregorian()
{
	Gregorian_DateTime dt_temp;

	// convert to sols

	float totalsols = (d_sol + (d_year * d_sols_per_year) + (d_hour / 24) + (d_minute / 24 / 60) + (d_seconds / 24 / 60 / 60));

	for (int i = 1; i < d_month; i++)
	{
		totalsols += d_months_size[i];
	}

	totalsols -= d_sols_from_start;// changes the sols from start to 2000

	// sols into hour;

	totalsols = totalsols * d_sol_day_ratio;                           

	// into days
	totalsols = totalsols / 24;

	float totaldays = totalsols;


	// totaldays into years

	float totalyear = totaldays / 365;

	// int year
	int g_year = static_cast<int>(totalyear);

	// now for months
	float totaldaysofyear = (totalyear - g_year) * 365;

	//daysof year into month

	int g_month;
	if (g_year % 4 == 0 && totaldaysofyear > 60)
	{

		int i =3;
		do
		{
			totaldaysofyear -= g_months_size[i];
			i++;
		} 
		while (totaldaysofyear > g_months_size[i]);

		 g_month = i;
	}
	else
	{
		int i = 1;
		do
		{
			totaldaysofyear -= g_months_size[i];
			i++;
		}
		while (totaldaysofyear > g_months_size[i]);

		 g_month = i;
	}

	int g_day = static_cast<int>(totaldaysofyear);

	float hour = (totaldaysofyear - g_day)*24;

	int g_hour = static_cast<int>(hour);

	float min = (hour - g_hour) * 60;

	int g_min = static_cast<int>(min);

	float sec = (min - g_min) * 60;

	int g_sec = static_cast<int>(sec);

	dt_temp.set_date(g_year, g_month, g_day);
	dt_temp.set_time(g_hour, g_min, g_sec);

	return dt_temp;
};

void Darian_Date_Time::increase()
{
	d_seconds += 1;
	d_minute += d_seconds / 60;
	d_minute += d_seconds / 60;
	d_seconds = d_seconds % 60;
	d_minute = d_minute % 60;
	d_hour = d_hour % 24;

};

string Darian_Date_Time::get_input_month_name(int n)
{
	return d_months_name[n];
};

//get corresponding input month name
string Darian_Date_Time::get_input_week_name(int n)
{
	return d_week_days[n];
};



int Darian_Date_Time::get_no_of_months()
{
	return 24;
};

Darian_Date_Time::~Darian_Date_Time()
{

}