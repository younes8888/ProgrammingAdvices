#include <iostream>



int main()
{
    int a = 10;
    int b = 30;
    int c = 40;

    std::cout << "value of a: "<< a << std::endl;
    std::cout << "address of &a is: " << &a << std::endl;
    std::cout << "address of &b is: " << &b << std::endl;

    int *p = &a;
    p = &b;

    std::cout << "\nvalue of p: " << p << std::endl;
    std::cout << "address of &p: " << &p << std::endl;
    std::cout << "dereferencing of *p: " << *p << std::endl;
    

    *p = c;
    std::cout << "\naddress of &p: " << &p << std::endl;
    std::cout << "dereferencing of *p: " << *p << std::endl;
    std::cout << "value of a: "<< a << std::endl;
    std::cout << "value of b: "<< b << std::endl;

    return 0;

}