#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int GenerateRandomNumbers(int From, int To)
{
    int RandomNumber = rand() % (To - From -1) + From;
    return RandomNumber;
}

void PrintArray(int Arr[100], int ArrLength)
{
     std::cout << "Array Elements: ";

    for (int i = 0; i < ArrLength; i++)
       std::cout << Arr[i] << " ";
    std::cout << "\n";

}

void FillArrayWithRandomNumbers(int Arr[100], int& ArrLength)
{
    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> ArrLength;

    for (int i = 0; i < ArrLength; i++) 
        Arr[i] = GenerateRandomNumbers(1,100);
    std::cout << "\n";
}


int main()
{
    srand((unsigned)time(NULL));
    
     int Arr[100], ArrLength;
     
    FillArrayWithRandomNumbers(Arr, ArrLength);
    PrintArray(Arr, ArrLength);
    return 0;
} 



// int ReadPositiveNumber(std::string Msg)
// {
//     int Number = 0;
//     do{
//         std::cout << Msg << std::endl;
//         std::cin >> Number;
//     } while(Number <= 0);
//     return Number;
// }

// int GenerateRandomNumbers(int From, int To)
// {
//     int RandomNumber = rand() % (To - From -1) + From;
//     return RandomNumber;
// }

// void PrintArray(int Arr[100], int ArrLength)
// {
//      std::cout << "Array Elements: ";

//     for (int i = 0; i < ArrLength; i++)
//     {
//        std::cout << Arr[i] << " ";
//     }
//     std::cout << "\n";
// }

// void FillArrayWithRandomNumbers(int Arr[100], int ArrLength)
// {
//     for (int i = 0; i < ArrLength; i++)
//     {
//         Arr[i] = GenerateRandomNumbers(1,100);
//     }
//     std::cout << "\n";
//     PrintArray(Arr, ArrLength);
// }


// int main()
// {
//     srand((unsigned)time(NULL));
    
//      int Arr[100], ArrLength;
     
//     ArrLength = ReadPositiveNumber("Select the array size to fill with random numbers: ");
//     FillArrayWithRandomNumbers(Arr, ArrLength);

//     return 0;
// } 