#include <iostream>


int main()
{

    int Arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Arr[i][j] = ((i + 1) * (j + 1));
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%0*d",2, Arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}

// int main()
// {
//     int x[3][4] = {
//         {1,2,3,4},
//         {5,6,7,8},
//         {9,10,11,12}
//     };

//     for(int i = 0; i < 3; i++)
//     {
//         for(int j = 0; j < 4; j++)
//         {
//             std::cout << x[i][j] << " ";
//         }
//         std::cout << "\n";
//     }
//     return 0;
// }