#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime = 2
};

int RandomNumber(int From, int To)
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

enPrimeNotPrime CheckPrime(int Num)
{
    if (Num <= 1)
        return enPrimeNotPrime::NotPrime;
    int M = round(Num / 2);

    for (int i = 2; i <= M; i++)
    {
        if (Num % i == 0)
        {
            return enPrimeNotPrime::NotPrime;
        }
    }
    return enPrimeNotPrime::Prime;
}

int CopyOnlyPrimeNumbers(int Arr1[100], int Arr2[100], int Arr1Length, int& Arr2Length)
{
    int j = 0;
    for (int i = 0; i < Arr1Length; i ++)
    {
        if (CheckPrime(Arr1[i]) == enPrimeNotPrime::Prime)
        {
            AddArrayElement(Arr1[i], Arr2, Arr2Length);
        }
    }
    return j;
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
   
    CopyOnlyPrimeNumbers(Arr1, Arr2, ArrLength1, ArrLength2);
    
    std::cout << "\nArray 2 prime numbers: " << std::endl; 
    PrintArray(Arr2, ArrLength2);


    return 0;
}  