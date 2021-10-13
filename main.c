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
    hashAberto *hash = (hashAberto *) malloc (sizeof(hashAberto));;
	int op;
	aluno *a;
	inicializaHashAberto(hash,TAM_INICIAL, FATOR);
	do{
		op = menu();
		switch (op){
			case 1:
				
				a = (aluno *) malloc (sizeof (aluno));
				printf("\n Digite a Matricula e o Nome do aluno: \n");
				scanf("%d", &a->matricula);
				fflush(stdin);
				gets(a->nome);
				hash=insereAluno(*a,hash);
			break;
			
			case 2:
				imprimeAllHash(hash);
			break;
		}
		
	}while (op!=0);

    return 0;
}