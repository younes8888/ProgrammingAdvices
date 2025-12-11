#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadPositiveNumber(std::string Msg)
{
    int Number = 0;
    do{
        std::cout << Msg << std::endl;
        std::cin >> Number;
    } while(Number <= 0);
    return Number;
}

void ReadArray(int Arr[100], int& ArrLength)
{
    std::cout << "\nEnter number of elements:\n";
    std::cin >> ArrLength;
    std::cout << "\nEnter array elements: \n";
    for (int i = 0; i < ArrLength; i++)
    {
        std::cout << "Element [" << i +  1 << "] : ";
        std::cin >> Arr[i];
    }
    std::cout << "\n";
}
 
void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << "\n"; 
}

int TimesRepeated(int Number, int Arr[100], int ArrLength)
{
    int Count = 0;
    for (int i = 0; i <= ArrLength - 1; i++)
    {
        if (Arr[i] == Number)
            Count++;
    }
    return Count;
}

int main()
{
     int Arr[100], ArrLength, NumberToCheck;
     ReadArray(Arr, ArrLength);

     NumberToCheck = ReadPositiveNumber("Enter a number you want to acheck: ");

     std::cout << "Original Array: ";
     PrintArray(Arr, ArrLength);
     std::cout << "\n";
     int Times = TimesRepeated(NumberToCheck, Arr, ArrLength);
     std::cout << NumberToCheck << " is repeated " << Times << " time(s)" << std::endl;

    return 0;
}

// int ReadPositiveNumber(std::string Msg)
// {
//     int Number = 0;
//     do{
//         std::cout << Msg << std::endl;
//         std::cin >> Number;
//     } while(Number <= 0);
//     return Number;
// }

// int PrintArrayElements(int Arr[5])
// {
//     int Original = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         Original = Original * 10 + Arr[i];
//     }
//     std::cout << "Original String is: " << Original << std::endl;
//     return Original;
// }

// int NumberRepetition(int NumTOCheck, int Original)
// {
//     int Counter = 0;
//     int Remainder = 0;

//     while (Original > 0)
//     {
//         Remainder = Original % 10;
//         if (NumTOCheck == Remainder)
//             Counter++;
//         Original = Original / 10;
//     }
//     return Counter;
// }

// typedef struct stDifferentNumbers
// {
//     int NumToCheck;
//     int Counter;
//     int Original;

// }t_stDifferentNumbers;

// stDifferentNumbers StoreElements(int Number)
// {
//     int Arr[Number];
//     t_stDifferentNumbers All;
//     for (int i = 0; i < Number; i++)
//     {
//         std::cout << "Element [" << i << "]: ";
//         std::cin >> Arr[i];
//         std::cout << "\n"; 
//     }
//     All.NumToCheck = ReadPositiveNumber("Enter the number you want to check: ");

//     All.Original = PrintArrayElements(Arr);
//     All.Counter = NumberRepetition(All.NumToCheck, All.Original);
//     return All;
// }

// void PrintRepetitionTime(int NumToCheck, int Counter)
// {
//     std::cout << NumToCheck << " is repeated " << Counter << " time(s)" << std::endl;
// }

// int main()
// {
//     t_stDifferentNumbers NumToCheck = StoreElements(ReadPositiveNumber("Enter a positive number: "));
//     PrintRepetitionTime(NumToCheck.NumToCheck, NumToCheck.Counter);

//     return 0;
// }