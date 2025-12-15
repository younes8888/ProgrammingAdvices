#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

short ReadYear()
{
    short Year;
    std::cout << "Please enter year: ";
    std::cin >> Year;
    return Year;
}
short ReadMonth()
{
    short Month;
    std::cout << "\nPlease enter month: ";
    std::cin >> Month;
    return Month;
}
short ReadDay()
{
    short Day;
    std::cout << "\nPlease enter year: ";
    std::cin >> Day;
    return Day;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short A = (14 - Month) / 12;
    short Y = Year - A;
    short M = Month + (12 * A) - 2;

    return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M)/12)) % 7;
}

std::string DayShortName(short DayOfWeekOrder)
{
    std::string ArrShortNameDay[7] = {"Sun", "Mon", "Tues","Wed" "Thurs", "Frid", "Sat"};

    return ArrShortNameDay[DayOfWeekOrder];
}

int main()
{
    short Year, Month, Day;
    Year = ReadYear();
    Month = ReadMonth();
    Day = ReadDay();


    std::cout << "\nData" << std::setw(15) << ":" << Day << "/" << Month << "/" << Year << std::endl;
    std::cout << "Day Order" << std::setw(10) << ":" << DayOfWeekOrder(Day, Month, Year) << std::endl;
    std::cout << "Day Name" << std::setw(11) << ":" << DayShortName(DayOfWeekOrder(Day, Month, Year)) << std::endl;


    return 0;
}