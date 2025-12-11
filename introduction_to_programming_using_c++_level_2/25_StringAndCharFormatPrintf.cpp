#include <iostream>

int main()
{
    char Name1[] = "Hello";
    char Name2[] = "Bye";


    printf("The name 1 is: %s\n\n", Name1);
    printf("name 2 is: %s\n\n", Name2);

    char c = 'S';
    printf("Setting the width of c: %*c\n",1,c );
    printf("Setting the width of c: %*c\n",2,c );
    printf("Setting the width of c: %*c\n",3,c );
    printf("Setting the width of c: %*c\n",4,c );
    printf("Setting the width of c: %*c\n",5,c );

    return 0;
}