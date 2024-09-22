SOURCE_FILES = ./src/main.c ./src/filereader.c ./src/interpreter.c

brainfuck : $(SOURCE_FILES) resources.o
	gcc $(SOURCE_FILES) resources.o -o brainfuck

resources.o : resources.rc
	windres resources.rc resources.o

clean:
	del brainfuck.exe resources.o