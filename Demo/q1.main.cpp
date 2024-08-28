#include <iostream>
#include <string>

#include "q1.date.hpp"

namespace parameters
{
};

namespace prompts
{
    const std::string date = "Enter a date (mm/dd/yyyy):";
};

namespace messages
{
    std::string output_message(const Date& date, const weekday_t& weekday)
    {
        return date.to_string() + " is a " + to_String(weekday) + ".";
    }
}

int main()
{
    std::string input;
    Date date;
    weekday_t weekday;

    std::cout << prompts::date << std::endl;
    std::cin >> input;

    date = Date(input);
    weekday = date.weekday();

    std::cout << messages::output_message(date, weekday) << std::endl;

    return 0;
}
