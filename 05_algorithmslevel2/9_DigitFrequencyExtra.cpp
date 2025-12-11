#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadNum(std::string Message)
{
    int Num;
    do {
        std::cout << Message << std::endl;
        std::cin >> Num;
    } while (Num <= 0 );
    return Num;
}

int DigitFrequencyInNumber(int Num, short Digit)
{
    int Count, Remainder;
    Remainder = 0;
    Count = 0;
    while (Num > 0)
    {
        Remainder = Num % 10;
        Num = Num / 10;
        if (Remainder == Digit)
            Count++;
    }
    return Count;
}

void PrintAllDigitsFrequency(int Num)
{
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;
        DigitFrequency = DigitFrequencyInNumber(Num, i);
        if (DigitFrequency > 0)
        {
            std::cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s).\n";
        }

    }
}
int main()
{
    int Number;
    Number = ReadNum("Please, enter a number: ");
    PrintAllDigitsFrequency(Number);

    return 0;
}
// int DigitFrequencyInNumber(int Num, int Digit)
// {
//     int Count, Remainder;
//     Remainder = 0;
//     Count = 0;
//     while (Num > 0)
//     {
//         Remainder = Num % 10;
//         Num = Num / 10;
//         if (Remainder == Digit)
//             Count++;
//     }
//     return Count;
// }

// void PrintFrequency(int Count, int Digit)
// {
//     std::cout << "Digit " << Digit << " frequency is " << Count << " times" << std::endl;
// }
// int NumLength(int Num)
// {
//     int i = 0;
//     while (Num > 0)
//     {
//         Num = Num / 10;
//         i++;
//     }
//     return i;
// }

// int DoesItAlreadyExit(int Num, int Digit, int Position)
// {
//     int Len = NumLength(Num);
//     int NumCheck;
//     while (Position < Len)
//     {
//         NumCheck = Num % 10;
//         if (NumCheck == Digit)
//         {
//             return 1;
//         }
//         Num = Num / 10;
//         Len--;
//     }
//     return 0;
// }

// int DigitFrequencyOfMultipleNumbers(int Num)
// {
//     int Count, Num2, Remainder, Digit, Len;
//     Remainder = 0;
//     Count = 0;
//     Num2 = Num;
//     Len = NumLength(Num);
//     while (Len > 0)
//     {
//         Remainder = Num % 10;
//         Digit = Remainder;
//         // std::cout << DoesItAlreadyExit(Num2, Digit, Len) << std::endl;
//         if (DoesItAlreadyExit(Num2, Digit, Len) == 0)
//         {
//             Count = DigitFrequencyInNumber(Num, Digit);
//             PrintFrequency(Count, Digit);
//         }
//         Num = Num / 10;
//         Len--;
//     }
//     return Count;
// }
