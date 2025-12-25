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
stDate IncreaseDateByXDays(stDate Date, short NumberOfDaysToAdd)
{
    if (IsMonthLastInYear(Date.Month) && IsDayLastInMonth(Date))
    {
        Date.Day = NumberOfDaysToAdd;
        Date.Month = 1;
        Date.Year++;
    }
    else if (IsDayLastInMonth(Date))
    {
        Date.Day = NumberOfDaysToAdd;
        Date.Month++;
    }
    else
    {
        Date.Day+= NumberOfDaysToAdd;
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date, short NumberOfDaysToAdd = 7)
{
    if (IsMonthLastInYear(Date.Month) && IsDayLastInMonth(Date))
    {
        Date.Day = NumberOfDaysToAdd;
        Date.Month = 1;
        Date.Year++;
    }
    else if (IsDayLastInMonth(Date))
    {
        Date.Day = NumberOfDaysToAdd;
        Date.Month++;
    }
    else
    {
        Date.Day+= NumberOfDaysToAdd;
        if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
        {
            Date.Day = Date.Day - NumberOfDaysInMonth(Date.Month, Date.Year);
            if (IsMonthLastInYear(Date.Month))
            {
                Date.Month = 1;
            }
            else
            {

            }
                Date.Month++;
        }
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
    while(true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
        if( RemainingDays > MonthDays)
        {
            RemainingDays-= MonthDays;
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

stDate IncreaseDateByXWeek(stDate Date, short NumberOfDaysToAdd = 70)
{
    return DateAddDays(NumberOfDaysToAdd, Date);
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

    return Date;
}

void PrintModifiedDate(stDate Date)
{

    std::cout << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;
}

stDate IncreaseDateByXMonths(stDate Date, short NumberOfMonths)
{
    if (IsMonthLastInYear(Date.Month))
    {
        Date.Month = NumberOfMonths;
        Date.Year++;
    }
    else
    {
        Date.Month+= NumberOfMonths;
        if (Date.Month > 12)
        {
            Date.Month-= 12;
            Date.Year++;
        }
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, short NumberOfYearsToAdd)
{
    Date.Year+=NumberOfYearsToAdd;
    return Date;
}
stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYearsToAdd)
{
    Date.Year+=NumberOfYearsToAdd;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date, short OneDecade = 10)
{
    Date.Year+= 10;
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades)
{
    Date.Year+= (NumberOfDecades * 10);
    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
{
    Date.Year+= (NumberOfDecades * 10);
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year+= 100;
    return Date;
}

stDate increaseDateByOneMillennium(stDate Date)
{
    Date.Year+= 1000;
    return Date;
}

int main()
{
    stDate Date = ReadFullDate();

    Date = IncreaseDateByXDays(Date, 1);
    std::cout << "\n01-Adding one day is: ";
    PrintModifiedDate(Date);
    
    Date = IncreaseDateByXDays(Date, 10);
    std::cout << "02-Adding 10 days is: ";
    PrintModifiedDate(Date);
    
    Date = IncreaseDateByOneWeek(Date);
    std::cout << "03-Adding one week is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByXWeek(Date);
    std::cout << "04-Adding 10 week is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByOneMonth(Date);
    std::cout << "05-Adding one month is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByXMonths(Date, 5);
    std::cout << "06-Adding 5 months is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByOneYear(Date);
    std::cout << "07-Adding one year is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByXYears(Date, 10);
    std::cout << "08-Adding 10 years is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByXYearsFaster(Date, 10);
    std::cout << "09-Adding 10 years (faster) is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByOneDecade(Date);
    std::cout << "10-Adding One decade is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByXDecades(Date, 10);
    std::cout << "11-Adding 10 decade is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    std::cout << "12-Adding 10 decade (faster) is: ";
    PrintModifiedDate(Date);

    Date = IncreaseDateByOneCentury(Date);
    std::cout << "13-Adding one century is: ";
    PrintModifiedDate(Date);

    Date = increaseDateByOneMillennium(Date);
    std::cout << "14-Adding one millennium is: ";
    PrintModifiedDate(Date);

}