#include <iostream>
#include <string>

std::string TrimLeft(std::string Str)
{

    for (short i = 0; i < Str.length();i++)
    {
        if (Str[i] != ' ')
        {
            return Str.substr(i, Str.length() - i);
        }
    }
    return "";
}

std::string TrimRight(std::string Str)
{

    for (short i = Str.length() - 1; 0 <= i ; i--)
    {
        if (Str[i] != ' ')
        {
            return Str.substr(0,i + 1);
        }
    }
    return "";
}

std::string Trim(std::string Str)
{
    return (TrimLeft(TrimRight(Str)));
}

// std::string TrimLeft(std::string Str, char Delimiter)
// {
//     std::string NewStr;
//     int Len = Str.length();
//     int i = 0;


//     while (Str[i] == Delimiter)
//         i++;
//     while (i < Len)
//     {
//         NewStr = NewStr + Str[i];
//         i++;
//     }
//     return NewStr;
// }

// std::string TrimRight(std::string Str, char Delimiter)
// {
//     std::string NewStr;
//     int i = 0;
//     int Len = Str.length();
//     while (Str[Len - 1] == Delimiter)
//         Len--;
//     while(i < Len)
//     {
//         NewStr = NewStr + Str[i];
//         i++;
//     }
//     return NewStr;
// }
// std::string TrimBoth(std::string Str, char Delimiter)
// {
//     std::string NewString;
//     NewString = TrimLeft(Str, Delimiter);
//     NewString = TrimRight(NewString, Delimiter);
//     return NewString;
// }

int main()
{

    std::string Str = "   iPlus One   ";

    std::cout << "String = " << Str << std::endl;

    std::cout << "\n\nTrim left = " << TrimLeft(Str) << std::endl;
    std::cout << "\n\nTrim left = " << TrimRight(Str) << std::endl;
    std::cout << "\n\nTrim left = " << Trim(Str) << std::endl;


    // std::cout << "String = " << Str  << std::endl;

    //  NewStr = TrimLeft(Str, c);
    // std::cout << "\nTrim left = " << NewStr << std::endl;

    // NewStr = TrimRight(Str, c);
    // std::cout << "\nTrim left = " << NewStr  << std::endl;

    // NewStr = TrimBoth(Str, c);
    // std::cout << "\nTrim both = " << NewStr  << std::endl;



    return 0;
}