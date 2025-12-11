#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


std::string ReadInput()
{
    std::string PassWord;
    do {
        std::cout << "Please Enter the input: " << std::endl;
        std::cin >> PassWord;
    } while (PassWord == "");
    return PassWord;
}

int FindCorrectPassword(std::string PassWord, std::string Guess, int Trials)
{
    if (PassWord == Guess)
    {
        std::cout << "\n";
        std::cout << "PassWord is " << PassWord << std::endl;
        std::cout << "Found after " << Trials << " Trial(s)" << std::endl;
        return 1;
    }
    return 0;
}

void PrintWordsFromAAAToZZZ(std::string PassWord)
{
    std::string Word = "";
    int Trials = 0;

    for (int i = 65; i <= 90; i++)
    {
        for(int j = 65; j <= 90; j++)
        {
            for(int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word= Word + char(j);
                Word = Word + char(k);
                Trials++;
                std::cout << "Trail[" << Trials << "]: " << Word << std::endl; 
                if (FindCorrectPassword(PassWord,Word,Trials) == 1)
                {
                    return ;
                }
                Word = "";
            }
        }
        std::cout << "\n";
    }
}

int main()
{
    std::string PassWord = ReadInput();
    PrintWordsFromAAAToZZZ(PassWord);

    return 0;
}