#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

#define TRUE 1
#define FALSE -1

typedef int bool;

typedef struct{
    int chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux *prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;

void iniciar_lista(LISTA *l){
    l->inicio = NULL;
}

int tamanhoDaLista(LISTA *l){
    PONT end = l->inicio;
    int tam=0;

    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;

}

void exibir_lista(LISTA *l){
    
    printf("Lista: \" ");
    for(PONT aux = l->inicio ; aux != NULL ; aux = aux->prox){
        printf("%d ", aux->reg.chave);
    }
    printf("\"\n");
}

PONT busca_sequencial(LISTA *l, int ch){

    PONT aux = l->inicio;

    while(aux != NULL){
        if(aux->reg.chave == ch){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

PONT buscaSeqOrd(LISTA* l, int ch){
    PONT aux = l->inicio;

    while(aux != NULL && aux->reg.chave < ch){
        aux = aux->prox;
    }
    if(aux != NULL && aux->reg.chave == ch){
        return aux;
    }
    return NULL;
}

PONT buscaSequencialExc(LISTA* l, int ch, PONT* ant){
    
    *ant = NULL;
    PONT atual = l->inicio;

    while(atual != NULL && atual->reg.chave < ch){
        *ant = atual;
        atual = atual->prox;
    }

    if((atual != NULL) && (atual->reg.chave == ch)){
        return atual;
    }
    return NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){

    int ch = reg.chave;
    PONT i, ant;

    i = buscaSequencialExc(l, ch, &ant);
    if(i != NULL){
        return FALSE;
    }
    i = (PONT)malloc(sizeof(ELEMENTO));

    i->reg = reg;

    if(ant == NULL){
        i->prox = l->inicio;
        l->inicio = i;
    }else{
        i->prox = ant->prox;
        ant->prox = i;
    }
    return TRUE;
}

bool excluirElemLista(LISTA* l, int ch){
    
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);

    if(i == NULL){
        return FALSE;
    }
    if(ant == NULL){
        l->inicio = i->prox;
    }else{
        ant->prox = i->prox;
    }
    free(i);
    return TRUE;
}

void reinicializarLista(LISTA* l){

    PONT aux = l->inicio;
    while( aux != NULL){
        PONT apagar = aux;
        aux = aux->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

int main(){

    int n;

    LISTA p;

    while(1){
        printf("Insira sua opcao: \n");
        scanf("%d",&n);

        if(n==1){
            iniciar_lista(&p);
            printf("lista iniciada com sucesso!\n");
        }
        if(n==2){
            int tam = tamanhoDaLista(&p);
            printf("tamanho da lista = %d\n", tam);
        }
        if(n==3){
            exibir_lista(&p);
        }
        if(n==4){
            REGISTRO reg;
            scanf("%d",&reg);
            int i=inserirElemListaOrd(&p, reg);
            if(i == FALSE){
                printf("elemento ja existe!\n");
            }else
            printf("elemento inserido com sucesso!\n");
        }
        if(n==5){
            int ch;
            scanf("%d",&ch);
            int i = excluirElemLista(&p, ch);
            if(i == FALSE){
                printf("elemento nao existe na lista!\n");
            }else
            printf("elemento removido da lista!\n");
        }
        if(n==6){
            reinicializarLista(&p);
        }
    }





    return 0;
}