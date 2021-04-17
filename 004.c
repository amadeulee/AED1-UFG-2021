#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
    char string[25];
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
}PILHA;

void iniciar_pilha(PILHA *p){
    p->topo = NULL;
}

bool inserirPilha(PILHA *p){

    char string[21];

    scanf("%s", string);
    if(strcmp(string, "ESCOLA") == 0){
        return false;
    }
    
    PONT novo;

    novo = (PONT)malloc(sizeof(ELEMENTO));

    strcpy(novo->reg.string, string);
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

void removerPilha(PILHA *p){
    PONT apaga = p->topo;
    p->topo = p->topo->prox;
    free(apaga);
}

void reiniciar_pilha(PILHA *p){
    PONT end = p->topo;
    PONT apaga;

    while(end != NULL){
        apaga = end;
        end = end->prox; 
        free(apaga);
    }
    p->topo = NULL;
}

int main(){

    int t, i;
    PILHA p;
    iniciar_pilha(&p);

    scanf("%d", &t);
    getchar();

    for(i = 0; i < t; i++){
        while(1){
            if(inserirPilha(&p) == false){
                break;
            }
        }
        PONT end = p.topo;
        while(p.topo != NULL){
            PONT end = p.topo;
            
            if(strcmp(end->reg.string, "DIREITA") == 0){
                if(p.topo->prox == NULL){
                printf("Vire a ESQUERDA na sua CASA.\n");
                break;
            }
                removerPilha(&p);
                end = p.topo;
                printf("Vire a ESQUERDA na rua %s.\n", end->reg.string);
                removerPilha(&p);
            }else if(strcmp(end->reg.string, "ESQUERDA") == 0){
                if(p.topo->prox == NULL){
                printf("Vire a DIREITA na sua CASA.\n");
                break;
            }
                removerPilha(&p);
                end = p.topo;
                printf("Vire a DIREITA na rua %s.\n", end->reg.string);
                removerPilha(&p);
            }

        }
        reiniciar_pilha(&p);
    }
    return 0;
}
