#pragma once

#include <string>

enum class weekday_t : unsigned char
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};

std::string to_String(const weekday_t& weekday);

class Day
{
public: // Public typedefs
    typedef unsigned char day_t;
private: // Private members
    day_t day_value;
public:
    Day() = default;
    Day(const day_t& day_value);
    void set(const day_t& day_value);
    day_t value() const;
};

class Month
{
public: // Public members
    enum month_t : unsigned char
    {
        january = 1,
        february,
        march,
        april,
        may,
        june,
        july,
        august,
        september,
        october,
        november,
        december
    };
private: // Private members
    month_t month_value;
public:
    Month() = default;
    Month(const month_t& month_value);
    void set(const month_t& month_value);
    month_t value() const;
};

class Year // Assumes AD
{
public: // Public typedefs
    typedef unsigned short year_t;
private: // Private members
    year_t year_value;
public:
    Year() = default;
    Year(const year_t& year_value);
    void set(const year_t& year_value);
    year_t value() const;
    bool is_leap_year() const;
};

class Date
{
private: // Private members
    Day day;
    Month month;
    Year year;
private: // Private functions
    // For weekday() function
    unsigned int getCenturyValue() const;
    unsigned int getYearValue() const;
    unsigned int getMonthValue() const;
public:
    Date() = default; // Default constructor
    /**
     * I'm sorry for doing it this way.
     * Having a string parse constructor creates an informal dependency between the 2 modules, increasing complexity.
     * But this is never going to be expanded into a large program, so I'm programming tactically.
     */
    Date(const std::string& date); // Constructor with string parameter (mm/dd/yyyy)(m/d/yyyy)

    std::string to_string() const; // outputs as mm/dd/yyyy, maintains leading zeros

    weekday_t weekday() const; // Returns the weekday of the date
};