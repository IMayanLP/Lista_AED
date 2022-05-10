#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

int main(){
    Lista *lds, *ldsA, *ldsB;
    lds = criar();
    ldsA = criar();
    ldsB = criar();
    struct pessoas dados;
    strcpy(dados.nome, "Julia");
    int i;
    for (i = 0; i < 10; i++){
        dados.id = i;
        inserirSemRep(lds, dados);
    }

    segmentar(lds, 5, ldsA, ldsB);
    imprimir(ldsA);
    imprimir(ldsB);
    printf("\n");
    return 0;
}