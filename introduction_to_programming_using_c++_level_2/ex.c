#include <stdio.h>

void Swap(int *a, int *b)
{
    int Temp;
    Temp = *a;

    *a = *b;
    *b = Temp;
}

int main()
{
    int a = 10;
    int b = 50;

    int *c = &a;
    int *d = &b;

    printf("\nBefore swap a is: %d\n", a);
    printf("Before swap b is: %d\n", b);
    

    // Swap(&a,&b);
    Swap(c,d);
    printf("\nAfter swap a is: %d\n", a);
    printf("After swap b is: %d\n", b);
    
    return 0;
}