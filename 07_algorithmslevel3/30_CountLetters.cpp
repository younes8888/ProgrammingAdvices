#include <iostream>
#include <string>

std::string ReadString()
{
    std::string Str;
    std::cout << "Please enter your string: " << std::endl;
    std::getline(std::cin, Str);
    return Str;
}

char ReadChar()
{
    char c;
    std::cout << "\nPlease enter a character: " << std::endl;
    std::cin >> c;
    return c;
}

int CountCharacterInString(std::string Str, char c, bool MatchCase = true)
{
    int Counter = 0;
    for (short i = 0; i < Str.length(); i++)
    {
        if (MatchCase)
        {
            if (Str[i] == c)
                Counter++;
        } else
        {
            if (tolower(Str[i] == tolower(c)))
                Counter++;
        }
    }
    return Counter;
}
int main()
{
    std::string S1 = ReadString();
    char c = ReadChar();

    std::cout << "\nLetter '" << c << "' Counter = " << CountCharacterInString(S1,c) << std::endl;
    return 0;
}