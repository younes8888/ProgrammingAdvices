#include <iostream>
#include <string>
#include <ctime>

struct stDate
{
    short Day;
    short Month;
    short Year;
};

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

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

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1EqualDate2(Date1, Date2) && !IsDate1BeforeDate2(Date1, Date2));
}

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    else if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    else
        return enDateCompare::After;
}

int main()
{
    stDate Date1, Date2;
    enDateCompare Result;

    std::cout << "\nEnter Date1: ";
    Date1 = ReadFullDate();
    std::cout << "\nEnter Date2: ";
    Date2 = ReadFullDate();

    std::cout << "\nCompare result= " << CompareDates(Date1, Date2) << std::endl;

    return 0;
}