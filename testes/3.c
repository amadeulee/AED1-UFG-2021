#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#define MAX 1000

typedef char Texto;

typedef struct{
    Texto frase[MAX];
}text;

Texto  *criarTexto (Texto * t);
unsigned int tamanhoTexto (Texto * t);
char * obterTexto (Texto * t);
void mostrarTexto (Texto *t, unsigned int colunas);
char * obterSubtexto (Texto * t, unsigned int inicio, unsigned int tamanho);

Texto  *criarTexto (Texto * t){

    Texto texto[MAX];

    for(int i=0;i<strlen(t);i++){
        texto[i]=t[i];
    }
    //char *ptr=t;

    return (texto);

}
char * obterTexto (Texto * t){

    int i;
    Texto *copia=t;
    
    return copia;
}
void mostrarTexto (Texto *t, unsigned int colunas){

    int i,j;
    Texto copia[MAX][MAX];
    
    for(i=0,j=0;i<colunas;i++){
        copia[i][j]=t[i];
    }
    for(i=0,j=0;i<colunas;i++){
        printf("%c\n",copia[i][j]);
    }
    printf("\n");
   
    return ;
}

unsigned int tamanhoTexto (Texto * t){

    unsigned int n=strlen(t);
    return n;

}

char * obterSubtexto (Texto * t, unsigned int inicio, unsigned int tamanho){

    Texto copia[MAX],*ptr;
    ptr=&copia;
    for(int i=inicio-1,j=0;i<tamanho-inicio;i++,j++){
        copia[j]=t[i];
    }
    return(ptr);

}


int main(){

    int n,i;
    int contador=0;
    char string[MAX],string2[MAX];
    text *p;

    while(1){
        
        printf("Insira um valor\n");
        scanf("%d",&n);
        getchar();

        if(n==1){

            if(contador==0){

                printf("Insira um texto\n");
                gets(string);
                criarTexto(string);
                printf("TExto criado com sucesso!\n");
                contador++;

            }else if(contador==1){

                printf("Insira proximo texto\n");
                gets(string2);
                criarTexto(string2);
                printf("TExto criado com sucesso!\n");
                contador++;

            }else{

                printf("Maximo de texto permitido!!\n");
    
            }

        }
        if(n==3){

            int m;
            printf("Voce deseja escolher o texto 1 ou 2?\n");
            scanf("%d",&m);
            if(m==1){
                tamanhoTexto(string);
                unsigned int tam=tamanhoTexto(string);
                printf("Tamanho do seu texto eh de %u\n",tam);
            }else if(m==2){
                tamanhoTexto(string2);
                unsigned int tam=tamanhoTexto(string2);
                printf("Tamanho do seu texto eh de %u\n",tam);
            }else{
                printf("nao existe tal texto!\n");
            }
        }

        if(n==4){

            int m;
            printf("Voce deseja escolher o texto 1 ou 2?\n");
            scanf("%d",&m);
            if(m==1){
                obterTexto(string);
                puts(string);
            }
            else if(m==2){
                obterTexto(string2);
                puts(string2);
            }
            else{
               printf("nao existe tal texto!\n");
           }
        }

        if(n==5){
            int m;
            printf("Insira qual texto vc deseja mostrar!\n");
            scanf("%d",&m);

            if(m==1){
                unsigned int tam=strlen(string);
                mostrarTexto(string,tam);
            }
            else if(m==2){
                unsigned int tam=strlen(string2);
                mostrarTexto(string2,tam);
            }
            else{
               printf("nao existe tal texto!\n");
           }
        }
        if(n==9){
            int m;
            printf("Insira qual texto vc deseja mostrar!\n");
            scanf("%d",&m);

            if(m==1){
                printf("QUal o inicio e o fim q vc deseja?\n");

                unsigned int inicio,fim;

                scanf("%u %u",&inicio,&fim);
                obterSubtexto(string, inicio,fim);
                char *ptr=obterSubtexto(string,inicio,fim);
                for(int i=0;i<(fim-inicio)-1;i++){
                    printf("%c", ptr[i]);
                }printf("\n");
            }
        }
        if(n==0){
            break;
        }
    }


    return 0;
}