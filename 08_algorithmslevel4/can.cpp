#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

int main()
{

    int Num = 26;
    int output = 26 % 10;
    int digit = Num - output;
    
    std::cout << output << std::endl;
    std::cout << digit << std::endl;


}