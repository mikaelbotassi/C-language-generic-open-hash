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
