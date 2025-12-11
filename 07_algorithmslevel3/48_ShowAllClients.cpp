#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

std::string ClientsFileName = "file.txt";


struct sClient {

    std::string AccountNumber;
    std::string PinCode;
    std::string ClientName;
    std::string PhoneNumber;
    double AccountBalance;
};

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

void PrintClientRecord(sClient Client)
{
    std::cout << "| " << std::setw(15) << std::left << Client.AccountNumber;
    std::cout << "| " << std::setw(10) << std::left << Client.PinCode;
    std::cout << "| " << std::setw(20) << std::left << Client.ClientName;
    std::cout << "| " << std::setw(16) << std::left << Client.PhoneNumber;
    std::cout << "| " << std::setw(16) << std::left << Client.AccountBalance;

}

void PrintAllClientsData(std::vector<sClient> vClients)
{
    std::cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)";
    std::cout << 
    "\n_______________________________________________________________________";
    std::cout << "_______________________________________________________________________\n" << std::endl;

    std::cout << "| " << std::left << std::setw(15) << "Account Number";
    std::cout << "| " << std::left << std::setw(10) << "Pin Code";
    std::cout << "| " << std::left << std::setw(20) << "Client Name";
    std::cout << "| " << std::left << std::setw(16) << "Phone Number";
    std::cout << "| " << std::left << std::setw(16) << "Account Balance";
     
    std::cout << 
    "\n_______________________________________________________________________";
    std::cout << "_______________________________________________________________________\n" << std::endl;

    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        std::cout << std::endl;
    }

    std::cout << 
    "\n_______________________________________________________________________";
    std::cout << "_______________________________________________________________________\n" << std::endl;

}
int main()
{
    std::vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintAllClientsData(vClients);
}