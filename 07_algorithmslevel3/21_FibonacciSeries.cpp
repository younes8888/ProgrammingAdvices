#include <string>
#include <iostream>

void Fibonacci(int Num)
{
    int Previous = 0;
    int Next = 1;
    int NewValue = 0;
    int i  = 1;
    std::cout << "1 ";
    while (i < Num)
    {
        NewValue = Previous + Next;
        std::cout << NewValue << " ";
        Previous = Next;
        Next = NewValue;
        i++;
    }
    std::cout << "\n";

}

int main()
{
    int Num = 10;

    Fibonacci(Num);

    return 0;
}