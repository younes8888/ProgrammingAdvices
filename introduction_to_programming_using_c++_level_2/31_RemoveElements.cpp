#include <vector>
#include <iostream>

int main()
{
    std::vector <int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    std::cout << "Stack size= " << vNumbers.size() << std::endl;
    
    // for(int &Number: vNumbers)
    // {
    //     std::cout << Number << " ";
    // }

    std::cout << std::endl;

    // vNumbers.pop_back();
    // vNumbers.pop_back();
    // vNumbers.pop_back();
    // vNumbers.pop_back();
    // vNumbers.pop_back();

    //Or

    vNumbers.clear();

    std::cout << "Stack size= " << vNumbers.size() << std::endl;


    // for(int &Number : vNumbers)
    // {
    //     std::cout << Number << " ";
    // }
    std::cout << std::endl;

    return 0;
}