### MAKEFILE ###

build: all
	./a.out

clean:
	rm *.o
	rm ./a.out

all: main

main: manipulaArquivos.o 
	gcc -c main.c
	gcc main.o  manipulaArquivos.o 



manipulaArquivos.o: manipulaArquivos.c
	gcc -c manipulaArquivos.c
