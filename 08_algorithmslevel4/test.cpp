#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

void ReadNumber(int &Number)
{
    std::cout << "Enter a number: ";
    std::cin >> Number;
}

std::string UnitsConvertToWords(int &Number)
{
    if (Number == 0)
        return "Zero ";
    else if (Number == 1)
        return "One ";
    else if (Number == 2)
        return "Two ";
    else if (Number == 3)
        return "Three ";
    else if (Number == 4)
        return "Four ";
    else if (Number == 5)
        return "Five ";
    else if (Number == 6)
        return " Six ";
    else if (Number == 7)
        return "Seven ";
    else if (Number == 8)
        return "Eight ";
    else if (Number == 9)
        return "Nine ";

    return "";
}

std::string  TensConvertToWords1(int &Number)
{
    if (Number == 10)
        return "Ten ";
    else if (Number == 11)
        return "Eleven ";
    else if (Number == 12)
        return "Twelve ";
    else if (Number == 13)
        return "Thirteen ";
    else if (Number == 14)
        return "Fourteen ";
    else if (Number == 15)
        return "Fifteen ";
    else if (Number == 16)
        return "Sixteen ";
    else if (Number == 17)
        return "Seventeen ";
    else if (Number == 18)
        return "Eighteen ";
    else if (Number == 19)
        return "Nineteen ";
    return "";
}

std::string TensConvertToWords2(int &Number)
{
    std::string Num = "";
    if (Number == 20)
        return "Twenty ";
    else if (Number == 30)
        return "Thirty ";
    else if (Number == 40)
        return "Forty ";
    else if (Number == 50)
        return "Fifty ";
    else if (Number == 60)
        return "Sixty ";
    else if (Number == 70)
        return "Seventy ";
    else if (Number == 80)
        return "Eighty ";
    else if (Number == 90)
        return "Ninety ";

    return "";
}
void ConvertNumberToWords(int &Number)
{
    int Digit;
    int Digit2;
    int Buffer;

    if (Number >= 0 && Number <= 9)
    {
        std::cout << UnitsConvertToWords(Number) << std::endl;
    } 
    else if (Number >= 10 && Number <= 19)
    {
       std::cout << TensConvertToWords1(Number) << std::endl;
    } 
    else if (Number >= 20 && Number <= 99)
    {
        Buffer = Number % 10;
        Digit = Number - Buffer;
        std::cout << TensConvertToWords2(Digit) + UnitsConvertToWords(Buffer) << std::endl;
    }
    else if (Number >= 100 && Number <= 999)
    {
        Digit = Number % 10;
        
    }
}

int main()
{
    int Number;
    ReadNumber(Number);

    ConvertNumberToWords(Number);

    return 0;
}