//
//==============================================================================
// Arquivo questao1.h
//==============================================================================
//
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define max 999999
#define true 1
#define false 0
#define LONG_MIN -9223372036854775808L
#define LONG_MAX  9223372036854775807L

typedef int bool;

typedef long long int ll;

typedef struct {
    ll* valores;
    int qntVal;
} conjAUX;

typedef struct {
    int qntVal;
    char chave;
    ll valores[max];
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    ELEMENTO* inicio;
} LISTA;

void inicializarLista(LISTA *l);
bool criaConjunto(LISTA* l, char chave); 
bool conjuntoVazio(LISTA* l, char chave);
bool insereElementoConjunto(LISTA* l, char chave, ll valor); 
bool excluirElementoConjunto(LISTA* l, char chave, ll valor);
int tamanhoConjunto(LISTA* l, char chave); 
int maior(LISTA* l, char chave, ll valorComp); 
int menor(LISTA* l, char chave, ll valorComp);
bool pertenceConjunto(LISTA* l, char chave, ll valor);
bool conjuntosIdenticos(LISTA *l, char chave1, char chave2); 
bool subconjunto(LISTA* l, char chaveSubConj, char chaveConj);
conjAUX* complemento(LISTA* l, char chaveC1, char chaveC2, conjAUX* cc);
conjAUX* uniao(LISTA* l, char chaveC1, char chaveC2, conjAUX* cu); 
conjAUX* interseccao(LISTA* l, char chaveC1, char chaveC2, conjAUX* ca); 
conjAUX* diferenca(LISTA* l, char chaveC1, char chaveC2, conjAUX* cd);
conjAUX* conjuntoPartes(LISTA* l, char chave, conjAUX* cp);
void mostraConjunto(LISTA* l, char chave, int ordem); 
bool copiarConjunto(LISTA* l, char chave1, char chave2); 
int destroiConjunto(LISTA *l, char chave); 

//
//==============================================================================
// Arquivo questao1.c
//==============================================================================
//

PONT buscaAux(LISTA *l, char chave, ELEMENTO** ant);
bool excluirElementoAux(ll *valores, int qntVal, ll valor) ;

