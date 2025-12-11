#include <iostream>
#include <string>


std::string JoinString(std::vector <std::string> vString, std::string Delimiter)
{
    std::string Str = "";
    for(std::string &Word : vString)
    {
        Str = Str + Word + Delimiter;
    }
    return (Str.substr(0,Str.length() - Delimiter.length()));
}

std::string JoinString(std::string Arr[4], short Len, std::string Delimiter)
{
    std::string Str = "";
    for (short i = 0; i < Len; i++)
    {
        Str = Str + Arr[i] + Delimiter;
    }

    return (Str.substr(0, Str.length() - Delimiter.length()));

}

int main()
{
    std::vector <std::string> vString = {"Apple","Banana", "Kiwi", "Kaki"};
    std::string Arr[4] = {"Pineapple", "Orange", "Lemon", "Berries"};

    std::cout << "Vector after join: \n" <<  JoinString(vString, " ") << std::endl;

    std::cout << "\nArray after join: \n" <<  JoinString(Arr, 4, " ") << std::endl;


    return 0;
}