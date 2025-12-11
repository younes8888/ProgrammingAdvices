#include <iostream>
#include <string>


std::string RemovePunctuationFromString(std::string Str)
{
    std::string NewStr = "";
    short i = 0;

    for (short i = 0; i < Str.length(); i++)
    {
        if (!ispunct(Str[i]))
        {
            NewStr+=Str[i];
        }
    }
    return NewStr;
}

int main()
{

    std::string Str = "Welcome to Belgium, Belgium is a nice country; it's amazing.";
    std::string NewStr = RemovePunctuationFromString(Str);

    std::cout << "Original string: \n" << Str << std::endl;
    std::cout << "Punctuation removed: \n" << NewStr << std::endl;
    return 0;
}