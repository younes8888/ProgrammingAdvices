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

void GenerateKeys(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        std::cout << "Key [" << i << "]" << "\t" << ": ";
        std::cout << GenerateKey() << std::endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please Enter the number of keys to generate: \n"));
    return 0;
}
// int ReadInput()
// {
//     int Num;
//     do {
//         std::cout << "Enter number of keys to generate: " << std::endl;
//         std::cin >> Num;
//     } while (Num < 0);
//     return Num;
// }

// int RandomNumber(int From, int To)
// {
//     int Num = rand() % (To - From + 1) + From;
//     return
//      Num;
// }

// void PrintKeys(int Trials, std::string Key)
// {
//     std::cout << "Key[" << Trials << "]: " << Key << std::endl;
// }
// void GenerateKeys(int Num)
// {
//     int Trials = 0;
//     int Key = 0;
//     int Counter = 0;
//     for (int i = 0; i < Num; i++)
//     {
//         std::string WholeKey;
//         for (int j = 0; j <= 15; j++)
//         {
//             Key = RandomNumber(65,90);
//             Counter++;
//             WholeKey = WholeKey + char(Key);
//             if (Counter == 4 || Counter == 8 || Counter == 12)
//             {
//                 WholeKey = WholeKey + "-";
//             }
//         }
//         Trials++;
//         Counter = 0;
//         PrintKeys(Trials, WholeKey);
//         std::cout << "\n";
//         WholeKey = "";
//     }
// }

// int main()
// {
//     srand((unsigned)time(NULL));

//     int Num = ReadInput();
//     std::cout << "\n";
//     GenerateKeys(Num);

//     return 0;
// }