//
//  main.c
//  MikaelHashAberta
//
//  Created by Victorio Carvalho on 18/10/21.
//
#include "aluno.h"
#include "controleArquivo.h"
#define FATOR 0.7

int main() {
    hashAberto *h = (hashAberto *) malloc (sizeof(hashAberto));
	inicializaHashAberto(h,100000, FATOR);
	printf("\nTAMANHO HASH: %d", h->tamanho);
	h=readHashAlunoFromFile(h);
	printf("\nTAMANHO HASH: %d", h->tamanho);
	start(h);
	//printAllHash(h);
	writeHashOnFile(h);
}
