#include "p1.date.hpp"

std::string to_String(const weekday_t &weekday)
{
    switch (weekday)
    {
    case weekday_t::sunday:
        return "Sunday";
    case weekday_t::monday:
        return "Monday";
    case weekday_t::tuesday:
        return "Tuesday";
    case weekday_t::wednesday:
        return "Wednesday";
    case weekday_t::thursday:
        return "Thursday";
    case weekday_t::friday:
        return "Friday";
    case weekday_t::saturday:
        return "Saturday";
    default:
        return "Err_Weekday";
    };
}

Day::Day(const day_t &day_value) : day_value(day_value)
{
}

void Day::set(const day_t &day_value)
{
    this->day_value = day_value;
}

Day::day_t Day::value() const
{
    return day_value;
}

Month::Month(const month_t &month_value) : month_value(month_value)
{
}

void Month::set(const month_t &month_value)
{
    this->month_value = month_value;
}

Month::month_t Month::value() const
{
    return month_value;
}

Year::Year(const year_t &year_value) : year_value(year_value)
{
}

void Year::set(const year_t &year_value)
{
    this->year_value = year_value;
}

Year::year_t Year::value() const
{
    return year_value;
}

bool Year::is_leap_year() const
{
    if (year_value % 400 == 0) { return true; }
    if (year_value % 100 == 0) { return false; }
    if (year_value % 4 == 0) { return true; }
    return false;
}

unsigned int Date::getCenturyValue() const
{
    Year::year_t first_two_digits = year.value() / 100;
    unsigned char remainder = first_two_digits % 4;
    return (3 - remainder) * 2;
}

unsigned int Date::getYearValue() const
{
    unsigned char last_two_digits = year.value() % 100;
    unsigned char quotient = last_two_digits / 4;
    return last_two_digits + quotient;
}

unsigned int Date::getMonthValue() const
{
    switch (month.value())
    {
    case Month::january:
        if (year.is_leap_year()) { return 6; }
        return 0;
    case Month::february:
        if (year.is_leap_year()) { return 2; }
        return 3;
    case Month::march:
        return 3;
    case Month::april:
        return 6;
    case Month::may:
        return 1;
    case Month::june:
        return 4;
    case Month::july:
        return 6;
    case Month::august:
        return 2;
    case Month::september:
        return 5;
    case Month::october:
        return 0;
    case Month::november:
        return 3;
    case Month::december:
        return 5;
    default:
        return 0;
    };
}

Date::Date(const std::string &date) :
    day(0),
    month(Month::january),
    year(0)
{
    std::string::const_iterator begin = date.begin();
    std::string::const_iterator it = begin;
    std::string::const_iterator end = date.end();

    while (*it != '/')
    {
        ++it;
    }
    month.set(static_cast<Month::month_t>(std::stoi(std::string(begin, it))));
    while (*it != '/')
    {
        ++it;
    }
    day.set(std::stoi(std::string(begin, it)));
    while (it != end)
    {
        ++it;
    }
    year.set(std::stoi(std::string(begin, it)));
}

std::string Date::to_string() const
{
    std::string month_string, day_string, year_string;

    if (month.value() < 10) { month_string = "0" + std::to_string(month.value()); }
    else { month_string = std::to_string(month.value()); }

    if (day.value() < 10) { day_string = "0" + std::to_string(day.value()); }
    else { day_string = std::to_string(day.value()); }

    if (year.value() < 10) { year_string = "000" + std::to_string(year.value()); }
    else if (year.value() < 100) { year_string = "00" + std::to_string(year.value()); }
    else if (year.value() < 1000) { year_string = "0" + std::to_string(year.value()); }
    else { year_string = std::to_string(year.value()); }

    return month_string + "/" + day_string + "/" + year_string;
}

weekday_t Date::weekday() const
{
    unsigned int sum = day.value() + getMonthValue() + getYearValue() + getCenturyValue();
    unsigned char remainder = sum % 7;
    switch (remainder)
    {
    case 0:
        return weekday_t::saturday;
    case 1:
        return weekday_t::sunday;
    case 2:
        return weekday_t::monday;
    case 3:
        return weekday_t::tuesday;
    case 4:
        return weekday_t::wednesday;
    case 5:
        return weekday_t::thursday;
    case 6:
        return weekday_t::friday;
    default:
        return weekday_t::sunday;
    };
}
