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
    int qnt_val;
} conj_aux;

typedef struct {
    int qnt_val;
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
conj_aux* complemento(LISTA* l, char chaveC1, char chaveC2, conj_aux* cc);
conj_aux* uniao(LISTA* l, char chaveC1, char chaveC2, conj_aux* cu); 
conj_aux* interseccao(LISTA* l, char chaveC1, char chaveC2, conj_aux* ca); 
conj_aux* diferenca(LISTA* l, char chaveC1, char chaveC2, conj_aux* cd);
void mostraConjunto(LISTA* l, char chave, int ordem); 
bool copiarConjunto(LISTA* l, char chave1, char chave2); 
int destroiConjunto(LISTA *l, char chave); 

//
//==============================================================================
// Arquivo questao1.c
//==============================================================================
//

PONT buscaAux(LISTA *l, char chave, ELEMENTO** ant);
bool excluirElementoAux(ll *valores, int qnt_val, ll valor) ;

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
        printf("Qual conjunto quer criar?(a-z) \n");
        scanf("%c", &chave);
        getchar();
        if(criaConjunto(&lista, chave)) {
            printf("Conjunto criado com sucesso!\n", chave);
        }else{
            printf("ERRO! Esse conjunto ja existe!\n");
        }
    }else if(opcao == 2) {
        char chave;
        printf("Qual conjunto quer verficar se é vazio?\n ");
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
        printf("Qual o conjunto a ser modificado?\n ");
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
        printf("Qual conjunto voce deseja excluir elemento?\n");
        scanf("%c", &chave);
        getchar();
        printf("Digite o elemento que voce deseja excluir : ");
        scanf("%lld", &valor);
        int res = excluirElementoConjunto(&lista, chave, valor);
        if(res == -1) {
            printf("Deu erro\n");
        }else if(res == true) {
            printf("Elemento excluido com sucesso!\n");
        }else {
            printf("ERRO! Valor nao encontrado!\n");
        }
    }else if(opcao == 5) {
        char chave;
        printf("Qual conjunto voce deseja? \n ");
        scanf("%c", &chave);
        int res = tamanhoConjunto(&lista, chave); 
        if(res == -1) {
            printf("ERRO! Conjunto nao existe\n");
        }else {
            printf("Conjunto selecionado possui %d elementos!\n", res);
        }
    }else if(opcao == 6) {
        char chave;
        ll valorBase;
        printf("Qual conjunto deseja verificar?\n");
        scanf("%c", &chave);
        printf("Digite o valor para ser comparado: ");
        scanf("%lld", &valorBase);
        int res = maior(&lista, chave, valorBase);
        if(res == -1) {
            printf("ERRO! Conjunto nao existe\n");
        }else if(res == 0) {
            printf("Todos os valores do conjunto sao maiores que %lld!\n",valorBase);
        }else if(res == -2) {
            printf("Nenhum valor maior que %lld!\n",valorBase);
        }else {
            printf("%d valores maiores que %lld!\n", res, valorBase);
        }
    }else if(opcao == 7) {
        char chave;
        ll valorBase;
        printf("Qual conjunto deseja verificar?\n");
        scanf("%c", &chave);
        printf("Digite o valor para ser usado na base da comparacao: ");
        scanf("%lld", &valorBase);
        int res = maior(&lista, chave, valorBase);
        if(res == -1) {
            printf("ERRO! Conjunto nao existe\n");
        }else if(res == 0) {
            printf("Todos os valores do conjunto sao menores que %lld!\n",valorBase);
        }else if(res == -2) {
            printf("Nenhum valor menor que %lld!\n",valorBase);
        }else {
            printf("%d valores menores que %lld!\n", res, valorBase);
        }
    }else if(opcao == 8) {
        char chave;
        ll valor;
        printf("Qual conjunto deseja verificar?\n");
        scanf("%c", &chave);
        printf("Digite o elemento deseja procurar: ");
        scanf("%lld", &valor);
        int res = pertenceConjunto(&lista, chave, valor);
        if(res == -1) {
            printf("ERRO! Conjunto nao existe\n");
        }else if(!res) {
            printf("Esse elemento nao pertence ao conjunto escolhido!\n");
        }else {
            printf("Esse elemento pertence ao conjunto escolhido!\n");
        }
    }else if(opcao == 9) {
        char chave1, chave2;
        printf("Digite o nome do conjunto 1: ");
        scanf("%c", &chave1);
        getchar();
        printf("Agora digite o nome do conjunto 2: ");
        scanf("%c", &chave2);
        getchar();
        printf("\n");
        int res = conjuntosIdenticos(&lista, chave1, chave2);
        if(res == -1) {
            printf("ERRO!!\n");
        }else if(res == -2) {
            printf("Os dois conjuntos possuem tamanho diferente \n");
        }else if(res == false) {
            printf("Os dois conjuntos possuem elementos diferentes\n");
        }else {
            printf("Os dois conjuntos sao identicos!\n");
        }
    }else if(opcao == 10) {
        char chaveSubConj, chaveConj;
        printf("Digite o nome do conjunto que deseja verificar se é subconjunto: ");
        scanf("%c", &chaveSubConj);
        getchar();
        printf("Digite o nome do maior conjunto: ");
        scanf("%c", &chaveConj);
        getchar();
        int res = subconjunto(&lista, chaveSubConj, chaveConj);
        if(res == -1) {
            printf("ERRO!!\n");
        }else if(res == true) {
            printf("Conjunto %c eh subconjunto de %c!\n", chaveSubConj, chaveConj);
        }else {
            printf("Conjunto %c NAO eh subconjunto de %c!\n", chaveSubConj, chaveConj);
        }
    }else if(opcao == 11) {
        char chaveC1, chaveC2;
        printf("Digite o nome do conjunto 1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite o nome do conjunto 2: ");
        scanf("%c", &chaveC2);
        conj_aux cc, *ptrCc = &cc;
        complemento(&lista, chaveC1, chaveC2, ptrCc);
        printf("Conjunto complemento possui %d elementos: \"", ptrCc->qnt_val);
        int i;
        for(i=0; i<ptrCc->qnt_val; i++) {
            printf("%lld", ptrCc->valores[i]);
            if(i != ptrCc->qnt_val-1) printf(", ");
        }
        free(ptrCc->valores);
        printf("\"\n");
    }else if(opcao == 12) {
        char chaveC1, chaveC2;
        printf("Digite o nome do conjunto 1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite o nome do conjunto 2: ");
        scanf("%c", &chaveC2);
        conj_aux cUniao, *ptrCUniao = &cUniao;
        uniao(&lista, chaveC1, chaveC2, ptrCUniao);
        printf("Conjunto uniao possui %d elementos: \"", ptrCUniao->qnt_val);
        int i;
        for(i=0; i<ptrCUniao->qnt_val; i++) {
            printf("%lld", ptrCUniao->valores[i]);
            if(i != ptrCUniao->qnt_val-1) printf(", ");
        }
        free(ptrCUniao->valores);
        printf("\"\n");
    }else if(opcao == 13) {
        char chaveC1, chaveC2;
        printf("Digite o nome do conjunto 1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite o nome do conjunto 2: ");
        scanf("%c", &chaveC2);
        conj_aux cInter, *ptrCInter = &cInter;
        interseccao(&lista, chaveC1, chaveC2, ptrCInter);
        printf("Conjunto interseccao possui %d elementos: \"", ptrCInter->qnt_val);
        int i;
        for(i=0; i<ptrCInter->qnt_val; i++) {
            printf("%lld", ptrCInter->valores[i]);
            if(i != ptrCInter->qnt_val-1) printf(", ");
        }
        free(ptrCInter->valores);
        printf("\"\n");
    }else if(opcao == 14) {
        char chaveC1, chaveC2;
        printf("Digite o nome do conjunto 1: ");
        scanf("%c", &chaveC1);
        getchar();
        printf("Digite o nome do conjunto 2: ");
        scanf("%c", &chaveC2);
        conj_aux cDif, *ptrCDif = &cDif;
        diferenca(&lista, chaveC1, chaveC2, ptrCDif);
        printf("Conjunto diferenca possui %d valor(es): \"", ptrCDif->qnt_val);
        int i;
        for(i=0; i<ptrCDif->qnt_val; i++) {
            printf("%lld", ptrCDif->valores[i]);
            if(i != ptrCDif->qnt_val-1) printf(", ");
        }
        free(ptrCDif->valores);
        printf("\"\n");
    }else if(opcao == 15) {
        int ordem;
        char chave;
        printf("Digite o nome do conjunto que deseja exibir: ");
        scanf("%c", &chave);
        printf("Digite 1-ordem crescente ou 2-ordem decrescente: ");
        scanf("%d", &ordem);
        mostraConjunto(&lista, chave, ordem);
    }else if(opcao == 16) {
        char chave1, chave2;
        printf("Digite o nome do conjunto 1: ");
        scanf("%c", &chave1);
        getchar();
        printf("Digite o nome do conjunto 2: ");
        scanf("%c", &chave2);
        if(copiarConjunto(&lista, chave1, chave2)) {
            printf("Conjunto 1 copiado para conjunto 2 com sucesso!\n");
        }else {
            printf("ERRO!!\n");
        }
    }else if(opcao == 17) {
        char chave;
        printf("Digite o nome do conjunto que deseja destruir: ");
        scanf("%c", &chave);
        if(destroiConjunto(&lista, chave)) {
            printf("Conjunto destruido com sucesso!\n", chave);
        }else {
            printf("ERRO!! Conjunto nao existe!\n");
        }
    }else if(opcao == 0) {
        printf("Fim! \n");
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

void inicializarLista(LISTA *l) {
    l->inicio = NULL;
}

bool criaConjunto(LISTA* l, char chave) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i != NULL) return false;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg.chave = chave;
    i->reg.qnt_val = 0;
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
    else if(i->reg.qnt_val == 0) return true;
    return false;
}

