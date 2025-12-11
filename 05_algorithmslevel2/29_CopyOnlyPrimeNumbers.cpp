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
    int RandomNumber = rand() % (To - From -1) + From;
    return RandomNumber;
}

void FillArrayWithRandomNumbers(int Arr1[100], int& Arr1Length)
{
    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> Arr1Length;
    
    for (int i = 0; i < Arr1Length; i++) 
        Arr1[i] = RandomNumber(1,100);
    std::cout << "\n";
}

void PrintArray(int Arr1[100], int Arr1Length, std::string Msg)
{
    std::cout << Msg;
    for (int i = 0; i < Arr1Length; i++)
        std::cout << Arr1[i] << " ";
    std::cout << "\n";
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
        if (CheckPrime(Arr1[i]) == 1)
        {
            Arr2[j] = Arr1[i];
            Arr2Length++;
            j++;
        }
    }
    return j;
}

int main()
{
    srand((unsigned)time(NULL));
    
    int Arr1[100], Arr2[100], Arr1Length, Arr2Length;
    Arr2Length = 0;
    FillArrayWithRandomNumbers(Arr1, Arr1Length);
    
    CopyOnlyPrimeNumbers(Arr1,Arr2, Arr1Length, Arr2Length);

    PrintArray(Arr1, Arr1Length, "Array 1 elements: \n");
     std::cout << "\n";
    PrintArray(Arr2, Arr2Length, "Array 2 elements after copy: \n");
    
    std::cout << "\n";

    return 0;
} 