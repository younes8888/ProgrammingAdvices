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

void Swap(int& Num1, int &Num2)
{
    int Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) - From;
    return RandomNumber;
}

void FillArrayWithOrderedNumbers(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr1[i] = i + 1;
    }
}

void ShuffleOrderedArray(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Swap(Arr1[RandomNumber(1, ArrLength) - 1], Arr1[RandomNumber(1, ArrLength) - 1]);
    }
}

void PrintArray(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr1[i] << " ";
    std::cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr1[100],ArrLength;

    ReadPositiveNumber(ArrLength);

    FillArrayWithOrderedNumbers(Arr1, ArrLength);

    std::cout << "\nArray elements before shuffle: " << std::endl;
    PrintArray(Arr1, ArrLength);
    
    std::cout << "\nArray elements after shuffle: " << std::endl;
    ShuffleOrderedArray(Arr1,ArrLength);
    PrintArray(Arr1, ArrLength);

    return 0;
} 