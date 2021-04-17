#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

#define FALSE -1
#define MAX 50

typedef int TIPOCHAVE;
typedef int bool;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
}ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio;
    int disponiveis;
}LISTA;

void inicia_lista(LISTA* l){
    
}