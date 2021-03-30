#include<iostream>
#include<string>
#include<math.h>
#include "myDate.h"

using namespace std;

int Greg2Julian(int month, int day, int year)
{
    int jd = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12)/ 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
    return jd;
}

void Julian2Greg(int JD, int &month, int &day, int &year)
{
    int i;
    int j;
    int k;
    int l = JD + 68569;
    int n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    year = i;
    month = j;
    day = k;
}

myDate::myDate()
{
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
    if(m > 12)
    {
        month = 5;
        day = 11;
        year = 1959;
    }else if(d > 31)
    {
        month = 5;
        day = 11;
        year = 1959;
    }
}
/*
int myDate::Greg2Julian(int month, int day, int year)
{
    int jd = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12)/ 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
    return jd;
}

void myDate::Julian2Greg(int JD, int &month, int &day, int &year)
{
    int i;
    int j;
    int k;
    int l = JD + 68569;
    int n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    j = 80 * l / 2447;
    k = l - 2447 * j / 80;
    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n - 49) + i + l;

    year = i;
    month = j;
    day = k;
}
*/

void myDate::display()
{
    string m;
    if(month == 1)
    {
        m = "January";
    }
    else if(month == 2)
    {
        m = "February";
    }
    else if(month == 3)
    {
        m = "March";
    }
    else if(month == 4)
    {
        m = "April";
    }
    else if(month == 5)
    {
        m = "May";
    }
    else if(month == 6)
    {
        m = "June";
    }
    else if(month == 7)
    {
        m = "July";
    }
    else if(month == 8)
    {
        m = "August";
    }
    else if(month == 9)
    {
        m = "September";
    }
    else if(month == 10)
    {
        m = "October";
    }
    else if(month == 11)
    {
        m = "November";
    }
    else if(month == 12)
    {
        m = "December";
    }
    cout << m << " " << day << ", " << year;
}

void myDate::increaseDate(int n)
{
    int jd = Greg2Julian(month, day, year);
    jd += n;
    Julian2Greg(jd, month, day, year);
}

void myDate::decreaseDate(int n)
{
    int jd = Greg2Julian(month, day, year);
    jd -= n;
    Julian2Greg(jd, month, day, year);
}

int myDate::daysBetween(myDate d)
{
    return Greg2Julian(d.getMonth(), d.getDay(), d.getYear()) - Greg2Julian(month, day, year);
}

int myDate::getMonth()
{
    return month;
}

int myDate::getDay()
{
    return day;
}

int myDate::getYear()
{
    return year;
}

int myDate::dayOfYear()
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        if(month == 1)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i;
                }
            }
        }
        if(month == 2)
        {
            for(int i = 1; i < 29; i++)
            {
                if(day == i)
                {
                    return i + 31;
                }
            } 
        }
        if(month == 3)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 60;
                }
            }
        }
        if(month == 4)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 91;
                }
            }
        }
        if(month == 5)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 121;
                }
            }
        }
        if(month == 6)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 152;
                }
            }
        }
        if(month == 7)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 182;
                }
            }
        }
        if(month == 8)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 213;
                }
            }
        }
        if(month == 9)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 244;
                }
            }
        }
        if(month == 10)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 274;
                }
            }
        }
        if(month == 11)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 305;
                }
            }
        }
        if(month == 12)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 335;
                }
            }
        }
    }
    else
    {
        if(month == 1)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i;
                }
            }
        }
        if(month == 2)
        {
            for(int i = 1; i < 28; i++)
            {
                if(day == i)
                {
                    return i + 31;
                }
            } 
        }
        if(month == 3)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 59;
                }
            }
        }
        if(month == 4)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 90;
                }
            }
        }
        if(month == 5)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 120;
                }
            }
        }
        if(month == 6)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 151;
                }
            }
        }
        if(month == 7)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 181;
                }
            }
        }
        if(month == 8)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 212;
                }
            }
        }
        if(month == 9)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 243;
                }
            }
        }
        if(month == 10)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 273;
                }
            }
        }
        if(month == 11)
        {
            for(int i = 1; i <= 30; i++)
            {
                if(day == i)
                {
                    return i + 304;
                }
            }
        }
        if(month == 12)
        {
            for(int i = 1; i <= 31; i++)
            {
                if(day == i)
                {
                    return i + 334;
                }
            }
        }
    }
    return 0;
}

string myDate::dayName()
{
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int jd = Greg2Julian(month, day, year);
    if(jd % 7 == 0)
    {
        return days[0];
    }
    else if(jd % 7 == 1)
    {
        return days[1];
    }
    else if(jd % 7 == 2)
    {
        return days[2];
    }
    else if(jd % 7 == 3)
    {
        return days[3];
    }
    else if(jd % 7 == 4)
    {
        return days[4];
    }
    else if(jd % 7 == 5)
    {
        return days[5];
    }
    else
    {
        return days[6];
    }
}

string myDate::toString()
{
    string m;
    if(month == 1)
    {
        m = "January";
    }
    else if(month == 2)
    {
        m = "February";
    }
    else if(month == 3)
    {
        m = "March";
    }
    else if(month == 4)
    {
        m = "April";
    }
    else if(month == 5)
    {
        m = "May";
    }
    else if(month == 6)
    {
        m = "June";
    }
    else if(month == 7)
    {
        m = "July";
    }
    else if(month == 8)
    {
        m = "August";
    }
    else if(month == 9)
    {
        m = "September";
    }
    else if(month == 10)
    {
        m = "October";
    }
    else if(month == 11)
    {
        m = "November";
    }
    else if(month == 12)
    {
        m = "December";
    }
    return m + " " + to_string(day) + ", " + to_string(year);
}