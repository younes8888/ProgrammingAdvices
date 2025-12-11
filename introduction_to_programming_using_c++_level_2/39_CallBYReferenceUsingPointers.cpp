#include <iostream>


// Using pointers

void Swap(int *a, int *b)
{
    int Temp = *a;
    *a = *b;
    *b = Temp;
}

int main()
{
    int a = 10, b = 50;

    int *c = &a;
    int *d = &b;

    std::cout << "\nBefore swap a is: " << a << std::endl;
    std::cout << "Before swap a is: " << b << std::endl;

    // Swap(c,d);
    Swap(&a,&b);

    std::cout << "\nAfter swap a is: " << a << std::endl;
    std::cout << "After swap b is: " << b << std::endl;

    return 0;
}

// Doing it with reference, not pointer

// void Swap(int &a, int &b)
// {
//     int Temp = a;
//     a = b;
//     b = Temp;
// }

// int main()
// {
//     int a = 10, b = 50;

//     std::cout << "\nBefore swap a is: " << a << std::endl;
//     std::cout << "Before swap a is: " << b << std::endl;

//     Swap(a,b);

//     std::cout << "\nAfter swap a is: " << a << std::endl;
//     std::cout << "After swap b is: " << b << std::endl;

//     return 0;
// }