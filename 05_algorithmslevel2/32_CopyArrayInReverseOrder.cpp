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
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr1[i] = RandomNumber(1, ArrLength);
    }
}

void CopyArrayInReverseOrder(int ArrSource[100], int ArrDestination[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        ArrDestination[i] = ArrSource[(ArrLength - 1) - i];
}

// void CopyArrayInReverseOrder(int Arr1[100], int Arr2[100], int ArrLength)
// {
//     int j = ArrLength - 1;
//     for (int i = 0; i < ArrLength; i++)
//     {
//         Arr2[i] = Arr1[j];
//         j--;
//     }
// }

void PrintArray(int Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr1[i] << " ";
    std::cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr1[100],Arr2[100],ArrLength;

    ReadPositiveNumber(ArrLength);

    FillArrayWithRandomNumbers(Arr1, ArrLength);

    std::cout << "\nArray elements in random order: " << std::endl;
    PrintArray(Arr1, ArrLength);
    
    std::cout << "\nArray elements int reverse oder: " << std::endl;
    CopyArrayInReverseOrder(Arr1,Arr2,ArrLength);
    PrintArray(Arr2, ArrLength);

    return 0;
} 