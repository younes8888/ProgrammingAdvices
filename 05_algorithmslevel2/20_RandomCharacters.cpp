#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

enum enRandomAsciis
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};


int RandomNumber(int From, int To)
{
    int Num = rand() % (To - From + 1) + From;
    return
     Num;
}
char GetRandomCharacter(enRandomAsciis CharType)
{
    switch (CharType)
    {
        case enRandomAsciis::SmallLetter:
        {
            return char(RandomNumber(97,122));
            break;
        }

        case enRandomAsciis::CapitalLetter:
        {
            return char(RandomNumber(65,90));
            break;
        }

        case enRandomAsciis::SpecialCharacter:
        {
           return char(RandomNumber(33,47));
           break;
        }
        case enRandomAsciis::Digit:
        {
            return char(RandomNumber(33,47));
            break;
        }

    }
}


int main()
{
    srand((unsigned)time(NULL));

    std::cout << GetRandomCharacter(enRandomAsciis::SmallLetter) << std::endl;
    std::cout << GetRandomCharacter(enRandomAsciis::CapitalLetter) << std::endl;
    std::cout << GetRandomCharacter(enRandomAsciis::SpecialCharacter) << std::endl;
    std::cout << GetRandomCharacter(enRandomAsciis::Digit) << std::endl;

    return 0;
}