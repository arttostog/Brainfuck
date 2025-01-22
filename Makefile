TARGET = brainfuck

GCC = gcc
GCC_FLAGS = -Wall -I./include

WINDRES = windres

ifeq ($(OS), Windows_NT)
	RESOURCE_FILE = resource.rc
	RESOURCE_OUTPUT_FILE = resource.o
	CLEAN_COMMAND = del $(TARGET).exe $(RESOURCE_OUTPUT_FILE)
else
	CLEAN_COMMAND = rm $(TARGET)
endif

$(TARGET) :
ifeq ($(OS), Windows_NT)
	$(WINDRES) $(RESOURCE_FILE) $(RESOURCE_OUTPUT_FILE)
endif
	$(GCC) $(GCC_FLAGS) $(wildcard ./src/*.c) $(RESOURCE_OUTPUT_FILE) -o $(TARGET)

clean:
	$(CLEAN_COMMAND)