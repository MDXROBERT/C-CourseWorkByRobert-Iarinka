#ifndef DATE_H
#define DATE_H

class Date {
    private:
    int day;
    int month;
    int year;

    public:
    Date(int day, int month, int year);

    int getDay();
    int getMonth();
    int getYear();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
};


#endif