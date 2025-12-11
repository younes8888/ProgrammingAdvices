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

void PrintInvertedPatter(int Num)
{
    int j;
    while (Num > 0)
    {
        j = 0;
        while (Num > j)
        {
            std::cout << Num;
            j++;
        }
        std::cout << "\n";
        Num--;
    }
}

int main()
{
    int Number1 = ReadNum("Enter a number: ");
    PrintInvertedPatter(Number1);
    return 0;
}