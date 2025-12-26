#include <iostream>
#include <string>
#include <ctime>
struct stDate
{
    short Day;
    short Month;
    short Year;
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
    return (Date1.Year == Date2.Year) ? ((Date1.Month ==Date2.Month)? ((Date1.Day == Date2.Day) ? true : false): false): false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1EqualDate2(Date1,Date2) && !IsDate1BeforeDate2(Date1,Date2));
}

// bool IsDate1AfterToDate2(stDate Date1, stDate Date2)
// {
//     return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day : false)) : false);
// }

int main()
{
    stDate Date1, Date2;

    std::cout << "\nEnter Date1: ";
    Date1 = ReadFullDate();
    std::cout << "\nEnter Date2: ";
    Date2 = ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2))
        std::cout << "\nYes, Date1 is after Date2\n";
    else
        std::cout << "\nNo, Date1 is NOT after Date2\n";

    return 0;
}