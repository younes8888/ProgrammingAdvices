#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

short ReadDay()
{
    short Day;
    std::cout << "\nPlease enter day: ";
    std::cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    std::cout << "\nPlease enter month: ";
    std::cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    std::cout << "\nPlease enter year: ";
    std::cin >> Year;
    return Year;
}

bool IsLeap(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
}

short    NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
        short TotalDays = 0;
      
        for (short i = 0; i < Month - 1 ; i++)
        {
            TotalDays+= NumberOfDaysInMonth(i+1, Year);
        }
        return TotalDays+= Day;
}

int main()
{   
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    std::cout << "\nNumber of days from the beginning of the year is: ";
    std::cout << NumberOfDaysFromTheBeginningOfTheYear(Day,Month,Year) << std::endl;

    return 0;
}