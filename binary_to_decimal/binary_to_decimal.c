#include <stdio.h>


int main()
{
    int binary, remainder;
    int decimal = 0, base = 1;

    scanf("Enter a binary number %d", &binary);

    while (binary > 0)
    {
        remainder = binary % 10;
        decimal = decimal + remainder * base;
        binary = binary / 10;
        base = base * 2;
    }

    printf("The decimal equivalent is: %d", decimal);

    return 0;
}