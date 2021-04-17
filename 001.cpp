#include <bits/stdc++.h>
using namespace std;

#define true 1
#define false 0

typedef struct{
    char c;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
}PILHA;

void iniciarPilha(PILHA *p){        //iniciando pilha
    p->topo = NULL;
}

void push(PILHA *p, REGISTRO reg){  //inserindo na pilha

    PONT novo;
    novo=(PONT)malloc(sizeof(ELEMENTO));

    novo->reg = reg;

    novo->prox = p->topo;
    p->topo = novo;
}

void pop(PILHA *p){                 //remover da pilha

    PONT apaga = p->topo;

    p->topo = p->topo->prox;
    free(apaga);
}

void reinicializarPilha(PILHA* p) { //reiniciar pilha
    PONT apagar;
    PONT posicao = p->topo;

    while(posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }

    p->topo = NULL;
}

bool balancear(string str){           //balancear

    int i;
    char c;
    PILHA p;
    iniciarPilha(&p);

    for(i = 0; i < str.length(); i++){

        if(str[i] == '('){        //se for simbolo de abertura, inseri na pilha
            REGISTRO reg;
            reg.c = str[i];
            push(&p, reg);
        }
              //caso chegue aqui, n foi abertura, portanto simbolo de fechar vem antes, return false

        if(str[i] == ')') {
            if(p.topo == NULL) return false; 
            c = p.topo->reg.c;
            pop(&p);
        }
        
    }

    if(p.topo != NULL) return false;
    return true;

}

int main(){
 
    string frase;
    cin >> frase;

    if(balancear(frase)) {
        printf("correta\n");
    }else {
        printf("incorreta\n");   
    }
    return 0;
}