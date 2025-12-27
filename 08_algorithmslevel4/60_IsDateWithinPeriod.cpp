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

stPeriod ReadPeriod()
{
    stPeriod Period;

    std::cout << "\nEnter Start Date: " << std::endl;
    Period.StartDate = ReadFullDate();

    std::cout << "\nEnter Enter Date: " << std::endl;
    Period.EndDate = ReadFullDate();
    
    return Period;
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

bool IsLeapYear(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
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

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    else if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    else
        return enDateCompare::After;
}

bool IsDateInPeriod(stPeriod Period, stDate Date)
{
   return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before 
        || CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

// bool IsDateInPeriod(stPeriod Period, stDate Date)
// {
//     if (IsDate1BeforeDate2(Date, Period.StartDate) && 
//         IsDate1AfterDate2(Date, Period.EndDate))
//         return true;

//     return false;
// }

int main()
{

    std::cout << "\nEnter Period : ";

    stPeriod Period = ReadPeriod();

    std::cout << "\nEnter date to check: \n";
    stDate Date = ReadFullDate();

    if (IsDateInPeriod(Period, Date))
        std::cout << "\nYes, Date is within period.\n" << std::endl;
    else
        std::cout << "\nNo, Date is not within period.\n" << std::endl;


    return 0;
}