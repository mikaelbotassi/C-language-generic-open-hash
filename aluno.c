#include "aluno.h"

/*
Função de menu, esta função chama as outras funções dependendo da resposta do usuário.
*/
void start(hashAberto *h1,hashAberto *h2){
    int res=5;
    while(res !=4){
        printf("\n 1 - EXIBIR ESTATISTICAS;");
        printf("\n 2 - EFETUAR BUSCA POR MATRICULA;");
        printf("\n 3 - INCLUIR ALUNO;");
        printf("\n 4 - SAIR");

        printf("\nDigite o numero correspondente a funcao que deseja utilizar: ");
        scanf(" %d", &res);
        
        /*if(res==1){
            exibeEstatisticas(h1, h2);
        }
        if(res==2){
            alunoSearch(h1, h2);
        }*/

        if(res==3){
            newAluno(h1, h2);
        }
    }
}

aluno * allocAluno(){
    aluno * p=(aluno *)malloc(sizeof(aluno));
    p->matricula=0;
    p->nota=0;
    strcpy(p->nome, "\0");
    return p;
}

void newAluno(hashAberto * h1, hashAberto *h2){//Caso o usuário queira inserir um aluno novo sem leitura de arquivos
    aluno * p = allocAluno();
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &p->matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %31[^\n]", &p->nome);
    printf("Digite a nota do aluno: ");
    scanf("%d", &p->nota);
    insertAluno(h1, p);
    insertAluno(h2, p);
}

void insertAluno(hashAberto *h, aluno * a){
    inserirNaHashAberta('A', h, a, returnChave);
}

int descobreTipo(char id){
/*
Esta função pega o tipo de dado passado pelo variavel, neste caso
como quero trabalhar apenas com aluno, recdbo apenas o tipo 'A' ou 'a'
*/
    if(id=='A' || id=='a'){
        return 1;
    }
    else{
        return 0;
    }
}

int cmp(char id, elemento * n1, elemento *n2){
/*
Nesta função, chamada pela biblioteca de lista basicamente compara o nó atual com o novo nó
que se quer inserir, o novo nó é o node *n1 e o no atual que se compara o valor é o n2.
*/
    if(descobreTipo(id)){
        if(n2!=NULL){
            aluno *p1=n1->valor;//faz o cash dos valores dos dois nós
            aluno *p2=n2->valor;
            if(p1->matricula>p2->matricula){//Se for maior anda pra frente na estrutura lista
                return 1;
            }
            else{
                return 0;//Se for menor retorna falso e para de andar a lista
            }
        }
        else{
            return 0;
        }
    }
    else{
        printf("Insira outras verificações dos tipos de varáveis possíveis! ");
        return -1;
    }
}

/*void alunoSearch(hashAberto *h1, hashAberto *h2){//Procura o aluno pela matricula
    int age;
    printf("\nQual a matricula da pessoa que voce quer procurar? ");
    scanf("%d", &age);
    pesquisaNaHash(h1, age, matriculaCompare, printAluno);
    pesquisaNaHash(h2, age, matriculaCompare, printAluno);
}*/

int matriculaCompare(int matricula, void * elem, char id){//função de comparar pra ver se as matriculas são iguais
    if(descobreTipo(id)){
        aluno *p=elem;
        if(p->matricula==matricula){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        printf("\nDigite outras sentenças aqui!");
        return 0;
    }
}

void printAluno(char id, void *elem){
    if(descobreTipo(id)){
        aluno *p = elem;
        printf("\nMatricula: %d", p->matricula);
        printf("\nNome: %s", p->nome);
        printf("\nNota: %d", p->nota);
        printf("\n");

    }
    else{//Caso a variavel não seja do tipo aluno
        printf("\nDigite mais sentenças! ");
    }
}

void printIndice(elemento *elem, int indice){
    if(descobreTipo(elem->tipo)){
        aluno *p = elem->valor;
        printf("\n Indice = %d - Matricula = %d - Nome = %s\n", indice, p->matricula, p->nome);
    }
    else{//Caso a variavel não seja do tipo aluno
        printf("\nDigite mais sentencas! ");
    }
}

void printAllHash(hashAberto *h){
    if(h->tamanho==0){
        printf("Hash vazia!\n");
    }
    else{
        imprimeHash(h, printIndice);
    }
}

int returnChave(void * elem, char id){
    if(descobreTipo(id)){// É do tipo aluno?
        aluno * a = elem;
        return a->matricula;//Se sim retorna a matricula do aluno, a "chave" para a inserção
    }
    else{
        printf("\nDigite mais setenças de tipos de chaves! \n");
        return 0;
    }
}