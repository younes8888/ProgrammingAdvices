#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadPositiveNumber(std::string Msg)
{
    int Number = 0;
    do{
        std::cout << Msg << std::endl;
        std::cin >> Number;
    } while(Number <= 0);
    return Number;
}

int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}


void FillArrayWithRandomNumbers(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i ++)
        Arr1[i] = RandomNumber(10, 100);
}

void PrintArrayElements(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr1[i] << " ";
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

bool IsNumberInArray(int Number, int Arr1[100], int ArrLength)
{
    return FindNumberPositionInArray(Number, Arr1, ArrLength) != -1;
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr1[100], ArrLength;
    ArrLength = ReadPositiveNumber("Enter the length of the array: ");
    FillArrayWithRandomNumbers(Arr1, ArrLength);
    PrintArrayElements(Arr1,ArrLength);
    
    short NumToSearch = ReadPositiveNumber("\nPlease, enter number to search for: ");
    std::cout << "\nNumber you are looking for is: " << NumToSearch << std::endl;

    if (!IsNumberInArray(NumToSearch,Arr1, ArrLength))
        std::cout << "\nNo, the number is not found: -(" << std::endl;
    else      
        std::cout << "Yes, the number is found: -(" << std::endl;

    return 0;

}