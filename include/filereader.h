#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <string.h>
#include "settings.h"

exit_code_t read_file(char* fileName, char* outputBuffer);

#endif