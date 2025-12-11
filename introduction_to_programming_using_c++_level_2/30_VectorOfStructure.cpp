#include <iostream>
#include <cstdio>
#include <vector>

struct stEmployee
{
    std::string FirstName;
    std::string LastName;
    int Salary;
};

void ReadEmployees(std::vector <stEmployee> &vEmployee)
{
    stEmployee TempEmployee;
    char AddMore = 'Y';

    std::cout << "Enter an employee: \n";
    
    while (AddMore == 'y' || AddMore == 'Y')
    {
        std::cout << "\nEnter first name: ";
        std::cin >> TempEmployee.FirstName;

        std::cout << "Enter last name: ";
        std::cin >> TempEmployee.LastName;
        
        std::cout << "Enter salary: ";
        std::cin >> TempEmployee.Salary;
        
        vEmployee.push_back(TempEmployee);
        
        std::cout << "\nDo you want to add another employee? [Yes]: y, [No] n: \n";
        std::cin >> AddMore;
    }
    std::cout << std::endl;
}

void PrintEmployees(std::vector <stEmployee> &vEmployee)
{
    for(stEmployee Num: vEmployee)
    {
        std::cout << "First Name: " << Num.FirstName << std::endl;
        std::cout << "Last Name: " << Num.LastName << std::endl;
        std::cout << "Salary: " << Num.Salary << std::endl;
        std::cout << std::endl;
    }
}

int main()
{
    std::vector <stEmployee> vEmployee;

    ReadEmployees(vEmployee);
    PrintEmployees(vEmployee);

    return 0;
}

// struct stEmployee
// {
//     std::string FirstName;
//     std::string LastName;
//     int Salary;
// };

// void ReadEmployees(stEmployee &TempEmployee, std::vector <stEmployee> &vEmployee)
// {
//     char AddMore = 'Y';
//     std::cout << "Enter an employee: \n";
//     while (AddMore == 'y' || AddMore == 'Y')
//     {
//         std::cout << "\nEnter first name: ";
//         std::cin >> TempEmployee.FirstName;
//         std::cout << "Enter last name: ";
//         std::cin >> TempEmployee.LastName;
//         std::cout << "Enter salary: ";
//         std::cin >> TempEmployee.Salary;
//         vEmployee.push_back(TempEmployee);
//         std::cout << "\nDo you want to add another employee? [Yes]: y, [No] n: \n";
//         std::cin >> AddMore;
//     }
//     std::cout << std::endl;
// }

// void PrintEmployees(std::vector <stEmployee> &vEmployee)
// {
//     for(stEmployee Num: vEmployee)
//     {
//         std::cout << "First Name: " << Num.FirstName << std::endl;
//         std::cout << "Last Name: " << Num.LastName << std::endl;
//         std::cout << "Salary: " << Num.Salary << std::endl;
//         std::cout << std::endl;
//     }
// }

// int main()
// {
//     std::vector <stEmployee> vEmployee;
//     stEmployee TempEmployee;

//     ReadEmployees(TempEmployee, vEmployee);
//     PrintEmployees(vEmployee);

//     return 0;
// }

// struct stEmployee
// {
//     std::string FirstName;
//     std::string LastName;
//     float Salary;
// };

// int main()
// {
//     std::vector <stEmployee> vEmployee; // vEmployee is a collection(vector)

//     stEmployee tempEmployee; //vEmployee[i] = an actual stEmployee object inside it.

//     tempEmployee.FirstName = "Adam";
//     tempEmployee.LastName = "Des";
//     tempEmployee.Salary = 5000;
//     vEmployee.push_back(tempEmployee);

//     tempEmployee.FirstName = "Mouad";
//     tempEmployee.LastName = "Des";
//     tempEmployee.Salary = 7000;
//     vEmployee.push_back(tempEmployee);

//     tempEmployee.FirstName = "Simo";
//     tempEmployee.LastName = "Des";
//     tempEmployee.Salary = 9000;
//     vEmployee.push_back(tempEmployee);
    
//     for (stEmployee &Num: vEmployee)
//     {
//         std::cout << "First Name: " << Num.FirstName << std::endl;
//         std::cout << "Last Name: " << Num.LastName << std::endl;
//         std::cout << "Salary: " << Num.Salary << std::endl;
//         std::cout << std::endl;
//     }

//     return 0;
// }