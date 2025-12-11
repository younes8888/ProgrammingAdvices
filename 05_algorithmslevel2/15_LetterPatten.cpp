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

void LetterPattern(int Num)
{
    for (int i = 65; i < (65 + Num); i++)
    {   
        for(int j = 65; j <= i; j++)
        {
            std::cout << char(i);
        }
        std::cout << "\n";
    }    
}

int main()
{
    LetterPattern(ReadNum("Enter a number: "));
    return 0;
} 