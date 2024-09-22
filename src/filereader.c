#include "filereader.h"

exit_code read_file(char* fileName, char* outputBuffer) {
    FILE* fileWithCommands = fopen(fileName, "r");

    if (fileWithCommands == NULL)
        return FILE_ERROR;

    for (char temp[LISTS_LENGTH]; fgets(temp, LISTS_LENGTH, fileWithCommands);) {
        strcat(outputBuffer, temp);
        outputBuffer[strlen(outputBuffer) - 1] = '\0';
    }

    fclose(fileWithCommands);
}