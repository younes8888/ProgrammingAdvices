#include <iostream>
#include <string>

std::string ReadString()
{
    std::string Str;
    std::cout << "Please enter your string\n";
    std::getline(std::cin, Str);
    return Str;
}

char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

std::string InvertAllLettersInString(std::string Str)
{
    std::cout << "String after inverting all letters case:\n";

    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = InvertLetterCase(Str[i]);
    }
    std::cout << "\n";
    return Str;
}

int main()
{

    std::string Str = ReadString();
    Str = InvertAllLettersInString(Str);
    std::cout << Str << std::endl;
    return 0;
}