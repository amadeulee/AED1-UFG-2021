#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define MAX 1000
#define TRUE 1
#define FALSE -1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int n_elemento;
}LISTA;

bool inserir_inimigo(LISTA* l, TIPOCHAVE ch1, TIPOCHAVE ch2);
bool remover_inimigo(LISTA* l, TIPOCHAVE ch);
int inimigos_frente(LISTA* l, TIPOCHAVE ch1, TIPOCHAVE ch2);
void exibir_lista(LISTA* l);

void inicializar_lista(LISTA* l, TIPOCHAVE ch){
    l->n_elemento=ch;
}

int busca_sequencial(LISTA* l, TIPOCHAVE ch){
    int i;

    for(i=0;i<l->n_elemento;i++){
        if(ch == l->A[i].chave){
            return i;
        }
    }
    return FALSE;

}

bool inserir_inimigo(LISTA* l, TIPOCHAVE ch1, TIPOCHAVE ch2){
    int i,pos;
    pos=busca_sequencial(l,ch2);
    if(pos==-1 || l->n_elemento==MAX){
        return FALSE;
    }
    for(i=l->n_elemento;i>pos+1;i--){
        l->A[i].chave=l->A[i-1].chave;
    }
    l->A[pos+1].chave=ch1;
    l->n_elemento++;
    return TRUE;
}

bool remover_inimigo(LISTA* l, TIPOCHAVE ch){
    int i,resultado;
    resultado=busca_sequencial(l,ch);
    if(resultado==-1){
        return FALSE;
    }
    for(i=resultado;i<l->n_elemento+1;i++){
        l->A[i].chave=l->A[i+1].chave;
    }
    l->n_elemento--;
    return TRUE;
}

int inimigos_frente(LISTA* l, TIPOCHAVE ch1, TIPOCHAVE ch2){

    int p_pos,s_pos,distancia;
    p_pos=busca_sequencial(l,ch1);
    if(p_pos==-1){
        return FALSE;
    }
    s_pos=busca_sequencial(l,ch2);
    if(s_pos==-1){
        return FALSE;
    }
    if(s_pos>p_pos){
        distancia=(s_pos-p_pos)-1;
    }else if(p_pos>s_pos){
        distancia=(p_pos-s_pos)-1;
    }else if(p_pos==s_pos){
        distancia =0;
    }
    return distancia;
}

void exibir_lista(LISTA* l){
    int i;

    printf("lista ");
    for(i=0;i<l->n_elemento;i++){
        printf("%d ",l->A[i].chave);
    }
    printf("\n");
}

int main(){

    int i,j,n,chave, chav1,chav2,resultado;
    char c;
    LISTA *p;
    p=(LISTA*)malloc(sizeof(LISTA));

    scanf("%d",&n);
    inicializar_lista(p,n);
    for(i=0;i<n;i++){
        scanf("%d",&chave);
        p->A[i].chave=chave;
    }
    while(1){

    scanf("%c",&c);

    if(c=='I'){
        scanf("%d %d",&chav1,&chav2);
        resultado=inserir_inimigo(p,chav1,chav2);
        if(resultado==-1){
            printf("erro!\n");
        }else{
            printf("inserido %d\n",chav1);
        }
    }
    if(c=='R'){
        int remover,res;
        scanf("%d",&remover);
        res=remover_inimigo(p,remover);
        if(res==-1){
            printf("deu erro!\n");
        }else{
            printf("removido %d\n",remover);
        }
        
    }
    if(c=='C'){
        int res;
        scanf("%d %d",&chav1,&chav2);
        res=inimigos_frente(p,chav1,chav2);
        if(res==-1){
            printf("deu erro!\n");
        }else{
            printf("quantidade %d\n",res);
        }

    }
    if(c=='M'){
        exibir_lista(p);
    }
    if(c=='F'){
        printf("fim\n");
        break;
    }

    }

    return 0;
}