#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include "settings.h"

void brainfuck_interpreter(char* commandsArray, char* dataArray, UNSIGNED_DATA_TYPE* dataIndex);

#endif