int main() {
int opcao; 
LISTA lista;
inicializarLista(&lista);
while(1) {
        printf("\n");
        printf("-----Menu de opçóes-----\n\n");
        printf("Digite o numero para selecionar uma das opcoes:\n\n");
        printf("1-Criar um novo conjunto vazio\n");
        printf("2-Verificar se o conjunto eh vazio\n");
        printf("3-Incluir elemento ao conjunto\n");
        printf("4-Excluir elemento do conjunto\n");
        printf("5-Cardinalidade do conjunto\n");
        printf("6-Verificar quando elementos do conjunto maiores que um valor desejado\n");
        printf("7-Verificar quando elementos do conjunto menores que um valor desejado\n");
        printf("8-Verificar se um elemento pertence ao conjunto\n");
        printf("9-Comparar se dois conjuntos sao iguais\n");
        printf("10-identificar se conjunto C1 eh subconjunto de um conjunto C2\n");
        printf("11-Complemento do conjunto C1 em relação ao conjunto C2\n");
        printf("12-Gerar a uniao do conjunto C1 com o conjunto C2\n");
        printf("13-Gerar a interseccao do conjunto C1 com o conjunto C2\n");
        printf("14-Gerar a diferenca entre um conjunto o C1 e outro conjunto C2\n");
        printf("15-Mostrar os elementos do conjunto\n");
        printf("16-Copiar um conjunto C1 para um conjunto C2\n");
        printf("17-Destruir um conjunto C\n\n");
        printf("0 - Para finalizar o programa\n\n");

    scanf("%d", &opcao);
    getchar();
    if(opcao == 1) {
        char chave;
        printf("Qual conjunto quer criar?(a-z) ");
        scanf("%c", &chave);
        getchar();
        if(criaConjunto(&lista, chave)) {
            printf("Conjunto criado com sucesso!\n", chave);
        }else{
            printf("Deu erro\n");
        }
    }else if(opcao == 2) {
        char chave;
        printf("Qual conjunto quer verficar se é vazio? ");
        scanf("%c", &chave);
        getchar();
        int res = conjuntoVazio(&lista, chave);
        if(res == -1) {
            printf("Deu erro\n", chave);
        }else if(res == true) {
            printf("O conjunto é vazio!\n", chave);
        }else{
            printf("O conjunto não é vazio!\n", chave);
        }
    }else if(opcao == 3) {
        char chave;
        ll valor;
        printf("Qual o conjunto a ser modificado? ");
        scanf("%c", &chave);
        printf("Elemento a ser adicionado: ");
        scanf("%lld", &valor);
        int res = insereElementoConjunto(&lista, chave, valor);
        if(res == -1) {
            printf("Deu erro\n", chave);
        }else if(res == -2) {
            printf("O elemento já está presente no conjunto\n", valor, chave);
        }else{
            printf("O elemento foi adicionado\n", valor, chave);
        }
    }else if(opcao == 4) {
        char chave;
        ll valor;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        getchar();
        printf("Digite o valor a ser excluido: ");
        scanf("%lld", &valor);
        int res = excluirElementoConjunto(&lista, chave, valor);
        if(res == -1) {
            printf("ERRO!!! -- Conjunto inexistente!\n");
        }else if(res == true) {
            printf("Valor \"%lld\" excluido do conjunto \"%c\" com sucesso!\n", valor, chave);
        }else {
            printf("ERRO!!! -- Valor \"%lld\" nao foi encontrado no conjunto \"%c\"!\n", valor, chave);
        }
    }else if(opcao == 5) {
        char chave;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        int res = tamanhoConjunto(&lista, chave); 
        if(res == -1) {
            printf("ERRO!!! -- Conjunto de chave \"%c\" inexistente!\n", chave);
        }else {
            printf("Conjunto de chave \"%c\" possui \"%d\" elementos!\n", chave, res);
        }
    }else if(opcao == 6) {
        char chave;
        ll valorBase;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        printf("Digite o valor para ser usado na base da comparacao: ");
        scanf("%lld", &valorBase);
        int res = maior(&lista, chave, valorBase);
        if(res == -1) {
            printf("ERRO!!! -- Conjunto \"%c\" inexistente!\n", chave);
        }else if(res == 0) {
            printf("No conjunto \"%c\", todos os valores sao maiores que \"%lld\"!\n", chave, valorBase);
        }else if(res == -2) {
            printf("No conjunto \"%c\", nenhum valor e maior que \"%lld\"!\n", chave, valorBase);
        }else {
            printf("No conjunto \"%c\", \"%d\" valor(es) eh/sao maior(es) que \"%lld\"!\n", chave, res, valorBase);
        }
    }else if(opcao == 7) {
        char chave;
        ll valorBase;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        printf("Digite o valor para ser usado na base da comparacao: ");
        scanf("%lld", &valorBase);
        int res = maior(&lista, chave, valorBase);
        if(res == -1) {
            printf("ERRO!!! -- Conjunto \"%c\" inexistente!\n", chave);
        }else if(res == 0) {
            printf("No conjunto \"%c\", todos os valores sao menores que \"%lld\"!\n", chave, valorBase);
        }else if(res == -2) {
            printf("No conjunto \"%c\", nenhum valor e menor que \"%lld\"!\n", chave, valorBase);
        }else {
            printf("No conjunto \"%c\", \"%d\" valor(es) eh/sao menor(es) que \"%lld\"!\n", chave, res, valorBase);
        }
    }else if(opcao == 8) {
        char chave;
        ll valor;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        printf("Valor a ser procurado no conjunto: ");
        scanf("%lld", &valor);
        int res = pertenceConjunto(&lista, chave, valor);
        if(res == -1) {
            printf("ERRO!!! -- Conjunto inexistente!\n");
        }else if(!res) {
            printf("Elemento \"%lld\" nao percente ao conjunto \"%c\"!\n", valor, chave);
        }else {
            printf("Elemento \"%lld\" percente ao conjunto \"%c\"!\n", valor, chave);
        }
    }else if(opcao == 9) {
        char chave1, chave2;
        printf("Digite a chave do primeiro conjunto: ");
        scanf("%c", &chave1);
        getchar();
        printf("Digite a chave do segundo conjunto: ");
        scanf("%c", &chave2);
        getchar();
        int res = conjuntosIdenticos(&lista, chave1, chave2);
        if(res == -1) {
            printf("ERRO!!! -- Chaves dos conjuntos inseridas incorretamente\n");
        }else if(res == -2) {
            printf("Conjuntos diferentes! --> Os tamanhos diferem.\n");
        }else if(res == false) {
            printf("Conjuntos diferentes! -> Possuem elementos que diferem.\n");
        }else {
            printf("Conjuntos identicos!\n");
        }
    }else if(opcao == 10) {
        char chaveSubConj, chaveConj;
        printf("Digite a chave do conjunto que sera analisado se eh subconjunto: ");
        scanf("%c", &chaveSubConj);
        getchar();
        printf("Digite a chave do conjunto maior: ");
        scanf("%c", &chaveConj);
        getchar();
        int res = subconjunto(&lista, chaveSubConj, chaveConj);
        if(res == -1) {
            printf("ERRO!!! -- Chaves incorretas ou conjuntos nao existentes!\n");
        }else if(res == true) {
            printf("Conjunto \"%c\" eh subconjunto de \"%c\"!\n", chaveSubConj, chaveConj);
        }else {
            printf("Conjunto \"%c\" NAO eh subconjunto de \"%c\"!\n", chaveSubConj, chaveConj);
        }
    }else if(opcao == 11) {
        char chaveC1, chaveC2;
        printf("Digite a chave do conjunto C1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite a chave do conjunto C2: ");
        scanf("%c", &chaveC2);
        conjAUX cc, *ptrCc = &cc;
        complemento(&lista, chaveC1, chaveC2, ptrCc);
        printf("O conjunto complemento de \"%c\" em relacao a \"%c\" tem %d valor(es): \"", chaveC1, chaveC2, ptrCc->qntVal);
        int i;
        for(i=0; i<ptrCc->qntVal; i++) {
            printf("%lld", ptrCc->valores[i]);
            if(i != ptrCc->qntVal-1) printf(", ");
        }
        free(ptrCc->valores);
        printf("\"\n");
    }else if(opcao == 12) {
        char chaveC1, chaveC2;
        printf("Digite a chave do conjunto C1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite a chave do conjunto C2: ");
        scanf("%c", &chaveC2);
        conjAUX cUniao, *ptrCUniao = &cUniao;
        uniao(&lista, chaveC1, chaveC2, ptrCUniao);
        printf("O conjunto uniao de \"%c\" e \"%c\" tem %d valor(es): \"", chaveC1, chaveC2, ptrCUniao->qntVal);
        int i;
        for(i=0; i<ptrCUniao->qntVal; i++) {
            printf("%lld", ptrCUniao->valores[i]);
            if(i != ptrCUniao->qntVal-1) printf(", ");
        }
        free(ptrCUniao->valores);
        printf("\"\n");
    }else if(opcao == 13) {
        char chaveC1, chaveC2;
        printf("Digite a chave do conjunto C1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite a chave do conjunto C2: ");
        scanf("%c", &chaveC2);
        conjAUX cInter, *ptrCInter = &cInter;
        interseccao(&lista, chaveC1, chaveC2, ptrCInter);
        printf("O conjunto interseccao de \"%c\" e \"%c\" tem %d valor(es): \"", chaveC1, chaveC2, ptrCInter->qntVal);
        int i;
        for(i=0; i<ptrCInter->qntVal; i++) {
            printf("%lld", ptrCInter->valores[i]);
            if(i != ptrCInter->qntVal-1) printf(", ");
        }
        free(ptrCInter->valores);
        printf("\"\n");
    }else if(opcao == 14) {
        char chaveC1, chaveC2;
        printf("Digite a chave do conjunto C1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite a chave do conjunto C2: ");
        scanf("%c", &chaveC2);
        conjAUX cDif, *ptrCDif = &cDif;
        diferenca(&lista, chaveC1, chaveC2, ptrCDif);
        printf("O conjunto diferenca de \"%c\" e \"%c\" tem %d valor(es): \"", chaveC1, chaveC2, ptrCDif->qntVal);
        int i;
        for(i=0; i<ptrCDif->qntVal; i++) {
            printf("%lld", ptrCDif->valores[i]);
            if(i != ptrCDif->qntVal-1) printf(", ");
        }
        free(ptrCDif->valores);
        printf("\"\n");
    }else if(opcao == 15) {
        char chave;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        conjAUX cp, *ptrCP = &cp;
        conjuntoPartes(&lista, chave, ptrCP);
        printf("O conjunto das partes do conjunto \"%c\" possui \"%d\" elementos!\n", chave, ptrCP->qntVal);
    }else if(opcao == 16) {
        int ordem;
        char chave;
        printf("Digite a chave do conjunto: ");
        scanf("%c", &chave);
        printf("Digite a ordem (1 para crescente ou 0 para decrescente): ");
        scanf("%d", &ordem);
        mostraConjunto(&lista, chave, ordem);
    }else if(opcao == 17) {
        char chave1, chave2;
        printf("Digite a chave do conjunto C1: ");
        scanf("%c", &chave1);
        getchar();
        printf("Digite a chave do conjunto C2: ");
        scanf("%c", &chave2);
        if(copiarConjunto(&lista, chave1, chave2)) {
            printf("Conjunto \"%c\" copiado para conjunto \"%c\"!\n", chave1, chave2);
        }else {
            printf("ERRO!!! -- Chaves incorretas!\n");
        }
    }else if(opcao == 18) {
        char chave;
        printf("Digite a chave do conjunto que voce quer destruir: ");
        scanf("%c", &chave);
        if(destroiConjunto(&lista, chave)) {
            printf("Conjunto \"%c\" destruido com sucesso!\n", chave);
        }else {
            printf("ERRO!!! -- Conjunto inexistente!\n");
        }
    }else if(opcao == 0) {
        printf("Fim da execucao do programa!\n");
        break;
    }
}
return 0;
}

