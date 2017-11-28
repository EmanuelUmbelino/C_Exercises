typedef struct quadrado Quadrado;
// recebe as coordenadas x e y do vertice superior direito, medida do lado
// e o nome que identifica um quadrado, criando um novo quadrado e o retornando
Quadrado *quaCria(float x, float y, float lado, char *nome);
// retorna a coordenada x do vertice superior direito
float quaObtemXdeVSD(Quadrado *q);
// retorna a coordenada y do vertice superior direito
float quaObtemYdeVSD(Quadrado *q);
// retorna a medida do lado do quadrado
float quaObtemLado(Quadrado *q);
// retorna o nome do quadrado
char *quaObtemNome(Quadrado *q);
// libera o quadrado
void quaLibera(Quadrado *q);