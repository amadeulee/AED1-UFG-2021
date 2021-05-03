#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    int horas;
    int minutos;
    int timeToDie;
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

    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}


void exibirFila(FILA* f){

    PONT end = f->inicio;

    printf("Fila : \" ");
    while(end != NULL){
        printf("%d %d %d \n", end->reg.horas, end->reg.minutos, end->reg.timeToDie);
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

void excluirElemento(FILA* f){

    if(f->inicio == NULL){
        printf("fila vazia\n");
    }
    //*reg = f->inicio->reg;
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

int numMortos(FILA* f){

    int i, horarioChegada, proAtendimento = 0, tempoMorte, mortos = 0;
    PONT end = f->inicio;

    while(end != NULL){

        horarioChegada = (end->reg.horas * 60) + end->reg.minutos;
        if(horarioChegada < proAtendimento + 30){
            proAtendimento = proAtendimento + 30;
        }else{
            if(horarioChegada % 30 == 0){
                proAtendimento = horarioChegada + 30;   
            }else{
                int cifra = horarioChegada % 30;
                int complemento = 30 - cifra;
                proAtendimento = horarioChegada + complemento;
            }
        }

        excluirElemento(f);
        end = f->inicio;
        if(end == NULL){
            break;
        }
        horarioChegada = (end->reg.horas * 60) + end->reg.minutos;
        if(horarioChegada > proAtendimento && horarioChegada < proAtendimento + 30){
            mortos++;
        }
        tempoMorte = (end->reg.horas * 60) + end->reg.minutos + end->reg.timeToDie;

        if(tempoMorte < proAtendimento){
            mortos++;
        }
    }
    return mortos;
}

int main(){

    int num, i, quantidade = 0;
    FILA f;
    iniciarFila(&f);
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        REGISTRO reg;
        scanf("%d %d %d", &reg.horas, &reg.minutos, &reg.timeToDie);
        inserirElemento(&f, reg);
    }
    quantidade = numMortos(&f);
    printf("%d\n", quantidade);

    return 0;

}
















