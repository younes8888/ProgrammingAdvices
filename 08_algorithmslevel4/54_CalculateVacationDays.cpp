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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

// short CountVacationDaysWithoutWeekends(stDate StartDate, stDate EndDate)
// {

//     short NumberOfVacationDays = GetDifferenceInDays(StartDate, EndDate, false);
//     short NumberOfWeekDays = 0;

//     for (short i = 0; i < NumberOfVacationDays; i++)
//     {
//         if (IsWeekEnd(StartDate))
//         {
//             NumberOfWeekDays++;
//         }
//         StartDate = IncreaseDateByOneDay(StartDate);
//     }
//     return NumberOfVacationDays - NumberOfWeekDays;
// } 

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

short CalculateVacationDays(stDate StartDate, stDate EndDate)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(StartDate, EndDate))
    {
        if (IsBusinessDay(StartDate))
        {
            DaysCount++;
        }
        StartDate = IncreaseDateByOneDay(StartDate);
    }
    return DaysCount;
}

int main()
{
    stDate StartDate, EndDate;

    std::cout << "\nVacation Starts: ";
    StartDate = ReadFullDate();
    
    std::cout << "\nVacation Ends: ";
    EndDate = ReadFullDate();

    std::cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(StartDate))  << " , " << StartDate.Day << "/"
        << StartDate.Month << "/" << StartDate.Year << std::endl;

    std::cout << "Vacation To: " << DayShortName(DayOfWeekOrder(EndDate))  << " , " << EndDate.Day << "/"
        << EndDate.Month << "/" << EndDate.Year << std::endl;

    std::cout << "\nActual Vacation days is: " << CalculateVacationDays(StartDate, EndDate) << std::endl;

    return 0;
}