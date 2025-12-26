
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

stDate GetSystemDate()
{
    time_t t = time(0);
    tm *Now = localtime(&t);
    stDate Date;

    Date.Day = Now->tm_mday;
    Date.Month = Now->tm_mon + 1;
    Date.Year = Now->tm_year + 1900;
    return Date;
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short A = (14 - Month) / 12;
    short Y = Year - A;
    short M = Month + (12 * A) - 2;

    return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    short A = (14 - Date.Month) / 12;
    short Y = Date.Year - A;
    short M = Date.Month + (12 * A) - 2;

    return (Date.Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
}

std::string DayShortName(short DayOfWeekOrder)
{
    std::string ArrShortNameDay[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return ArrShortNameDay[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
    return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(stDate Date)
{
    return (DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 7);
}

bool IsBusinessDay(stDate Date)
{
    short IndexDay = DayOfWeekOrder(Date);

   return ( IndexDay <= 5 || IndexDay >= 1);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return (6 - (DayOfWeekOrder(Date)));
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

short DaysUntilTheEndOfMonth(stDate Date)
{  
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}





short DaysUntilTheEndOfYear(stDate Date)
{
    stDate EndOFYearDate;

    EndOFYearDate.Day = 31;
    EndOFYearDate.Month = 12;
    EndOFYearDate.Year = Date.Year;
    
    return GetDifferenceInDays(Date, EndOFYearDate, true);
}

int main()
{
    stDate Date;

    Date = GetSystemDate();
    std::cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date))
              << " , "
              << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

    std::cout << "\nIs it the end of the week? " << std::endl;
    if (IsEndOfWeek(Date))
        std::cout << "Yes, it is the end of the week.\n";
    else 
        std::cout << "No, it is NOT end of week.\n";

    std::cout << "\nIs it weekend? " << std::endl;
    if (IsWeekEnd(Date))
        std::cout << "Yes, it is a weekend";
    else
        std::cout << "Today isn't weekend.\n";

    std::cout << "\nIs it business day? " << std::endl;
    IsBusinessDay(Date);

    std::cout << "\nDays until end of week: " << DaysUntilTheEndOfWeek(Date) << " Day(s).\n";
    std::cout << "\nDays until end of month: " << DaysUntilTheEndOfMonth(Date) << " Day(s).\n";
    std::cout << "\nDays until end of year: " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";

    return 0;
}