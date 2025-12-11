#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From -1) + From;
    return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrLength)
{
    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> ArrLength;
    
    for (int i = 0; i < ArrLength; i++) 
        Arr[i] = RandomNumber(1,100);
}

void PrintArray(int Arr[100], int ArrLength)
{
    std::cout << "Array Elements: ";
    for (int i = 0; i < ArrLength; i++)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << "\n";
}

int MinNumberInArray(int Arr[100], int ArrLength)
{
    int MinNumb = Arr[0];
    for (int i = 0; i < ArrLength; i++)
    {
        if ( MinNumb > Arr[i])
        {
            MinNumb = Arr[i];
        }
    }
    return MinNumb;
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr[100], ArrLength;
    
    FillArrayWithRandomNumbers(Arr, ArrLength);

    PrintArray(Arr, ArrLength);
    
    std::cout << "\n";
    std::cout << "Min number is: " << MinNumberInArray(Arr,ArrLength) << std::endl;

    return 0;
} 