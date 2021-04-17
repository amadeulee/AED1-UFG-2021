#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
#define MAX 50

/*Reutilizando do TAD definida pelo prof Luciano http://www.each.usp.br/digiampietri/ed/*/
/***Definicao do TAD Lista Sequencial***/

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;


void inicializarLista(LISTA *l);

int tamanho(LISTA *l);

void exibirLista(LISTA *l);

int buscaSequencial(LISTA *l, TIPOCHAVE ch);

bool inserirElemLista(LISTA *l, REGISTRO reg, int i);

bool excluirElemLista(LISTA *l, TIPOCHAVE ch);

void reinicializarLista(LISTA *l);


/**Funcoes para atender a lista Arya*/

int Insercao(LISTA *li, REGISTRO p, REGISTRO e);

void Contagem(LISTA *li, REGISTRO elema, REGISTRO elemb);

void MostraLista(LISTA *li);

int Remocao(LISTA *li, TIPOCHAVE ch);


int main()
{
    LISTA lista;
    inicializarLista(&lista);

    TIPOCHAVE ch, chp, che;
    REGISTRO dado, p, e;
    char operacao;
    int n, i;

    //printf("Lista de Arya\n\n");
    scanf("%d", &n);
    while ((n < 1) || (n > 1000))
    {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ch);
        dado.chave = ch;
        inserirElemLista(&lista, dado, i);
    }

    // Execucao de operacoes I, R, C, M ou F
    do
    {
        scanf("%c", &operacao);
        if (operacao == 'I')
        {
            scanf("%i%i", &p, &e);
            //p.chave = chp;
            //e.chave = che;
            Insercao(&lista, p, e);
        }

        if (operacao == 'C')
        {
            scanf("%i%i", &p, &e);
            Contagem(&lista, p, e);
        }

        if (operacao == 'M')
        {
            MostraLista(&lista);
        }

        if (operacao == 'R')
        {
            scanf("%i", &p);
            Remocao(&lista, p.chave);
        }
        if (operacao == 'F')
        {
            printf("fim");
            break;
        }

    } while (1);

    reinicializarLista(&lista);
    system("pause > nul");
    return 0;
}

/*Definicao da implementacao*/
/* Inicializa��o da lista sequencial */
void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
} /* inicializarLista */


/* Retornar o tamanho da lista (numero de elementos) */
int tamanho(LISTA *l)
{
    return l->nroElem;

} /* tamanho */


/* Exibi��o da lista seq�encial */
void exibirLista(LISTA *l)
{
    int i;
    printf("Lista: \" ");
    for (i=0; i < l->nroElem; i++)
        printf("%i ", l->A[i].chave);
    printf("\"\n");

} /* exibirLista */


/* Busca sequencial (lista ordenada ou nao) */
int buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
    int i = 0;
    while (i < l->nroElem){
        if(ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;

} /* buscaSequencial */

/* Insercao em posicao especifica*/
bool inserirElemLista(LISTA *l, REGISTRO reg, int i)
{
    int j;
    if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return true;

} /* inserirElemLista */


/* Exclus�o do elemento de chave indicada */
bool excluirElemLista(LISTA *l, TIPOCHAVE ch)
{
    int pos, j;
    pos = buscaSequencial(l,ch);
    if(pos == -1) return false;
    for(j = pos; j < l->nroElem-1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return true;

} /* excluirElemLista */

/* Destrui��o da lista sequencial
   libera a memoria de todos os elementos da lista*/
void reinicializarLista(LISTA *l)
{
   l->nroElem = 0;
} /* destruirLista */


// Implementacoes referentes a Lista de Arya

int Insercao(LISTA *li, REGISTRO p, REGISTRO e)
{
    int pos;
    bool inserido;

    if (li == NULL)
        return false;
    pos = buscaSequencial(li, e.chave);
    inserido = inserirElemLista(li, p, pos + 1);

    if (inserido == true)
    {
        printf("inserido %i", p.chave);
        return true;
    }
    else
    {
        return false;
    }
}


void Contagem(LISTA *li, REGISTRO elema, REGISTRO elemb)
{
    int a, b, distancia;
    a = buscaSequencial(li, elema.chave);
    b = buscaSequencial(li, elemb.chave);

    if (a > b)
    {
        distancia = a - b - 1;
    }
    else
    {
        if (b > a)
        {
            distancia = b - a - 1;
        }
        else
        {
            if (b == a)
            {
                distancia = -1;
            }
        }
    }
    printf("quantidade %i", distancia);
}

void MostraLista(LISTA *li)
{
    printf("lista ");
    exibirLista(li);
}

int Remocao(LISTA *li, TIPOCHAVE ch)
{
    bool excluido;

    excluido = excluirElemLista(li, ch);
    if (excluido == true)
        printf("removido %i", ch);
}