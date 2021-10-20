//
//  hashFechada.c
//  LibLista
//
//  Created by Mikael Botassi de Oliveira on 07/10/21.
//

#include "hashAberta.h"
#include <stdio.h>
#include <stdlib.h>

hashAberto *expandeHash(hashAberto *hash, int (*pegaChave)(void *, char));

void inicializaHashAberto(hashAberto *hash, int tamanhoInicial, float fatorCarga)
{
	hash->quant = 0;
	hash->tamanho = tamanhoInicial;
	hash->fatorCarga = fatorCarga;
	hash->tabela = (elemento *)malloc(tamanhoInicial * sizeof(elemento));

	int i;
	for (i = 0; i < tamanhoInicial; i++)
	{
		hash->tabela[i].situacao = 0;
		hash->tabela[i].tipo = '\0';
		hash->tabela[i].valor = NULL;
	}
}

int hashCode(int matricula, int tam)
{
	return matricula % tam;
}

hashAberto *inserirNaHashAberta(char chave, hashAberto *hash, void *a, int (*pegaChave)(void *, char))
{
	//verifico se é necessário expandir
	if (((float)hash->quant / (float)hash->tamanho) > hash->fatorCarga)
	{
		hash = expandeHash(hash, pegaChave);
	}
	int code = hashCode(pegaChave(a, chave), hash->tamanho); //Pega a chave com a função na biblioteca aluno
	//Achar primeira posiço não ocupada a partir do codigo calculado (note a circularidade)
	while (hash->tabela[code].situacao == 1)
		code = (code + 1) % hash->tamanho;
	hash->tabela[code].valor = a;
	hash->tabela[code].situacao = 1;
	hash->tabela[code].tipo = chave;
	hash->quant++;
	return hash;
}

hashAberto *expandeHash(hashAberto *hash, int (*pegaChave)(void *, char))
{
	int i;
	//Aloco uma nova hash com o dobro do tamanho da orginal
	hashAberto *novaHash;
	novaHash = (hashAberto *)malloc(sizeof(hashAberto));
	inicializaHashAberto(novaHash, hash->tamanho * 2, hash->fatorCarga);

	//Transfiro os elementos da hash antiga para a nova
	for (i = 0; i < hash->tamanho; i++)
	{
		if (hash->tabela[i].situacao == 1)
		{
			inserirNaHashAberta(hash->tabela[i].tipo, novaHash, hash->tabela[i].valor, pegaChave);
		}
	}
	//desaloco a tabela da hash antiga e depois a hash em si.
	free(hash->tabela);
	free(hash);
	return novaHash;
}

void imprimeHash(hashAberto *hash, void (*print)(elemento *, int))
{
	int i;
	for (i = 0; i < hash->tamanho; i++)
	{
		if (hash->tabela[i].situacao == 1)
		{
			print(&(hash->tabela[i]), i);
		}
	}
}

elemento *pesquisaNaHash(hashAberto *h, int chave, int (*cmp)(int, elemento *))
{
	int code = hashCode(chave, h->tamanho);

	while (code != h->tamanho)
	{
		if (&(h->tabela[code]) == NULL)
		{
			return NULL;
		}
		else
		{
			if (h->tabela[code].situacao == 1)
			{
				if (cmp(chave, &(h->tabela[code])))
				{
					printf("\nIndice: %d", code);
					return &(h->tabela[code]);
				}
				else
				{
					code++;
				}
			}
			else
			{
				if (h->tabela[code].situacao == -1)
				{
					code++;
				}
				else
				{
					return NULL;
				}
			}
		}
	}
	return NULL;
}

//###################### FUNÇÕES DE ESTATATÍSTICAS ##########################################

void todasEstatisticas(hashAberto *h){//Printa as estatisticas
    totalElementos(h);
    /*printf("\nA media de elementos em cada indice eh: %.1f", mediaElementosIndice(h));
    descobreIndiceMaiorMenor(h);
    printf("\nO desvio padrao da hash eh: %.1f", calculaDesvioPadrao(h));
    printf("\n A quantidade de indices no intervalo eh: %d", indicesNoIntervalo(h));*/
}

void totalElementos(hashAberto *h){//quantidade total de elementos
    printf("\nO total de elementos da Hash eh: %d", h->quant);
}

/*float mediaElementosIndice(hashAberto * h){//quantidade média de elementos por índice
    int i;
    int totalNos=0;
    float media;
    for(i=0; i<h->tamanho; i++){
        totalNos = totalNos + h->dados[i].tam;
    }
    media=(float)(totalNos/h->tamanho);
    return media;
}

void descobreIndiceMaiorMenor(hashAberto * h){
    int i;
    int maior=0;
    int menor = 0;
    int elementosMaior = -1;
    int elementosMenor = 99999999;
    for(i=0; i<h->tamanho; i++){
        if(h->dados[i].tam>elementosMaior){//índice com a maior quantidade de elementos
            maior=i;
            elementosMaior=h->dados[i].tam;//quantidade de elementos desse índice
        }
        if(h->dados[i].tam<elementosMenor){//índice com a menor quantidade de elementos
            menor=i;
            elementosMenor=h->dados[i].tam;//quantidade de elementos desse índice
        }
    }

    printf("\nO indice com o maior numero de elementos eh: %d, e ele possui %d elementos", maior, elementosMaior);
    printf("\nO indice com o menor numero de elementos eh: %d, e ele possui %d elementos", menor, elementosMenor);
}

float calculaDesvioPadrao(hashAberto *h){//desvio padrão da quantidade de elementos pelos índices
    int i;
    float media = mediaElementosIndice(h);
    float soma = 0;
    float desvioPadrao=0;
    for(i=0; i<h->tamanho; i++){
        soma=soma + pow((h->dados[i].tam - media), 2);
    }
    desvioPadrao=soma/h->tamanho;
    return desvioPadrao;
}

int indicesNoIntervalo(hashAberto *h){//quantos índices tem quantidade dentro do intervalo da média +/- o desvio padrão.
    int i;
    int quantidadeIndicesIntervalo = 0;
    for(i=0; i<h->tamanho; i++){
        if(h->dados[i].tam >= (mediaElementosIndice(h) - calculaDesvioPadrao(h)) && h->dados[i].tam <= (mediaElementosIndice(h) - calculaDesvioPadrao(h))){
            quantidadeIndicesIntervalo++;
        }
    }
    return quantidadeIndicesIntervalo;
}*/