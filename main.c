//
//  main.c
//  MikaelHashAberta
//
//  Created by Victorio Carvalho on 18/10/21.
//
#include "aluno.h"
#include "controleArquivo.h"
#define FATOR 0.9

int main() {
    hashAberto *h = (hashAberto *) malloc (sizeof(hashAberto));
	inicializaHashAberto(h,100000, FATOR);
	h=readHashAlunoFromFile(h);
	menu(h);
	writeHashOnFile(h);
}
