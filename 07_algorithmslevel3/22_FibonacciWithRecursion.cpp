#include <iostream>
#include <string>



void PrintFibonacciUsingRecursion(short Number, int Previous1, int Previous2)
{
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Previous1 + Previous2;
        Previous2 = Previous1;
        Previous1 = FebNumber;
        std::cout << FebNumber << " ";
        PrintFibonacciUsingRecursion(Number - 1, Previous1, Previous2);
    }
}

int main()
{
    PrintFibonacciUsingRecursion(10,0,1);
    std::cout << "\n";
    return 0;
}