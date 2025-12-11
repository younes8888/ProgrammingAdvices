#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

void ReadPositiveNumber(int& ArrLength)
{
    do {
        std::cout << "Enter a positive number of elements: " << std::endl;
        std::cin >> ArrLength;

    } while (ArrLength <= 0);
}

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From -1) + From;
    return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++) 
        Arr1[i] = RandomNumber(1,100);
}

void PrintArray(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr1[i] << " ";
    std::cout << "\n";
}

void SumElementsOfTwoArrays(int Arr1[100], int Arr2[100], int Arr3[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr3[i] = Arr1[i] + Arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr1[100], Arr2[100], Arr3[100],ArrLength;

    ReadPositiveNumber(ArrLength);

    FillArrayWithRandomNumbers(Arr1, ArrLength);
    FillArrayWithRandomNumbers(Arr2, ArrLength);

    std::cout << "\nArray 1 elements: " << std::endl;
    PrintArray(Arr1, ArrLength);

    std::cout << "\nArray 2 elements: " << std::endl;
    PrintArray(Arr2, ArrLength);


    std::cout << "\nSum of array1 and array2 elements: " << std::endl;
    SumElementsOfTwoArrays(Arr1, Arr2, Arr3, ArrLength);
    PrintArray(Arr3, ArrLength);

    return 0;
} 