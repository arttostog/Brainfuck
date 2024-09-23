#include "interpreter.h"

void brainfuck_interpreter(char* commandsArray, char* dataArray) {
    for (UNSIGNED_DATA_TYPE commandIndex = 0, dataIndex = 0; commandsArray[commandIndex] && commandIndex < ARRAYS_LENGTH; ++commandIndex) {
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
                putchar(dataArray[dataIndex]);
                break;
            case ',':
                dataArray[dataIndex] = getchar();
                break;
            case ']':
                if (dataArray[dataIndex])
                    for (; commandsArray[commandIndex] != '['; --commandIndex);
                break;
        }
    }
}