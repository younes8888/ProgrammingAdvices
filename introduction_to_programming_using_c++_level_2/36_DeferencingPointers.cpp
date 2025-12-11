#include <iostream>

int main()
{
    int a = 10;
    
    std::cout << "\nvalue of a: "<< a << std::endl;
    std::cout << "address of &a is: " << &a << std::endl;

    int *p = &a;

    std::cout << "\nvalue of p: " << p << std::endl;
    std::cout << "address of &p: " << &p << std::endl;
    std::cout << "dereferencing of *p: " << *p << std::endl;
    

    *p = 90;
    std::cout << "\nvalue of p: "<< p << std::endl;
    std::cout << "value of a: "<< a << std::endl;
    std::cout << "address of &p: " << &p << std::endl;

    *p = 50;
    std::cout << "\nvalue of p: "<< p << std::endl;
    std::cout << "value of a: "<< a << std::endl;
    std::cout << "address of &p: " << &p << std::endl;
   

    return 0;

}