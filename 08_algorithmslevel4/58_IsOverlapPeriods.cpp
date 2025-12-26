#include <iostream>
#include <string>
#include <ctime>

struct stDate
{
    short Day;
    short Month;
    short Year;
};
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

// bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
// {
   

//     if ((IsDate1BeforeDate2(Period2.StartDate, Period1.StartDate) || IsDate1EqualDate2(Period2.StartDate, Period1.StartDate))&&
//      (IsDate1BeforeDate2(Period2.EndDate, Period1.EndDate) || IsDate1EqualDate2(Period2.EndDate, Period1.EndDate)))
//     {
//         return true;
//     }
//     else if ((IsDate1AfterDate2(Period2.StartDate, Period1.StartDate) || IsDate1EqualDate2(Period2.StartDate,Period1.StartDate)) && 
//     (IsDate1AfterDate2(Period2.EndDate, Period1.EndDate) || IsDate1EqualDate2(Period2.EndDate, Period1.EndDate)))
//     {
//         return true;
//     }
//     else if ((IsDate1BeforeDate2(Period2.StartDate, Period1.StartDate) || IsDate1EqualDate2(Period2.StartDate, Period1.StartDate)) &&
//      (IsDate1AfterDate2(Period2.EndDate, Period1.EndDate) || IsDate1EqualDate2(Period2.EndDate, Period1.EndDate)))
//     {
//         return true;
//     }
//     else if ((IsDate1AfterDate2(Period2.StartDate, Period1.StartDate) || IsDate1EqualDate2(Period2.StartDate, Period1.StartDate)) && 
//         IsDate1BeforeDate2(Period2.EndDate, Period1.EndDate) || IsDate1EqualDate2(Period2.EndDate, Period1.EndDate))
//     {
//         return true;
//     }
//     else if (IsDate1EqualDate2(Period2.EndDate, Period1.StartDate)) 
//     {
//         return true;
//     }
//     else if(IsDate1EqualDate2(Period2.StartDate, Period1.EndDate))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }

// }

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    else if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    else
        return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
   
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
     || CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}


// bool IsOverlapPeriods(stDate StartDate1, stDate EndDate1, stDate StartDate2, stDate EndDate2)
// {
//     short TotalDays;

//     if (IsDate1BeforeDate2(StartDate1, StartDate2))
//     {
//         TotalDays = GetDifferenceInDays(StartDate1, EndDate1, false);

//         for(short i = 0; i < TotalDays; i++)
//         {
//             if (IsDate1EqualDate2(StartDate1, StartDate2))
//                 return true;
//             StartDate1 = IncreaseDateByOneDay(StartDate1);
//         }
//     } 
//     else if (IsDate1AfterDate2(StartDate1, StartDate2))
//     {
//         TotalDays = GetDifferenceInDays(StartDate2, EndDate2, false);

//         for(short i = 0; i < TotalDays; i++)
//         {
//             if (IsDate1EqualDate2(StartDate2, StartDate1))
//                 return true;
//             StartDate2 = IncreaseDateByOneDay(StartDate2);
//         }
//     }

//     return false;
// }

stPeriod ReadPeriod()
{
    stPeriod Period;

    std::cout << "\nEnter Start Date: " << std::endl;
    Period.StartDate = ReadFullDate();

    std::cout << "\nEnter Enter Date: " << std::endl;
    Period.EndDate = ReadFullDate();
    
    return Period;
}

int main()
{

    std::cout << "\nEnter Period 1: ";

    stPeriod Period1 = ReadPeriod();

    std::cout << "\nEnter Period 2: ";
    stPeriod Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2))
        std::cout << "\nYes, periods overlap\n";
    else
        std::cout << "\nNo, periods don't overlap\n";


    return 0;
}