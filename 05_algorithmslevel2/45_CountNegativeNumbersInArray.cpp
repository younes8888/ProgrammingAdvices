#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int GenerateRandomNumbers(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

void PrintArray(int Arr[100], int ArrLength)
{

    for (int i = 0; i < ArrLength; i++)
       std::cout << Arr[i] << " ";
    std::cout << "\n";

}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrLength)
{
    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> ArrLength;

    for (int i = 0; i < ArrLength; i++) 
        Arr[i] = GenerateRandomNumbers(-100,100);
    std::cout << "\n";
}

short CountOfNegativeNumbers(int Arr[100], int ArrLength)
{
    int Counter = 0;
    for (int i = 0; i < ArrLength; i++)
    {
        if (Arr[i] < 0)
            Counter++;
    }
    return Counter;
}

int main()
{
    srand((unsigned)time(NULL));
    
     int Arr[100], ArrLength;
     
    FillArrayWithRandomNumbers(Arr, ArrLength);
    
    std::cout << "\nArray Elements: ";
    PrintArray(Arr, ArrLength);

    std::cout << "\nNegative numbers count is: ";
    std::cout << CountOfNegativeNumbers(Arr, ArrLength) << std::endl;

    return 0;
}