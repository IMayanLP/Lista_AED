#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\lista.h"

struct elementoN {
    struct pessoas dados;
    struct elementoN *prox;
};

typedef struct elementoN Elementon;

Lista* criar(){
    Lista *lds;
    lds = (Lista*)malloc(sizeof(Lista));
    if(lds != NULL){
        *lds = NULL;
    }
    return lds;
}

int inserirInicio(Lista *lds, struct pessoas novosD){
    if(lds == NULL)return 0;
    Elementon *novo;
    novo = (Elementon*)malloc(sizeof(Elementon));
    novo->dados = novosD;
    novo->prox = *lds;
    *lds = novo;
    return 1;
}

int imprimir(Lista* lds){
    if(lds == NULL)return 0;
    if(*lds == NULL){
        printf("\n||\n");
        return 1;
    }
    Elementon *aux;
    aux = *lds;
    while(aux != NULL){
        printf("[%d, %s]-> ", aux->dados.id, aux->dados.nome);
        aux = aux->prox;
    }
    printf("||\n");
    return 1;
}

int removerInicio(Lista* lds){
    if(lds == NULL)return 0;
    if(*lds == NULL)return 0;
    Elementon *aux;
    aux = *lds;
    *lds = (*lds)->prox;
    free(aux);
    return 1;
}

int inserirFim(Lista* lds, struct pessoas novosD){
    if(lds == NULL)return 0;
    Elementon *novo;
    novo = (Elementon*)malloc(sizeof(Elementon));
    novo->dados = novosD;
    if(*lds == NULL){
        *lds = novo;
    } else {
        Elementon *aux;
        aux = *lds;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
    }
    return 1;
}

int removerFim(Lista* lds){
    if(lds == NULL)return 0;
    if(*lds == NULL)return 0;
    Elementon *aux, *ant;
    ant = NULL;
    aux = *lds;
    if(tamanho(lds) == 1){
        *lds = NULL;
        free(aux);
    } else {
        while(aux->prox != NULL){
         ant = aux;
         aux = aux->prox;
        }
        ant->prox = NULL;
        free(aux);
    }
    return 1;
}

