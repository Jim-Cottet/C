#include <stdio.h>
#include <string.h>

void generic_swap(void* a,void* b,int size) //We assume that size > 0
{
    //Size - specifies the numer of bytes
    void *tempMemory = malloc(size);

    // memory Copy Function
    // void *memcpy(void *dest, const void *src, size_t num);
    memcpy(tempMemory, a, size);
    memcpy(a, b, size);
    memcpy(b, tempMemory, size);

    free(tempMemory);
}

int main()
{
    int num1 = 5, num2 = 7;
    double average1 = 90.5, average2 = 89.7;
    generic_swap(&average1, &average2, sizeof(double));

    return 0;
}