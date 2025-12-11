#include <iostream>
#include <string>



void ReadString(std::string &Str)
{
    std::cout << "\nPlease Enter your String\n";
    std::getline(std::cin, Str);
}

void ConvertToUpperCase(std::string &Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = toupper(Str[i]);
    }
}

void ConvertToLowerCase(std::string &Str)
{
    for (short i = 0; i < Str.length(); i++)
    {
        Str[i] = tolower(Str[i]);
    }
}

void PrintString(std::string Str)
{
    std::cout << Str << std::endl;
}

int main()
{
    std::string Str;
    ReadString(Str);

    std::cout << "\nString after upper: \n";
    ConvertToUpperCase(Str);
    PrintString(Str);

    std::cout << "\nString after lower: \n";
    ConvertToLowerCase(Str);
    PrintString(Str);


    return 0;
}