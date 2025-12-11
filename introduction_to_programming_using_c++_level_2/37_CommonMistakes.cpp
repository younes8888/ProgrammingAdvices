#include <iostream>

int main()
{
    int x, *p;

    // p = x; //wrong;

    p = &x; // correct;

    // *p = &x; // wrong;

    *p = x; // correct;
    return 0;
}