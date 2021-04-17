#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 1000

typedef struct{
    int vetor[MAX]; 
    int topo;
}Pilha;
void push(Pilha *, int);
void pop(Pilha *);

int main(){	
	
	int fora, vagoes, i, fail, coming, zero; 
	Pilha p;
	
	scanf("%d", &vagoes);
		while(1){			
			p.topo = -1;
			for(i=0, coming=1, fail=0, zero=0; i<vagoes && !fail && !zero; i++){
				scanf("%d", &fora);
				if(!fora){
					zero=1;
					break;
				}
				while(1){
					if(fora == coming){
						coming++;
						break;
					}else
						if(fora > coming){
							push(&p, coming);
							coming++;
						}else{
							if(p.vetor[p.topo] == fora)
								pop(&p);
							else{
								fail=1;
								for(;i<vagoes-1;i++)
									scanf("%d", &fora);
							}								
							break;
						}
				}				
			}
			if(!zero)
				if(!fail){
					printf("sim\n");
                    return 0;
                }
				else{
					printf("nao\n");
                    return 0;
                }
			else{
				break;
            }
		}
	
	return 0;
}

void push(Pilha *p, int id){
	p->vetor[++p->topo] = id;
}

void pop(Pilha *p){
	p->topo--;
}