bool insereElementoConjunto(LISTA* l, char chave, ll valor) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1; 
    int it;
    for(it=0; it<i->reg.qnt_val; it++) {
        if(i->reg.valores[it] == valor) return -2;
    }
    i->reg.valores[i->reg.qnt_val] = valor;
    i->reg.qnt_val++;
    return true;
}

bool excluirElementoAux(ll *valores, int qnt_val, ll valor) {
    int i, j, aux = 0;
    for(i=0, j=0; i<qnt_val; i++) {
        if(valores[i] != valor) {
            valores[j++] = valores[i];
        } else aux = 1;
    }
    if(aux) return true;
    return false;
}

bool excluirElementoConjunto(LISTA* l, char chave, ll valor) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    if(excluirElementoAux(i->reg.valores, i->reg.qnt_val, valor)) {
        i->reg.qnt_val--;
        return true;
    }
    return false;
}

int tamanhoConjunto(LISTA* l, char chave) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    int tam = i->reg.qnt_val;
    return tam;
}

int maior(LISTA* l, char chave, ll valorComp) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    int it, cnt;
    for(it=0, cnt=0; it<i->reg.qnt_val; it++) {
        if(i->reg.valores[it] > valorComp) cnt++;
    }
    if(cnt == i->reg.qnt_val) return 0;
    else if(cnt == 0) return -2;
    return cnt;
}

