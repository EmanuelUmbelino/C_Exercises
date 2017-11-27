typedef struct livro Livro;
struct livro
{
    char autor[51];
    char titulo[31];
    int qtdVendida;
};

typedef struct no No;
struct no
{
    Livro *info;
    No *prox;
};

