#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From -1) + From;
    return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr1[100], int& ArrLength)
{
    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> ArrLength;
    
    for (int i = 0; i < ArrLength; i++) 
        Arr1[i] = RandomNumber(1,100);
    std::cout << "\n";
}

void PrintArray(int Arr1[100], int ArrLength, std::string Msg)
{
    std::cout << Msg;
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr1[i] << " ";
    std::cout << "\n";
}

void CopyArrayElements(int Arr1[100], int Arr2[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i ++)
        Arr2[i] = Arr1[i];
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr1[100], Arr2[100], ArrLength;
    
    FillArrayWithRandomNumbers(Arr1, ArrLength);
    
    CopyArrayElements(Arr1,Arr2, ArrLength);

    PrintArray(Arr1, ArrLength, "Array 1 elements: \n");
     std::cout << "\n";
    PrintArray(Arr2, ArrLength, "Array 2 elements after copy: \n");
    
    std::cout << "\n";

    return 0;
} 