#include <iostream>

void Function1(int &x)
{
    std::cout << "Address of x is: " << &x << std::endl;
    x++;
}

int main()
{
    int a = 10;
    std::cout << "Address of a is: " << &a << std::endl;
    Function1(a);
    std::cout << "\n A after calling function: "<< a << std::endl;

    return 0;

}