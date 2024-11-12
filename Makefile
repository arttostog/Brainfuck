TARGET = brainfuck

ifeq ($(OS), Windows_NT)
	RESOURCE_FILE = resource.rc
	RESOURCE_OUTPUT_FILE = resource.o
	CLEAN_COMMAND = del $(TARGET).exe $(RESOURCE_OUTPUT_FILE)
else
	CLEAN_COMMAND = rm $(TARGET)
endif

$(TARGET) : $(RESOURCE_OUTPUT_FILE)
	gcc -Wall $(wildcard ./src/*.c) $(RESOURCE_OUTPUT_FILE) -o $(TARGET)

$(RESOURCE_OUTPUT_FILE) : $(RESOURCE_FILE)
	windres $(RESOURCE_FILE) $(RESOURCE_OUTPUT_FILE)

clean:
	$(CLEAN_COMMAND)