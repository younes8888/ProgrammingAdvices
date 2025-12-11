#include <iostream>
#include <cmath>

void Function4()
{
    std::cout << "I am function 4\n";
}

void Function3()
{
    Function4();
}

void Function2()
{
    Function3();
}

void Function1()
{
    Function2();
}

int main()
{
    Function1();
    return 0;
}