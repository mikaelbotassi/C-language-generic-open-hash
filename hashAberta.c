//
//  hashFechada.c
//  LibLista 
//
//  Created by Mikael Botassi de Oliveira on 07/10/21.
//

#include "hashAberta.h"


#include <stdio.h>
#include <stdlib.h>
#define TAM_INICIAL 10
#define FATOR 0.7

hashAberto* expandeHash(hashAberto *hash);

void inicializaHashAberto (hashAberto *hash, int tamanhoInicial, float fatorCarga){	
	hash->quant = 0;
	hash->tamanho = tamanhoInicial;
	hash->fatorCarga = fatorCarga;
	hash->tabela = (elemento *) malloc (tamanhoInicial * sizeof(elemento));
	
	int i;
	for (i =0; i< tamanhoInicial; i++){
		hash->tabela[i].situacao=0;
	}
}

int hashCode(int matricula, int tam){
	return matricula % tam;
}

hashAberto* push(void * a, hashAberto *hash){
	//verifico se ? necess?rio expandir
	if (( (float)hash->quant/(float)hash->tamanho) > hash->fatorCarga){
		hash=expandeHash(hash);
	}
	int code = hashCode(a.matricula, hash->tamanho);
	//Achar primeira posi??o n?o ocupada a partir do codigo calculado (note a circularidade)
	while (hash->tabela[code].situacao == 1)
		code = (code + 1)%hash->tamanho;
	hash->tabela[code].valor=a;
	hash->tabela[code].situacao = 1;
	hash->quant++;
}

hashAberto* expandeHash(hashAberto *hash){
	int i;
	//Aloco uma nova hash com o dobro do tamanho da orginal
	hashAberto *novaHash;
	novaHash = (hashAberto *) malloc (sizeof(hashAberto));
	inicializaHashAberto(novaHash,hash->tamanho*2, hash->fatorCarga);
	
	//Transfiro os elementos da hash antiga para a nova
	for (i =0; i< hash->tamanho; i++){
		if (hash->tabela[i].situacao==1){
			insereAluno(hash->tabela[i].valor,novaHash);
		}
	}
	
	//desaloco a tabela da hash antiga e depois a hash em si.
	free(hash->tabela);
	free (hash);
	return novaHash;
}

void imprimeHash(hashAberto *hash){
	int i;
	for (i =0; i< hash->tamanho; i++){
		if (hash->tabela[i].situacao==1){
			printf("\n Indice = %d - Matricula = %d - Nome = %s\n",i,hash->tabela[i].valor.matricula,hash->tabela[i].valor.nome);
		}
	}
}
	


int menu(){
	int op;
	printf("\n0 - Sair\n");
	printf("\n1 - Inserir\n");
	printf("\n2 - Listar\n");
	printf("\n\nDigite a opcao desejada: \n\n");
	scanf("%d", &op);
	return op;
}