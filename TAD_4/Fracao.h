typedef struct frac Fracao;

Fracao *criarFrac(int numerador, int denominador, int sinal);

void imprimirFracao(Fracao *frac);
//Recebe 2 fracoes e retorna 1 se a primeira eh maior, -1 se eh menor e 0 se sao iguais
int comparaFrac(Fracao *f1, Fracao *f2);

void liberaFrac(Fracao *frac);