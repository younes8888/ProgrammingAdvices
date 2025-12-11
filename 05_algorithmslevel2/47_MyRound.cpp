#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>


void ReadNumber(float &Number)
{
    std::cout << "Enter a number: " << std::endl;
    std::cin >> Number;
}

float GetFractionalPart(float Number)
{
   return (Number - int(Number));
}

int MyRound(float Number)
{
    int IntPart;
    float FractionalPart;

    IntPart = int(Number);
    FractionalPart = GetFractionalPart(Number);

    if (abs(FractionalPart) >= .5)
    {
        if (Number > 0)
            return IntPart + 1;
        else
            return IntPart - 1;
    }
    else
        return IntPart;
}

int main()
{
    float Number;
    ReadNumber(Number);

    std::cout << "My round result : " << MyRound(Number) << std::endl;
    std::cout << "C++ Round Result: " << round(Number) << std::endl;

    return 0;
}
// void ReadNumber(float &Number)
// {
//     std::cout << "Enter a number: " << std::endl;
//     std::cin >> Number;
// }

// float GetFractionalPart(float Number)
// {
//     int ConvertNumber = Number * 10;
//     return ConvertNumber % 10;
// }

// int MyRound(float Number)
// {
//     int LastNum = GetFractionalPart(Number);

//     if (LastNum >= 5)
//         return (int)Number + 1;
//     else
//         return (int)Number;
// }

// int main()
// {
//     float Number;
//     ReadNumber(Number);
//     std::cout << Number << std::endl;

//     if (Number > 0)
//     {
//         std::cout << "My round result : ";
//         std::cout << MyRound(Number) << std::endl;
//     }
//     else
//     {
//         std::cout << "My round result : ";
//         std::cout << MyRound(Number) - 1 << std::endl;
//     }

//     std::cout << "C++ Round Result: ";
//     std::cout << round(Number) << std::endl;

//     return 0;
// }