#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int ReadPositiveNumber()
{
    int Number = 0;
    do{
        std::cout << "Please enter a number: ";
        std::cin >> Number;
    } while(Number <= 0);
    return Number;
}

void AddArrayElement(int Number, int Arr[100], int& ArrLength)
{
    ArrLength++;
    Arr[ArrLength - 1] = Number;
}

void InputUserNumbersInArray(int Arr[100], int& ArrLength)
{
    bool AddMore = true;
    do
    {
        AddArrayElement(ReadPositiveNumber(),Arr,ArrLength);
        std::cout << "Do you want to add more numbers? [0]:No,[1]:yes?";
        std::cin >> AddMore;
    } while (AddMore);
    
}

void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
        std::cout << Arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int Arr[100], Number, ArrLength;
    ArrLength = 0;
    InputUserNumbersInArray(Arr, ArrLength);
    
    std::cout << "\nArray Length: " << ArrLength << std::endl;
    std::cout << "Array elements: "; 
    PrintArray(Arr,ArrLength);

    return 0;
}

// int ReadPositiveNumber(std::string Msg)
// {
//     int Number = 0;
//     do{
//         std::cout << Msg;
//         std::cin >> Number;
//     } while(Number <= 0);
//     return Number;
// }

// void SaveNumbersInArray(int Arr[100], int& ArrLength)
// {
//     int YesOrNo = 0;
//     int i = 0;
//     do {
//         Arr[i] = ReadPositiveNumber("Please enter a number: ");
//         i++;
//         ArrLength++;
//         std::cout << "Do you want to add more numbers? [0]:No,[1]:yes?";
//         std::cin >> YesOrNo;
//         std::cout << "\n";
//     } while (YesOrNo == 1);
// }

// void PrintArray(int Arr[100], int ArrLength)
// {
//     std::cout << "\nArray Length: " << ArrLength << std::endl;
//     std::cout << "Array elements: "; 
//     for (int i = 0; i < ArrLength; i++)
//         std::cout << Arr[i] << " ";
//     std::cout << "\n";
// }

// int main()
// {
//     int Arr[100], Number, ArrLength;
//     ArrLength = 0;

//     SaveNumbersInArray(Arr, ArrLength);
//     PrintArray(Arr, ArrLength);

//     return 0;
// }