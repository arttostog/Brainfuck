#include <stdio.h>
#include "settings.h"
#include "filereader.h"
#include "interpreter.h"

exit_code real_time_interpretation(char* commandsArray, char* dataArray) {
    printf("[ Real-time interpretation | Enter 'e' to exit ]");
    while (1) {
        printf("\n: ");
        if (scanf("%s", commandsArray)) {
            getchar();
            if (commandsArray[0] == 'e')
                break;
            brainfuck_interpreter(commandsArray, dataArray);
        }
    }
    return OK;
}

exit_code file_interpretiaion(char* filePath, char* commandsArray, char* dataArray) {
    if (read_file(filePath, commandsArray)) {
        printf("Unable to read file!");
        return FILE_ERROR;
    }
    brainfuck_interpreter(commandsArray, dataArray);
    printf("\n");
    return OK;
}

int main(int argc, char** argv)
{
    if (argc > 2) {
        printf("To many arguments!");
        return ARGUMENTS_ERROR;
    }

    char commandsArray[ARRAYS_LENGTH], dataArray[ARRAYS_LENGTH];
    if (argc == 1)
        return real_time_interpretation(commandsArray, dataArray);
    return file_interpretiaion(argv[1], commandsArray, dataArray);
}