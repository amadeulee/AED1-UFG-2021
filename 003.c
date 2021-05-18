/////////////////////////// ponto.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#define true 1
#define false 0
typedef int bool;

typedef struct{
    int bilhete;
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

void iniciarFila(FILA* f);
void inserirBilhete(FILA* f);
PONT buscaSequencialExc(FILA* f, int ch, PONT* ant);
void removerBilhete(FILA* f, int ch);
void filaFinal(FILA* f, int n);

//////////////////////////////// .c

void iniciarFila(FILA* f){
    f->inicio=NULL;
    f->fim=NULL;
}

void inserirBilhete(FILA* f){
    PONT novo;
    novo=(PONT) malloc(sizeof(ELEMENTO));
    scanf("%d", &novo->reg.bilhete);
    novo->prox=NULL;
    if(f->inicio == NULL){
        f->inicio=novo;
    }else{
        f->fim->prox=novo;
    }
    f->fim=novo;
}

PONT buscaSequencialExc(FILA* f, int ch, PONT* ant){
    *ant = NULL;
    PONT atual=f->inicio;
    while (atual != NULL){
        if(atual->reg.bilhete==ch) return atual;
    *ant=atual;
    atual=atual->prox;
    }
    return NULL;
    }
    
void removerBilhete(FILA* f, int ch){
    PONT ant, i;
    i = buscaSequencialExc(f, ch, &ant);
    if (i == NULL) printf("erro!\n");
    int proFicha=i->reg.bilhete;
    if (ant == NULL) f->inicio=i->prox;
    else ant->prox=i->prox;
    free(i);
}

void filaFinal(FILA* f, int n){
    int i, remover;
    for(i=0; i<n; i++){
        scanf("%d", &remover);
        removerBilhete(f, remover);
    }
    PONT end=f->inicio;
    while(end != NULL){
        printf("%d ", end->reg.bilhete);
        end=end->prox;
    }
    
}

//////////////////////////  main

int main(){

    int num, i, removidos;
    FILA f;
    iniciarFila(&f);
    scanf("%d", &num);

    for(i=0; i<num; i++){
        inserirBilhete(&f);
    }
    scanf("%d", &removidos);
    filaFinal(&f, removidos);
    return 0;
}