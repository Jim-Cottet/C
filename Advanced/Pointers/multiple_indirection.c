#include <stdio.h>

int main()
{   
    int a = 5; // Classic variable with a literal
    int *ptr1 = &a; // Normal pointer with an address
    int **ptr2 = &ptr1; // Pointer to a Pointer

    return 0;
}