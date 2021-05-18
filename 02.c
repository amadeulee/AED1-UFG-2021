/////////////////////////ponto.h
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#define true 1;
#define false 0;
typedef int bool;

typedef struct {
    char nome[35];
    int ficha;
}REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
    PONT fim;
}FILA;

void inicializarFila(FILA* f);
int numElementos(FILA* f);
bool inserirNaFila(FILA* f, REGISTRO reg);
void retirarDaFila(FILA* f, char* nome);
void reiniciarFila(FILA* f);
void vencedor(FILA* f);

///////////////////////////////// .c

void inicializarFila(FILA* f){
    f->inicio=NULL;
    f->fim=NULL;
}

int numElementos(FILA* f){
    PONT end=f->inicio;
    int tam=0;
    while(end != NULL) {
        tam++;
        end=end->prox;
    }
    return tam;
}

bool inserirNaFila(FILA* f, REGISTRO reg){

    PONT novo=(PONT) malloc(sizeof(ELEMENTO));
    novo->reg=reg;
    novo->prox=NULL;
    if(f->inicio == NULL)f->inicio=novo;
    else f->fim->prox=novo;
    f->fim=novo;
    return true;
}

void retirarDaFila(FILA* f, char* nome) {
    PONT end=f->inicio;
    PONT ant=NULL;
    while(strcmp(end->reg.nome, nome) != 0) {
        ant=end;
        end=end->prox;
    }
    if(ant==NULL) {
        if(end == f->fim) f->fim=NULL;
        PONT apagar = end;
        f->inicio=end->prox;
        free(apagar);
    }else {
        if(end==f->fim) f->fim=ant;
        PONT apagar=end;
        ant->prox=end->prox;
        free(apagar);
    }
}

void reiniciarFila(FILA* f) {
    PONT end=f->inicio;
    while(end != NULL) {
        PONT apagar=end;
        end=end->prox;
        free(apagar);
    }
    f->inicio=NULL;
    f->fim=NULL;
}

void vencedor(FILA* f) {
    int elementos = numElementos(f);
    int num=f->inicio->reg.ficha, cont = 0;

    if(num%2==0){
        cont=elementos-(num % elementos);
    }else{
        cont=num%elementos;
    }
    while(f->inicio->prox != NULL) {
        PONT end=f->inicio;
        int i=0;
        for(i=0; i<cont; i++) {
            if(end->prox != NULL) end=end->prox;
            else end=f->inicio;
        }
        elementos = numElementos(f)-1;
        num=end->reg.ficha;
        if(num%2 == 0){
            cont=elementos-(num % elementos);
        }else cont=num % elementos;
        retirarDaFila(f, end->reg.nome);
    }
    printf("%s\n", f->inicio->reg.nome);
}

////////////////////////// main

int main(){

    int n, i;
    FILA f;
    inicializarFila(&f);

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        REGISTRO reg;
        scanf("%s %d", reg.nome, &reg.ficha);
        inserirNaFila(&f, reg);
    }
    vencedor(&f);
    reiniciarFila(&f);
    return 0;
}