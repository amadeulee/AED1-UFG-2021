#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define MAX 30000
#define TRUE 1
#define FALSE -1

typedef int bool;
typedef int TIPOCHAVE;


typedef struct{
    TIPOCHAVE cor;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int n_elemento;
}LISTA;

typedef struct{
    int cores;
    int contador;
}reg_cor;

typedef struct{
    reg_cor B[MAX];
    int n_cores;
}lista_cor;

void inicia_lista(LISTA* l, lista_cor* lc){
    l->n_elemento=0;
    lc->n_cores=0;
}

bool busca_sequencial(LISTA* l, TIPOCHAVE ch){
    int i;
    for(i=0;i<l->n_elemento;i++){
        if(ch == l->A[i].cor){
            return i;
        }
    }
    return FALSE;
}

bool atribuir_cores(lista_cor* lc){
    int i;
    if(lc->n_cores<1){
        return FALSE;
    }
    for(i=0;i<lc->n_cores;i++){
        lc->B[i].cores=i+1;
    }
    return TRUE;
}

bool atribuir_contador(lista_cor* lc){
    int i;
    if(lc->n_cores<1){
        return FALSE;
    }
    for(i=0;i<lc->n_cores;i++){
        lc->B[i].cores=0;
    }
    return TRUE;
}

bool inserir_chaves(LISTA* l){
    int i;
    int chave;

    if(l->n_elemento<3 || l->n_elemento>MAX){
        return FALSE;
    }
    for(i=0;i<l->n_elemento;i++){
        scanf("%d",&chave);
        l->A[i].cor=chave;
    }
    return TRUE;
}

bool foto_boa(LISTA* l, lista_cor* lc, int x, int y){

    int i,j;
    int cont;
    double meio;
    meio=((y-x)+1)/2;


    for(i=0;i<lc->n_cores;i++){
        
        
        atribuir_contador(lc);
        for(j=x-1;j<=y-1;j++){
            if(lc->B[i].cores== l->A[j].cor){
                lc->B[i].contador=lc->B[i].contador+1;
                if(lc->B[i].contador > meio){
                return lc->B[i].contador;
            }
            }
        }
    }
    return FALSE;
}

int main(){

    int casos,i,j;
    double entrada;
    
    LISTA *p;
    p=(LISTA*)malloc(sizeof(LISTA));
    lista_cor *lc;
    lc=(lista_cor*)malloc(sizeof(lista_cor));

    scanf("%d",&casos);

    for(i=0;i<casos;i++){
        int n,c,conferir;
        inicia_lista(p,lc);
        scanf("%d %d",&n,&c);
        p->n_elemento=n;
        lc->n_cores=c;

        conferir=inserir_chaves(p);
        if(conferir == -1){
            printf("ocorreu algum erro\n");
        }
        conferir=atribuir_cores(lc);
        if(conferir == -1){
            printf("ocorreu algum erro\n");
        }
        for(int o=0;o<p->n_elemento;o++){
            printf("%d ",p->A[o].cor);
        }printf("\n");
        for(int o=0;o<lc->n_cores;o++){
            printf("%d ",lc->B[o].cores);
        }printf("\n");

        int m,a,b;
        printf("numero de m\n");
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d %d",&a,&b);
            entrada=0;
            conferir=foto_boa(p,lc,a,b);
        if(conferir == 1){
            printf("bonita %.0lf\n",conferir);
        }
        else if(conferir==-1){
            printf("feia\n");
        }
        }

    }


    return 0;
}