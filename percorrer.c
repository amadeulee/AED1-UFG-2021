#include <stdio.h>
#include <malloc.h>

#define true 1
#define false -1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
TIPOCHAVE chave;
// outros campos...
} REGISTRO;

typedef struct aux {
REGISTRO reg;
struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
PONT inicio;
} LISTA;

void inicializarLista(LISTA* l){
l->inicio = NULL;
}

PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant){

    *ant = NULL;
    PONT atual = l->inicio;
    while ((atual != NULL) && (atual->reg.chave>ch)) {
    *ant = atual;
    atual = atual->prox;
    }
    if ((atual != NULL) && (atual->reg.chave == ch)) return atual;
    return NULL;
    }

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {

    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialExc(l,ch,&ant);
    if (i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if (ant == NULL) {
    i->prox = l->inicio;
    l->inicio = i;
    } else {
    i->prox = ant->prox;
    ant->prox = i;
    }
    return true;
}

void exibirLista(LISTA* l){

    PONT end = l->inicio;
    printf("Lista: \" ");
    while (end != NULL) {
    printf("%i ", end->reg.chave);
    end = end->prox;
    }
    printf("\"\n");
}

int main(){

    LISTA l;
    inicializarLista(&l);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        REGISTRO reg;
        scanf("%d", &reg.chave);
        inserirElemListaOrd(&l, reg);
    }
    exibirLista(&l);











    return 0;
}