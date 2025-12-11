#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


bool IsAPrimeNumber(int Num)
{
    if (Num == 1)
        return true;

    for (int i = 2; i < (Num - 1); i++)
    {
        if (Num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int Num = 5;

    if (IsAPrimeNumber(Num) == true)
        std::cout << Num << " is Prime" << std::endl;
    else
        std::cout << Num << " is not prime" << std::endl;
    return 0;
}