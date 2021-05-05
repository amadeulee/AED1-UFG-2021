#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    int senha;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}FILA;

void iniciarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

void exibirFila(FILA* f){

    PONT end = f->inicio;
    printf("Fila : \" ");
    while(end != NULL){
        printf("%d\n", end->reg.senha);
        end = end->prox;
    } 
    printf("\"\n");
}

void inserirElemento(FILA* f, REGISTRO reg){

    PONT novo;
    novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;

    if(f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
}

PONT buscaSequencialExc(FILA* f, int ch, PONT* ant){

    *ant = NULL;
    PONT atual = f->inicio;
    
    while (atual != NULL){
        if(atual->reg.senha == ch) return atual;
    *ant = atual;
    atual = atual->prox;
    }
    return NULL;
    }
    
void excluirElemento(FILA* f, int ch) {

    PONT ant, i;
    i = buscaSequencialExc(f, ch, &ant);
    if (i == NULL) printf("elemento n existe\n");
    int proFicha = i->reg.senha;
    if (ant == NULL) f->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
}

void filaRestante(FILA* f, int n){
    int i, remover;
    for(i = 0; i < n; i++){
        scanf("%d", &remover);
        excluirElemento(f, remover);
    }
    PONT end = f->inicio;
    while(end != NULL){
        printf("%d ", end->reg.senha);
        end = end->prox;
    }
    
}


int main(){

    int num, i, removidos;
    FILA f;
    iniciarFila(&f);
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        REGISTRO reg;
        scanf("%d", &reg.senha);
        inserirElemento(&f, reg);
    }
    scanf("%d", &removidos);
    filaRestante(&f, removidos);
    return 0;
}