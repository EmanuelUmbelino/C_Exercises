typedef struct rect Retangulo;

Retangulo *criarRect(float x, float y, float base, float altura);

float getX(Retangulo *rect);

float getY(Retangulo *rect);

float getBase(Retangulo *rect);

float getAltura(Retangulo *rect);

void liberaRect(Retangulo *rect);