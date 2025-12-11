#include <iostream>

 
void MySum(int a, int b, int c =0 , int d = 1)
{
    std::cout << a + b + c + d<< std::endl;
}

int main()
{
    MySum(1,2);
   return 0;
}
