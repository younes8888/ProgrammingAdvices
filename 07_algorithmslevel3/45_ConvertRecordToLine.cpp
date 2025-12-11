#include <iostream>
#include <string>
#include <vector>


struct sClient
{
    std::string AccountNumber;
    std::string PinCode;
    std::string Name;
    std::string PhoneNumber;
    double AccountBalance;
};

sClient ReadClientInput()
{
    sClient Client;

    std::cout << "\nEnter account number: ";
    std::getline(std::cin, Client.AccountNumber);
    std::cout << "Enter pin code: ";
    std::getline(std::cin, Client.PinCode);
    std::cout << "Enter name: ";
    std::getline(std::cin, Client.Name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, Client.PhoneNumber);
    std::cout << "Enter accountBalance: ";
    std::cin >> Client.PhoneNumber;
  
    return Client;
}

std::string ConvertRecordToOneString(struct sClient &client, std::string Separator = "#//#")
{
    std::string stClientRecord = "";

    stClientRecord+= client.AccountNumber + Separator;
    stClientRecord+= client.PinCode + Separator;
    stClientRecord+= client.Name + Separator;
    stClientRecord+= client.PhoneNumber + Separator;
    stClientRecord+= std::to_string(client.AccountBalance);

    return stClientRecord;
}

int main()
{   
    std::cout << "\nPlease enter client data: \n\n";
    struct sClient Client;

    Client = ReadClientInput();

    std::cout << Client.Name << std::endl;
    std::cout << "\n\nClient Record for saving is: \n";
    std::cout << ConvertRecordToOneString(Client) << std::endl;

    return 0;
}
// struct sClient
// {
//     std::string AccountNumber;
//     std::string PinCode;
//     std::string Name;
//     std::string PhoneNumber;
//     std::string AccountBalance;
// };

// sClient ReadClientInput(struct sClient &Client)
// {
//     std::cout << "Please enter client data: \n";
//     std::cout << "\nEnter account number: ";
//     std::getline(std::cin, Client.AccountNumber);
//     std::cout << "Enter pin code: ";
//     std::getline(std::cin, Client.PinCode);
//     std::cout << "Enter name: ";
//     std::getline(std::cin, Client.Name);
//     std::cout << "Enter phone number: ";
//     std::getline(std::cin, Client.PhoneNumber);
//     std::cout << "Enter accountBalance: ";
//     std::getline(std::cin, Client.PhoneNumber);
  
//     return Client;
// }

// std::string ConvertRecordToOneString(struct sClient &client, std::string Separator)
// {
//     std::string stClientRecord = "";

//     stClientRecord+= client.AccountNumber + Separator;
//     stClientRecord+= client.PinCode + Separator;
//     stClientRecord+= client.Name + Separator;
//     stClientRecord+= client.PhoneNumber + Separator;
//     stClientRecord+= client.AccountBalance;

//     return stClientRecord;
// }

// int main()
// {   
//     struct sClient Client;
//     std::string NewStr;
//     std::string Separator = "#//#";
//     ReadClientInput(Client);

//     std::cout << Client.Name << std::endl;
//     std::cout << "\nClient Record for saving is: \n";
//     NewStr = ConvertRecordToOneString(Client, Separator);
//     std::cout << NewStr << std::endl;

//     return 0;
// }