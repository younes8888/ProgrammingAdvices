#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

enum enCharType{

    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

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

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97,122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65,90));    
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33,47));
            break;
        }
        case enCharType::Digit:
        {
                return char(RandomNumber(48,57));
                break;
        }
    }
    return '\0';
}
std::string GenerateWord(enCharType CharType, short Length)
{
    std::string Word;
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

std::string GenerateKey()
{
    std::string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}

void FillArrayWithKeys(std::string Arr1[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        Arr1[i] = GenerateKey();
    }
}

void PrintStringArray(std::string Arr1[100], int ArrLength)
{
    std::cout << "Array elements are: \n" << std::endl;
     
    for (int i = 0; i < ArrLength; i++)
    {
        std::cout << "Array [" << i << "]" << "\t" << ": " << Arr1[i] << std::endl;
    }    
}
int main()
{
    srand((unsigned)time(NULL));

    std::string Arr1[100];
    int ArrLength;
    ArrLength = ReadPositiveNumber("Type number of keys to generate: \n");
    FillArrayWithKeys(Arr1, ArrLength);
    PrintStringArray(Arr1, ArrLength);
    return 0;
}