#include <stdio.h>

int fatorial(int x){

    int resultado;

    if(x==0){
        return 1;
    }else
        return x*fatorial(x-1);

}

int main(){

    int x, resultado;

    printf("Insira: \n");
    scanf("%d",&x);

    resultado=fatorial(x);

    printf("%d",resultado);

    return 0;

}