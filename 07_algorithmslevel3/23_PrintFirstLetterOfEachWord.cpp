#include <iostream>
#include <string>

std::string ReadInput()
{
    std::string Str;
    std::cout << "\nPlease, Enter your string: \n";
    std::getline(std::cin, Str);
    return Str;
}

void PrintFirstLetterOfEachWord(std::string Str)
{
    bool isFirstLetter = true;
    std::cout << "First letters of this string: " << std::endl;

    for (short i = 0; i < Str.length(); i++)
    {
       if (Str[i] != ' ' && isFirstLetter)
       {
            std::cout << Str[i] << std::endl;
       }
       isFirstLetter = (Str[i] == ' ') ? true : false;
    }
}

// void PrintFirstLetterOfEachWord(std::string Str)
// {
    
//     for (short i = 0; Str[i] != '\0'; i++)
//     {
//         if (i == 0)
//             std::cout << Str[i] << std::endl;
//         if (Str[i] == ' ')
//         {
//             std::cout << Str[i + 1] << std::endl;
//         }
//     }
// }

int main()
{
    
    PrintFirstLetterOfEachWord(ReadInput());

    return 0;
}