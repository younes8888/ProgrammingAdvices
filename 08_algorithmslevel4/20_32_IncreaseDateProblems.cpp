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

stDate IncreaseDateByXDays( short NumberOfDaysToAdd, stDate Date)
{

    for (short i = 1; i <= NumberOfDaysToAdd; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
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

stDate DateAddDays(short Days, stDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

stDate IncreaseDateByXWeeks(short NumberOfWeeks, stDate Date)
{
    for (short i = 1; i <= NumberOfWeeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (IsMonthLastInYear(Date.Month))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

void PrintModifiedDate(stDate Date)
{

    std::cout << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;
}

stDate IncreaseDateByXMonths(short NumberOfMonths, stDate Date)
{

    for (short i = 1; i <= NumberOfMonths; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(short NumberOfYearsToAdd, stDate Date)
{
    for (short i = 1; i <= NumberOfYearsToAdd; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXYearsFaster(short NumberOfYearsToAdd, stDate Date)
{
    Date.Year += NumberOfYearsToAdd;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(short NumberOfDecades, stDate Date)
{
    for (short i = 1; i <= NumberOfDecades * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(short NumberOfDecades, stDate Date)
{
    Date.Year += (NumberOfDecades * 10);
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    stDate Date1 = ReadFullDate();\

    std::cout << "\nDate After: \n";

    Date1 = IncreaseDateByOneDay(Date1);
    std::cout << "\n01-Adding one day is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDays(10, Date1);
    std::cout << "\n02-Adding 10 days is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneWeek(Date1);
    std::cout << "\n03-Adding one week is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = IncreaseDateByXWeeks(10, Date1);
    std::cout << "\n04-Adding 10 weeks is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    
    Date1 = IncreaseDateByOneMonth(Date1);
    std::cout << "\n05-Adding one month is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXMonths(5, Date1);
    std::cout << "\n06-Adding 5 months is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneYear(Date1);
    std::cout << "\n07-Adding one year is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYears(10, Date1);
    std::cout << "\n08-Adding 10 Years is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYearsFaster(10, Date1);
    std::cout << "\n09-Adding 10 Years (faster) is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneDecade(Date1);
    std::cout << "\n10-Adding one Decade is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecades(10, Date1);
    std::cout << "\n11-Adding 10 Decades is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecadesFaster(10, Date1);
    std::cout << "\n12-Adding 10 Decade (faster) is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneCentury(Date1);
    std::cout << "\n13-Adding One Century is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMillennium(Date1);
    std::cout << "\n14-Adding One Millennium is: "
         << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << std::endl;

    return 0;
}