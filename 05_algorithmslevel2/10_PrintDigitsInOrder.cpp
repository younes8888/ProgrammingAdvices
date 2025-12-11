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

int ReverseDigits(int Number)
{
    int Remainder = 0;
    int Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number/=10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}

void PrintDigits(int Number)
{
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number/=10;
        std::cout << Remainder << std::endl;
    }
}
int main()
{
    int Number = ReadNum("Enter a number: ");
    PrintDigits(ReverseDigits(Number));
    return 0;
}



// int ReadNum(std::string Message)
// {
//     int Num;
//     do {
//         std::cout << Message << std::endl;
//         std::cin >> Num;
//     } while (Num <= 0 );
//     return Num;
// }
// void PrintNumbersInOrder(int Num)
// {
//     int Remainder = 0;
//     std::string ConvertedNum = std::to_string(Num);
//     int Len = ConvertedNum.length();
//     int i = 0;
//     while (Len > i)
//     {
//         std::cout << ConvertedNum[i] << std::endl;
//         i++;
//     }
// }
// int main()
// {
//     int Number;
//     Number = ReadNum("Please, enter a number: ");
//     std::cout << "\n";
//     PrintNumbersInOrder(Number);
//     return 0;
// }