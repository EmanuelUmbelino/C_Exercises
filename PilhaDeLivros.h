#include "livro.h"
typedef struct pilhaDeLivros PilhaDeLivros;
// funcao que cria uma pilha de inteiros e retorna seu endereco
PilhaDeLivros *piCria(void);
// funcao que recebe o endereco da pilha e um novo digito, inserindo-o
void piPush(PilhaDeLivros *p, Livro *liv);
// funcao que recebe o end da pilha e faz a retirada do elemento do topo da pilha, retornando-o
Livro *piPop(PilhaDeLivros *p);
// funcao que recebe o endereco da pilha e retorna 1, se vazia, ou 0, caso contrario
int piVazia(PilhaDeLivros *p);
// funcao que recebe o endereco de uma pilha e libera o espaco por ela utilizado
void piLibera(PilhaDeLivros *p);
