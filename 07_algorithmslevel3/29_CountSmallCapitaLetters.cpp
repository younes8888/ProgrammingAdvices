#include <iostream>
#include <string>

std::string ReadString()
{
    std::string S1;
    std::cout << "Please enter your string\n";
    std::getline(std::cin,S1);
    return S1;
}

enum enWhatToCount
{
    SmallLetter,
    CapitalLetter,
    All
};

int CountLetters(std::string S1, enWhatToCount whatToCount)
{
    int Counter = 0;
    if(whatToCount == enWhatToCount::All)
        return S1.length();
    for (short i = 0; i < S1.length(); i++)
    {
        if(isupper(S1[i]) && whatToCount == enWhatToCount::CapitalLetter)
            Counter++;
        if (islower(S1[i]) && whatToCount == enWhatToCount::SmallLetter)
            Counter++;
    }
    return Counter;
}

int main()
{
    std::string S1;
    S1 = ReadString();
    std::cout << "\nTotal number of letters = " << CountLetters(S1,enWhatToCount::All);

    std::cout << "\nSmall Letters Count = " << CountLetters(S1,enWhatToCount::SmallLetter);
    std::cout << "\nCapital Letters Count = " << CountLetters(S1, enWhatToCount::CapitalLetter) << std::endl;

    return 0;
}