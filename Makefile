CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = hashAberta.o controleArquivo.o aluno.o main.o
EXE = main
MAIN = main.c

all:hashAberta.o controleArquivo.o aluno.o main.o
	$(CC) $(OBJS) -o $(EXE)

main.o: main.c
	$(CC) $(flags) $(MAIN) $(CFLAGS)

hashFechada.o: hashAberta.c
	$(CC) $(flags) hashAberta.c $(CFLAGS)

controleArquivo.o: controleArquivo.c
	$(CC) $(flags) controleArquivo.c $(CFLAGS)

aluno.o: aluno.c
	$(CC) $(flags) aluno.c $(CFLAGS)

run:
	./main

listar:
	ls $(ARQUIVOS)

clean:
	rm -f $(EXE) *.o