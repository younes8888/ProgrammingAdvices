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

int MyCeil
(float Number)
{
    if (Number > 0)
        return int(++Number);
    else
        return int(Number);
}

int main()
{
    float Number;
    ReadNumber(Number);

    std::cout << "My ceil result : " << MyCeil
    (Number) << std::endl;
    std::cout << "C++ ceil Result: " << ceil(Number) << std::endl;

    return 0;
}