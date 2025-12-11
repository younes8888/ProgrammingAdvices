#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

void FillArray(int Arr1[100], int& ArrLength)
{
    ArrLength = 10;

    Arr1[0] = 10;
    Arr1[1] = 10;
    Arr1[2] = 10;
    Arr1[3] = 50;
    Arr1[4] = 50;
    Arr1[5] = 70;
    Arr1[6] = 70;
    Arr1[7] = 70;
    Arr1[8] = 70;
    Arr1[9] = 90;

}

void AddArrayElement(int Number, int Arr[100], int &ArrLength)
{
    ArrLength++;
    Arr[ArrLength - 1] = Number;
}

void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr[i] << " ";
    std::cout << "\n";
}
short FindNumberPositionInArray(int Number, int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        if (Arr1[i] == Number)
                return i;
    }
    return -1;
}
bool IsNumberInArray(int Number, int Arr1[10],int Position)
{
    return FindNumberPositionInArray(Number, Arr1, Position) != -1;
}

void CopyOnlyDistinctNumbers(int ArrSource[10], int ArrDestination[10], int SourceLength1, int &DestinationLength2)
{
    for (int i = 0; i < SourceLength1; i++)
    {

        if (!IsNumberInArray(ArrSource[i], ArrDestination, DestinationLength2))
        {
             AddArrayElement(ArrSource[i], ArrDestination, DestinationLength2);
        }
    }
}

int main()
{
    int Arr1[100], Arr2[100], ArrLength1 = 10, ArrLength2 = 0;

    FillArray(Arr1, ArrLength1);
    std::cout << "\nArray 1 elements: " << std::endl; 
    PrintArray(Arr1,ArrLength1);
   
    CopyOnlyDistinctNumbers(Arr1, Arr2, ArrLength1, ArrLength2);

    std::cout << "\nArray 2 distinct elements: " << std::endl; 
    PrintArray(Arr2, ArrLength2);


    return 0;
}  