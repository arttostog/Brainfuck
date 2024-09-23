SOURCE_FILES = ./src/main.c ./src/filereader.c ./src/interpreter.c
COMPILE_FLAGS = -Wall -Wextra -pedantic -O3

ifeq ($(OS), Windows_NT)
	RESOURCES_OUTPUT_FILE = resources.o
    CLEAN_COMMAND = del brainfuck.exe $(RESOURCES_OUTPUT_FILE)
else
	CLEAN_COMMAND = rm brainfuck
endif

brainfuck : $(SOURCE_FILES) $(RESOURCES_OUTPUT_FILE)
	gcc $(COMPILE_FLAGS) $(SOURCE_FILES) $(RESOURCES_OUTPUT_FILE) -o brainfuck

resources.o : resources.rc
	windres resources.rc resources.o

clean:
	$(CLEAN_COMMAND)