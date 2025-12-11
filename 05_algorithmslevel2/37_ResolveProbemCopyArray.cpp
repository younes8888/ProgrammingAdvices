#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


int RandomNumber(int To, int From)
{
    int Num = rand() % (To - From + 1) + From;
    return Num;
}

void FillArrayWithRandomNumbers(int Arr1[100], int& ArrLength)
{
    std::cout << "\nEnter a number of elements: \n";
    std::cin >> ArrLength;

    for (int i = 0; i < ArrLength; i++)
        Arr1[i] = RandomNumber(1,100);
}

void AddArrayElement(int Number, int Arr[100], int &ArrLength)
{
    ArrLength++;
    Arr[ArrLength - 1] = Number;
}
void CopyArrayToArray(int ArrSource[100], int ArrDestination[100], int ArrLength, int &ArrLength2)
{
    for (int i = 0; i < ArrLength; i++)
        AddArrayElement(ArrSource[i], ArrDestination, ArrLength2);
}

void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int Arr1[100], Arr2[100], ArrLength1 = 0, ArrLength2 = 0;

    FillArrayWithRandomNumbers(Arr1, ArrLength1);


    std::cout << "\nArray 1 elements: " << std::endl; 
    PrintArray(Arr1,ArrLength1);
   
    CopyArrayToArray(Arr1, Arr2, ArrLength1, ArrLength2);
    
    std::cout << "\nArray 2 elements: " << std::endl; 
    PrintArray(Arr2, ArrLength2);


    return 0;
}