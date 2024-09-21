#include <stdio.h>
#include <stdlib.h>

int main()
{   

    char filename[50];
    char final_command[100];

    printf("Enter the name of the file to compile: ");
    fgets(filename, sizeof(filename), stdin);

    snprintf(final_command, sizeof(final_command), "gcc %s", filename);

    int result = system(final_command);

    if (result == -1) {
        printf("Error executing command.\n");
    } else {
        printf("%s\n", result);
    }

    return 0;

}