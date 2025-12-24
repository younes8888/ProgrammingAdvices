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

// sDate ReadDate()
// {
//     sDate date;
//     std::cout << "\nPlease Enter a day: ";
//     std::cin >> date.Day;
//      std::cout << "Please Enter a day: ";
//     std::cin >> date.Month;
//      std::cout << "Please Enter a day: ";
//     std::cin >> date.Year;
//     return date;
// }

bool IsDate1EqualToDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

// bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
// {
//     if (Date1.Year > Date2.Year)
//     {
//         return 1;
//     }
//     else if (Date1.Year == Date2.Year)
//     {
//         if (Date1.Month > Date2.Month)
//         {
//             return 1;
//         }
//         else if (Date1.Month == Date2.Month)
//         {
//             if (Date1.Day > Date2.Day)
//             {
//                 return 1;
//             }
//         }

//     }
//     return 0;
// }
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
        std::cout << "\nYes, Date1 is less than Date2\n";
    }
    else
    {
        std::cout << "\nNo, Date1 is NOT less than Date2\n";
    }

    return 0;
}