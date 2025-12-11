#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadPositiveNumber(std::string Msg)
{
    int Num = 0;
    do{
        std::cout << Msg << std::endl;
        std::cin >> Num;

    } while (Num <= 0);
    return Num;
}

bool IsItPerfectNumber(int Num)
{
    int Total = 0;
    for (int i = 1; i < Num; i++)
    {

        if (Num % i == 0)
        {
            Total+=i;
        }
    }
    return Total == Num;
}

void PrintPerfectNumbersFrom1ToN(int Num)
{
     for (int Start = 1; Start < Num; Start++)
    {
        if (IsItPerfectNumber(Start))
        {
            std::cout << Start << std::endl;
        }
    }
   
}

int main()
{
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please, enter a positive number: "));

    return 0;   
}