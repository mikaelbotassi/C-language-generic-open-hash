#ifndef hashAberta_h
#define hashAberta_h
#include <stdio.h>
#include <math.h>


// #################### ESTRUTURAS  #################################

typedef struct Bloco{
	int indiceInicial;
	int indiceFinal;
	int quant;
}bloco;

typedef struct Elemento{
	void * valor;
	int situacao; //0 - nunca utilizado, 1 - ocupado, -1 excluido
    char tipo; //Necessário para fazer o cast, já que é uma estrutura genérica
}elemento;

typedef struct HashAberto{
	elemento *tabela;
	int quant;
	int tamanho;
	float fatorCarga;
}hashAberto;

// #####################################################################

// #################### FUNÇÕES ########################################

void inicializaHashAberto (hashAberto *hash, int tamanhoInicial, float fatorCarga);

int hashCode(int matricula, int tam);

hashAberto* inserirNaHashAberta(char chave, hashAberto *hash, void * a, int(* pegaChave)(void *, char));

void imprimeHash(hashAberto *hash, void (* print)(elemento *, int));

elemento * pesquisaNaHash(hashAberto *h, int chave, int (* cmp)(int, elemento *));

bloco insereNoBloco(int quant, int inicio, int fim);

void todasEstatisticas(hashAberto *h);

void totalElementos(hashAberto *h);

float pegaMediaElementosBloco(hashAberto * h);

void descobreBlocoMaiorMenor(hashAberto * h);

void freeHash(hashAberto *h);

// #####################################################################

#endif
