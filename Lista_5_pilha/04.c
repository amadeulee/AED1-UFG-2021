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

void startStack(PILHA *p){
    p->topo = NULL;
}

bool push(PILHA *p){

    char str[25];

    scanf("%s", str);
    if(strcmp(str, "ESCOLA") == 0){
        return false;
    }
    
    PONT novo;
    novo = (PONT)malloc(sizeof(ELEMENTO));

    strcpy(novo->reg.string, str);
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

void pop(PILHA *p){

    PONT apaga = p->topo;

    p->topo = p->topo->prox;
    free(apaga);

}

void restartStack(PILHA *p){

    PONT posicao = p->topo;
    PONT apaga;

    while(posicao != NULL){
        apaga = posicao;
        posicao = posicao->prox; 
        free(apaga);
    }

    p->topo = NULL;
}

int main(){

    int n, i;
    PILHA p;
    startStack(&p);

    scanf("%d", &n);
    getchar();

    for(i = 0; i < n; i++){
        //printf("oi\n");
        while(1){
            if(push(&p) == false){
                break;
            }
        }

        PONT end = p.topo;
        /*while(end != NULL){

            printf("%s\n", end->reg.string);
            end = end->prox;

        }*/
        
        while(p.topo != NULL){
            PONT posicao = p.topo;
            
            if(strcmp(posicao->reg.string, "DIREITA") == 0){
                if(p.topo->prox == NULL){
                printf("Vire a ESQUERDA na sua CASA\n");
                break;
            }
                pop(&p);
                posicao = p.topo;
                printf("Vire a ESQUERDA na rua %s\n", posicao->reg.string);
                pop(&p);
            }else if(strcmp(posicao->reg.string, "ESQUERDA") == 0){
                if(p.topo->prox == NULL){
                printf("Vire a DIREITA na sua CASA\n");
                break;
            }
                pop(&p);
                posicao = p.topo;
                printf("Vire a DIREITA na rua %s\n", posicao->reg.string);
                pop(&p);
            }

        }
        restartStack(&p);
        
    }

    





    















    return 0;
}