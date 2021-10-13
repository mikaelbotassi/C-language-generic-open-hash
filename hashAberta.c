//
//  hashFechada.c
//  LibLista 
//
//  Created by Mikael Botassi de Oliveira on 07/10/21.
//

#include "hashAberta.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaElemento(elemento *e);

hashAberto* expandeHash(hashAberto *hash, int(* pegaChave)(void *, char));

void inicializaElemento(elemento * e){
    e->situacao=0;
    e->tipo = '\0';
    e->valor = NULL;
}

void inicializaHashAberto (hashAberto *hash, int tamanhoInicial, float fatorCarga){	
	hash->quant = 0;
	hash->tamanho = tamanhoInicial;
	hash->fatorCarga = fatorCarga;
	hash->tabela = (elemento *) malloc (tamanhoInicial * sizeof(elemento));
	
	int i;
	for (i =0; i< tamanhoInicial; i++){
        inicializaElemento(&(hash->tabela[i]));
	}
}

int hashCode(int matricula, int tam){
	return matricula % tam;
}

hashAberto* inserirNaHashAberta(char chave, hashAberto *hash, void * a, int(* pegaChave)(void *, char)){

	//verifico se é necessário expandir
	if (( (float)hash->quant/(float)hash->tamanho) > hash->fatorCarga){
		hash=expandeHash(hash, pegaChave);
	}
	int code = hashCode(pegaChave(a, chave), hash->tamanho);//PEga a chave com a função na biblioteca aluno
	//Achar primeira posiço não ocupada a partir do codigo calculado (note a circularidade)
	while (hash->tabela[code].situacao == 1)
		code = (code + 1)%hash->tamanho;
	hash->tabela[code].valor=a;
	hash->tabela[code].situacao = 1;
    hash->tabela[code].tipo=chave;
	hash->quant++;
    return hash;
}

hashAberto* expandeHash(hashAberto *hash, int(* pegaChave)(void *, char)){
	int i;
	//Aloco uma nova hash com o dobro do tamanho da orginal
	hashAberto *novaHash;
	novaHash = (hashAberto *) malloc (sizeof(hashAberto));
	inicializaHashAberto(novaHash,hash->tamanho*2, hash->fatorCarga);
	
	//Transfiro os elementos da hash antiga para a nova
	for (i =0; i< hash->tamanho; i++){
		if (hash->tabela[i].situacao==1){
			inserirNaHashAberta(hash->tabela[i].tipo, novaHash, hash->tabela[i].valor, pegaChave);
		}
	}
	
	//desaloco a tabela da hash antiga e depois a hash em si.
	free(hash->tabela);
	free (hash);
	return novaHash;
}

void imprimeHash(hashAberto *hash, void (* print)(elemento *, int)){
	int i;
	for (i =0; i< hash->tamanho; i++){
		if (hash->tabela[i].situacao==1){
			print(&(hash->tabela[i]), i);
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