#include <filereader.h>

void read_file(char* fileName, char* outputBuffer) {
    FILE* fileWithCommands = fopen(fileName, "r");

    if (fileWithCommands == NULL) {
        perror("Unable to read file!");
        exit(2);
    }

    for (char temp[ARRAYS_LENGTH]; fgets(temp, ARRAYS_LENGTH, fileWithCommands);) {
        strcat(outputBuffer, temp);
        outputBuffer[strlen(outputBuffer) - 1] = '\0';
    }

    fclose(fileWithCommands);
}