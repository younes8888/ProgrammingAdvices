#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

struct sDate
{
    std::string Day;
    std::string Month;
    std::string Year;
};

bool IsDate1EqualToDate2(sDate Date1, sDate Date2)
{
    // return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) :false;
}

short ReadDay()
{
    short Day;
    std::cout << "\nPlease Enter a day: ";
    std::cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    std::cout << "Please Enter a month: ";
    std::cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    std::cout << "Please Enter a year: ";
    std::cin >> Year;
    return Year;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();

    if (IsDate1EqualToDate2(Date1, Date2))
    {
        std::cout << "\nYes, Date1 is equal to Date2\n";
    }
    else
    {
        std::cout << "\nNo, Date1 is NOT equal to Date2\n";
    }

    return 0;
}