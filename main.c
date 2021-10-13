#include "aluno.h"
#include "controleArquivo.h"

#define TAM_INICIAL 10
#define FATOR 0.7

/*
AVISO: A estrutura está encapsulada, somente a biblioteca de aluno tem acesso a bibloteca de Hash Fechada,
somente a bibloteca de Hash tem acesso a bibloteca de lista.
Todas as estruturas armazenam void, contudo como o bojetivo do trabalho é armazenar alunos,
eu coloquei o cast somente para aluno.
*/

int main(){
    hashAberto *h1 = (hashAberto *) malloc (sizeof(hashAberto));
	hashAberto *h2 = (hashAberto *) malloc (sizeof(hashAberto));
	inicializaHashAberto(h1,TAM_INICIAL, FATOR);
	inicializaHashAberto(h2,TAM_INICIAL, FATOR);

	start(h1, h2);

    return 0;
}