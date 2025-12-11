#include <iostream>
#include <string>
#include <vector>

struct stClients
{
    std::string Name;
    std::string Gender;
    std::string Age;  
};

void DeleteClientFromVector(std::vector <stClients> &vClients, std::string Name)
{

    std::vector<stClients>::iterator iter = vClients.begin();

    while(iter != vClients.end())
    {
            if (iter->Name == Name)
            {
                iter = vClients.erase(iter);
            }
            else
            {
                iter++;
            }
    }

}

void PrintVector(std::vector<stClients> vClients)
{
    std::cout << "\nClients are: \n\n";

    for (stClients Client : vClients)
    {
        std::cout << Client.Name << std::endl;
        std::cout << Client.Gender << std::endl;
        std::cout << Client.Age << std::endl;
        std::cout << "\n";
    }
}
int main()
{
    stClients Client1, Client2, Client3;
    std::vector<stClients> vClients;
    std::string Name = "Chaimae";


    Client1.Name = "Adam";
    Client1.Gender = "Male";
    Client1.Age = "20";
    vClients.push_back(Client1);

    Client2.Name = "Chaimae";
    Client2.Gender = "Femake";
    Client2.Age = "60";
    vClients.push_back(Client2);


    Client3.Name = "Said";
    Client3.Gender = "Make";
    Client3.Age = "30";
    vClients.push_back(Client3);
    std::cout << "\nBefore deletion: \n";
    PrintVector(vClients);
    DeleteClientFromVector(vClients, Name);
    std::cout << "\nAfter deletion: \n";

    PrintVector(vClients);
    return 0;
}