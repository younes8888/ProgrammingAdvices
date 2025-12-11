#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

enum enGame
{
    scissors = 1,
    stone = 2,
    paper = 3
};

typedef struct stGame
{
    int NumberOfRounds = 0;
    int PlayerChoice;
    int PlayerWonTimes = 0;
    int ComputerChoice;
    int ComputerWontTimes = 0;
    int DrawTimes = 0;
    int RoundTracker = 0;
    char YesOrNO;
    std::string FinalWinner;
    std::string Msg;
} t_stGame;

int RandomNumbers(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + 1;
    return RandNum;
}

int ReadNumber1(std::string Msg)
{
    int NumberOfRounds;
   do {
        std::cout << Msg;
        std::cin >> NumberOfRounds;
   } while (NumberOfRounds <= 0 || NumberOfRounds > 10);
   
   return NumberOfRounds;
}
int ReadNumber2(std::string Msg)
{
    int NumberOfRounds;
   do {
        std::cout << Msg;
        std::cin >> NumberOfRounds;
   } while (NumberOfRounds < 1 || NumberOfRounds > 3);
   
   return NumberOfRounds;
}
std::string EnumConverter(t_stGame GameInfo)
{
    if (GameInfo.PlayerChoice == 1)
        return "Stone";
    if (GameInfo.PlayerChoice == 2)
        return "Paper";
    if (GameInfo.PlayerChoice == 3)
        return "Scissors";

    if (GameInfo.ComputerChoice == 1)
        return "Stone";
    if (GameInfo.ComputerChoice == 2)
        return "Paper";
    if (GameInfo.ComputerChoice == 3)
        return "Scissors";
    return "Invalid";
}

void PrintRoundResult(t_stGame GameInfo)
{
    EnumConverter(GameInfo);
    std::cout << "\n_______________________";
    std::cout << "Round [" << GameInfo.RoundTracker << "]";
    std::cout << "_______________________\n" << std::endl;

    std::cout << "Player 1 choice\t: " << EnumConverter(GameInfo) << std::endl;
    std::cout << "Computer Choice\t: " << EnumConverter(GameInfo) << std::endl;
    std::cout << "Round Winner\t: [" << GameInfo.Msg << "]" << std::endl; 
}
std::string FinalWinner(t_stGame GameInfo)
{
    if (GameInfo.ComputerWontTimes > GameInfo.PlayerWonTimes)
    {
       return GameInfo.FinalWinner = "Computer";
    } 
    else if (GameInfo.ComputerWontTimes < GameInfo.PlayerWonTimes)
    {
        return GameInfo.FinalWinner = "Player 1";
    }
    else
       return GameInfo.FinalWinner = "No winner";
}

void EndGame(t_stGame GameInfo)
{
    std::cout << "\n*****************************************************************************\n";
    std::cout  << "\t\t\t    +++ Game Over +++" << "\t\t\t\t" << std::endl;
    std::cout << "*****************************************************************************\n";
    std::cout << "\n******************************";
    std::cout << "[Game Results]"  <<  "******************************" << std::endl;
    std::cout << "\nGame Rounds\t\t: " << GameInfo.NumberOfRounds << std::endl;
    std::cout << "Player 1 won times\t: " << GameInfo.PlayerWonTimes << std::endl;
    std::cout << "Computer won times\t: " << GameInfo.ComputerWontTimes << std::endl;
    std::cout << "Draw times\t\t: " << GameInfo.DrawTimes << std::endl;
    std::cout << "Final Winner\t\t: " << FinalWinner(GameInfo) << std::endl;
    std::cout << "\n*****************************************************************************\n"; 
}

void StartGame(t_stGame GameInfo)
{
    for (int i = 0; i < GameInfo.NumberOfRounds; i++)
    {   
       std::cout << "\nRound " << "[" << ++GameInfo.RoundTracker << "]" << " begins: " << std::endl;
       GameInfo.PlayerChoice = ReadNumber2("\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors: ");
       GameInfo.ComputerChoice = RandomNumbers(1,3);
       if (GameInfo.PlayerChoice == GameInfo.ComputerChoice)
       {
            system("echo -e '\033[43m'");
            GameInfo.Msg = "No Winner";
            GameInfo.DrawTimes++;
            PrintRoundResult(GameInfo);
       }
        else if (GameInfo.PlayerChoice == 1 && GameInfo.ComputerChoice == 2)
       {
            system("echo -e '\033[41m'");
            GameInfo.Msg = "Computer";
            GameInfo.ComputerWontTimes++;
            PrintRoundResult(GameInfo);
       }
        else if (GameInfo.PlayerChoice == 1 && GameInfo.ComputerChoice== 3)
       {
            system("echo -e '\033[42m'");
            GameInfo.Msg = "Player 1";
            GameInfo.ComputerWontTimes++;
            PrintRoundResult(GameInfo);
       }
       else if (GameInfo.PlayerChoice == 2 && GameInfo.ComputerChoice == 1)
       {
            system("echo -e '\033[42m'");
            GameInfo.Msg = "Player 1";
            GameInfo.PlayerWonTimes++;
            PrintRoundResult(GameInfo);
       }
        else if (GameInfo.PlayerChoice == 2 && GameInfo.ComputerWontTimes == 3)
       {
             system("echo -e '\033[41m'");
            GameInfo.Msg = "Computer";
            GameInfo.ComputerWontTimes++;
            PrintRoundResult(GameInfo);
       }
       else if (GameInfo.PlayerChoice == 3 && GameInfo.ComputerChoice == 1)
       {
            system("echo -e '\033[41m'");
            GameInfo.Msg = "Computer";
            GameInfo.ComputerWontTimes++;
            PrintRoundResult(GameInfo);
       }
       else if (GameInfo.PlayerChoice == 3 && GameInfo.ComputerChoice == 2)
       {
            system("echo -e '\033[42m'");
            GameInfo.Msg = "Player 1";
            GameInfo.PlayerWonTimes++;
            PrintRoundResult(GameInfo);
       } else
            std::cout << "You entered invalid choice." << std::endl;
    }
    EndGame(GameInfo);
}

void ReStartGame(t_stGame GameInfo)
{
    do 
    {
        std::cout << "\nDo you want to play again? Y/N? ";
        std::cin >> GameInfo.YesOrNO;
        if (GameInfo.YesOrNO == 'Y' || GameInfo.YesOrNO == 'y')
        {
            GameInfo.NumberOfRounds = ReadNumber1("Choose number of rounds from 1 to 10: ");
            StartGame(GameInfo);
        }
    } while (GameInfo.YesOrNO == 'Y' || GameInfo.YesOrNO == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    t_stGame GameInfo;
    GameInfo.NumberOfRounds = ReadNumber1("Choose number of rounds from 1 to 10: ");

    StartGame(GameInfo);

    ReStartGame(GameInfo);
        
    return 0;
}

