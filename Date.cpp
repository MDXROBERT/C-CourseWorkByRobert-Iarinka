#include "Date.h"
#include <iostream>

Date::Date() : day(1), month(1), year(1) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay()  {
    return this->day;
}

int Date::getMonth()  {
    return this->month;
}

int Date::getYear()  {
    return this->year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

// Calculate the difference in days between two Date objects
int Date::differenceInDays( Date otherDate) {
    int days1 = this->year * 365 + this->month * 30 + this->day;
    int days2 = otherDate.year * 365 + otherDate.month * 30 + otherDate.day;

    return std::abs(days1 - days2);
}


Date Date::getCurrentDate() {
    int currentDay, currentMonth, currentYear;
    std::cout << "Enter the current date (dd mm yyyy): ";
    std::cin >> currentDay >> currentMonth >> currentYear;
    return Date(currentDay, currentMonth, currentYear);
}
