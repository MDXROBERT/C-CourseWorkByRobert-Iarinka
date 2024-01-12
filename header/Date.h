#ifndef DATE_H
#define DATE_H
/*
Date.h
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    static Date getCurrentDate();
    int differenceInDays(Date otherDate);
};

#endif
