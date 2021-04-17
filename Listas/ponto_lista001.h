#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define TAM 100

typedef int elemento;

struct conjunto{
    elemento* v;
};

conjunto* c_conjunto_vazio(int *erro){

    int i;
    conjunto* conj=(conjunto*)malloc(sizeof(conjunto));

    if(conj==NULL){
        *erro=1;
        exit(1);
    }
    conj->v=(int*)malloc(TAM*sizeof(int));

    for(i=0;i<TAM;i++){
        conj->v[i]=0;
    }
    erro=0;
    return conj;
}





