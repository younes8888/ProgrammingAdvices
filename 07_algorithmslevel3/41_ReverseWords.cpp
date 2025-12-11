#include <iostream>
#include <string>

std::string ReadString()
{
    std::string Str;
    std::cout << "Please enter your string: " << std::endl;
    std::getline(std::cin, Str);
    return Str;
}

std::vector <std::string> SplitString(std::string S1, std::string Delimiter)
{
    short pos = 0;
    std::string NewWord = "";
    std::vector <std::string> vString;

    while((pos = S1.find(Delimiter)) != std::string::npos)
    {
        NewWord = S1.substr(0, pos);
        if (NewWord != "")
        {
            vString.push_back(NewWord);
        }
        S1.erase(0, pos + Delimiter.length());

    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

std::string ReverseString(std::string S1)
{
    std::string NewStr;
    std::vector <std::string> vString = SplitString(S1, " ");
    std::vector<std::string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        NewStr+= *iter + " ";
    }
    NewStr = NewStr.substr(0, NewStr.length() - 1);
    return NewStr;
}
// std::string ReverseString(std::string S1)
// {
//     std::string NewStr;
//     std::vector <std::string> vString = SplitString(S1, " ");
//     short Len = vString.size() - 1;
//     while (0 <= Len)
//     {
//         NewStr = NewStr + vString[Len] + " ";
//         Len--;
//     }
//     NewStr = NewStr.substr(0, NewStr.length() - 1);
//     return NewStr;
// }

int main()
{
    std::string Str = ReadString();
    short i = Str.length();
    std::cout << "Initial string length: " << i << std::endl;
    std::string ReversedStr = ReverseString(Str);
    std::cout << "Reversed string is: \n" << ReverseString(Str) << std::endl;
    i = ReversedStr.length();
    std::cout << "String length after reversing: " << i << std::endl;


    return 0;
}

// std::string ReverseString(std::string Str)
// {
//     std::string NewStr = "";

//     short Len = Str.length() - 1;
//     short NewLen;
//     short word_end = Len;
//     short word_start;

//     while (Len >= 0)
//     {
//         if (Str[Len] == ' ')
//         {
//             word_start = Len;
//             NewStr = NewStr + " " + Str.substr(word_start + 1, word_end - word_start);
//             word_end = Len - 1;
//         }
//         else if (Len == 0)
//         {
//             word_start = Len;
//             NewStr = NewStr + " " + Str.substr(word_start, word_end - word_start + 1);
//             word_end = Len - 1;
//         }
//         Len--;
//     }
//     return NewStr;
// }

// std::string ReverseString(std::string Str)
// {
//     std::string NewStr = "";
//     int pos = 0;
//     std::vector <std::string> vStr;
//     std::string sWord;
//     while((pos = Str.find(' ')) != std::string::npos)
//     {
//         sWord = Str.substr(0,pos);
//         vStr.push_back(sWord);
//     }

//     return NewStr;
// }

// int main()
// {
//     // std::string Str = ReadString();
//     std::string Str = "Hello how are you doing";
//     std::cout << "Reversed string is: \n" << ReverseString(Str) << std::endl;

//     return 0;
// }