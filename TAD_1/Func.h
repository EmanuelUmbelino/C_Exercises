typedef struct funcionario Func;

Func *func_cria(char *nome, int ano);

char *func_getNome(Func *f);

int func_getAno(Func *f);