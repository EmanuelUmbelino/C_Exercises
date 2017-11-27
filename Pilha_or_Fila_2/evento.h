typedef struct data Data;
struct data
{
    int dia,mes,ano;
};

typedef struct evento Evento;
struct evento
{
    char nomeEvento[81];
    char produtor[51];
    Data dt;
};

