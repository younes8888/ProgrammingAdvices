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
short ReadMonth()
{
    short M;
    std::cout << "\nPlease enter month: ";
    std::cin >> M;
    return M;
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

    printf("----------------------%s----------------------\n\n", MonthShortName(Month).c_str());
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


int main()
{
    short Year, Month;
    Year = ReadYear();
    Month = ReadMonth();

    PrintMonthCalender(Year, Month);

    return 0;
}
// short ReadYear()
// {
//     short Y;
//     std::cout << "Please enter year: ";
//     std::cin >> Y;
//     return Y;
// }
// short ReadMonth()
// {
//     short M;
//     std::cout << "\nPlease enter month: ";
//     std::cin >> M;
//     return M;
// }

// bool IsLeap(int Year)
// {
//     return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
// }

// short DayOfWeekOrder(short Day, short Month, short Year)
// {
//     short A = (14 - Month) / 12;
//     short Y = Year - A;
//     short M = Month + (12 * A) - 2;

//     return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
// }

// short NumberOfDaysInMonth(short Month, short Year)
// {
//     if (Month < 1 || Month > 12)
//         return 0;

//     int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//     return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
// }

// void FillCalenderWithDays(short Year, short Month)
// {
//     short NumberOfDays = NumberOfDaysInMonth(Month, Year);
//     short StartPoint = DayOfWeekOrder(1, Month, Year);

//     int ArrNumberOfDays[5][7];
//     short NumberCounter = 1;

//     short TrackNumberOfDays = 0;
//     for (short i = 0; i < 5; i++)
//     {
//         for (short j = 0; j < 7; j++)
//         {
//             if (TrackNumberOfDays >= (NumberOfDays))
//             {
//                 break;
//             }

//             if ((i == 0 && (StartPoint) > j))
//             {
//                 ArrNumberOfDays[i][j] = 0;
//                 std::cout << std::setw(4) << std::right << ArrNumberOfDays[i][j] << "   ";
//                 continue;
//             }

//             ArrNumberOfDays[i][j] = NumberCounter;
//             std::cout << std::setw(4) << std::right << ArrNumberOfDays[i][j] << "   ";
//             NumberCounter++;
//             TrackNumberOfDays++;
//         }
//         std::cout << "\n";
//     }
// }

// void PrintMonthCalender(short Year, short Month)
// {
//     std::string ArrOfMonthNames[12] = {"Jan", "Feb", "Mar", "Apr", "Ma", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
//     std::string ArrShortNameDay[7] = {"Sun", "Mon", "Tues", "Wed","Thurs","Frid", "Sat"};

//     std::cout << "\n----------------------" << ArrOfMonthNames[Month - 1] << "----------------------" << std::endl;

//     std::cout << std::setw(4) << "\n Sun" << "   ";
//     std::cout << std::setw(4) << " Mon" << "   ";
//     std::cout << std::setw(4) << " Tue" << "   ";
//     std::cout << std::setw(4) << " Wed" << "   ";
//     std::cout << std::setw(4) << " Thu" << "   ";
//     std::cout << std::setw(4) << " Fri" << "   ";
//     std::cout << std::setw(4) << " Sat" << std::endl;
//     std::cout << "\n";
//     FillCalenderWithDays(Year, Month);
//     std::cout << "\n-----------------------------------------------" << std::endl;
// }

// int main()
// {
//     short Year, Month;
//     Year = ReadYear();
//     Month = ReadMonth();

//     PrintMonthCalender(Year, Month);

//     return 0;
// }