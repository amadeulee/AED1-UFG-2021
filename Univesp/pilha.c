#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define true 1
#define false -1

typedef int bool;

typedef struct{
    int chave;
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

int tamanho(PILHA * p){
    PONT end = p->topo;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

bool pilhaVazia(PILHA *p){

    PONT end = p->topo;

    if(end == NULL){
        return true;
    }
    return false;
    
}

void exibirPilha(PILHA *p){

    PONT end = p->topo;

    printf("Pilha :\" ");
    while(end != NULL){
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool push(PILHA *p, REGISTRO reg){

    PONT i;

    i=(PONT) malloc(sizeof(ELEMENTO));

    i->reg = reg;

    i->prox = p->topo;
    p->topo = i;

    return true;

}

bool pop(PILHA *p, REGISTRO *reg){

    if(p->topo == NULL){
        return false;
    }
    *reg = p->topo->reg;

    PONT i = p->topo;
    p->topo = p->topo->prox;

    free(i);
    return true;

}

void reiniciar(PILHA *p){

    PONT aux = p->topo;

    while(aux != NULL){
        PONT end = aux;
        aux = aux->prox;
        free(end);
    }

    p->topo = NULL;
}

int main(){

    int n;

    PILHA p;

    while(1){

        printf("1- iniciar pilha\n 2- tamanho da pilha\n 3- pilha vazia!\n 4- exibir pilha\n 5- inserir elemento no topo\n 6-remover elemento do topo\n 7- reiniciar pilha\n");
        scanf("%d", &n);

        if(n == 1){
            iniciar_pilha(&p);
            printf("iniciada com sucesso!\n");
        }
        if(n == 2){
            int tam = tamanho(&p);
            printf("Tamanho: %d!\n", tam);
        }
        if(n == 3){
            int res = pilhaVazia(&p);
            if(res == 1){
                printf("Pilha vazia!\n");
            }else{
                printf("pilha nao vazia!\n");
            }
        }
        if(n == 4){
            exibirPilha(&p);
        }
        if(n == 5){
            REGISTRO reg;

            printf("insira o elemento : ");
            scanf("%d", &reg.chave);
            push(&p, reg);
        }
        if(n == 6){

            REGISTRO reg;
            pop(&p, &reg);
            printf("topo removido com sucesso! elemento %d\n", reg.chave);
        }
        if(n == 7){
            reiniciar(&p);
        }
    }   






















    return 0;
}