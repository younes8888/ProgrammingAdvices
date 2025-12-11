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

    std::cout << "First element: " << vNumbers.front() << std::endl;
    std::cout << "last element: " << vNumbers.back() << std::endl;

    //return number of elements present in the vector
    std::cout << "size: " << vNumbers.size() << std::endl;

    std::cout << "capacity: " << vNumbers.capacity() << std::endl;

    std::cout << "Is it empty? : " << vNumbers.empty() << std::endl;

    return 0;
}