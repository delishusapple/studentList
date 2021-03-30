#ifndef MYDATE_H
#define MYDATE_H

#include<iostream>
#include<string>

using namespace std;

class myDate
{
    private:
        int month;
        int day;
        int year;
    public:
        myDate();
        myDate(int m, int d, int y);
        void display();
        void increaseDate(int n);
        void decreaseDate(int n);
        int daysBetween(myDate d);
        int getMonth();
        int getDay();
        int getYear();
        int dayOfYear();
        string dayName();
        string toString();
};
#endif