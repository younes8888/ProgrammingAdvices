#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadNum()
{
    int Num;
    do
    {
        std::cout << "Enter a positive num: " << std::endl;
        std::cin >> Num;
    } while (Num < 0);
    
    return Num;
}

int CalculateLength(int Num)
{
    int Num2 = 0;
    int Remainder = 0;
    while (Num > 0)
    {
       Remainder = Num % 10;
       Num = Num / 10;
       Num2 = Num2 * 10 + Remainder;

    }
    return Num2;
}

void PrintNum(int Num)
{
    std::cout << "Reversed num is: " << Num << std::endl;
}
// void PrintReversedNum(int Num, int Len)
// {
//     int Reversed[Len];
//     int i = 0;
//     while (i < Len)
//     {
//         Reversed[i] =  Num % 10;
//         Num = Num / 10;
//         std::cout << Reversed[i];
//         i++;
//     }
//     std::cout << "\n";
// }
int main()
{
    int Num = ReadNum();
    PrintNum(CalculateLength(Num));

    return 0;
}