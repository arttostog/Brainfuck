ifdef OS
	REMOVE_COMMAND = del Brainfuck.exe
else
	REMOVE_COMMAND = rm Brainfuck
endif

Brainfuck : ./src/main.c
	gcc ./src/main.c -o Brainfuck

clean:
	$(REMOVE_COMMAND)