typedef struct pilha Pilha;
// funcao que cria uma pilha de inteiros e retorna seu endereco
Pilha *piCria(void);
// funcao que recebe o endereco da pilha e um novo digito, inserindo-o
void piPush(Pilha *pi, int ninf);
// funcao que recebe o end da pilha e faz a retirada do elemento do topo da pilha, retornando-o
int piPop(Pilha *pi);
// funcao que recebe o endereco da pilha e retorna 1, se vazia, ou 0, caso contrario
int piEhVazia(Pilha *pi);
// funcao que recebe o endereco de uma pilha e libera o espaco por ela utilizado
void piLibera(Pilha *pi);
