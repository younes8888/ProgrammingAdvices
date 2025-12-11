#pragma once
#include <iostream>

namespace MyLibrary
{
    void Test()
    {
        std::cout << "Hey, this is my first library function\n";
    }

    int Sum2Numbers(int Num1, int Num2)
    {
        return (Num1 + Num2);
    }
}