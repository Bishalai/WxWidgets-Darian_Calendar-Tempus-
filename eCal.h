#pragma once
#include<string>
class eCal
{
public:
    int hour, min, sec;
    int mYear;
    std::string mMonths[13];
    std::string mWeekDays[8];
    int mDays[13];
    int firstDayOfMonth(int , int );

public:
    eCal(void);                 // for date
    void getYearly(int year);

    eCal();
    eCal(int, int, int);  // for time 
    void setTime(int, int, int);
    void getTime();

    int  getNumberOfDays(int month, int year);
    void exception_handling(void);
    void to_dofunc();
};

eCal::eCal(void) {
   // mMonths[0] = "";    // month starts from 1
    mMonths[1] ="January";
    mMonths[2] = "February";
    mMonths[3] = "March";
    mMonths[4] = "April";
    mMonths[5] = "May";
    mMonths[6] = "June";
    mMonths[7] = "July";
    mMonths[8] = "August";
    mMonths[9] = "September";
    mMonths[10] = "October";
    mMonths[11] = "November";
    mMonths[12] = "December";

    mDays[0] = 0;
    mDays[1] = 31;
    mDays[2] = 28;
    mDays[3] = 31;
    mDays[4] = 30;
    mDays[5] = 31;
    mDays[6] = 30;
    mDays[7] = 31;
    mDays[8] = 31;
    mDays[9] = 30;
    mDays[10] = 31;
    mDays[11] = 30;
    mDays[12] = 31;

    //mWeekDays[0] = " ";
    mWeekDays[1] = "Sun";
    mWeekDays[2] = "Mon";
    mWeekDays[3] = "Tue";
    mWeekDays[4] = "Wed";
    mWeekDays[5] = "Thu";
    mWeekDays[6] = "Fri";
    mWeekDays[7] = "Sat";
}
//Using a standard c++ algorithm to find day of week for a date
int eCal::firstDayOfMonth(int month, int year) //dow = day of week, sun =0, mon=1
{
    int dow = 0;
    int day = 1;
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    dow = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    return dow;
}

void eCal::getYearly(int year)
{
    mYear = year;
    // leap year check
    if ((mYear % 4 == 0 && mYear % 100 != 0) || (mYear % 400 == 0))
        mDays[2] = 29;
}

int eCal::getNumberOfDays(int month, int year)
{
    
    if (month == 2)
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29; //leap year month>>2
        else
            return 28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
        || month == 10 || month == 12)
        return 31;     //moth >>31 days
    else
        return 30;
    }

eCal::eCal()  //time conatructor
{
    hour = 0;
    min = 0;
    sec = 0;
}

void eCal::setTime(int h, int m, int s)

{
    hour = (h >= 0 && h < 24) ? h : 0;
    min = (m >= 0 && m < 60) ? m : 0;
    sec = (s >= 0 && s < 60) ? s : 0;
}


void eCal::to_dofunc(void)
{

}

void eCal::getTime()
{
   }

void eCal::exception_handling()
{
}



