#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define MAX 50
#define TRUE 1
#define FALSE -1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave ;
}REGISTRO;

typedef struct{
    REGISTRO A[50];
    int n_elementos;
}LISTA;

void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void exibirLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
bool inserirElemLista(LISTA* l, REGISTRO reg, int i);
bool excluirElemLista(TIPOCHAVE ch, LISTA* l);
void reinicializarLista(LISTA* l);

void inicializarLista(LISTA* l){
    l->n_elementos=0;
}

int tamanho(LISTA* l){
    return l->n_elementos;
}

void exibirLista(LISTA* l){

    int j;

    printf("Lista: \"");
    for(j =0 ; j < l->n_elementos ; j++){
        printf("%d ",l->A[j].chave);
    }printf("\"\n");
    
    return;
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch){

    int i;

    for(i=0;i<l->n_elementos;i++){
        if(ch == l->A[i].chave){
            return i;
        }
    }
    return FALSE;

}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i){

    int j;
    if(i<0 || i>l->n_elementos || l->n_elementos>MAX){
            return FALSE;
    }

    for(j=l->n_elementos; j>i ; j--){ 
        
            l->A[j].chave=l->A[j-1].chave;
        
    };
    l->A[i].chave = reg.chave;
    l->n_elementos++;
    return TRUE;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA* l){

    int pos;
    pos=buscaSequencial(l,ch);
    if(pos==-1){
        return FALSE;
    }

    for(pos;pos<l->n_elementos-1;pos++){
        l->A[pos].chave=l->A[pos+1].chave;
    }
    l->n_elementos--;
    return TRUE;
}

void reinicializarLista(LISTA* l){
    l->n_elementos=0;
}

int main(){

    int n;
    LISTA *p;
    p=(LISTA*)malloc(sizeof(LISTA));
    REGISTRO elemento;
    TIPOCHAVE chave;

    while(1){
        printf("Insira qual operacao deseja: \n");
        printf("1-iniciar lista \n2-Mostra tamanho \n3-Buscar posicao do elemento \n4-inserir elemento \n5-excluir elemento \n6-reiniciar lista \n7-exibir lista\n\n");
        scanf("%d",&n);
        getchar();

        if(n==1){
            inicializarLista(p);
        }
        if(n==2){
            int n=tamanho(p);
            printf("tamanho %d\n",n);

        }
        if(n==3){
            int pos;
            printf("Insira o elemento: ");
            scanf("&d",&chave);
            getchar();
            pos= buscaSequencial(p, chave);
            if(pos=-1){
                printf("Nao existe tal elemento\n");
            }else{
                printf("Elemento esta na posicao %d",pos);
            }

        }
        if(n==4){
            int pos;
            printf("Insira qual elemento vc quer inserir, e dps a posicao q deseja inserir\n");
            scanf("%d %d",&elemento.chave,&pos);
            
            int saida;
            saida=inserirElemLista(p,elemento,pos);
            if(saida==-1){
                printf("algo errado!\n");
            }else{
                printf("Numero inserido com sucesso!\n");
            }
        }
        if(n==5){

            TIPOCHAVE chave;
            printf("insira valor para remover\n");
            scanf("%d",&chave);
            int saida =excluirElemLista(chave,p);
            if(saida==-1){
                printf("deu algum erro\n");
            }else{
                printf("elemento removido\n");
            }
        }
        if(n==6){
            reinicializarLista(p);
        }
        if(n==7){
            exibirLista(p);
        }
    }

    return 0;
}