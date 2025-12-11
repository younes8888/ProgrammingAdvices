#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

std::string ClientsFileName = "file.txt";

struct sClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string ClientName;
    std::string PhoneNumber;
    double AccountBalance;
    bool MarkedToBeDeleted = false;
};

bool isClientAlreadyExist(std::string AccountNumber, std::vector<sClient> &vClients)
{
    for (sClient &C : vClients)
    {

        if (AccountNumber == C.AccountNumber)
        {
            return true;
        }
    }
    return false;
}

sClient ReadNewClientData(std::vector<sClient> &vClients)
{

    sClient NewClient;

    std::cout << "\nEnter account number: ";
    std::getline(std::cin >> std::ws, NewClient.AccountNumber);
    while (isClientAlreadyExist(NewClient.AccountNumber, vClients) == true)
    {
        std::cout << "Client with [" << NewClient.AccountNumber << "] already exits, Enter another Account Number: ";
        std::getline(std::cin, NewClient.AccountNumber);
    }

    std::cout << "\nEnter pin code: ";
    std::getline(std::cin >> std::ws, NewClient.PinCode);
    std::cout << "\nEnter client name: ";
    std::getline(std::cin, NewClient.ClientName);
    std::cout << "\nEnter phone number ";
    std::getline(std::cin, NewClient.PhoneNumber);
    std::cout << "\nEnter account balance: ";
    std::cin >> NewClient.AccountBalance;

    return NewClient;
}

std::vector<std::string> SplitString(std::string Line, std::string Separator = "#//#")
{
    std::string sWord = "";
    int pos = 0;
    std::vector<std::string> NewWord;

    while ((pos = Line.find(Separator)) != std::string::npos)
    {
        sWord = Line.substr(0, pos);
        if (sWord != "")
        {
            NewWord.push_back(sWord);
        }
        Line.erase(0, pos + Separator.length());
    }
    if (Line != "")
    {
        NewWord.push_back(Line);
    }
    return NewWord;
}

sClient ConvertLineToRecord(std::string Line)
{
    sClient Client;
    std::vector<std::string> ClientLine = SplitString(Line);

    Client.AccountNumber = ClientLine[0];
    Client.PinCode = ClientLine[1];
    Client.ClientName = ClientLine[2];
    Client.PhoneNumber = ClientLine[3];
    Client.AccountBalance = stod(ClientLine[4]);
    return Client;
}
std::string ConvertRecordToLine(sClient Client, std::string Separator = "#//#")
{

    std::string NewLine = "";

    NewLine += Client.AccountNumber + Separator;
    NewLine += Client.PinCode + Separator;
    NewLine += Client.ClientName + Separator;
    NewLine += Client.PhoneNumber + Separator;
    NewLine += std::to_string(Client.AccountBalance);

    return NewLine;
}

void WriteClientsDataToFile(std::vector<sClient> &vClients)
{

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::out);

    if (MyFile.is_open())
    {
        std::string Line = "";
        for (sClient &C : vClients)
        {
            if (C.MarkedToBeDeleted == false)
            {
                Line = ConvertRecordToLine(C);
                MyFile << Line << std::endl;
            }
        }
        MyFile.close();
    }
}

void LoadClientsDataInVector(std::vector<sClient> &vClients)
{

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::in);

    if (MyFile.is_open())
    {
        std::string Line = "";
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
    }
}

void PrintClientsCard(std::vector<sClient> vClients)
{
    bool IsAlreadyPrinted = false;

    system("clear");
    if (IsAlreadyPrinted == false)
    {
        std::cout << "\t\t\t\t Client List (" << vClients.size() << ") Client(s)" << std::endl;
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        std::cout << "| " << std::setw(14) << std::left << "Account Number";
        std::cout << "| " << std::setw(14) << std::left << "Pin Code";
        std::cout << "| " << std::setw(20) << std::left << "Client Name";
        std::cout << "| " << std::setw(16) << std::left << "Phone Number";
        std::cout << "| " << std::setw(14) << std::left << "Account Balance";
        std::cout << "\n----------------------------------------------------------------------------------------\n";
        IsAlreadyPrinted = true;
    }

    for (sClient &C : vClients)
    {
        std::cout << "\n| " << std::setw(14) << std::left << C.AccountNumber;
        std::cout << "| " << std::setw(14) << std::left << C.PinCode;
        std::cout << "| " << std::setw(20) << std::left << C.ClientName;
        std::cout << "| " << std::setw(16) << std::left << C.PhoneNumber;
        std::cout << "| " << std::setw(14) << std::left << C.AccountBalance;
    }
    std::cout << "\n";
}

