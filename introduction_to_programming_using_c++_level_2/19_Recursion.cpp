#include <iostream>

// void PrintNumbers(int N, int M)
// {
//   if (N <= M)
//   {
//     std::cout << M << std::endl;
//     PrintNumbers(N, M - 1);
//   }
// }

// int CalculatePower(int N, int M, int& Result)
// {

//     if (M > 0)
//     {
//         // std::cout << "N is: " << N << std::endl;
//         // std::cout << "M is: " <<  M << std::endl;
//         Result = Result * CalculatePower(N, M - 1, Result);
//         // std::cout << "Result is: " << Result << std::endl;
//         CalculatePower(N, M - 1, Result);
//         return Result;
//     }
//     else
//         return 1;
//     // std::cout << pow(N,M) << std::endl;
// }

// void PrintHello()
// {
//     while (1)
//     {
//         std::cout << "Hello\n";
//     }
// }

int CalculatePower(int Base, int Power)
{
    if (Power == 0)
        return 1;
    else
    {
        return (Base * CalculatePower(Base, Power - 1));
    }
}
int main()
{

    std::cout << CalculatePower(2,5) << std::endl;
    // int Result = 1;
    // CalculatePower(2,5, Result);
    // std::cout << Result << std::endl;
    
    // PrintNumbers(1,99);
    // PrintHello();
    return 0;
}