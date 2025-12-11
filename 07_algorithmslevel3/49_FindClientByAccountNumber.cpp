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
};

std::string ReadClientAccountNumber()
{
    std::string AccountNumber;
    std::cout << "\nPlease enter account number: ";
    std::cin >> AccountNumber;
    return AccountNumber;
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
    Client.AccountBalance = stod(vClientData[4]);

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

bool FindClientByAccountNumber(std::string AccountNumber, sClient &Client)
{
    std::vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    {
        for (sClient C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
    }
    return false;
}

void PrintClientCard(sClient C)
{
    std::cout << "\nThe following are the client details: \n";
    std::cout << "\nAccount Number: " << C.AccountNumber<< std::endl;
    std::cout << "Pin Code: " << C.PinCode<< std::endl;
    std::cout << "Client Name: " << C.ClientName << std::endl;
    std::cout << "Phone Number: " << C.PhoneNumber << std::endl;
    std::cout << "Account Balance: " << C.AccountBalance << std::endl;
}

int main()
{
    sClient Client;
    std::string AccountNumber = ReadClientAccountNumber();

    if(FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        std::cout << "Client with Account number(" << AccountNumber << ") NOT FOUND." << std::endl;

    }
    return 0;
}