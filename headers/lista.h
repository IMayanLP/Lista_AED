struct pessoas {
    int id;
    char nome[20];
};

struct informacoes {
    int impares;
    int pares;
    int maior;
    int menor;
};

typedef struct elementoN *Lista;

Lista* criar();
int inserirInicio(Lista*, struct pessoas);
int imprimir(Lista*);
int removerInicio(Lista*);
int inserirFim(Lista*, struct pessoas);
int removerFim(Lista*);
int inserirOrdenado(Lista*, struct pessoas);
int tamanho(Lista*);
int removerValor(Lista*, int);
int acessarValor(Lista*, int, struct pessoas*);
int acessarIndice(Lista*, int, struct pessoas*);
void destruir(Lista*);

// funções atividade
Lista* concatenar(Lista*, Lista*); // OK
int inserirSemRep(Lista*, struct pessoas); // OK
int verifValor(Lista*, int); // OK
int info(Lista*, struct informacoes*); // OK
int removerDoisI(Lista *); // OK
int removerDoisF(Lista *); // OK
int inverter(Lista *); // OK
int segmentar(Lista*, int, Lista*, Lista*); // OK