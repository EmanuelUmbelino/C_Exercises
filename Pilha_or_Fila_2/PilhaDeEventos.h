#include "evento.h"
typedef struct pilhaDeEventos PilhaDeEventos;
// funcao que cria uma pilha de inteiros e retorna seu endereco
PilhaDeEventos *piCria(void);
// funcao que recebe o endereco da pilha e um novo digito, inserindo-o
void piPush(PilhaDeEventos *p, Evento *ev);
// funcao que recebe o end da pilha e faz a retirada do elemento do topo da pilha, retornando-o
Evento *piPop(PilhaDeEventos *p);
// funcao que recebe o endereco da pilha e retorna 1, se vazia, ou 0, caso contrario
int piVazia(PilhaDeEventos *p);
// funcao que recebe o endereco de uma pilha e libera o espaco por ela utilizado
void piLibera(PilhaDeEventos *p);
