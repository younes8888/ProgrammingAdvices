#include <iostream>
#include <string>

std::string ReadString()
{
    std::string Str;
    std::cout << "Please enter your string: " << std::endl;
    std::getline(std::cin, Str);
    return Str;
}

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void ConvertVowelsInString(std::string Str)
{

    std::cout << "Vowels in string are: ";
    
    for (short i = 0; i < Str.length(); i++)
    {
        if (IsVowel(Str[i]))
        {
            std::cout << Str[i] << " ";
        }
    }

}
int main()
{
    std::string Str = ReadString();

    ConvertVowelsInString(Str);
    std::cout << "\n";

    return 0;
}