void AddNewClient(std::vector<sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\t\tAdd New Clients Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    char AddMore;
    std::cout << "\n Adding New Clients: ";
    do
    {
        sClient NewClient = ReadNewClientData(vClients);
        vClients.push_back(NewClient);
        std::cout << "\nClient Added successfully, do you want to add more clients? Y/N: ";
        std::cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void PrintOneClientData(std::string AccountNumber, std::vector<sClient> &vClients)
{
    std::cout << "\nThe following are the client details: ";
    std::cout << "\n---------------------------------------------------------------------\n";
    for (sClient &C : vClients)
    {
        if (AccountNumber == C.AccountNumber)
        {
            std::cout << "Account Number: " << C.AccountNumber;
            std::cout << "\nPin Code: " << C.PinCode;
            std::cout << "\nClient Name: " << C.ClientName;
            std::cout << "\nPhone Number: " << C.PhoneNumber;
            std::cout << "\nAccount Balance: " << C.AccountBalance;
        }
    }
    std::cout << "\n---------------------------------------------------------------------\n";
}

void DeleteClientInFile(std::vector<sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\t\tDelete Client Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    std::string AccountNumberToBeDeleted;
    char ToBeDeleted;
    std::cout << "Please enter account number: ";
    std::getline(std::cin >> std::ws, AccountNumberToBeDeleted);
    if (isClientAlreadyExist(AccountNumberToBeDeleted, vClients) == false)
    {
        std::cout << "Client with account number (" << AccountNumberToBeDeleted << ") is NOT FOUND!\n";
    }
    else
    {
        PrintOneClientData(AccountNumberToBeDeleted, vClients);
        std::cout << "Are you sure you want to delete this client? y/n: ";
        std::cin >> ToBeDeleted;
        if (toupper(ToBeDeleted) == 'Y')
        {
            for (sClient &C : vClients)
            {
                if (AccountNumberToBeDeleted == C.AccountNumber)
                {
                    C.MarkedToBeDeleted = true;
                }
            }
            WriteClientsDataToFile(vClients);
            std::cout << "/Client deleted successfully.\n";
        }
    }
}

void UpdateClientInfo(std::vector<sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\tUpdate Client Info Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    std::string AccountNumberToBeUpdated;
    char ToBeUpdated;
    std::cout << "Please enter account number: ";
    std::getline(std::cin >> std::ws, AccountNumberToBeUpdated);
    if (isClientAlreadyExist(AccountNumberToBeUpdated, vClients) == false)
    {
        std::cout << "Client with account number (" << AccountNumberToBeUpdated << ") is NOT FOUND!\n";
    }
    else
    {
        PrintOneClientData(AccountNumberToBeUpdated, vClients);
        std::cout << "Are you sure you want to update this client? y/n: ";
        std::cin >> ToBeUpdated;
        if (toupper(ToBeUpdated) == 'Y')
        {
            sClient AddNewClient;
            for (sClient &C : vClients)
            {
                if (AccountNumberToBeUpdated == C.AccountNumber)
                {
                    std::cout << "\nEnter pin code: ";
                    std::getline(std::cin >> std::ws, AddNewClient.PinCode);
                    C.PinCode = AddNewClient.PinCode;

                    std::cout << "\nEnter client name: ";
                    std::getline(std::cin, AddNewClient.ClientName);
                    C.ClientName = AddNewClient.ClientName;

                    std::cout << "\nEnter phone number ";
                    std::getline(std::cin, AddNewClient.PhoneNumber);
                    C.PhoneNumber = AddNewClient.PhoneNumber;

                    std::cout << "\nEnter account balance: ";
                    std::cin >> AddNewClient.AccountBalance;
                    C.AccountBalance = AddNewClient.AccountBalance;
                }
            }
            WriteClientsDataToFile(vClients);
            std::cout << "\nClient Updated successfully.\n";
        }
    }
}

void    FindClientInFile(std::vector <sClient> &vClients)
{
    std::cout << "\n---------------------------------------------------------------------\n";
    std::cout << "\t\tFind Client Screen";
    std::cout << "\n---------------------------------------------------------------------\n";

    std::string AccountNumberToSearch;
    char ToBeUpdated;
    std::cout << "Please enter account number: ";
    std::cin >> AccountNumberToSearch;
    if (isClientAlreadyExist(AccountNumberToSearch, vClients) == false)
    {
        std::cout << "Client with account number (" << AccountNumberToSearch << ") is NOT FOUND!\n";
    }
    else
    {
        PrintOneClientData(AccountNumberToSearch,vClients);
    }
}

void EndProgram()
{
    std::cout << "\n========================================================================\n";
    std::cout << "\n\t\t\t Program Ends :-) \n";
    std::cout << "\n========================================================================\n";
}

bool ShowMainMenu(std::vector<sClient> &vClients)
{
    std::cout << "\n========================================================================\n";
    std::cout << "\n\t\t\t Main Menu Screen\n";
    std::cout << "\n========================================================================\n";

    std::cout << "\t[1] Show Client List." << std::endl;
    std::cout << "\t[2] Add New Client." << std::endl;
    std::cout << "\t[3] Delete Client." << std::endl;
    std::cout << "\t[4] Update Client Info." << std::endl;
    std::cout << "\t[5] Find Client." << std::endl;
    std::cout << "\t[6] Exit." << std::endl;

    std::cout << "========================================================================\n";

    short Choice;
    std::cout << "Choose what you want to do from [1 to 6]: \n";
    std::cin >> Choice;
    if (Choice == 1)
    {
        system("clear");
        PrintClientsCard(vClients);
    }
    else if (Choice == 2)
    {
        system("clear");
        AddNewClient(vClients);
        WriteClientsDataToFile(vClients);
    }
    else if (Choice == 3)
    {
        system("clear");
        DeleteClientInFile(vClients);
    }
    else if (Choice == 4)
    {
        system("clear");
        UpdateClientInfo(vClients);
    }
    else if (Choice == 5)
    {
        system("clear");
        FindClientInFile(vClients);
    }
    else if (Choice == 6)
    {
        system("clear");
        EndProgram();
        return false;
    }
    return true;
}

int main()
{
    std::vector<sClient> vClients;

    LoadClientsDataInVector(vClients);
    char BackToMainMenu;

    bool KeepRunning = true;
    while (KeepRunning)
    {
       KeepRunning = ShowMainMenu(vClients);
       if (KeepRunning)
       {
           std::cout << "\nPress any key to return to main men....";
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           std::cin.get();
       }
    }

    return 0;
}