#include <string>
#include <iostream>


std::string ReadInput()
{
    std::string Str;
    std::cout << "\nPlease Enter your string: \n";
    std::getline(std::cin, Str);

    return Str;
}

std::string ConvertFirstLetterOfEachWordToUpper(std::string Str)
{
    bool isFirstLetter = true;

    for (short i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && isFirstLetter)
        {
            Str[i] = toupper(Str[i]);
        }
        isFirstLetter = (Str[i] == ' ') ? true : false;
    }
    return Str;
}

void PrintString(std::string Str)
{
    std::cout << "\nString after conversion: " << std::endl;
    std::cout << Str << std::endl;
}

int main()
{

    PrintString(ConvertFirstLetterOfEachWordToUpper(ReadInput()));

    return 0;
}