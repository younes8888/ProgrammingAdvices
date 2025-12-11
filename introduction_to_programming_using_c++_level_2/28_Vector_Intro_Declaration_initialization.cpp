#include <iostream>
#include <cstdio>


int main()
{
    std::vector <int> vX = {1,2,3,4,5};

    for (int &Num : vX) //it works also with int Num, but in this case you keep adding new copies
    {
        std::cout << Num << " ";
    }
    printf("\n");

    return 0;
}