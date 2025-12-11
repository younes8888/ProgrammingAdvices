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

int MyFloor(float Number)
{
    if (Number > 0)
        return int(Number);
    else
        return int(--Number);
}

int main()
{
    float Number;
    ReadNumber(Number);

    std::cout << "My floor result : " << MyFloor(Number) << std::endl;
    std::cout << "C++ floor Result: " << floor(Number) << std::endl;

    return 0;
}