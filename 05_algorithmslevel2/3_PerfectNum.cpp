#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadPositiveNumber(std::string Msg)
{
    int Num;
    do{
        std::cout << Msg << std::endl;
        std::cin >> Num;

    } while (Num <= 0);
    return Num;
}

bool IsItPerfectNumber(int Num)
{
    int Total = 1;
    for (int i = 2; i < Num; i++)
    {

        if (Num % i == 0)
        {
            Total+=i;
        }
    }
    // std::cout << Total << std::endl;
    return Total == Num;
}

void PrintIfPerfectOrNot(int Num)
{
    if (IsItPerfectNumber(Num))
        std::cout << Num << " is a perfect number." << std::endl;
    else
        std::cout << Num << " is not a perfect number." << std::endl;
}

int main()
{
    PrintIfPerfectOrNot(ReadPositiveNumber("Please, enter a positive number"));
    return 0;   
}