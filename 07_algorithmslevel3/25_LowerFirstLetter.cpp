#include <iostream>
#include <string>

void ReadInput(std::string &Str)
{
    std::cout << "\nPlease Enter your String?\n";
    std::getline(std::cin, Str);
}

void FirstLetterToLowerCase(std::string &Str)
{
    bool isFirstLetter = true;

    for (short i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && isFirstLetter)
        {
            Str[i] = tolower(Str[i]);
        }
        isFirstLetter = (Str[i] == ' ') ? true : false;
    }
}

int main()
{
    std::string Str;
    ReadInput(Str);

    FirstLetterToLowerCase(Str);
    std::cout << "\nString after conversion: \n";

    std::cout << Str << std::endl;

    return 0;
}