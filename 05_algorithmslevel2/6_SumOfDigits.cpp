#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadNum()
{
    int Num;
    std::cout << "Enter a num: " << std::endl;
    std::cin >> Num;
    return Num;
}

int SumOfDigits(int Num)
{
    int Sum = 0;
    int Remainder = 0;
    while (Num > 0)
    {   
        Remainder = (Num % 10);
        Num = Num / 10;
        Sum = Remainder + Sum;
    }
    return Sum;
}
void PrintSum(int Sum)
{
    std::cout << "Total sum is: " << Sum << std::endl;
}

int main()
{
    PrintSum(SumOfDigits(ReadNum()));
    return 0;
}