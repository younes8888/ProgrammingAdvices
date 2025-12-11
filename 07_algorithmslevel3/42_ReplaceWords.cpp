#include <string>
#include <vector>
#include <iostream>

// std::vector <std::string> Ft_Split(std::string Str, std::string Delimiter)
// {

//     std::vector <std::string> vStrings;
//     int pos = 0;
//     std::string sWord;
//     while((pos = Str.find(Delimiter)) != std::string::npos)
//     {
//         sWord = Str.substr(0,pos);
//         if (sWord != "")
//         {
//             vStrings.push_back(sWord);
//         }
//         Str.erase(0, pos + Delimiter.length());
//     }
//     if (Str != "")
//         vStrings.push_back(Str);
//     return vStrings;
// }

// std::vector <std::string> UpDateString(std::string Str, std::string WordToUpdate)
// {
//     std::vector <std::string> vString = Ft_Split(Str," ");

//     for (short i = 0; i < vString.size(); i++)
//     {
//         if (vString[i] == WordToUpdate)
//         {
//             vString.at(i) = "Younes";
//         }
//     }
//     return vString;
// }

// std::string ConvertVectorToString(std::vector <std::string> vStrings)
// {
//     std::vector<std::string>::iterator iter;
//     std::string NewWord = "";
//     for (iter = vStrings.begin(); iter != vStrings.end();iter++)
//     {
//         NewWord = NewWord + *iter + " ";
//     }
//     return NewWord;
// }

std::string ReplaceWordInStringUsingBuiltInFunction(std::string Str, std::string StringToReplace, std::string sReplace)
{
    int pos = Str.find(StringToReplace);
    while(pos != std::string::npos)
    {
        Str = Str.replace(pos, StringToReplace.length(), sReplace);
        pos = Str.find(StringToReplace);
    }
    return Str;
}

int main()
{
    std::string Str = "hello Adam classmate, how are you Adam .";
    std::string WordToUpdate = "Adam";
    std::string NewStr = ReplaceWordInStringUsingBuiltInFunction(Str,WordToUpdate, "Younes");


    std::cout << NewStr << std::endl;
    return 0;
}