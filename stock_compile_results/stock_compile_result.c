#include <stdio.h>
#include <stdlib.h>

//TODO Need a refactorisation and a subdivision in several functions

//TODO

int main()
{   

    FILE *buffer_file;

    char filename[50];
    char final_command[100];
    char output[1024];

    //TODO a block to verify that GCC compiler exists or not

    //TODO

    printf("Enter the name of the file to compile: ");
    fgets(filename, sizeof(filename), stdin);

    snprintf(final_command, sizeof(final_command), "gcc %s", filename);

    buffer_file = popen(final_command, "r");
    if (buffer_file == NULL) {
        printf("Failed to run command\n");
    }

    //TODO Change this part to not display it but to put it into a file

    //?Which file format?
    //?The name of the file will be created with the timestamp?
    //?A unique file with a timestamp each time we write?
    //?If an error is corrected we display the correction?
    //? Autocorrect the the lack of semi colone? 
    //TODO

    while (fgets(output, sizeof(output), buffer_file) != NULL) {
        printf("%s", output);
    }

    pclose(buffer_file);

    return 0;

}