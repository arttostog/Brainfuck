#include <stdio.h>
#include "settings.h"
#include "filereader.h"
#include "interpreter.h"

exit_code real_time_interpretation(char* commandsArray, char* dataArray, UNSIGNED_DATA_TYPE* dataIndex) {
    printf("[ Real-time interpretation | Enter 'e' to exit ]");
    while (1) {
        printf("\n: ");
        if (scanf("%s", commandsArray)) {
            getchar();
            if (commandsArray[0] == 'e')
                break;
            brainfuck_interpreter(commandsArray, dataArray, dataIndex);
        }
    }
    return OK;
}

exit_code file_interpretiaion(char* filePath, char* commandsArray, char* dataArray, UNSIGNED_DATA_TYPE* dataIndex) {
    if (read_file(filePath, commandsArray))
        return FILE_ERROR;
    
    brainfuck_interpreter(commandsArray, dataArray, dataIndex);
    putchar('\n');
    return OK;
}

int main(int argc, char** argv)
{
    if (argc > 2) {
        perror("To many arguments!");
        return ARGUMENTS_ERROR;
    }

    char commandsArray[ARRAYS_LENGTH], dataArray[ARRAYS_LENGTH];
    UNSIGNED_DATA_TYPE dataIndex = 0;
    return argc == 1 ? real_time_interpretation(commandsArray, dataArray, &dataIndex) :
        file_interpretiaion(argv[1], commandsArray, dataArray, &dataIndex);
}