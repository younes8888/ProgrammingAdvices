#include <iostream>

// int Number = 1;

void MyFunction()
{
    static int Number = 1;
    std::cout << "Value of number: " << Number << "\n";
    Number++;
}

int main()
{
    MyFunction();
    MyFunction();
    MyFunction();
    
    return 0;
}