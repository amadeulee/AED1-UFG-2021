#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef int vcdecide;

typedef struct{
    vcdecide horas;
    vcdecide minutos;
    vcdecide segundos;
}horario;

typedef horario tempo;

int main(){

    horario *p;
    tempo y;
    int i;

    int n;

    scanf("%d",&n);

    p=(horario*)malloc(sizeof(horario)*n);

    for(i=0;i<n;i++){
        scanf("%d %d %d",&p[i].horas,&p[i].minutos,&p[i].segundos);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d",p->horas,&p[i].minutos,&p[i].segundos);
    }

    


    return 0;
}