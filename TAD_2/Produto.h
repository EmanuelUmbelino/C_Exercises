typedef struct prod Produto;

Produto *criaProduto(char *nome, int qtd, float preco);

void imprimeProduto(Produto *p);

int estoqueVazio(Produto *p);

void liberaProduto(Produto *p);