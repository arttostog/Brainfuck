#include "interpreter.h"

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
                scanf(" %c", dataArray + dataIndex);
                break;
            case ']':
                if (dataArray[dataIndex])
                    for (; commandsArray[commandIndex] != '['; --commandIndex);
                break;
        }
    }
}