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

std::string SearchAccountNumber()
{
    std::string AccountNumber;
    std::cout << "\nPlease enter account number: ";
    std::cin >> AccountNumber;
    return AccountNumber;
}

std::vector <std::string> SplitString(std::string Line, std::string Separator = "#//#")
{
    int pos = 0;
    std::string sWord = "";
    std::vector <std::string> vClient;

    while ((pos = Line.find(Separator)) != std::string::npos)
    {
        sWord = Line.substr(0,pos);
        if (sWord != "")
        {
            vClient.push_back(sWord);
        }
        Line.erase(0, pos + Separator.length());
    }
    if (Line != "")
        vClient.push_back(Line);
    return vClient;
}

sClient ConvertLineToRecord(std::string Line)
{
    sClient Client;
    std::vector <std::string> vClientsData = SplitString(Line);

    Client.AccountNumber = vClientsData[0];
    Client.PinCode = vClientsData[1];
    Client.ClientName = vClientsData[2];
    Client.PhoneNumber = vClientsData[3];
    Client.AccountBalance = stod(vClientsData[4]);

    return Client;
}

std::vector <sClient> LoadClientsDataFromFile(std::string ClientsFileName)
{
    std::vector <sClient> vClients;

    std::fstream MyFile;
    MyFile.open(ClientsFileName, std::ios::in);
    if (MyFile.is_open())
    {
        std::string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClient(sClient C)
{
    std::cout << "\nThe following are the client details: \n";
    std::cout << "\nAccount Number: " << C.AccountNumber<< std::endl;
    std::cout << "Pin Code: " << C.PinCode<< std::endl;
    std::cout << "Client Name: " << C.ClientName << std::endl;
    std::cout << "Phone Number: " << C.PhoneNumber << std::endl;
    std::cout << "Account Balance: " << C.AccountBalance << std::endl;
}

void SearchAndPrintClient(std::vector <sClient> vClients, std::string ClientToSearch)
{   

        
        for (sClient C : vClients)
        {
            if (C.AccountNumber == ClientToSearch)
                return PrintClient(C);
        }
        std::cout << "Client with Account number(" << ClientToSearch << ") NOT FOUND." << std::endl;
}

int main()
{
    std::vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    std::string ClientToSearch = SearchAccountNumber();
    SearchAndPrintClient(vClients, ClientToSearch);

    return 0;
}