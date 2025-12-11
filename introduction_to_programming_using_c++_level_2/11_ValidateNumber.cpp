#include <iostream>

int ReadNumber()
{
    int Number;
    std::cout << "Please enter a number: " << std::endl;
    std::cin >> Number;

    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number, Enter a valid one: \n";
        std::cin >> Number;
    }
    return Number;
}
int main()
{

    ReadNumber();
    return 0;
}