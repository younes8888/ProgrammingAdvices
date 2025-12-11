#include <iostream>
#include <string>

std::string ReadString()
{
    std::string Str;
    std::cout << "Please enter your string: \n";
    std::getline(std::cin, Str);
    return Str;
}

std::vector <std::string> Ft_Split(std::string Str, std::string Delimiter)
{
    std::vector <std::string> sString;
    std::string sWord;
    int pos;

    while ((pos = Str.find(Delimiter)) != std::string::npos)
    {
        sWord = Str.substr(0,pos);
        if (sWord != "")
            sString.push_back(sWord);
        Str.erase(0, pos + Delimiter.length());
    }
    if (Str != "")
        sString.push_back(Str);
    return sString;
}

int main()
{
    std::string Str = ReadString();
    std::vector <std::string> sString;
    std::string Delimiter = " ";
    int Tokens;
    sString = Ft_Split(Str, Delimiter);
    Tokens = sString.size();
    std::cout << "Tokens = " << Tokens << std::endl;
    
    for (std::string &Word : sString)
        std::cout << Word << std::endl;

    return 0;
}