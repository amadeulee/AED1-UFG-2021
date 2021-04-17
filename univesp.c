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

int tamanho(LISTA* l) {

    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL) {
    tam++;
    end = end->prox;
    }
    return tam;
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

PONT buscaSequencial(LISTA* l, TIPOCHAVE ch) {

    PONT pos = l->inicio;
    while (pos != NULL) {
    if (pos->reg.chave == ch) return pos;
    pos = pos->prox;
    }
    return NULL;
}
// lista ordenada pelos valores das chaves dos registros
PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch) {

    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch) pos = pos->prox;
    if (pos != NULL && pos->reg.chave == ch) return pos;
    return NULL;
}

PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant){

    *ant = NULL;
    PONT atual = l->inicio;
    while ((atual != NULL) && (atual->reg.chave<ch)) {
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

bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {

    PONT ant, i;
    i = buscaSequencialExc(l,ch,&ant);
    if (i == NULL) return false;
    if (ant == NULL) l->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
    return true;
}

void reinicializarLista(LISTA* l) {
    
    PONT end = l->inicio;
    while (end != NULL) {
    PONT apagar = end;
    end = end->prox;
    free(apagar);
    }
    l->inicio = NULL;
}