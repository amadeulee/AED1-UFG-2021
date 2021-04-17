///
///  ponto.h
///
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>

#define MAX 1000
typedef int bool;

typedef struct{
    char nome[25];
    char sentido[15];
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nElemento;
}LISTA;

void iniciarLista(LISTA* l);
void s_Horario(LISTA* l);
void s_Anti_horario(LISTA* l);

///
///   .c
///


void iniciarLista(LISTA* l){
    l->nElemento=0;
}

void s_Horario(LISTA* l){

    int i;

    for(i=0;i<2;i++){
        strcpy(l->A[i].sentido,"horario");
    }
}

void s_Anti_horario(LISTA* l){

    int i;

    for(i=l->nElemento-2;i<l->nElemento;i++){
        strcpy(l->A[i].sentido,"anti-horario");
    }
}


///
/// main
///


int main(){

    int i,j,k;
    char nome[25], sentido[15];
    
    LISTA *p;
    p=(LISTA*)malloc(sizeof(LISTA));
    iniciarLista(p);

    while(1){

        scanf("%s",&nome);

        if(strcmp("FIM",nome)==0){
            break;
        }

        strcpy(p->A[p->nElemento].nome,nome);
        p->nElemento++;

    }
    
    int cont=0;
    int n=p->nElemento;

        for(j=0;j<n;j++){

            s_Horario(p);
            s_Anti_horario(p);
            scanf("%s %s",&nome,&sentido);

            for(i=0;i<2;i++){

                if(strcmp(p->A[i].nome,nome)==0){
                    if(strcmp(p->A[i].sentido,sentido)==0){

                        cont++;
                        for(k=i;k<p->nElemento+1;k++){
                            strcpy(p->A[k].nome,p->A[k+1].nome);
                        }
                        p->nElemento--;

                    }
                }
            }

            for(i=p->nElemento-2;i<p->nElemento;i++){

                if(strcmp(p->A[i].nome,nome)==0){
                    if(strcmp(p->A[i].sentido,sentido)==0){

                        cont++;
                        for(k=i;k<p->nElemento+1;k++){
                            strcpy(p->A[k].nome,p->A[k+1].nome);
                        }
                        p->nElemento--;

                    }
                }
            }
            
        }
        printf("%d\n",cont);
        

    return 0;
}