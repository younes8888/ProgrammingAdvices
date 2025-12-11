#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

std::string ClientsFileName = "file.txt";

struct sClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string ClientName;
    std::string PhoneNumber;
    double AccountBalance;
    bool MarkForUpdate = false;
};

std::string ReadClientAccountNumber()
{
    std::string AccountNumber = "";
    std::cout << "\nPlease enter account number: ";
    std::cin >> AccountNumber;
    return AccountNumber;
}

char ReadNextInstruction()
{
    char IsYes;
    std::cout << "Are you sure you want to delete this client? Y/N ";
    std::cin >> IsYes;
    return IsYes;
}

std::vector<std::string> SplitStrings(std::string S1, std::string Delimiter)
{
    std::vector<std::string> vString;
    short pos = 0;
    std::string sWord;

    while((pos = S1.find(Delimiter)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delimiter.length());
    }
    if (S1 != "")
        vString.push_back(S1);
    
    return vString;
}

sClient ConvertLineToRecord(std::string Line, std::string Separator = "#//#")
{
    sClient Client;
    std::vector<std::string> vClientData;

    vClientData = SplitStrings(Line, Separator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.ClientName= vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = std::stod(vClientData[4]);

    return Client;
}

std::vector<sClient> LoadClientsDataFromFile(std::string FileName)
{
    std::vector<sClient> vClients;
    std::fstream MyFile;

    MyFile.open(FileName, std::ios::in);
    if (MyFile.is_open())
    {
        std::string Line;
        sClient Client;
        while(getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

bool FindClientByAccountNumber(std::string AccountNumber, std::vector<sClient> vClients, sClient &Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientCard(sClient C)
{
    std::cout << "\nThe following are the client details: \n";
    std::cout << "\nAccount Number: " << C.AccountNumber;
    std::cout << "\nPin Code: " << C.PinCode;
    std::cout << "\nClient Name: " << C.ClientName;
    std::cout << "\nPhone Number: " << C.PhoneNumber;
    std::cout << "\nAccount Balance: " << C.AccountBalance;
}
bool MarkClientForUpDateByAccountNumber(std::string AccountNumber, std::vector<sClient>& vClients)
{
    for(sClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForUpdate = true;
            return true;
        }
    }
    return false;
}
std::string ConvertRecordToLine(sClient Client, std::string Separator = "#//#")
{
    std::string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.ClientName + Separator;
    stClientRecord += Client.PhoneNumber + Separator;
    stClientRecord += std::to_string(Client.AccountBalance);
   
    return stClientRecord;
}

void SaveClientsDataToFile(std::string ClientsFileName, std::vector<sClient> vClients)
{
    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::out);
    std::string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
   
            DataLine = ConvertRecordToLine(C);
            MyFile << DataLine << std::endl;
       
        }
    }
    MyFile.close();
}

void    UpdateClientData(std::string AccountNumber, std::vector<sClient> &vClients)
{
    sClient Update;

    for (sClient &C : vClients)
    {
        if (C.MarkForUpdate == true)
        {
            std::cout << "\nEnter pin code: ";
            std::cin.ignore();
            std::getline(std::cin, Update.PinCode);
            C.PinCode = Update.PinCode;

            std::cout << "Enter client name: ";
            std::getline(std::cin, Update.ClientName);
            C.ClientName = Update.ClientName;
            
            std::cout << "Enter your phone number: ";
            std::getline(std::cin, Update.PhoneNumber);
            C.PhoneNumber = Update.PhoneNumber;
            
            std::cout << "Enter account balance: ";
            std::cin >> Update.AccountBalance;
            C.AccountBalance = Update.AccountBalance;
        }
    }

}

bool UpdateClientByAccountNumber(std::string AccountNumber, std::vector<sClient> &vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        std::cout << "\n\nAre you sure you want to update this client? y/n: ";
        std::cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForUpDateByAccountNumber(AccountNumber, vClients);
            UpdateClientData(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            std::cout << "\n\nClient Deleted Successfully.\n";
            return true;
        }
        
    }
    else
    {
        std::cout << "\nClient With Account Number (" << AccountNumber << ") is NOT FOUND";
        return false;
    }
    return false;

}

int main()
{
    std::vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    std::string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);

    return 0;
}