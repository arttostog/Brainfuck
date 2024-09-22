#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "settings.h"

exit_code read_file(char* fileName, char* outputBuffer);

#endif