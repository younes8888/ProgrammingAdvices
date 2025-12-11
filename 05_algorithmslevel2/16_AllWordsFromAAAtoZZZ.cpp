#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


// void PrintAllCombinationsOfThreeLetters()
// {
//     for (char Char1 = 'A'; Char1 <= 'Z'; Char1++)
//     {
//         for (char Char2 = 'A'; Char2 <= 'Z'; Char2++)
//         {
//             for (char Char3 = 'A'; Char3 <= 'Z'; Char3++)
//             {
//                 std::cout << Char1 << Char2 << Char3 << std::endl;
//             }
//         }
//         std::cout << "\n";
//     }
// }

void PrintWordsFromAAAToZZZ()
{
    std::string Word = "";

    for (int i = 65; i <= 90; i++)
    {
        for(int j = 65; j <= 90; j++)
        {
            for(int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word= Word + char(j);
                Word = Word + char(k);
                std::cout << Word << std::endl;
                Word = "";
            }
        }
        std::cout << "\n";
    }
}

int main()
{
    PrintWordsFromAAAToZZZ();
    return 0;

}