PONT buscaAux(LISTA *l, char chave, ELEMENTO** ant) { 
    *ant = NULL;
    ELEMENTO* atual = l->inicio;
    while(atual != NULL && atual->reg.chave != chave) {
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL) && (atual->reg.chave == chave)) {
        return atual;
    }
    return NULL;
}

bool excluirElementoAux(ll *valores, int qntVal, ll valor) {
    int i, j, aux = 0;
    for(i=0, j=0; i<qntVal; i++) {
        if(valores[i] != valor) {
            valores[j++] = valores[i];
        } else aux = 1;
    }
    if(aux) return true;
    return false;
}

void inicializarLista(LISTA *l) {
    l->inicio = NULL;
}

bool criaConjunto(LISTA* l, char chave) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg.chave = chave;
    i->reg.qntVal = 0;
    if(ant == NULL) {
        i->prox = l->inicio;
        l->inicio = i;
    }else {
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

bool conjuntoVazio(LISTA* l, char chave) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    else if(i->reg.qntVal == 0) return true;
    return false;
}

bool insereElementoConjunto(LISTA* l, char chave, ll valor) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1; 
    int it;
    for(it=0; it<i->reg.qntVal; it++) {
        if(i->reg.valores[it] == valor) return -2;
    }
    i->reg.valores[i->reg.qntVal] = valor;
    i->reg.qntVal++;
    return true;
}

