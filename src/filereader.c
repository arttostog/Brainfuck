#include <filereader.h>

exit_code_t read_file(char* fileName, char* outputBuffer) {
    FILE* fileWithCommands = fopen(fileName, "r");

    if (fileWithCommands == NULL) {
        perror("Unable to read file!");
        return FILE_READ_ERROR;
    }

    for (char temp[ARRAYS_LENGTH]; fgets(temp, ARRAYS_LENGTH, fileWithCommands);) {
        strcat(outputBuffer, temp);
        outputBuffer[strlen(outputBuffer) - 1] = '\0';
    }

    fclose(fileWithCommands);
    return OK;
}