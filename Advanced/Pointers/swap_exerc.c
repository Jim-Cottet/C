#include <stdio.h>

void swap_numbers(int *num1, int *num2)
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    int a = 5, b = 9;
    printf("a before swap = %d\n", a);
    printf("b before swap = %d\n", b);
    swap_numbers(&a, &b);
    printf("a after swap = %d\n", a);
    printf("b after swap = %d\n", b);

    return 0;
}

//* Sehr Gut !