int menor(LISTA* l, char chave, ll valorComp) {
    PONT ant, i = buscaAux(l, chave, &ant);
    if(i == NULL) return -1;
    int it, cnt;
    for(it=0, cnt=0; it<i->reg.qnt_val; it++) {
        if(i->reg.valores[it] < valorComp) cnt++;
    }
    if(cnt == i->reg.qnt_val) return 0;
    else if(cnt == 0) return -2;
    return cnt;
}

bool pertenceConjunto(LISTA* l, char chave, ll valor) {
    // Retornos possiveis: -1 (Conjunto inexistente),  0 (Elemento nao pertence),  1 (Elemento pertence ao conjunto)
    PONT ant, i = buscaAux(l, chave, &ant);
    int it;
    if(i == NULL) return -1;
    for(it=0; it<i->reg.qnt_val; it++) {
        if(i->reg.valores[it] == valor) return 1;
    }
    return 0;
}

bool conjuntosIdenticos(LISTA *l, char chave1, char chave2) {
    PONT ant, c1 = buscaAux(l, chave1, &ant), c2 = buscaAux(l, chave2, &ant);
    if(c1 == NULL || c2 == NULL) return -1;
    else if (c1->reg.qnt_val != c2->reg.qnt_val) return -2;
    int i, j, tam = c1->reg.qnt_val;
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
    for(i=0; i<verfSubConj->reg.qnt_val; i++) {
        aux = 0;
        for(j=0; j<conj->reg.qnt_val; j++) {
            if(verfSubConj->reg.valores[i] == conj->reg.valores[j]) aux = 1;
        }
        if(aux == 0) return false;
    }
    return true;
}

