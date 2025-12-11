#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


// std::string ReadInput()
// {
//     std::string Str;
//     do {
//         std::cout << "Please Enter the input: " << std::endl;
//         std::cin >> Str;
//     } while (Str == "");
//     return Str;
// }

// std::string EncryptText(std::string Str)
// {
//     int Len = Str.length();
//     std::string NewStr(Len, '\0');
//     for (int i = 0; i < Len; i++)
//     {
//         if (i % 2 == 0)
//         {
//             NewStr[i] = Str[i] + 2;
//         }
//         else
//         {
//             NewStr[i] = Str[i] + 1;
//         }
//     }
//     return NewStr;
// }

// std::string DecryptText(std::string Str)
// {
//     int Len = Str.length();
//     std::string NewStr(Len, '\0');
//     std::cout << "Lenght of string is " << Len << std::endl;
//     for (int i = 0; i < Len; i++)
//     {
//         if (i % 2 == 0)
//         {
//             NewStr[i] = Str[i] - 2;
//         }
//         else
//         {
//             NewStr[i] = Str[i] - 1;
//         }
//     }
//     return NewStr;
// }

std::string ReadInput()
{
    std::string Str;
    std::cout << "Please enter a text: " << std::endl;
    std::getline(std::cin, Str);

    return Str;
}

std::string EncryptText(std::string Str, short Key)
{
    for (int i = 0; i < Str.length(); i++)
    {
        Str[i] = char(short(Str[i]) + Key);
    }
    return Str;
}

std::string DecryptText(std::string Str, short Key)
{
    for (int i = 0; i < Str.length(); i++)
    {
        Str[i] = char(short(Str[i]) - Key);
    }
    return Str;
}
int main()
{
    short Key = 2;
    std::string NewStr = ReadInput();
    std::string NewStr2 = EncryptText(NewStr, Key);
    std::string NewStr3 = DecryptText(NewStr2, Key);
    std::cout << "\n";
    std::cout << "Text before encryption: " << NewStr << std::endl;
    std::cout << "Text after encryption:  " << NewStr2 << std::endl;
    std::cout << "Text after decryption: " << NewStr3 << std::endl;

    return 0;
}