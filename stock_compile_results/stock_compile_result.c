#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO Need a refactorisation and a subdivision in several functions
//TODO Handle real arguments instead of scans...

int main(int argc, char *argv[])
{   
    FILE *buffer_file, *writing_file;

    char filename[50];
    char final_command[100];
    char output[1024];

    //TODO Change this part to not display it but to put it into a file
    //?A unique file with a timestamp each time we write?
    //?If an error is corrected we display the correction?
    //?Auto correct the the lack of semi colone?
    //?Add a list of compilation errors at the top of the file with a count of occurrences

    //! How do I test this ???
    if (system("where gcc >nul 2>&1") != 0) {
        printf("Gcc compiler cannot be found.\n");
        return 1;
    }

    if (argc != 2) {
        printf("Usage %s <arguments>\n", argv[0]);
        return 1;
    }

    strncpy(filename, argv[1], sizeof(filename) - 1);
    filename[sizeof(filename) - 1] = '\0';

    size_t len = strlen(filename);
    if (len > 0 && filename[len-1] == '\n') {
        filename[len-1] = '\0';
    }

    snprintf(final_command, sizeof(final_command), "gcc %s > temp_output.txt 2>&1", filename);
    printf("The command: %s\n", final_command); //! Debug line

    int ret = system(final_command);
    if (ret >= 2) {
        printf("Failed to run command, return code: %d\n", ret);
       return 1;
    }

    buffer_file = fopen("temp_output.txt", "r");
    if (buffer_file == NULL) {
        printf("Failed to open temporary output file\n");
        return 1;
    }

    writing_file = fopen("logs.txt", "a");
    if (writing_file == NULL) {
        printf("Failed to open %s for writing\n");
        fclose(buffer_file);
        return 1;
    }

    while (fgets(output, sizeof(output), buffer_file) != NULL) {
        fputs(output, writing_file);
        printf("%s", output);
    }

    fclose(buffer_file);
    fclose(writing_file);

    printf("Compilation output written to logs.txt");

    remove("temp_output.txt");

    return 0;

}