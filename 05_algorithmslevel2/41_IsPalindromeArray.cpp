#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

void FillArray(int Arr1[100], int& ArrLength)
{
    ArrLength = 6;

    Arr1[0] = 10;
    Arr1[1] = 20;
    Arr1[2] = 30;
    Arr1[3] = 30;
    Arr1[4] = 20;
    Arr1[5] = 10;
}

void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr[i] << " ";
    std::cout << "\n";
}

bool IsArrayPalindrome(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        if (Arr1[i] != Arr1[ArrLength - i - 1])
            return false;
        // ArrLength--; Or the use i instead
    }
    return true;
}

int main()
{
    int Arr1[100], ArrLength1 = 0;

    FillArray(Arr1, ArrLength1);
    std::cout << "\nArray  elements: " << std::endl; 
    PrintArray(Arr1,ArrLength1);
   
    if (IsArrayPalindrome(Arr1, ArrLength1))
        std::cout << "\nYes, array is palindrome" << std::endl;
    else
        std::cout << "\nNo, array is NOT palindrome\n";

    return 0;
}  