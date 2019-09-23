#include "structs.h"

int structs_isDate(sDate date)
{
    int returnValue = 0;

    if(date.year >= YEAR_MIN && date.year <= YEAR_MAX
        && date.month >= MONTH_MIN && date.month <= MONTH_MAX)
    {
        switch (date.month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(date.day >= DAY_MIN && date.day <= DAY_31)
                {
                    returnValue = 1;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(date.day >= DAY_MIN && date.day <= DAY_30)
                {
                    returnValue = 1;
                }
                break;
            case 2:
                if((date.year % 4 == 0 && date.day >= DAY_MIN && date.day <= DAY_29)
                    || (date.year % 4 != 0 && date.day >= DAY_MIN && date.day <= DAY_28))
                {
                    returnValue = 1;
                }
                break;
        }
    }

    return returnValue;
}

int structs_dateCompare(sDate date1, sDate date2)
{
    int returnValue = -2;

    if(structs_isDate(date1) && structs_isDate(date2))
    {
        if(date1.year > date2.year)
        {
            returnValue = 1;
        }
        else
        {
            if(date1.year < date2.year)
            {
                returnValue = -1;
            }
            else
            {
                if(date1.month > date2.month)
                {
                    returnValue = 1;
                }
                else
                {
                    if(date1.month < date2.month)
                    {
                        returnValue = -1;
                    }
                    else
                    {
                        if(date1.day > date2.day)
                        {
                            returnValue = 1;
                        }
                        else
                        {
                            if(date1.day < date2.day)
                            {
                                returnValue = -1;
                            }
                            else
                            {
                                returnValue = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return returnValue;
}

int structs_swapDate(sDate* date1, sDate* date2)
{
    int returnValue = -1;
    sDate aux1;
    sDate aux2;

    aux1 = *date1;
    aux2 = *date2;
    *date1 = *date2;
    *date2 = aux1;

    if(!structs_dateCompare(*date1, aux2) && !structs_dateCompare(*date2, aux1))
    {
        returnValue = 0;
    }

    return returnValue;
}