bool excluirElementoConjunto(LISTA* l, char chave, ll valor) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    if(excluirElementoAux(i->reg.valores, i->reg.qntVal, valor)) {
        i->reg.qntVal--;
        return true;
    }
    return false;
}

int tamanhoConjunto(LISTA* l, char chave) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    int tam = i->reg.qntVal;
    return tam;
}

int maior(LISTA* l, char chave, ll valorComp) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    int it, cnt;
    for(it=0, cnt=0; it<i->reg.qntVal; it++) {
        if(i->reg.valores[it] > valorComp) cnt++;
    }
    if(cnt == i->reg.qntVal) return 0;
    else if(cnt == 0) return -2;
    return cnt;
}

int menor(LISTA* l, char chave, ll valorComp) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    int it, cnt;
    for(it=0, cnt=0; it<i->reg.qntVal; it++) {
        if(i->reg.valores[it] < valorComp) cnt++;
    }
    if(cnt == i->reg.qntVal) return 0;
    else if(cnt == 0) return -2;
    return cnt;
}

bool pertenceConjunto(LISTA* l, char chave, ll valor) {
    // Retornos possiveis: -1 (Conjunto inexistente),  0 (Elemento nao pertence),  1 (Elemento pertence ao conjunto)
    PONT ant, i = buscaAux(l, chave, &ant);
    int it;
    if(i == NULL) return -1;
    for(it=0; it<i->reg.qntVal; it++) {
        if(i->reg.valores[it] == valor) return 1;
    }
    return 0;
}

