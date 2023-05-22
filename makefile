### MAKEFILE ###

all: main clean

main: manipulaArquivos.o buscaEmProfundidade.o programacaoDinamica.o main.o

	gcc manipulaArquivos.o buscaEmProfundidade.o programacaoDinamica.o main.o -o main.out


main.o: main.c ./headers/manipulaArquivos.h
	gcc -c main.c

manipulaArquivos.o: manipulaArquivos.c ./headers/manipulaArquivos.h
	gcc -c manipulaArquivos.c

buscaEmProfundidade.o: buscaEmProfundidade.c ./headers/buscaEmProfundidade.h
	gcc -c buscaEmProfundidade.c

programacaoDinamica.o: programacaoDinamica.c ./headers/programacaoDinamica.h
	gcc -c programacaoDinamica.c

clean:
	rm *.o