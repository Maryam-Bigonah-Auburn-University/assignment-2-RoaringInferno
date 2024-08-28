#include <iostream>

double convertToMPH(double kph) {
    return kph / 1.61;
}
double convertToMPH(int minutes, int seconds) {
    // Assuming here that the minutes and seconds are referring to the amount of time it took to travel 1 mile
    return 3600 / (minutes * 60 + seconds);
}

int main()
{
    int minutes, seconds;
    double kph;

    std::cout << "Enter the minutes and seconds it took to travel 1 mile.\nMinutes: ";
    std::cin >> minutes;
    std::cout << "Seconds: ";
    std::cin >> seconds;

    std::cout << "Speed in MPH: " << convertToMPH(minutes, seconds) << std::endl;

    std::cout << "Enter the speed in KPH: ";
    std::cin >> kph;

    std::cout << "Speed in MPH: " << convertToMPH(kph) << std::endl;
}