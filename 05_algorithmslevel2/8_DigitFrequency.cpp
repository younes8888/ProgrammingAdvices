#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

void ReadNum(int& Num, int& Digit)
{
    do {
        std::cout << "Enter a number: " << std::endl;
        std::cin >> Num;
        std::cout << "Enter a digit: " << std::endl;
        std::cin >> Digit;
    } while (Num < 0 || Digit < 0);
}

int DigitFrequencyInNumber(int Num, int Digit)
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
void PrintFrequency(int Count, int Digit)
{
    std::cout << "Digit " << Digit << " frequency is " << Count << " times" << std::endl;
}
int main()
{

    int Num, Digit, Count;
    ReadNum(Num, Digit);
    Count = DigitFrequencyInNumber(Num, Digit);
    PrintFrequency(Count, Digit);

    return 0;
}