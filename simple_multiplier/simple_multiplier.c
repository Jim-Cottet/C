#include <stdio.h>

int simple_multiplier(int a, int b)
{
    return a * b;
}

int main() 
{
    int num1, num2, result;

    printf("Enter two numbers to multiply:\n");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    }
    result = simple_multiplier(num1, num2);
    printf("The result is: %d\n", result);

    return 0;
}