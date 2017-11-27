#include "PilhaDeEventos.h"
typedef struct filaDeEventos FilaDeEventos;
//Iniciar uma fila
FilaDeEventos *fiCria(void);
//Insere um elemento na fila
void fiInsere(FilaDeEventos *f, Evento *ev);
//Retira o elemento do inicio da fila e retorna seu valor
Evento *fiRetira(FilaDeEventos *f);
//Se a fila estiver vazia retorna 1, caso contrario retorna 0
int fiVazia(FilaDeEventos *f);
//Libera a fila completa
void fiLibera(FilaDeEventos *f);
