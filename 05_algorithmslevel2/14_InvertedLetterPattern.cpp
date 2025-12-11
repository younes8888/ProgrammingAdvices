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

void InvertedLetterPattern(int Num)
{
    for (int i = 65 + (Num - 1); i >= 65; i--)
    {   
        for(int j = 1; j <= Num - (65 + Num - 1- i); j++)
        {
            std::cout << char(i);
        }
        std::cout << "\n";
    }    
}

int main()
{
    InvertedLetterPattern(ReadNum("Enter a number: "));
    return 0;
}