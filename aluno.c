#include "aluno.h"

/*
Função de menu, esta função chama as outras funções dependendo da resposta do usuário.
*/
void menu(hashAberto *h)
{
    int res = 5;
    while (res != 4)
    {
        printf("\n 0 - EXIBIR ESTATISTICAS;");
        printf("\n 1 - INCLUIR ALUNO;");
        printf("\n 2 - EFETUAR BUSCA POR MATRICULA;");
        printf("\n 3 - EXCLUIR POR MATRICULA;");
        printf("\n 4 - SAIR");

        printf("\nDigite o numero correspondente a funcao que deseja utilizar: ");
        scanf(" %d", &res);

        /*if(res==1){
            exibeEstatisticas(h1, h2);
        }*/
        if (res == 1)
        {
            newAluno(h);
        }
        if (res == 2)
        {
            alunoSearch(h);
        }
        if (res == 3)
        {
            excluiAluno(h);
        }
    }
}

aluno *allocAluno()
{
    aluno *p = (aluno *)malloc(sizeof(aluno));
    p->matricula = 0;
    p->nota = 0;
    strcpy(p->nome, "\0");
    return p;
}

void newAluno(hashAberto *h1)
{ //Caso o usuário queira inserir um aluno novo sem leitura de arquivos
    aluno *p = allocAluno();
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &p->matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %31[^\n]", &p->nome);
    printf("Digite a nota do aluno: ");
    scanf("%d", &p->nota);
    insertAluno(h1, p);
}

hashAberto *insertAluno(hashAberto *h, aluno *a)
{
    return inserirNaHashAberta('A', h, a, returnChave);
}

int descobreTipo(char id)
{
    /*
Esta função pega o tipo de dado passado pelo variavel, neste caso
como quero trabalhar apenas com aluno, recdbo apenas o tipo 'A' ou 'a'
*/
    if (id == 'A' || id == 'a')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void alunoSearch(hashAberto *h)
{ //Procura o aluno pela matricula
    int chave;
    printf("\nQual a matricula da pessoa que voce quer procurar? ");
    scanf(" %d", &chave);
    elemento *e = pesquisaNaHash(h, chave, matriculaCompare);
    if (e != NULL)
    {//ACHOU O ELEMENTO
        printAluno(e->tipo, e->valor);
    }
    else
    {//NÃO ACHOU
        printf("\nALUNO NAO EXISTE!\n");
    }
}

int matriculaCompare(int matricula, elemento *elem)
{ //função de comparar pra ver se as matriculas são iguais
    if (descobreTipo(elem->tipo))
    {
        aluno *p = elem->valor;
        if (p->matricula == matricula)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return 0;
    }
}

void excluiAluno(hashAberto * h)
{//Função que exclui um determinado aluno da Lista
    int chave;
    printf("\nQual a matricula da pessoa que voce quer excluir? ");
    scanf(" %d", &chave);
    elemento *e = pesquisaNaHash(h, chave, matriculaCompare);/*Chama a função de pesquisar na hash que
retorna o elemento que deseja excluir    */
    if (e != NULL)
    {
        printAluno(e->tipo, e->valor);
        e->situacao=-1;//Situação de excluido
        e->tipo='\0';//Como vai desalocar o elemento o tipo armazenado é void(\0)
        free(e->valor);//Da um free no elemento que o ponteiro void aponta
        e->valor=NULL;//Aponta o ponteiro void para NULL agora
        printf("\n\n.......ALUNO EXCLUIDO!.........\n\n");
    }
    else
    {
        printf("\nALUNO NAO EXISTE!\n");
    }
}

void printAluno(char id, void *elem)
{
    if (descobreTipo(id))
    {
        aluno *p = elem;
        printf("\nMatricula: %d", p->matricula);
        printf("\nNome: %s", p->nome);
        printf("\nNota: %d", p->nota);
        printf("\n");
    }
    else
    { //Caso a variavel não seja do tipo aluno
        printf("\nNao e possivel printar! ");
    }
}

void printIndice(elemento *elem, int indice)
{
    if (descobreTipo(elem->tipo))
    {
        aluno *p = elem->valor;
        printf("\n Indice = %d - Matricula = %d - Nome = %s\n", indice, p->matricula, p->nome);
    }
    else
    { //Caso a variavel não seja do tipo aluno
        printf("\nDigite mais sentencas! ");
    }
}

void printAllHash(hashAberto *h)
{
    if (h->tamanho == 0)
    {
        printf("Hash vazia!\n");
    }
    else
    {
        imprimeHash(h, printIndice);
    }
}

int returnChave(void *elem, char id)
{
    if (descobreTipo(id))
    { // É do tipo aluno?
        aluno *a = elem;
        return a->matricula; //Se sim retorna a matricula do aluno, a "chave" para a inserção
    }
    else
    {
        printf("\nDigite mais setenças de tipos de chaves! \n");
        return 0;
    }
}
