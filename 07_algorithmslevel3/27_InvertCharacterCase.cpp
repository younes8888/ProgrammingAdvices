    #include <string>
    #include <iostream>

    // char ReadChar()
    // {
    //     char C;
    //     std::cout << "Pleaser Enter a character: " << std::endl;
    //     std::cin >> C;
    //     return C;
    // }

    // void InvertCharacter(char C)
    // {
    //     std::cout << "\nChar after inverting case: \n";
    //     if (C >= 65 && C <= 90)
    //         std::cout << (char)tolower(C) << std::endl;
    //     else
    //         std::cout << (char)toupper(C) << std::endl;
    // }

    char ReadChar()
    {
        char char1;
        std::cout << "Please enter a character: \n";
        std::cin >> char1;
        return char1;
    }
    char InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }
    int main()
    {

        char ch1 = ReadChar();
        std::cout << "\nChar after inverting case:\n";
        ch1 = InvertLetterCase(ch1);
        std::cout << ch1 << std::endl;
        return 0;
    }