#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3
};

enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    std::string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    std::string WinnerName = "";
};

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + 1;
    return RandNum;
}

std::string WinnerName(enWinner Winner)
{
    std::string arrWinnerName[3] = {"Player1", "Computer", "No Winner"};
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;
    switch(RoundInfo.Player1Choice)
    {
        case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
            break;
        }
        case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
            break;
        }
        case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
            break;
        }
    }
    return enWinner::Player1;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (Player1WinTimes < ComputerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes )
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.Computer2WinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    
    return GameResults;
}

std::string ChoiceName(enGameChoice Choice)
{
    std::string arrGameChoices[3] = {"Stone", "Paper", "Scissors"};
    return arrGameChoices[Choice - 1];
}
void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
    {
        system("echo -e '\033[42m'");
        break;
    }
    case enWinner::Computer:
    {
        system("echo -e '\033[41m'");
        break;
    }
    default:
    {
        system("echo -e '\033[43m'");
        break;
    }
    }
}


void PrintRoundResults(stRoundInfo RoundInfo)
{
    std::cout << "\n______________Round [" << RoundInfo.RoundNumber << "]__________________\n\n";
    std::cout << "Player1  choice: " << ChoiceName(RoundInfo.Player1Choice) << std::endl;
    std::cout << "Computer choice: " << ChoiceName(RoundInfo.ComputerChoice) << std::endl;
    std::cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";
    std::cout << "____________________________________\n" << std::endl; 
    SetWinnerScreenColor(RoundInfo.Winner);

}
enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        std::cout << "\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        std::cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1,3);
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WintTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for(short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        std::cout << "\nRound[" << GameRound << "] beings\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
            Player1WintTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;
        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, Player1WintTimes, ComputerWinTimes, DrawTimes);
}

std::string Tabs(short NumberOfTabs)
{
    std::string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        std::cout << t;
    }
    return t;
}

void ShowGameOverScreen()
{
    std::cout << Tabs(2) << "___________________________________________________________________\n\n";
    std::cout << Tabs(2) << "                       +++ Game Over +++\n";
    std::cout << Tabs(2) << "____________________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
    std::cout << Tabs(2) << "____________________________[Game Result]____________________________\n\n";
    std::cout << Tabs(2) << "Game Rounds            :" << GameResults.GameRounds << std::endl;
    std::cout << Tabs(2) << "Player1 wont times.    :" << GameResults.Player1WinTimes << std::endl;
    std::cout << Tabs(2) << "Computer won times.    :" << GameResults.Computer2WinTimes << std::endl;
    std::cout << Tabs(2) << "Draw Times             :" << GameResults.Computer2WinTimes << std::endl;
    std::cout << Tabs(2) << "Final Winner.          :" << GameResults.Computer2WinTimes << std::endl;
    std::cout << Tabs(2) << "______________________________________________________________________\n\n";
    SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds()
{
    short GameRounds = 1;
    do
    {
        std::cout << "How Many Rounds 1 to 10? \n";
        std::cin >> GameRounds;
    } while (GameRounds < 1|| GameRounds > 10);
    return GameRounds;
}

void ResetScreen()
{
    system("clear");
    system("echo -e '\033[0m'");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    { 
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        std::cout << Tabs(3) << "Do you want to play again? Y/N? ";
        std::cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
    
}

int main()
{
    srand((unsigned)time(NULL));
    
    StartGame();
    return 0;
}