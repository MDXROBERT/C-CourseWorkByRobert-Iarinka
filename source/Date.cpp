/*
Date.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/
#include "../header/Date.h"
#include <iostream>
#include <cmath>

//Deafulat constructor
Date::Date() : day(1), month(1), year(1) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}


int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setYear(int year)
{
    this->year = year;
}


int Date::differenceInDays(Date otherDate)
{

    int days1 = this->year * 365 + this->month * 30 + this->day;
    int days2 = otherDate.year * 365 + otherDate.month * 30 + otherDate.day;

    
    return days1 - days2; 
}


// get current time
Date Date::getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);

    int currentDay = parts->tm_mday;
    int currentMonth = parts->tm_mon + 1;  
    int currentYear = parts->tm_year + 1900;  

    return Date(currentDay, currentMonth, currentYear);
}
// add days to the date
Date Date::addDays(int days)  {
    int newDay = this->day + days;
    int newMonth = this->month;
    int newYear = this->year;

    while (newDay > 30) { 
        newDay -= 30;
        newMonth += 1;
        if (newMonth > 12) {
            newMonth = 1;
            newYear += 1;
        }
    }

    return Date(newDay, newMonth, newYear);
}

