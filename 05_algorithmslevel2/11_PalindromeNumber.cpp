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

int ReverseNum(int Num)
{
    int Remainder = 0;
    int Num2 = 0;

    while (Num > 0)
    {
        Remainder = Num % 10;
        Num2 =  Num2 * 10 + Remainder;   
        Num = Num / 10;
    }
    return Num2;
}

void IsPalindromeNumber(int Num1, int Num2)
{
    if (Num1 == Num2)
        std::cout << "The number " << Num1 << " is a palindrome number." << std::endl;
    else
        std::cout << "The number " << Num2 << " is NOT a palindrome number." << std::endl;
}

int main()
{
    int Number1 = ReadNum("Enter a number: ");
    int Number2 = ReverseNum(Number1);
    IsPalindromeNumber(Number1, Number2);
    return 0;
}