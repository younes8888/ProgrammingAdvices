#include <iostream>

void Add(int, int);
 
int main()
{
    Add(1,2);    
   return 0;
}

void Add(int a, int b)
{
    std::cout << a + b << std::endl;
}