#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    int dificuldade;
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
        printf("%d ", end->reg.dificuldade);
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

PONT buscaSequencialNaoOrd(FILA* l, int ch, PONT* ant){

    *ant = NULL;
    PONT atual = l->inicio;
    while ((atual != NULL) && (atual->reg.dificuldade>ch)) {
    *ant = atual;
    atual = atual->prox;
    }
    if ((atual != NULL) && (atual->reg.dificuldade == ch)) return atual;
    return NULL;
    }

PONT buscaSequencialOrd(FILA* l, int ch, PONT* ant){

    *ant = NULL;
    PONT atual = l->inicio;
    while ((atual != NULL) && (atual->reg.dificuldade<ch)) {
    *ant = atual;
    atual = atual->prox;
    }
    if ((atual != NULL) && (atual->reg.dificuldade == ch)) return atual;
    return NULL;
    }

bool inserirElemFilaord(FILA* l, REGISTRO reg) {

    int ch = reg.dificuldade;
    PONT ant, i;
    i = buscaSequencialOrd(l,ch,&ant);
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

bool inserirElemFiladec(FILA* l, REGISTRO reg) {

    int ch = reg.dificuldade;
    PONT ant, i;
    i = buscaSequencialNaoOrd(l,ch,&ant);
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

void excluirElemento(FILA* f){

    if(f->inicio == NULL){
        printf("fila vazia\n");
    }
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL) f->fim = NULL;
}


void reinicializarFila(FILA* f) {

    PONT end = f->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int contadorQuestoes(FILA* f, int tempo, int* pontuacaototal) {
    
    PONT end = f->inicio;
    int pontuacao = 0, cont = 0, comparar = 0;
    while (pontuacao < tempo) {
    PONT apagar = end;
    end = end->prox;
    pontuacao = pontuacao + apagar->reg.dificuldade;
    if(pontuacao > tempo) break;
    *pontuacaototal = *pontuacaototal + pontuacao;
    free(apagar);
    cont++;
    }
    
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
   
    return cont;
}


int main(){

    FILA f1, f2, f3;
    iniciarFila(&f1);
    iniciarFila(&f2);
    iniciarFila(&f3);

    int teste, n, i, j, tempo, questoes;
    scanf("%d", &n);
    for(i = 0; i < n; i++){

        
        scanf("%d %d", &tempo, &questoes);
        for(j = 0; j < questoes; j++){
            REGISTRO reg;
            scanf("%d", &reg.dificuldade);
            inserirElemento(&f1, reg);
            inserirElemFilaord(&f2, reg);
            inserirElemFiladec(&f3, reg);
        }
        /*exibirFila(&f1);
        exibirFila(&f2);
        exibirFila(&f3);*/
        int cont1, cont2, cont3, pontuacao1 = 0, pontuacao2 = 0, pontuacao3 = 0;
            cont1 = contadorQuestoes(&f1, tempo, &pontuacao1);
            cont2 = contadorQuestoes(&f2, tempo, &pontuacao2);
            cont3 = contadorQuestoes(&f3, tempo, &pontuacao3);
            //printf("%d %d %d\n", cont1, cont2, cont3);

            if(cont1 > cont2 && cont1 > cont3){
                printf("John %d %d\n", cont1, pontuacao1);
            }else if(cont2 > cont1 && cont2 > cont3){
                printf("Jack %d %d\n", cont2, pontuacao2);
            }else if(cont3 > cont1 && cont3 > cont2){
                printf("Jade %d %d\n", cont3, pontuacao3);
            }else if(cont1 == cont2){
                if(pontuacao1 < pontuacao2){
                    printf("John %d %d\n", cont1, pontuacao1);
                }else{
                    printf("Jack %d %d\n", cont2, pontuacao2);
                }
            }
            else if(cont1 == cont3){
                if(pontuacao1 < pontuacao3){
                    printf("John %d %d\n", cont1, pontuacao1);
                }else{
                    printf("Jade %d %d\n", cont3, pontuacao3);
                }
            }
            else if(cont2 == cont3){
                if(pontuacao2 < pontuacao3){
                    printf("Jack %d %d\n", cont2, pontuacao2);
                }else{
                    printf("Jade %d %d\n", cont3, pontuacao3);
                }
            }

            
    }
    

    return 0;
}