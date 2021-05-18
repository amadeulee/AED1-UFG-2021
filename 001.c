/////////////////////ponto.h

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    int h;
    int m;
    int d;
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
void inserirElemento(FILA* f);
void removerDaFila(FILA* f);
int mortes(FILA* f);

//////////////////////////////////  .c
void iniciarFila(FILA* f){
    f->inicio=NULL;
    f->fim=NULL;
}

void inserirElemento(FILA* f){

    PONT novo;
    novo=(PONT) malloc(sizeof(ELEMENTO));
    scanf("%d %d %d", &novo->reg.h, &novo->reg.m, &novo->reg.d);
    novo->prox=NULL;
    if(f->inicio == NULL){
        f->inicio=novo;
    }else{
        f->fim->prox=novo;
    }
    f->fim=novo;
}

void removerDaFila(FILA* f){

    if(f->inicio==NULL){
        printf("empty\n");
    }
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio==NULL) f->fim=NULL;
}

int mortes(FILA* f){

    int chegada, atendimento, tempoAteMorte;
    int proximo=0, mortos=0;
    PONT end=f->inicio;
    while(end != NULL){
        chegada=(end->reg.h * 60) + end->reg.m;
        if(chegada<proximo){
            atendimento=proximo;
        }else{
            if(chegada % 30 == 0){
                atendimento=chegada;
            }else{
                int cifra=chegada % 30;
                atendimento=(30-cifra) + chegada;
            }
        }
        tempoAteMorte=(end->reg.h * 60) + end->reg.m + end->reg.d;
        if(tempoAteMorte<atendimento){
            mortos++;
        }
        proximo = atendimento + 30;
        removerDaFila(f);
        end=f->inicio;
        if(end == NULL){
            break;
        }
    }
    return mortos;
}


///////////main

int main(){

    int n, i, res=0;
    FILA f;
    iniciarFila(&f);
    scanf("%d", &n);

    for(i=0; i<n;i++){
        inserirElemento(&f);
    }
    res = mortes(&f);
    printf("%d\n", res);
    return 0;
}