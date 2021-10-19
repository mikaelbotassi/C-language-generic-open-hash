#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include "hashAberta.h"
#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct Aluno{
    int matricula;
    char nome[31];
    int nota;
}aluno;

void menu(hashAberto *h);

aluno * allocAluno();

void newAluno(hashAberto * h1);

hashAberto* insertAluno(hashAberto *h, aluno * a);

int descobreTipo(char id);

int cmp(char id, elemento * n1, elemento *n2);

void alunoSearch(hashAberto *h);

int matriculaCompare(int matricula, elemento * elem);

void printAluno(char id, void *elem);

void printIndice(elemento *elem, int indice);

void printAllHash(hashAberto *h);

int returnChave(void * elem, char id);

#endif
