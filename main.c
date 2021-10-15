#include "aluno.h"
#include "controleArquivo.h"
#define FATOR 0.7

/*
AVISO: A estrutura está encapsulada, somente a biblioteca de aluno tem acesso a bibloteca de Hash Fechada,
somente a bibloteca de Hash tem acesso a bibloteca de lista.
Todas as estruturas armazenam void, contudo como o bojetivo do trabalho é armazenar alunos,
eu coloquei o cast somente para aluno.
*/

int main(){
    hashAberto *h = (hashAberto *) malloc (sizeof(hashAberto));
	inicializaHashAberto(h,100000, FATOR);
	printf("\nTAMANHO HASH: %d", h->tamanho);
	readHashAlunoFromFile(h);
	printf("\nTAMANHO HASH: %d", h->tamanho);
	start(h);
	writeHashOnFile(h);

    return 0;
}