bool conjuntosIdenticos(LISTA *l, char chave1, char chave2) {
    PONT ant, c1 = buscaAux(l, chave1, &ant), c2 = buscaAux(l, chave2, &ant);
    if(c1 == NULL || c2 == NULL) return -1;
    else if (c1->reg.qntVal != c2->reg.qntVal) return -2;
    int i, j, tam = c1->reg.qntVal;
    for(i=0; i<tam; i++) {
        int aux = 0;
        for(j=0; j<tam; j++) {
            if(c1->reg.valores[i] == c2->reg.valores[j]) aux = 1;
        }
        if(aux == 0) return false;
    }
    return true;
}

bool subconjunto(LISTA* l, char chaveSubConj, char chaveConj) {
    PONT ant, verfSubConj = buscaAux(l, chaveSubConj, &ant), conj = buscaAux(l, chaveConj, &ant);
    if(verfSubConj == NULL || conj == NULL) return -1;
    else if(verfSubConj == conj) return true;
    int i, j, aux;
    for(i=0; i<verfSubConj->reg.qntVal; i++) {
        aux = 0;
        for(j=0; j<conj->reg.qntVal; j++) {
            if(verfSubConj->reg.valores[i] == conj->reg.valores[j]) aux = 1;
        }
        if(aux == 0) return false;
    }
    return true;
}

conjAUX* complemento(LISTA* l, char chaveC1, char chaveC2, conjAUX* cc) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    cc->qntVal = 0;
    cc->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c2->reg.qntVal; i++) {
            aux = 0;
            for(j=0; j<c1->reg.qntVal; j++) {
                if(c1->reg.valores[j] == c2->reg.valores[i]) aux = 1;
            }
            if(aux == 0) {
                if(cc->qntVal == 0) {
                    cc->valores[cc->qntVal++] = c2->reg.valores[i];
                }else {
                    cc->valores = realloc (cc->valores, sizeof(ll)*(cc->qntVal+1));
                    cc->valores[cc->qntVal++] = c2->reg.valores[i];
                }
            }
        }
    }
    return cc;
}

