#include <iostream>
#include <string>

std::string ReadString()
{
    std::string S1;
    std::cout << "Please enter your string: " << std::endl;
    std::getline(std::cin,S1);
    return S1;

}

int CountWords(std::string S1)
{
    std::string Delimeter = " ";
    int pos;
    std::string NewWord;
    int Counter = 0;
    
    while ((pos = S1.find(Delimeter)) != std::string::npos)
    {
        NewWord = S1.substr(0,pos);
        if (NewWord != "")
            Counter++;
        S1.erase(0, pos + Delimeter.length());
    }
    if (S1 != " ")
        Counter++;
    return Counter;
}

// int CountWords(std::string S1)
// {
//     char Delimiter = ' ';
//     int Counter = 1;

//     for (short i = 0; i < S1.length(); i++)
//     {
//         if (S1[i] == Delimiter)
//             Counter++;
//     }
//     return Counter;
// }

int main()
{
    std::string S1 = ReadString();
    int Counter = CountWords(S1);

    std::cout << "The number of words in your string is: " << Counter << std::endl;
    return 0;
}