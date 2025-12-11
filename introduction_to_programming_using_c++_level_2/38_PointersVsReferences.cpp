#include <iostream>

int main()
{
    int a = 10, b = 30;

    int *p;
    int &Ref = a;

    p = &a;
    // Ref = b; incorrect;

    std::cout << p << std::endl;
    std::cout << &Ref << std::endl;

    p = &b;
    std::cout << &b << std::endl;
    std::cout << p << std::endl;

    std::cout << *p++ << std::endl;
    return 0;
}