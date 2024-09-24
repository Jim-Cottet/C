#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    int a = 5, b = 7;
    printf("First number before swap = %d \n", a);
    printf("Second number before swap = %d \n", b);
    swap(&a, &b);
    printf("First number after swap = %d \n", a);
    printf("Second number after swap = %d \n", b);
}

//! If we run the program we see that nothing happens...
// It's because the two variables were effectively swapped inside the swap function
// But not really in the memory, so when we show them into the main function
// we use unchanged values.

// It's an important use case of the pointers.


