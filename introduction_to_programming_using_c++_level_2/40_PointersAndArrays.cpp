#include <iostream>

int    main()
{
    int Arr[4] = {10,20,30,40};
    int *ptr;
    ptr = Arr;

    std::cout << "Memory addresses: \n";

    std::cout << ptr << std::endl;
    std::cout << ptr + 1 << std::endl;
    std::cout << ptr + 2 << std::endl;
    std::cout << ptr + 3 << std::endl;

    std::cout << "\nValues are: \n";
    
    std::cout << *(ptr) << std::endl;
    std::cout << *(ptr + 1) << std::endl;
    std::cout << *(ptr + 2) << std::endl;
    std::cout << *(ptr + 3) << std::endl;

    return 0;
}