#include <iostream>
#include <cmath>

void MySum(int a, int b)
{
    std::cout << a + b << std::endl;
}

void MySum(double a, double b)
{
    std::cout << a + b << std::endl;
}

void MySum(int a, int b, int c)
{
    std::cout << a + b + c << std::endl;
}

void MySum(int a, int b, int c, int d)
{
    std::cout << a + b + c + d<< std::endl;
}

int main()
{
    MySum(1,2);
    MySum(34523452,234523);
    MySum(10,30,30);
    MySum(49,9,9,9);

   return 0;
}
