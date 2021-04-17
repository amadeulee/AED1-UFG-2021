///
///  ponto.h
///
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>


typedef int bool;

typedef struct{
    char nome[20];
    char sentido[15];
}REGISTRO;

typedef struct{
    REGISTRO A[10];
    int nElemento;
}LISTA;

void iniciar_lista(LISTA* l);
void horario(LISTA* l);
void anti_horario(LISTA* l);
int remover_nome(LISTA* l);


///
///   .c
///


void iniciar_lista(LISTA* l){
    l->nElemento=0;
}

void horario(LISTA* l){

    int i;

    for(i=0;i<2;i++){
        strcpy(l->A[i].sentido,"horario");
    }
}

void anti_horario(LISTA* l){

    int i;

    for(i=l->nElemento-2;i<l->nElemento;i++){
        strcpy(l->A[i].sentido,"anti-horario");
    }
}


int remover_nome(LISTA* l){

    int i,j;
    int cont_pontos=0;
    char nome[20], sentido[15];

    horario(l);
    anti_horario(l);

    scanf("%s %s",&nome,&sentido);

    for(i=0;i<2;i++){

        if(strcmp(l->A[i].nome,nome)==0){
            if(strcmp(l->A[i].sentido,sentido)==0){

                cont_pontos++;
                for(j=i;j<l->nElemento+1;j++){
                    strcpy(l->A[j].nome,l->A[j+1].nome);
                }
                l->nElemento--;

            }
        }
    }

    for(i=l->nElemento-2;i<l->nElemento;i++){

        if(strcmp(l->A[i].nome,nome)==0){
            if(strcmp(l->A[i].sentido,sentido)==0){

                cont_pontos++;
                for(j=i;j<l->nElemento+1;j++){
                    strcpy(l->A[j].nome,l->A[j+1].nome);
                }
                l->nElemento--;

            }
        }
    }
    return cont_pontos;

}

///
/// main
///


int main(){

    int i,j,n;
    char nome[20], fim[5];
    strcpy(fim,"FIM");
    LISTA *p;
    p=(LISTA*)malloc(sizeof(LISTA));
    iniciar_lista(p);

    while(1){

        scanf("%s",&nome);

        if(strcmp(fim,nome)==0){
            break;
        }

        strcpy(p->A[p->nElemento].nome,nome);
        p->nElemento++;

    }

    while(1){
        int res,resultado=0;
        int cont=p->nElemento;
        for(j=0;j<cont;j++){
            res=remover_nome(p);
            resultado=resultado+res;
        }
        printf("%d\n",resultado);
        break;

    }

    return 0;
}