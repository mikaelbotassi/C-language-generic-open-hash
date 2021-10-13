#include "aluno.h"
#include "controleArquivo.h"

/*
AVISO: A estrutura está encapsulada, somente a biblioteca de aluno tem acesso a bibloteca de Hash Fechada,
somente a bibloteca de Hash tem acesso a bibloteca de lista.
Todas as estruturas armazenam void, contudo como o bojetivo do trabalho é armazenar alunos,
eu coloquei o cast somente para aluno.
*/

int main(){
    hashAberto *hash = (THashAberto *) malloc (sizeof(THashAberto));;
	int op;
	TAluno *a;
	inicializaHashAberto(hash,TAM_INICIAL, FATOR);
	do{
		op = menu();
		switch (op){
			case 1:
				
				a = (TAluno *) malloc (sizeof (TAluno));
				printf("\n Digite a Matricula e o Nome do aluno: \n");
				scanf("%d", &a->matricula);
				fflush(stdin);
				gets(a->nome);
				hash=insereAluno(*a,hash);
			break;
			
			case 2:
				imprimeHash(hash);
			break;
		}
		
	}while (op!=0);

    return 0;
}