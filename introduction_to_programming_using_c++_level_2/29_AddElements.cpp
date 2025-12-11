#include <iostream>
#include <cstdio>
#include <vector>



void ReadNumbers(std::vector <int> &vNumbers)
{
    int Number;
    char ReadMore = 'Y';

    while(ReadMore == 'y' || ReadMore == 'Y')
    {
        std::cout << "Please enter a number: ";
        std::cin >> Number;

        vNumbers.push_back(Number);

        std::cout << "\nDo you want to add another number: [y]Yes, [n]No: ";
        std::cin >>  ReadMore;
    }

}

void PrintNumbers(std::vector <int> &vNumbers)
{
    std::cout << "Numbers Vector: \n";

    for (int &Num: vNumbers)
    {
        std::cout << Num << " ";
    }
    
    std::cout << std::endl;

}

int main()
{
    std::vector <int> vNumbers;

    ReadNumbers(vNumbers);
    PrintNumbers(vNumbers);

    return 0;
}

// void ReadNumbers(std::vector <int> &vNumbers)
// {
//     int Number;
//     char ReadMore = 'n';

//     do{
//         std::cout << "\nEnter a number: ";
//         std::cin >> Number;
//         vNumbers.push_back(Number);
//         std::cout << "\nDo you want to add another number: [y]Yes, [n]No: ";
//         std::cin >>  ReadMore;
//     } while(ReadMore == 'y' || ReadMore == 'Y');

// }

// void PrintNumbers(std::vector <int> vNumbers)
// {
//     std::cout << "\nVector contains these objects: \n";

//     for (int &Num: vNumbers)
//     {
//         std::cout << Num << " ";
//     }
    
//     std::cout << "\n";

// }

// int main()
// {
//     std::vector <int> vNumbers;

//     ReadNumbers(vNumbers);
//     PrintNumbers(vNumbers);

//     return 0;
// }