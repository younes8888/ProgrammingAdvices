#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int PrintThreeRandomNumbers(int From, int To)
{
    int Num = rand() % (To - From + 1) + From;
    return Num;
}


int main()
{
    srand((unsigned)time(NULL));

    std::cout << PrintThreeRandomNumbers(20,50) << std::endl;
    std::cout << PrintThreeRandomNumbers(20,50) << std::endl;
    std::cout << PrintThreeRandomNumbers(20,50) << std::endl;

    return 0;
}