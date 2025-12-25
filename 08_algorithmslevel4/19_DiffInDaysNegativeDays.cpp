#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

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

bool IsLeap(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short i = 0; i < Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(i + 1, Year);
    }
    return TotalDays += Day;
}

short NumberOfDaysOfDateTillEndYear(stDate Date1)
{
    short NumberOfDays = 0;

    for (short i = Date1.Month; i <= 12; i++)
    {
        for (short j = 1; j <= NumberOfDaysInMonth(i, Date1.Year); j++)
        {
            NumberOfDays++;
        }
    }
    return NumberOfDays - Date1.Day;
}

bool IsDayLastInMonth(stDate Date)
{

    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year)) ? true : false;
}

bool IsMonthLastInYear(short Month)
{

    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsDayLastInMonth(Date))
    {
        if (IsMonthLastInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

void SwapDates(stDate &Date1, stDate &Date2)
{
    stDate Temp;

    Temp.Day = Date1.Day;
    Temp.Month = Date1.Month;
    Temp.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = Temp.Day;
    Date2.Month = Temp.Month;
    Date2.Year = Temp.Year;

}

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short DateFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        DateFlagValue = -1;
    }


    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * DateFlagValue : Days* DateFlagValue;
}

// short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
// {
//     int Days = 0;

//     if (IsDate1BeforeDate2(Date1, Date2))
//     {
//         while (IsDate1BeforeDate2(Date1, Date2))
//         {
//             Days++;
//             Date1 = IncreaseDateByOneDay(Date1);
//         }
//     }
//     else
//     {
//         while (IsDate1BeforeDate2(Date2, Date1))
//         {
//             Days--;
//             Date2 = IncreaseDateByOneDay(Date2);
//         }
//         return IncludeEndDay ? --Days : Days;
//     }
//     return IncludeEndDay ? ++Days : Days;
// }

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();
 

    std::cout << "\nDifference is: " 
        << GetDifferenceInDays(Date1, Date2) << " Day(s).\n";

    std::cout << "Difference (including end day) is: " 
        << GetDifferenceInDays(Date1, Date2, true)  << " Day(s).\n";

    return 0;
}
