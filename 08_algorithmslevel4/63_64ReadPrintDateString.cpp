#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

struct stDate
{
    short Day;
    short Month;
    short Year;
};

std::string ReadStringDate(std::string Message)
{
    std::string DateString;
    std::cout << Message;
    std::getline(std::cin >> std::ws, DateString);
    return DateString;
}

std::vector <std::string> SplitString(std::string Str, std::string Delimiter)
{
    std::vector <std::string> sString;
    std::string sWord;
    int pos;

    while ((pos = Str.find(Delimiter)) != std::string::npos)
    {
        sWord = Str.substr(0,pos);
        if (sWord != "")
            sString.push_back(sWord);
        Str.erase(0, pos + Delimiter.length());
    }
    if (Str != "")
        sString.push_back(Str);
    return sString;
}

stDate StringToDate(std::string DateString)
{
    stDate Date;
    std::vector <std::string> vDate;

    vDate = SplitString(DateString, "/");
    
    Date.Day = std::stoi(vDate[0]);
    Date.Month = std::stoi(vDate[1]);
    Date.Year = std::stoi(vDate[2]);

    return Date;
}

std::string DateToString(stDate Date)
{
    return std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
}

int main()
{

    std::string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy: ");

    stDate Date = StringToDate(DateString);

    std::cout << "\nDay: " << Date.Day << std::endl;
    std::cout << "Month: " << Date.Month << std::endl;
    std::cout << "Year: " << Date.Year << std::endl;
    
    DateString = DateToString(Date);
    std::cout << "\nYou entered: " << DateString << std::endl;
    
    return 0;
}

// #include <iostream>
// #include <string>
// #include <ctime>

// struct stDate
// {
//     short Day;
//     short Month;
//     short Year;
// };

// std::string ReadDate()
// {
//     std::string Date;
//     std::cout << "\nPlease Enter Date dd/mm/yyyy: ";
//     std::cin >> Date;
//     return Date;
// }

// stDate StringToDate(std::string StrDate)
// {
//     stDate Date;
//     Date.Day = 0;
//     Date.Month = 0;
//     Date.Year = 0;

//     short i = 0;
//     short Len = StrDate.length();
//     std::string Temp = "";
//     short TempInt = 0;
//     while (i < Len)
//     {
//         if (StrDate[i] != '/' )
//         {
//             Temp+= StrDate[i];
//         }
//         else
//         {
//             Date.Day  = (Temp[0] - '0');
//             Date.Day = Date.Day * 10 + (Temp[1] - '0');
//             Temp = "";
//             i++;
//             break;
//         }
//         i++;
//     }

//     while (i < Len)
//     {
//         if (StrDate[i] != '/' )
//         {
//             Temp+= StrDate[i];
//         }
//         else
//         {
//             Date.Month  = (Temp[0] - '0');
//             Temp = "";
//             i++;
//             break;
//         }
//         i++;
//     }

//     while (i < Len)
//     {
//         TempInt =  (StrDate[i] - '0');
//         Date.Year = Date.Year * 10 + TempInt;
//         TempInt = 0;
//         i++;
//     }
//     return Date;
// }

// std::string DateToString(stDate Date)
// {
//     std::string StrDate;
//     StrDate = std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
//     return StrDate;
// }

// int main()
// {

//     std::string StrDate = ReadDate();

//     stDate Date = StringToDate(StrDate);

//     std::cout << "\nDay: " << Date.Day << std::endl;
//     std::cout << "Month: " << Date.Month << std::endl;
//     std::cout << "Year: " << Date.Year << std::endl;
    
//     StrDate = DateToString(Date);
//     std::cout << "\nYou entered: " << StrDate << std::endl;
    
//     return 0;
// }