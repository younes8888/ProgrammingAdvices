#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadNum()
{
    int Num;
    std::cout << "Enter a num: " << std::endl;
    std::cin >> Num;
    std::cout << "\n";
    return Num;
}

void ReverseNum(int Num)
{

    while (Num > 0)
    {
        int Reversed = Num % 10;
        Num = Num / 10;
        std::cout << Reversed << std::endl;
    }
}

int main()
{
    ReverseNum(ReadNum());
    return 0;
}


// std::string ReadNum()
// {
//     std::string Num;
//     std::cout << "Enter a number: " << std::endl;
//     std::cin >> Num;
//     return Num;
// }

// std::string ReverseNum(std::string Num)
// {
//     int Len = Num.length();
//     while (Len >= 0)
//     {
//         std::cout << Num[Len] << std::endl;
//         Len--;
//     }
//     return "hello";
// }

// int main()
// {
//     ReverseNum(ReadNum());
//     return 0;   
// }