int tamanho(Lista* lds){
    if(lds == NULL)return -1;
    if(*lds == NULL)return 0;
    Elementon *aux;
    int cont = 0;
    aux = *lds;
    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

int inserirOrdenado(Lista *lds, struct pessoas novosD){
    if(lds == NULL)return 0;
    Elementon *novo;
    novo = (Elementon*)malloc(sizeof(Elementon));
    novo->dados = novosD;
    if(tamanho(lds) == 0 || (*lds)->dados.id > novo->dados.id){
        inserirInicio(lds, novosD);
        return 1;
    } else {
        Elementon *ant = *lds;
        Elementon *aux = ant->prox;
        while(aux != NULL && aux->dados.id < novo->dados.id){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = novo;
        novo->prox = aux;
        return 1;
    } 
}

int removerValor(Lista* lds, int valor){
    if(lds == NULL) return 0;
    if(*lds == NULL) return 0;
    if(valor == (*lds)->dados.id){
        removerInicio(lds);
        return 1;
    }
    Elementon *aux, *ant;
    ant = *lds;
    aux = ant->prox;
    while(aux->prox != NULL && valor != aux->dados.id){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    free(aux);
}

int acessarValor(Lista* lds, int valor, struct pessoas *dados){
    if(lds == NULL) return 0;
    if(*lds == NULL) return 0;
    if(valor == (*lds)->dados.id){
        *dados = (*lds)->dados;
        return 1;
    }
    Elementon *aux;
    aux = *lds;
    while(aux != NULL && valor != aux->dados.id){
        aux = aux->prox;
    }
    if(aux == NULL)return -1;
    *dados = aux->dados;
    return 1;
}

int acessarIndice(Lista* lds, int indice, struct pessoas* dados){
    if(lds == NULL) return 0;
    if(*lds == NULL) return 0;
    int count = 1;
    Elementon *aux;
    aux = *lds;
    while(aux != NULL && indice != count){
        aux = aux->prox;
        count++;
    }
    if(aux == NULL){
        return 0;
    }
    *dados = aux->dados;
    return 1;
}

void destruir(Lista *lds){
    if(lds == NULL) return 0;
    if(*lds == NULL) return 0;
    Elementon *aux = *lds;
    while(aux != NULL){
        removerInicio(lds);
    }
    free(lds);
    return 1;
}

// FUNÇÕES ATIVIDADE

int verifValor(Lista *lds, int id){
    if(lds == NULL) return 0;
    Elementon *aux = *lds;
    while(aux != NULL && aux->dados.id != id){
        aux = aux->prox;
    }
    if(aux != NULL) return 1;
}

int inserirSemRep(Lista *lds, struct pessoas dados){
    if(lds == NULL) return 0;
    if(!verifValor(lds, dados.id)){
        inserirInicio(lds, dados);
        return 1;
    } else {
        return 0;
    }
}

int info(Lista *lds, struct informacoes *dados){
    if(lds == NULL) return 0;
    if(*lds == NULL) return 0;
    int min, max, i = 0, p = 0;
    Elementon *aux = *lds;
    min = aux->dados.id;
    max = aux->dados.id;
    while (aux != NULL){
        if(aux->dados.id > max) max = aux->dados.id;
        if(aux->dados.id < min) max = aux->dados.id;
        if(aux->dados.id%2 == 0) p++;
        else i++;
        aux = aux->prox;
    }
    
    dados->impares = i;
    dados->pares = p;
    dados->menor = min;
    dados->maior = max;

    return 1;
}

int removerDoisI(Lista *lds) {
    if(lds == NULL) return 0;
    if(tamanho(lds) < 2) return 0;
    else {
        Elementon *aux, *ant;
        ant = *lds;
        aux = ant->prox;
        *lds = aux->prox;
        free(ant);
        free(aux);
        return 1;
    }
}

int removerDoisF(Lista *lds) {
    if(lds == NULL) return 0;
    if(tamanho(lds) < 2) return 0;
    else {
        Elementon *ant, *aux, *post;
        ant = *lds;
        aux = ant->prox;
        post = aux->prox;
        while(post->prox != NULL){
            ant = aux;
            aux = post;
            post = post->prox;
        }
        ant->prox = NULL;
        free(aux);
        free(post);
        return 1;
    }
}

int inverter(Lista *lds){
    if(lds == NULL) return 0;
    if(tamanho(lds) < 2) return 0;
    else if(tamanho(lds) == 2){
        Elementon *aux, *ant;
        ant = *lds;
        aux = ant->prox;

        *lds = aux;
        aux->prox = ant;
        ant->prox = NULL;
    } else {
        Elementon *inicio, *aux, *ref, *fim;
        inicio = *lds;
        aux = *lds;
        ref = *lds;
        fim = *lds;
        while(fim->prox != NULL){
            fim = fim->prox;
            ref = ref->prox;
        }
        while(ref->prox != inicio){
            while(aux->prox != ref){
                aux = aux->prox;
            }
            ref->prox = aux;
            ref = aux;
            aux = *lds;
        }

        *lds = fim;
        inicio->prox = NULL;
    }

    return 1;
}

int segmentar(Lista *lds, int n, Lista *ldsA, Lista *ldsB){
    if(lds == NULL) return 0;
    if(*lds == NULL) return 0;
    if(n >= tamanho(lds)) return 0;
    int count = 0;
    int tamMax = tamanho(lds);
    while(count < n) {
        inserirInicio(ldsA, (*lds)->dados);
        removerInicio(lds);
        count++;
    }
    count = 0;
    while (count < (tamMax - n)){
        inserirInicio(ldsB, (*lds)->dados);
        removerInicio(lds);
        count++;
    }

    return 1;
}

Lista* concatenar(Lista *lds1, Lista *lds2){
    if(lds1 == NULL || lds2 == NULL) return 0;
    if(*lds1 == NULL || *lds2 == NULL) return 0;
    Lista *lds;
    lds = (Lista*)malloc(sizeof(Lista));
    if(lds != NULL) *lds = NULL;

    while(*lds1 != NULL){
        inserirInicio(lds, (*lds1)->dados);
        removerInicio(lds1);
    }

    while(*lds2 != NULL){
        inserirInicio(lds, (*lds2)->dados);
        removerInicio(lds2);
    }
    destruir(lds1);
    destruir(lds2);

    return lds;
}