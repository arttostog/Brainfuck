#include <stdio.h>
#include <settings.h>
#include <filereader.h>
#include <interpreter.h>

char commandsArray[ARRAYS_LENGTH], dataArray[ARRAYS_LENGTH];
UNSIGNED_DATA_TYPE dataIndex = 0;

void real_time_interpretation() {
    printf("[ Real-time interpretation | Enter 'e' to exit ]");
    while (1) {
        printf("\n: ");
        if (scanf("%s", commandsArray)) {
            getchar();
            if (commandsArray[0] == 'e')
                break;
            brainfuck_interpreter(commandsArray, dataArray, &dataIndex);
        }
    }
}

void file_interpretiaion(char* filePath) {
    read_file(filePath, commandsArray);
    
    brainfuck_interpreter(commandsArray, dataArray, &dataIndex);
    putchar('\n');
}

int main(int argc, char** argv)
{
    if (argc > 2) {
        perror("To many arguments!");
        return 1;
    }
    
    if (argc == 2) {
        file_interpretiaion(argv[1]);
        return 0;
    }
    real_time_interpretation();
}