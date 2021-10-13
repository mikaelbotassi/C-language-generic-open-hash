CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = lista.o hashFechada.o controleArquivo.o aluno.o main.o
EXE = main
MAIN = main.c

all: lista.o hashFechada.o controleArquivo.o aluno.o main.o
	$(CC) $(OBJS) -o $(EXE)

main.o: main.c
	$(CC) $(flags) $(MAIN) $(CFLAGS)

lista.o: lista.c
	$(CC) $(flags) lista.c $(CFLAGS)

hashFechada.o: hashFechada.c
	$(CC) $(flags) hashFechada.c $(CFLAGS)

controleArquivo.o: controleArquivo.c
	$(CC) $(flags) controleArquivo.c $(CFLAGS)

aluno.o: aluno.c
	$(CC) $(flags) aluno.c $(CFLAGS)

run:
	./main

listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o
	rm -f $(EXE)