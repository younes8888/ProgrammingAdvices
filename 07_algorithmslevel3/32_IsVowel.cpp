#include <string>
#include <iostream>

char ReadCharacter()
{
    char c;
    std::cout << "Please enter a character: " << std::endl;
    std::cin >> c;
    return c;
}

bool IsVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    char c = ReadCharacter();
    if (IsVowel(c))
        std::cout << "Yes, the letter " << c << " is vowel." << std::endl;
    else
        std::cout << "NO, the letter " << c << " is NOT vowel." << std::endl;

    return 0;
}