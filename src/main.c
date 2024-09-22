#include <stdio.h>
#include <limits.h>
#include <string.h>

#define LISTS_LENGTH 65535
#define UNSIGNED_DATA_TYPE unsigned short

void read_file(char* fileName, char* buffer) {
    FILE* fileWithCommands = fopen(fileName, "r");

    if (fileWithCommands == NULL) {
        printf("Unable to read file!");
        return;
    }

    for (char temp[LISTS_LENGTH]; fgets(temp, LISTS_LENGTH, fileWithCommands);) {
        strcat(buffer, temp);
        buffer[strlen(buffer) - 1] = '\0';
    }

    fclose(fileWithCommands);
}

void brainfuck_interpreter(char* commandsArray, char* dataArray) {
    for (UNSIGNED_DATA_TYPE commandIndex, dataIndex; commandsArray[commandIndex] && commandIndex < LISTS_LENGTH; ++commandIndex) {
        switch (commandsArray[commandIndex]) {
            case '>':
                ++dataIndex;
                break;
            case '<':
                --dataIndex;
                break;
            case '+':
                ++dataArray[dataIndex];
                break;
            case '-':
                --dataArray[dataIndex];
                break;
            case '.':
                printf("%c", dataArray[dataIndex]);
                break;
            case ',':
                scanf("%c", dataArray + dataIndex);
                break;
            case ']':
                if (dataArray[dataIndex])
                    for (; commandsArray[commandIndex] != '['; --commandIndex);
                break;
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("To few or many args!");
        return 1;
    }

    char commandsArray[LISTS_LENGTH], dataArray[LISTS_LENGTH];
    read_file(argv[1], commandsArray);

    brainfuck_interpreter(commandsArray, dataArray);
}