conjAUX* uniao(LISTA* l, char chaveC1, char chaveC2, conjAUX* cu) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    cu->qntVal = 0;
    cu->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c1->reg.qntVal; i++) {
            cu->valores = realloc(cu->valores, sizeof(ll)*(cu->qntVal+1));
            cu->valores[cu->qntVal++] = c1->reg.valores[i];
        }
        for(i=0; i<c2->reg.qntVal; i++) {
            aux = 0;
            for(j=0; j<cu->qntVal; j++) {
                if(c2->reg.valores[i] == cu->valores[j]) aux = 1;
            }
            if(aux == 0) {
                if(cu->qntVal == 0) {
                    cu->valores[cu->qntVal++] = c2->reg.valores[i];
                }else {
                    cu->valores = realloc(cu->valores, sizeof(ll)*(cu->qntVal+1));
                    cu->valores[cu->qntVal++] = c2->reg.valores[i];
                }
            }
        }
    }
    return cu;
}

conjAUX* interseccao(LISTA* l, char chaveC1, char chaveC2, conjAUX* ca) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    ca->qntVal = 0;
    ca->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c1->reg.qntVal; i++) {
            aux = 0;
            for(j=0; j<c2->reg.qntVal; j++) {
                if(c1->reg.valores[i] == c2->reg.valores[j]) aux = 1;
            }
            if(aux) {
                ca->valores = realloc (ca->valores, sizeof(ll) * (ca->qntVal + 1));
                ca->valores[ca->qntVal++] = c1->reg.valores[i];
            }
        }
    }
    return ca;
}

conjAUX* diferenca(LISTA* l, char chaveC1, char chaveC2, conjAUX* cd) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    cd->qntVal = 0;
    cd->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c1->reg.qntVal; i++) {
            aux = 0;
            for(j=0; j<c2->reg.qntVal; j++) {
                if(c1->reg.valores[i] == c2->reg.valores[j]) aux = 1;
            }
            if(!aux) {
                cd->valores = realloc(cd->valores, sizeof(ll)*(cd->qntVal+1));
                cd->valores[cd->qntVal++] = c1->reg.valores[i];
            }
        }
    }
    return cd;
}

conjAUX* conjuntoPartes(LISTA* l, char chave, conjAUX* cp) {
    PONT ant, c = buscaAux(l, chave, &ant);
    cp->qntVal = 0;
    if(cp == NULL) {
        printf("ERRO!!! -- Chave de conjunto invalida!\n");
    }else {
        cp->qntVal = pow(2, c->reg.qntVal);
    }
    return cp;
}

void bubbleSortOrd(ll arr[], int size, int ordem) { // funcao aux para mostraConjunto()
    int step;
    for (step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if(ordem == 1) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            else {
                if (arr[i] < arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }
    }
}

void mostraConjunto(LISTA* l, char chave, int ordem) {
    PONT ant, end = buscaAux(l, chave, &ant);
    if(end == NULL) {
        printf("ERRO!!! -- Chave de conjunto \"%c\" incorreta!\n", chave);
        return;
    }else {
        bubbleSortOrd(end->reg.valores, end->reg.qntVal, ordem);
        printf("Valores do Conjunto %c: \"", chave);
        int i;
        for(i=0; i<end->reg.qntVal; i++) {
            printf("%lld", end->reg.valores[i]);
            if(i != end->reg.qntVal-1) printf(", ");
        }
        printf("\"\n");
    }    
}

bool copiarConjunto(LISTA* l, char chave1, char chave2) {
    PONT ant, c1 = buscaAux(l, chave1, &ant), c2 = buscaAux(l, chave2, &ant);
    if(c1 == NULL || c2 == NULL) return false;
    int i, j;
    for(i=0; i<c1->reg.qntVal; i++) {
        c2->reg.valores[i] = c1->reg.valores[i];
    } 
    c2->reg.qntVal = c1->reg.qntVal;
    return true;
}

bool destroiConjunto(LISTA* l, char chave) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return 0;
    if(ant == NULL) {
        l->inicio = i->prox;
    }else {
        ant->prox = i->prox;
    }
    free(i);
    return 1;
}