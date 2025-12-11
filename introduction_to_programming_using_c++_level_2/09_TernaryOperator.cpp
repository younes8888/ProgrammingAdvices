#include <iostream>

int main()
{
    int Number;
    std::cout << "Enter your number: \n";
    std::cin >> Number;

    std::string Result;

    Result = Number == 0 ? "Zero" : Number > 0 ? "Positive" : "Negative";

    std::cout << "Number is " << Result << std::endl;
    return 0;
}