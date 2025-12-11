#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

bool CheckIfPrinted = false;
struct sClients {

    std::string AccountNumber;
    std::string PinCode;
    std::string ClientName;
    std::string PhoneNumber;
    std::string AccountBalance;
};

std::vector<std::string> ReadClientsInFile(std::string FileName, short &NumberOfClients)
{   
    std::fstream MyFile;
    std::vector<std::string> vClients;

    MyFile.open(FileName, std::ios::in);
    if (MyFile.is_open())
    {
        std::string Line;
        while (getline(MyFile, Line))
        {
           vClients.push_back(Line);
           NumberOfClients++;
        }
    }
    return vClients;
}

void PrintClientsOnScreen(sClients Client)
{
    if (CheckIfPrinted == false)
    {
        std::cout << "\n-----------------------------------------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(14) << "Account Number";
        std::cout << "|" << std::setw(10) << "Pin Code";
        std::cout << "|" << std::setw(14) << "Client Name";
        std::cout << "|" << std::setw(14) << "Phone Number";
        std::cout << "|" << std::setw(14) << "Account Balance";
        std::cout << "\n-----------------------------------------------------------------------------" << std::endl;
        CheckIfPrinted = true;
    }

    std::cout << "|" <<  std::setw(14) << Client.AccountNumber;
    std::cout << "|" << std::setw(10) << Client.PinCode;
    std::cout << "|" << std::setw(14) << Client.ClientName;
    std::cout << "|" << std::setw(14) << Client.PhoneNumber;
    std::cout << "|" << std::setw(14) << Client.AccountBalance << std::endl;

}

void SplitStrings(std::string Line, std::string Separator = "#//#")
{
    int pos = 0;
    std::string sWord;
    std::string NewWord = "";
    sClients Client;

    pos = Line.find(Separator);
    sWord = Line.substr(0, pos);
    Client.AccountNumber = sWord;
    Line.erase(0, pos + Separator.length());

    pos = Line.find(Separator);
    sWord = Line.substr(0, pos);
    Client.PinCode = sWord;
    Line.erase(0, pos + Separator.length());

    pos = Line.find(Separator);
    sWord = Line.substr(0, pos);
    Client.ClientName = sWord;
    Line.erase(0, pos + Separator.length());

    pos = Line.find(Separator);
    sWord = Line.substr(0, pos);
    Client.PhoneNumber = sWord;
    Line.erase(0, pos + Separator.length());

    pos = Line.find(Separator);
    sWord = Line.substr(0, pos);
    Client.AccountBalance = sWord;
    Line.erase(0, pos + Separator.length());

    PrintClientsOnScreen(Client);
    
}

void ReadClientsInVector(std::vector<std::string> vClients)
{
    for (std::string &L : vClients)
    {
         SplitStrings(L);
    }
}

int main()
{
    short NumberOfClients = 0;
    std::vector<std::string> vClients;
    vClients = ReadClientsInFile("file.txt", NumberOfClients);
    std::cout << "\n                     Client List (" << NumberOfClients << ") Client(s)           " << std::endl;
    ReadClientsInVector(vClients);

    std::cout << "\n-----------------------------------------------------------------------------" << std::endl;

    return 0;
}