#include <string>
#include <iostream>

std::string ReadString()
{
    std::string Str;
    std::cout << "Please enter a string: " << std::endl;
    std::getline(std::cin, Str);
    return Str;
}

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

short CountVowelsInString(std::string Str)
{
    short Counter = 0;
    for (short i = 0; i < Str.length(); i++)
    {
        if (IsVowel(Str[i]))
            Counter++;
    }
    return Counter;
}
int main()
{
    std::string Str = ReadString();

    std::cout << "\nNumber of vowels is: " << CountVowelsInString(Str) << std::endl;

    return 0;
}