
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

void IsEndOfWeek(stDate Date)
{
    std::string NameOfDay = DayShortName(DayOfWeekOrder(Date));
    if (NameOfDay == "Fri")
    {
        std::cout << "Yes, it is the end of the week\n";
    }
    else
    {
        std::cout << "No, it is not the end of the week.\n";
    }
}
void IsWeekEnd(stDate Date)
{
    std::string NameOfDay = DayShortName(DayOfWeekOrder(Date));
    if (NameOfDay == "Sat" || NameOfDay == "Sun")
    {
        std::cout << "Yes, it is the weekend\n";
    }
    else
    {
        std::cout << "No, it is not the end of the weekend\n";
    }
}

void IsBusinessDay(stDate Date)
{
    std::string NameOfDay = DayShortName(DayOfWeekOrder(Date));
    if (NameOfDay == "Mon" || NameOfDay == "Tue" || NameOfDay == "Wed" || NameOfDay == "Thu")
    {
        std::cout << "Yes, it is a business day\n";
    }
    else
    {
        std::cout << "No, it is not a business day\n";
    }
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return (6 - (DayOfWeekOrder(Date)));
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    return (DaysInMonth - Date.Day) + 1;
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

short DaysUntilTheEndOfYear(stDate Date)
{
    short Days = 0;
    short TotalDays;
    if (IsLeap(Date.Year))
    {
        TotalDays = 366;
    }
    else
    {
        TotalDays = 365;
    }

    for (short i = 1; i < Date.Month; i++)
    {
        Days += NumberOfDaysInMonth(i, Date.Year);
    }
    Days += Date.Day;
    TotalDays -= Days;
    return ++TotalDays;
}

int main()
{
    stDate Date;

    Date = GetSystemDate();
    std::cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date))
         << " , "
         << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

    std::cout << "\nIs it the end of the week? " << std::endl;
    IsEndOfWeek(Date);

    std::cout << "\nIs it weekend? " << std::endl;
    IsWeekEnd(Date);

    std::cout << "\nIs it business day? " << std::endl;
    IsBusinessDay(Date);

    std::cout << "\nDays until end of week: " << DaysUntilTheEndOfWeek(Date) << " Day(s).\n";
    std::cout << "\nDays until end of month: " << DaysUntilTheEndOfMonth(Date) << " Day(s).\n";
    std::cout << "\nDays until end of year: " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";

    return 0;
}