#include <iostream>
#include <string>

std::string ReadString()
{
    std::string S1;
    std::cout << "Please enter your string: " << std::endl;
    std::getline(std::cin,S1);
    return S1;
}
void PrintEachWordInString(std::string S1)
{
    std::string Delim = " ";
    short pos = 0;
    std::string sWord;

    while((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != " ")
            std::cout << sWord << std::endl;
        S1.erase(0,pos + Delim.length());
    }
    if (S1 != "")
        std::cout << S1 << std::endl;
}

// void PrintEachWordInString(std::string S1)
// {
//     std::string Temp = "";

//     std::cout << "\nYour string words are: \n" << std::endl;
//     for(short i = 0; i < S1.length(); i++)
//     {
//         while (S1[i] != ' ' && i < S1.length())
//         {
//             Temp+=S1[i];
//             i++;
//         }
//         std::cout << Temp << std::endl;
//         Temp = "";
//     }
//     std::cout << "\n";
// }

int main()
{

    std::string S1 = ReadString();
    PrintEachWordInString(S1);
    return 0;
}