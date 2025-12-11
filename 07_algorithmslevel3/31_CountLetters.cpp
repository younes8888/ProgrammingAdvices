#include <iostream>
#include <string>

std::string ReadString()
{
    std::string S1;
    std::cout << "Please enter your string: " << std::endl;
    std::getline(std::cin, S1);
    return S1;
}

char ReadCharacter()
{
    char c;
    std::cout << "Please enter a character: " << std::endl;
    std::cin >> c;
    return c;
}

short CountLetter(std::string S1, char c)
{
    int Counter = 0;
    for(short i = 0; i < S1.length();i++)
    {
        if (S1[i] == c)
            Counter++;
    }
    return Counter;
}

int main()
{
    std::string S1 = ReadString();
    char c = ReadCharacter();

    std::cout << "Letter '" << c << "' count = " << CountLetter(S1,c) << std::endl;
    return 0;
}