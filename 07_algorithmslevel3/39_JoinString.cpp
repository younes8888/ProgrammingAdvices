#include <iostream>
#include <string>


// std::string JoinString(std::vector <std::string> vString, char Delimiter)
// {
//     std::string Str;
//     short Len = vString.size();

//     for (std::string &Word : vString)
//     {
//         if (Len == 1)
//         {
//             Str = Str + Word;
//             break;
//         }
//         Str = Str + Word + Delimiter;
//         Len--;
//     }
//     return Str;
// }

std::string JoinString(std::vector <std::string> vString, std::string Delimiter)
{
    std::string Str = "";
 
    for (std::string &Word : vString)
    {
        Str = Str + Word + Delimiter;
    }
    return Str.substr(0,Str.length() - Delimiter.length());
}
int main()
{
    std::vector <std::string> vString = {"Apple", "Banana", "Kiwi", "kaki"};
    std::string Delimiter = ";";
    std::cout << "Vector after join: " << std::endl;
    std::cout << JoinString(vString, Delimiter) << std::endl;
    

    return 0;
}