#include <string>
#include <iostream>
#include <vector>

std::vector<std::string> SplitString(std::string S1, std::string Delimiter)
{
    std::vector<std::string> vString;
    short pos = 0;
    std::string sWord;
    while((pos = S1.find(Delimiter)) != std::string::npos)
    {
        sWord = S1.substr(0,pos);
        if (sWord != "")
            vString.push_back(sWord);
        S1.erase(0,pos + Delimiter.length());
    }
    if (S1 != "")
        vString.push_back(S1);
    
        return vString;
}

std::string JoinString(std::vector<std::string> vString, std::string Delimiter)
{
    std::string S1;
    for (std::string &s : vString)
    {
        S1 = S1 + s + Delimiter;
    }
    return S1;
}

std::string LowerAllString(std::string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}
std::string ReplaceWordInStringUsingSplit(std::string S1, std::string StringToReplace, std::string sReplaceTo, bool MatchCase = true)
{
    std::vector<std::string> vString = SplitString(S1, " ");
    for(std::string& s : vString)
    {
        if (MatchCase)
        {
            if(s == StringToReplace)
            {
                s = sReplaceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sReplaceTo;
            }
        }
    }
    return JoinString(vString, " ");
}

int main()
{
    std::string S1 = "Welcome to Belgium , we all love Belgium ";
    std::string StringToReplace = "belgium";
    std::string ReplaceTo = "USA";

    std::cout << "\nOriginal string: \n" << S1;
    std::cout << "\n\nReplace with match case: ";
    std::cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);
    std::cout << "\n\nReplace with non-match case: ";
    std::cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);

    return 0;
}

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

// std::vector <std::string> ReplaceStringMatchedCase(std::string Str, std::string WordToUpdate, std::string NewString)
// {
//     std::vector <std::string> vString = Ft_Split(Str," ");

//     for (short i = 0; i < vString.size(); i++)
//     {
//         if (vString[i] == WordToUpdate)
//         {
//             vString.at(i) = NewString;
//         }
//     }
//     return vString;
// }
// std::vector <std::string> ReplaceStringNotMatchedString(std::string Str, std::string WordToUpdate, std::string NewString)
// {
//     std::vector <std::string> vString = Ft_Split(Str," ");
//     WordToUpdate[0] = toupper(WordToUpdate[0]);
//     std::string WordOne = WordToUpdate;
//     WordToUpdate[0] = tolower(WordOne[0]);
//     std::string WordTwo = WordToUpdate;

//     for (short i = 0; i < vString.size(); i++)
//     {
//         if (vString[i] == WordOne || vString[i] == WordTwo)
//         {
//             vString.at(i) = NewString;
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

// int main()
// {
//     std::string String = "Welcome to Belgium , we all love Belgium .";
//     std::string StringToReplace = "Belgium";
//     std::string UpdatedString1 = ConvertVectorToString(ReplaceStringMatchedCase(String, StringToReplace, "Germany"));
//     std::string UpdatedString2 =  ConvertVectorToString(ReplaceStringNotMatchedString(String, StringToReplace, "Germany"));
    
//     std::cout << "Original string: \n" << String << std::endl;
//     std::cout << "\nReplace with match case: \n" << UpdatedString1 << std::endl;
//     std::cout << "\nReplace with no-match case: \n" << UpdatedString2 << std::endl;

// }