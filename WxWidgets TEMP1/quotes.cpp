#include "quotes.h"
#include <ctime>

quotes::quotes()
{

};



string quotes::get_quote(int n)
{
    //returns a quote for a month, total 24+12+2+1 quotes// uses only from 1- 38
    int entry = 1;
    if (n < 0)
    {
        return quotations[1];
    }
    else if (n > 38)
    {
        return quotations[38];
    }
    else
    {
        return quotations[n];
    }


};




quotes::~quotes()
{

};

//Tempus