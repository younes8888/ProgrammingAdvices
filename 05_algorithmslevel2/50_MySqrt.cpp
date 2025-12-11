#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>


void ReadNumber(float &Number)
{
    std::cout << "Enter a number: " << std::endl;
    std::cin >> Number;
}

int Mysqrt(float Number)
{
    return pow(Number, 0.5);
}

int main()
{
    float Number;
    ReadNumber(Number);
    
    std::cout << "My sqrt result : " << Mysqrt(Number) <<std::endl;

    std::cout << "C++ sqrt Result: " << sqrt(Number) << std::endl;

    return 0;
}