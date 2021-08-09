#pragma once
#include<string>
class dCal {
protected:
    int dYear;
    std::string mMonths[25];
    std::string mWeekDays[8];
    int mDays[25];

public:
    dCal(void);
    void getYearly(int year);

    int marsgetNumberOfDays(int month, int year);
};

dCal::dCal(void) {
    mMonths[0] = "";    // month starts from 1
    mMonths[1] = "Sagittarius";
    mMonths[2] = "Dhanus";
    mMonths[3] = "Makara Capricornus	";
    mMonths[4] = "Aquarius Makara ";
    mMonths[5] = "Aquarius ";
    mMonths[6] = "Khumba";
    mMonths[7] = "Pisces";
    mMonths[8] = "Mina";
    mMonths[9] = "Aries";
    mMonths[10] = "Mesha";
    mMonths[11] = "Taurus";
    mMonths[12] = "Mishabha";
    mMonths[13] = "Gemini";
    mMonths[14] = "Mithuna ";
    mMonths[15] = "Cancer";
    mMonths[16] = "Karka";
    mMonths[17] = "Leo ";
    mMonths[18] = "Simha";
    mMonths[19] = "Virgo";
    mMonths[20] = "Kanya";
    mMonths[21] = "Libra";
    mMonths[22] = "Tula ";
    mMonths[23] = "Scorpius";
    mMonths[24] = "Vrishika";


    mDays[0] = 0;
    mDays[1] = 27;
    mDays[2] = 27;
    mDays[3] = 27;
    mDays[4] = 27;
    mDays[5] = 27;
    mDays[6] = 28;
    mDays[7] = 27;
    mDays[8] = 27;
    mDays[9] = 27;
    mDays[10] = 27;
    mDays[11] = 27;
    mDays[12] = 27;
    mDays[13] = 28;
    mDays[14] = 27;
    mDays[15] = 27;
    mDays[16] = 27;
    mDays[17] = 27;
    mDays[18] = 27;
    mDays[19] = 28;
    mDays[20] = 27;
    mDays[21] = 27;
    mDays[22] = 27;
    mDays[23] = 27;
    mDays[24] = 27;

    mWeekDays[0] = ""; //Sol Solis, Sol Lunae, Sol Martis, Sol Mercurii, Sol Jovis, Sol Veneris, Sol Saturni.
    mWeekDays[1] = "Solis";
    mWeekDays[2] = "Lunae";
    mWeekDays[3] = "Martis";
    mWeekDays[4] = "Mercurii";
    mWeekDays[5] = "Jovis";
    mWeekDays[6] = "Veneris";
    mWeekDays[7] = "Saturni";
}

void dCal::getYearly(int year)
{
    dYear = year;
    // year check
    if ((dYear % 4 == 0 && dYear % 100 != 0) || (dYear % 400 == 0))   // check accouding to georgian calander
        mDays[2] = 28;
}

int dCal::marsgetNumberOfDays(int month, int year)
    {
    if (month == 23)  // month 23rd has either 28/27 days accoring to geording calandar correspondance
        {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
                return 28; //leap year month>>2
            else if (month == 6 || month == 12 || month == 18)
                return 27;
            else
                return 28;
        }

