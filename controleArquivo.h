#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

#ifndef HASH_FECHADA_CONTROLEARQUIVOALUNO_H
#define HASH_FECHADA_CONTROLEARQUIVOALUNO_H

void readHashAlunoFromFile(hashAberto *hash1);

void writeHashOnFile(hashAberto *hash);

#endif //HASH_FECHADA_CONTROLEARQUIVOALUNO_H