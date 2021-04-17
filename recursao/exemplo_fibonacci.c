#include <stdio.h>

int fibonacci(int x){

    int resultado;

    if(x==1){
        return 1;
    }if(x==2){
        return 1;
    }else{
        return ((fibonacci(x-1))+(fibonacci(x-2)));
    }


}

int main(){

    int x, resultado, i;

    printf("Sequencia Fibonacci:\n");
    scanf("%d",&x);

    resultado=fibonacci(x);

    for(i=0;i<x;i++){
        printf("%d",resultado);
    }

    return 0;
}