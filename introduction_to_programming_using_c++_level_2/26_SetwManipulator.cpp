#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "---------|--------------------------------|---------|" << std::endl;
    std::cout << "  Code   |               Name             |  Mark   |" << std::endl;
    std::cout << "---------|--------------------------------|---------|" << std::endl;
    
    std::cout << std::setw(9) << "C101" << "|" << std::setw(32) << "introduction to Programming 1" << "|" << std::setw(9) << "95" << "|" << std::endl;
   
    std::cout << std::setw(9) << "C102" << "|" << std::setw(32) << "Computer Hardware" << "|" << std::setw(9) << "88" << "|" << std::endl;
    
    std::cout << std::setw(9) << "C1035243" << "|" << std::setw(32) << "Network" << "|" << std::setw(9) << "75" << "|" << std::endl;
    
    std::cout << "---------|--------------------------------|---------|" << std::endl;
    
    return 0;
}