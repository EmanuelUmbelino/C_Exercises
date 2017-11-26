typedef struct fila Fila;
//Iniciar uma fila
Fila *cria(void);
//Insere um elemento na fila
void insere(Fila *f, int v);
//Retira o elemento do inicio da fila e retorna seu valor
int retira(Fila *f);
//Se a fila estiver vazia retorna 1, caso contrario retorna 0
int vazia(Fila *f);
//Libera a lista completa
void libera(Fila *f);
