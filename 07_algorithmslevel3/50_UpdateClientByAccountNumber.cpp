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

    while ((pos = S1.find(Delimiter)) != std::string::npos)
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
    sClient ClientsFileName;
    std::vector<std::string> vClientData;

    vClientData = SplitStrings(Line, Separator);

    ClientsFileName.AccountNumber = vClientData[0];
    ClientsFileName.PinCode = vClientData[1];
    ClientsFileName.ClientName = vClientData[2];
    ClientsFileName.PhoneNumber = vClientData[3];
    ClientsFileName.AccountBalance = std::stod(vClientData[4]);

    return ClientsFileName;
}

std::vector<sClient> LoadClientsDataFromFile(std::string FileName)
{
    std::vector<sClient> vClients;
    std::fstream MyFile;

    MyFile.open(FileName, std::ios::in);
    if (MyFile.is_open())
    {
        std::string Line;
        sClient ClientsFileName;
        while (getline(MyFile, Line))
        {
            ClientsFileName = ConvertLineToRecord(Line);
            vClients.push_back(ClientsFileName);
        }
        MyFile.close();
    }
    return vClients;
}

bool FindClientByAccountNumber(std::string AccountNumber, std::vector<sClient> vClients, sClient &ClientsFileName)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            ClientsFileName = C;
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
bool MarkClientForUpDateByAccountNumber(std::string AccountNumber, std::vector<sClient> &vClients)
{
    for (sClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForUpdate = true;
            return true;
        }
    }
    return false;
}
std::string ConvertRecordToLine(sClient ClientsFileName, std::string Separator = "#//#")
{
    std::string stClientRecord = "";

    stClientRecord += ClientsFileName.AccountNumber + Separator;
    stClientRecord += ClientsFileName.PinCode + Separator;
    stClientRecord += ClientsFileName.ClientName + Separator;
    stClientRecord += ClientsFileName.PhoneNumber + Separator;
    stClientRecord += std::to_string(ClientsFileName.AccountBalance);

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

sClient ChangeClientRecord(std::string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;

    std::cout << "\nEnter pin code: ";
    std::getline(std::cin >> std::ws, Client.PinCode);


    std::cout << "Enter client name: ";
    std::getline(std::cin, Client.ClientName);

    std::cout << "Enter your phone number: ";
    std::getline(std::cin, Client.PhoneNumber);


    std::cout << "Enter account balance: ";
    std::cin >> Client.AccountBalance;
    
    return Client;
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
            for (sClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
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
    std::vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    std::string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);

    return 0;
}