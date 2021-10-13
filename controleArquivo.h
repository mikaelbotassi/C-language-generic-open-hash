#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

#ifndef HASH_FECHADA_CONTROLEARQUIVOALUNO_H
#define HASH_FECHADA_CONTROLEARQUIVOALUNO_H

void readHashAlunoFromFile(hashFechada *hash1, hashFechada *hash2);

void writeHashOnFile(hashFechada *hash);

#endif //HASH_FECHADA_CONTROLEARQUIVOALUNO_H