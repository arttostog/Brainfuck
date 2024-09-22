SOURCE_FILES = ./src/main.c ./src/filereader.c ./src/interpreter.c

ifdef OS
	REMOVE_COMMAND = del Brainfuck.exe
else
	REMOVE_COMMAND = rm Brainfuck
endif

Brainfuck : $(SOURCE_FILES)
	gcc $(SOURCE_FILES) -o Brainfuck

clean:
	$(REMOVE_COMMAND)