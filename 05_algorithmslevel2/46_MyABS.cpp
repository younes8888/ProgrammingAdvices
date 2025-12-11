#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

void ReadNumber(int &Number)
{
    std::cout << "Enter a number: " << std::endl;
    std::cin >> Number;
}

int MyABS(int Number)
{
    if (Number > 0)
        return Number;
    else
        return (Number * -1);
}

int main()
{
    int Number;
    ReadNumber(Number);
    
    std::cout << "My abs result: ";
    std::cout << MyABS(Number) << std::endl;
    std::cout << "C++ abs Result: ";
    std::cout << abs(Number) << std::endl;

    return 0;
}