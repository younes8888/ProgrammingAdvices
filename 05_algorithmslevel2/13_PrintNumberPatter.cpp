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

void PrintNumberPatter(int Num)
{
    for (int i = 65 + Num - 1; i >= 65; i--)
    {
        for(int j = 0; j <= Num - (65 + Num - i); j++)
        {
            std::cout << char(i);
        }
        std::cout << "\n";
    }    
}

int main()
{
    PrintNumberPatter(ReadNum("Enter a number: "));
    return 0;
}