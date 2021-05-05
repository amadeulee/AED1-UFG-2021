#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    char nome[35];
    int ficha;
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

int tamanhoFila(FILA* f){

    PONT end = f->inicio;
    int tam = 0;
    while(end !=  NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirFila(FILA* f){

    PONT end = f->inicio;
    printf("Fila : \" ");
    while(end != NULL){
        printf("%s %d\n", end->reg.nome, end->reg.ficha);
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

PONT buscaSequencialExc(FILA* f, int pos, PONT* ant){

    *ant = NULL;
    PONT atual = f->inicio;
    int i = 0;
    while (atual != NULL){
        if(i == pos) return atual;
    *ant = atual;
    atual = atual->prox;
    i++;
    }
    return NULL;
    }
    
int excluirElemento(FILA* f, int pos) {

    PONT ant, i;
    i = buscaSequencialExc(f, pos, &ant);
    if (i == NULL) return false;
    int proFicha = i->reg.ficha;
    if (ant == NULL) f->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
    return proFicha;
}

int buscaSequencial(FILA* f, int ficha) {

    PONT pos = f->inicio;
    int posicao = 0;
    while (pos != NULL) {
        if (pos->reg.ficha == ficha){
            return posicao;
        }
    pos = pos->prox;
    posicao++;
    }
    return -1;
}

PONT buscaSequencial2(FILA* f, int posicao) {

    PONT pos = f->inicio;
    int atual = 0;
    while (pos != NULL) {
        if (atual == posicao){
            return pos;
        }
    pos = pos->prox;
    atual++;
    }
    return NULL;
}

void vencedor(FILA* f, int n){

    PONT end = f->inicio;
    PONT fim = f->inicio;

    while(fim->prox != NULL){
        int ficha = end->reg.ficha;
        int i = buscaSequencial(f, ficha);
        
        int contFicha = end->reg.ficha;
        if(contFicha % 2 != 0){
        for(contFicha; contFicha > 0; contFicha--){
            i++;
                if(i == n){
                    i = 0;
                }
            }
        }else{
            for(contFicha; contFicha > 0; contFicha--){
            i--;
                if(i < 0){
                    i = n - 1;
                }
            }
        }

        int proFicha = excluirElemento(f, i);
        n--;
        if(proFicha % 2 != 0){
            for(proFicha; proFicha > 0; proFicha--){
                i++;
                if(i == n){
                    i = 0;
                }
            }
        }else{
            for(proFicha; proFicha > 0; proFicha--){
                i--;
                if(i < 0){
                    i = n - 1;
                }
            }
        }
        //printf("%d\n", proFicha);
        end = buscaSequencial2(f, proFicha);
        fim = f->inicio;
        if(fim->prox == NULL){
            break;
        }
    }
    printf("%s\n", fim->reg.nome);
}



int main(){

    int num, i;
    FILA f;
    iniciarFila(&f);

    printf("insira total de jogadores e sua ficha:\n");
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        REGISTRO reg;
        scanf("%s %d", &reg.nome, &reg.ficha);
        inserirElemento(&f, reg);
    }
    exibirFila(&f);
    vencedor(&f, num);

    return 0;
}