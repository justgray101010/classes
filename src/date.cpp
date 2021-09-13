#include "../inc/mylib.h"

Date::Date() {
    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);

    m_day = local_time->tm_mday;
    m_month = 1 + local_time->tm_mon;
    m_year = 1900 + local_time->tm_year;
}

Date::Date(int day, int month, int year)
{
    setDate(day, month, year);
}

void Date::setDate(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

Date::Date(const Date& date) {
    m_day = date.m_day;
    m_month = date.m_month;
    m_year = date.m_year;
}

void Date::display() {
    cout << this->getDay() << "." << this->getMonth() << "." << this->getYear() << endl;
}

Date::~Date() {}
