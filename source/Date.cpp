/*
Date.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/
#include "../header/Date.h"
#include <iostream>

//Deafulat constructor
Date::Date() : day(1), month(1), year(1) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

//
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

//Returns the difference in days between two dates
int Date::differenceInDays(Date otherDate)
{
    //Calculate the number of days between the two dates
    int days1 = this->year * 365 + this->month * 30 + this->day;
    int days2 = otherDate.year * 365 + otherDate.month * 30 + otherDate.day;

    return std::abs(days1 - days2);
}

//Gets the current date from the user
Date Date::getCurrentDate()
{
    int currentDay, currentMonth, currentYear;
    std::cout << "Enter the current date (dd mm yyyy): ";
    std::cin >> currentDay >> currentMonth >> currentYear;
    return Date(currentDay, currentMonth, currentYear);
}