conj_aux* complemento(LISTA* l, char chaveC1, char chaveC2, conj_aux* cc) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    cc->qnt_val = 0;
    cc->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c2->reg.qnt_val; i++) {
            aux = 0;
            for(j=0; j<c1->reg.qnt_val; j++) {
                if(c1->reg.valores[j] == c2->reg.valores[i]) aux = 1;
            }
            if(aux == 0) {
                if(cc->qnt_val == 0) {
                    cc->valores[cc->qnt_val++] = c2->reg.valores[i];
                }else {
                    cc->valores = realloc (cc->valores, sizeof(ll)*(cc->qnt_val+1));
                    cc->valores[cc->qnt_val++] = c2->reg.valores[i];
                }
            }
        }
    }
    return cc;
}

conj_aux* uniao(LISTA* l, char chaveC1, char chaveC2, conj_aux* cu) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    cu->qnt_val = 0;
    cu->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c1->reg.qnt_val; i++) {
            cu->valores = realloc(cu->valores, sizeof(ll)*(cu->qnt_val+1));
            cu->valores[cu->qnt_val++] = c1->reg.valores[i];
        }
        for(i=0; i<c2->reg.qnt_val; i++) {
            aux = 0;
            for(j=0; j<cu->qnt_val; j++) {
                if(c2->reg.valores[i] == cu->valores[j]) aux = 1;
            }
            if(aux == 0) {
                if(cu->qnt_val == 0) {
                    cu->valores[cu->qnt_val++] = c2->reg.valores[i];
                }else {
                    cu->valores = realloc(cu->valores, sizeof(ll)*(cu->qnt_val+1));
                    cu->valores[cu->qnt_val++] = c2->reg.valores[i];
                }
            }
        }
    }
    return cu;
}

conj_aux* interseccao(LISTA* l, char chaveC1, char chaveC2, conj_aux* ca) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    ca->qnt_val = 0;
    ca->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c1->reg.qnt_val; i++) {
            aux = 0;
            for(j=0; j<c2->reg.qnt_val; j++) {
                if(c1->reg.valores[i] == c2->reg.valores[j]) aux = 1;
            }
            if(aux) {
                ca->valores = realloc (ca->valores, sizeof(ll) * (ca->qnt_val + 1));
                ca->valores[ca->qnt_val++] = c1->reg.valores[i];
            }
        }
    }
    return ca;
}

conj_aux* diferenca(LISTA* l, char chaveC1, char chaveC2, conj_aux* cd) {
    PONT ant, c1 = buscaAux(l, chaveC1, &ant), c2 = buscaAux(l, chaveC2, &ant);
    cd->qnt_val = 0;
    cd->valores = (ll*) malloc(sizeof(ll));
    if(c1 == NULL || c2 == NULL) {
        printf("ERRO!!! -- Chave(s) de conjunto(s) invalida(s)!\n");
    }else {
        int i, j, aux;
        for(i=0; i<c1->reg.qnt_val; i++) {
            aux = 0;
            for(j=0; j<c2->reg.qnt_val; j++) {
                if(c1->reg.valores[i] == c2->reg.valores[j]) aux = 1;
            }
            if(!aux) {
                cd->valores = realloc(cd->valores, sizeof(ll)*(cd->qnt_val+1));
                cd->valores[cd->qnt_val++] = c1->reg.valores[i];
            }
        }
    }
    return cd;
}

void bubbleSortOrdlha(ll arr[], int size, int ordem) { // funcao aux para mostraConjunto()
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
        bubbleSortOrdlha(end->reg.valores, end->reg.qnt_val, ordem);
        printf("Valores do Conjunto %c: \"", chave);
        int i;
        for(i=0; i<end->reg.qnt_val; i++) {
            printf("%lld", end->reg.valores[i]);
            if(i != end->reg.qnt_val-1) printf(", ");
        }
        printf("\"\n");
    }    
}

bool copiarConjunto(LISTA* l, char chave1, char chave2) {
    PONT ant, c1 = buscaAux(l, chave1, &ant), c2 = buscaAux(l, chave2, &ant);
    if(c1 == NULL || c2 == NULL) return false;
    int i, j;
    for(i=0; i<c1->reg.qnt_val; i++) {
        c2->reg.valores[i] = c1->reg.valores[i];
    } 
    c2->reg.qnt_val = c1->reg.qnt_val;
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