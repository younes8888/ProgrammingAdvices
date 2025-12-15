 #include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

short ReadYear()
{
    short Y;
    std::cout << "Please enter year: ";
    std::cin >> Y;
    return Y;
}

bool IsLeap(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short A = (14 - Month) / 12;
    short Y = Year - A;
    short M = Month + (12 * A) - 2;

    return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
}

std::string MonthShortName(short MonthNumber)
{
    std::string Months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};
    return (Months[MonthNumber - 1]);
}

void PrintMonthCalender(short Year, short Month)
{
    short NumberOfDays = NumberOfDaysInMonth(Month, Year);
    short Current = DayOfWeekOrder(1, Month, Year);

    printf("\n----------------------%s----------------------\n\n", MonthShortName(Month).c_str());
    printf("  Sun     Mon    Tue    Wed    Thu    Fri    Sat\n");
    int i;
    for (i = 0; i < Current; i++)
        printf("       ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d  ", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n------------------------------------------------\n");
}

void    PrintYearCalendar(short Year)
{
        printf("\n------------------------------------------------\n");
        printf("                 Calender - %d                     ", Year);
        printf("\n------------------------------------------------\n");

        for (short i = 1; i <= 12 ; i++)
        {
            PrintMonthCalender(2022,i);
        }

}

int main()
{
  
    PrintYearCalendar(ReadYear());
    

    return 0;
}