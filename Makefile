TARGET = brainfuck
COMPILE_FLAGS = -Wall -Wextra -pedantic -O3
SOURCE_FILES = ./src/main.c ./src/filereader.c ./src/interpreter.c

ifeq ($(OS), Windows_NT)
	RESOURCES_OUTPUT_FILE = resources.o
	CLEAN_COMMAND = del $(TARGET).exe $(RESOURCES_OUTPUT_FILE)
else
	CLEAN_COMMAND = rm $(TARGET)
endif

$(TARGET) : $(SOURCE_FILES) $(RESOURCES_OUTPUT_FILE)
	gcc $(COMPILE_FLAGS) $(SOURCE_FILES) $(RESOURCES_OUTPUT_FILE) -o $(TARGET)

resources.o : resources.rc
	windres resources.rc resources.o

clean:
	$(CLEAN_COMMAND)