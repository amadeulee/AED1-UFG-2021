#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define MENOR 1 
#define IGUAL 0
#define MAIOR 1
#define TRUE 1 
#define FALSE 0
#define DOMINGO 1
#define SEGUNDA 2
#define TERCA 3
#define QUARTA 4
#define QUINTA 5
#define SEXTA 6
#define SABADO 7

////=======================================
////---------------texto.h-----------------
////=======================================

typedef struct data Data;

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano);

Data * copiaData (Data *d);

void liberaData (Data * d);

Data * somaDiasData (Data *d, unsigned int dias);

Data * subtrairDiasData (Data *d, unsigned int dias);

void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);

unsigned int obtemDiaData (Data *d);

unsigned int obtemMesData (Data *d);

unsigned int obtemAnoData (Data *d);

unsigned int bissextoData (Data *d);

int comparaData (Data *d1, Data *d2);

unsigned int numeroDiasDatas (Data *d1, Data *d2);

unsigned int numeroMesesDatas (Data *d1, Data *d2);

unsigned int numeroAnosDatas (Data *d1, Data *d2);

unsigned int obtemDiaSemanaData (Data *d);

char * imprimeData (Data *d, char * formato);

///=================================
///---------------.C----------------
///=================================


int main(){
    Data *d1;
    Data *datacopia;
    Data *dataAux;
    Data *d2;
    char *data;
 
    while (1) {

        int n;
        printf("-----Menu de opcoes-----\n\n");
        printf("1- criar data\n");
        printf("2- copiar data\n");
        printf("3- apagar data\n");
        printf("4- somar dias para data\n");
        printf("5- subtrair dias da data\n");
        printf("6- atribuir data\n");
        printf("7- obter o dia da data\n");
        printf("8- obter o mes da data\n");
        printf("9- obter o ano da data\n");
        printf("10- verificar se data eh bissexto\n");
        printf("11- comparar data\n");
        printf("12- numero de dias entre datas\n");
        printf("13- numero de meses entre datas\n");
        printf("14- numero de anos entre datas\n");
        printf("15- obter dia de semana da data\n");
        printf("16- exibir a data\n");
        printf("17- finalizar o programa\n\n");
        printf("Selecione uma op├º├úo:\n");

        scanf("%d", &n);

        int d, m, y, result, qtdeDias;
        char formato[8];
        
        switch (n) {
        case 1:
            printf("Escolha: %d\n", n);
            printf("informe o dia, mes e ano respectivamente: ");
            scanf("%i %i %i\n", &d, &m, &y);
            d1 = criaData(d, m, y);
            break;
        case 2:
            printf("Escolha: %d\n", n);
            datacopia = copiaData(d1);
            printf("Cópia da data criada.\n");
            break;
        case 3:
            printf("Escolha: %d\n", n);
            liberaData(d1);
            printf("Data liberada.\n");
            break;
        case 4:
            printf("Escolha: %d\n", n);
            printf("informe a quantidade de dias a serem somados a data: ");
            scanf("%i\n", &qtdeDias);
            dataAux = somaDiasData(d1, qtdeDias);
            break;
        case 5:
            printf("Escolha: %d\n", n);
            printf("informe a quantidade de dias a serem subtraídos a data: ");
            scanf("%i\n", &qtdeDias);
            dataAux = subtrairDiasData(d1, qtdeDias);
            break;
        case 6:
            printf("Escolha: %d\n", n);
            printf("informe o novo dia, novo mes e novo ano respectivamenteaseres atribuídos a data: ");
            scanf("%i %i %i\n", &d, &m, &y);
            atribuirData(d1, d, m, y);
            break;
        case 7:
            printf("Escolha: %d\n", n);
            printf("Dia : %i\n", obtemDiaData(d1));
            break;
        case 8:
            printf("Escolha: %d\n", n);
            printf("Mes : %i\n", obtemMesData(d1));
            break;
        case 9:
            printf("Escolha: %d\n", n);
            printf("Ano : %i\n", obtemAnoData(d1));
            break;
        case 10:
            printf("Escolha: %d\n", n);
            if(bissextoData(d1)){
                printf("A data pertence a um ano bissexto. \n");
            }else{
                printf("A data não pertence a um ano bissexto. \n");
            }
            break;
        case 11:
            printf("Escolha: %d\n", n);
            printf("informe a nova data (dia, mes e ano) a ser comparada: ");
            scanf("%i %i %i\n", &d, &m, &y);
            d2 = criaData(d,m,y);
            result = comparaData(d1, d2);

            if(result==MAIOR){
                printf("A primeira data é maior que a segunda data. \n");
            }else if (result==MENOR){
                printf("A primeira data é menor que a segunda data. \n");
            }else{
                printf("A primeira data é igual a segunda data. \n");
            }

            break;
        case 12:
            printf("Escolha: %d\n", n);
            printf("informe a nova data (dia, mes e ano) a ser comparada: ");
            scanf("%i %i %i\n", &d, &m, &y);
            d2 = criaData(d,m,y);
            printf("Quantidade de dias entre as datas: %u\n", numeroDiasDatas(d1, d2));
            break;
        case 13:
            printf("Escolha: %d\n", n);
            printf("informe a nova data (dia, mes e ano) a ser comparada: ");
            scanf("%i %i %i\n", &d, &m, &y);
            d2 = criaData(d,m,y);
            printf("Quantidade de meses entre as datas: %u\n", numeroMesesDatas(d1, d2));
            break;
        case 14:
            printf("Escolha: %d\n", n);
            printf("informe a nova data (dia, mes e ano) a ser comparada: ");
            scanf("%i %i %i\n", &d, &m, &y);
            d2 = criaData(d,m,y);
            printf("Quantidade de anos entre as datas: %u\n", numeroAnosDatas(d1, d2));
            break;
        case 15:
            printf("Escolha: %d\n", n);
            printf("Dia da semana da data referente: ");
            switch (obtemDiaSemanaData(d1)){
                case DOMINGO: printf("Domingo\n");
                case SEGUNDA: printf("Segunda\n");
                case TERCA: printf("Terça\n");
                case QUARTA: printf("Quarta\n");
                case QUINTA: printf("Quinta\n");
                case SEXTA: printf("Sexta\n");
                case SABADO: printf("Sábado\n");
            }
            break;
        case 16:
            printf("Escolha: %d\n", n);
            printf("Informe o formato que deseja que a data seja impressa (Formatos aceitos: 1-ddmmaaaa e 2-aaaammdd): ");
            scanf("%s\n", &formato);
            getchar();
            data = imprimeData(d1, formato);
            printf("Data: %s\n", data);
            break;
        case 17:
            return (0);
        }
    }
    return (0);
}

struct data {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
};

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano){
    Data *d  = (Data *) malloc(sizeof(Data));

    if(d!=NULL){
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
    }
    
    return d;
}

Data * copiaData (Data *d){
    Data *copia  = (Data *) malloc(sizeof(Data));

    if(copia!=NULL){
        copia->dia = d->dia;
        copia->mes = d->mes;
        copia->ano = d->ano;
    }

    return copia;

}

void liberaData (Data * d){
    if(d!=NULL){
        free(d);
    }
}

Data * somaDiasData (Data *d, unsigned int dias){

}

Data * subtrairDiasData (Data *d, unsigned int dias){
    Data *dat = (Data *)malloc(sizeof(Data));
 
    if (dat != NULL){
        int auxMes = 0;
        if (d->dia <= dias){
            
            if(d->mes == 1){
                auxMes = 12;
                dat->ano = d->ano--;
            }else{
                auxMes = d->mes--;
                dat->ano = d->ano;
            }
            if (auxMes==1||auxMes==3||auxMes==5||auxMes==7||auxMes==8||auxMes==10||auxMes==12)
            {
                dat->dia = 31 - (dias - d->dia);
                dat->mes = auxMes;
            }
        }else {
            dat->dia = d->dia - dias;
            dat->mes = d->mes;
            dat->ano = d->ano;
        }
    }
    return dat;
}

void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano){
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

unsigned int obtemDiaData (Data *d){
    return d->dia;
}

unsigned int obtemMesData (Data *d){
    return d->mes;
}

unsigned int obtemAnoData (Data *d){
    return d->ano;
}

unsigned int bissextoData (Data *d){
    int dezena = d->ano%100;

    if(dezena==0){
        if(d->ano%400==0){
            return TRUE;
        }else{
            return FALSE;
        }
    }else{
        if(d->ano%4==0){
            return TRUE;
        }else{
            return FALSE;
        }
    }
}

int comparaData (Data *d1, Data *d2){
    if(d1->ano < d2->ano){
        return MENOR;
    }else if(d1->ano > d2->ano){
        return MAIOR;
    }else{
        if(d1->mes < d2->mes){
            return MENOR;
        }else if(d1->mes > d2->mes){
            return MAIOR;
        }else{
            if(d1->dia < d2->dia){
                return MENOR;
            }else if(d1->dia > d2->dia){
                return MAIOR;
            }else{
                return IGUAL;
            }
        }
    }
}

unsigned int numeroDiasDatas (Data *d1, Data *d2){
    unsigned int quantDias = 0;
    int anopro = 0, mespro = 0;

    anopro = d1->ano+1;

    if(d1->ano != d2->ano){
        while(anopro < d2->ano){
            if(anopro%400 == 0) quantDias = quantDias + 366;
            else if(anopro%100 != 0 && anopro%4 == 0) quantDias = quantDias + 366;
            else quantDias = quantDias + 365;
            anopro++;
        }
        mespro = d1->mes;
        while(mespro <= 12){
            if(mespro == d1->mes){
                if(d1->mes <= 7 && d1->mes%2 == 1) quantDias+=31 - (d1->dia - 1);
                else if (d1->mes <= 7 && d1->mes%2 == 0 && d1->mes != 2) quantDias+=30 - (d1->dia - 1);
                else if(d1->mes == 2){
                if(d1->ano%400 == 0) quantDias = quantDias + 29 - (d1->dia - 1);
                else if(d1->ano%100 != 0 && d1->ano%4 == 0) quantDias += 29 - (d1->dia - 1);
                else quantDias += 28 - (d1->dia - 1);
                }
                else if(d1->mes > 7 && d1->mes%2== 0) quantDias+=31 - (d1->dia - 1);
                else if(d1->mes > 7 && d1->mes%2== 1) quantDias+=30 - (d1->dia - 1);
            } else{
                if(mespro <= 7 && mespro%2 == 1) quantDias+=31;
                else if (mespro <= 7 && mespro%2 == 0 && mespro != 2) quantDias+=30;
                else if(mespro == 2){
                    if(d1->ano%400 == 0) quantDias = quantDias + 29;
                    else if(d1->ano%100 != 0 && d1->ano%4 == 0) quantDias += 29;
                    else quantDias += 28;
                }
                else if(mespro > 7 && mespro%2== 0) quantDias+=31;
                else if(mespro > 7 && mespro%2== 1) quantDias+=30;
            }

            mespro++;           
        }
        mespro = d2->mes;
        while (mespro >= 1)
        {
            if(mespro == d2->mes){
                 quantDias+= d2->dia;
                 
            } else{
                if(mespro <= 7 && mespro%2 == 1) quantDias+=31;
                else if (mespro <= 7 && mespro%2 == 0 && mespro != 2) quantDias+=30;
                else if(mespro == 2){
                    if(d2->ano%400 == 0) quantDias += 29;
                    else if(d2->ano%100 != 0 && d2->ano%4 == 0) quantDias += 29;
                    else quantDias += 28;
                } 
                else if(mespro > 7 && mespro%2== 0) quantDias+=31;
                else if(mespro > 7 && mespro%2== 1) quantDias+=30;
            }   
        mespro--;   
        }
    } else {
            mespro = d1->mes;
        while(mespro < d2->mes){
            if(mespro == d1->mes){
                if(d1->mes <= 7 && d1->mes%2 == 1) quantDias+=31 - (d1->dia - 1);
                else if (d1->mes <= 7 && d1->mes%2 == 0 && d1->mes != 2) quantDias+=30 - (d1->dia - 1);
                else if(d1->mes == 2){
                if(d1->ano%400 == 0) quantDias = quantDias + 29 - (d1->dia - 1);
                else if(d1->ano%100 != 0 && d1->ano%4 == 0) quantDias += 29 - (d1->dia - 1);
                else quantDias += 28 - (d1->dia - 1);
                } 
                else if(d1->mes > 7 && d1->mes%2== 0) quantDias+=31 - (d1->dia - 1);
                else if(d1->mes > 7 && d1->mes%2== 1) quantDias+=30 - (d1->dia - 1);
            } else{ 
                if(mespro <= 7 && mespro%2 == 1) quantDias+=31; 
                else if (mespro <= 7 && mespro%2 == 0 && mespro != 2) quantDias+=30;
                else if(mespro == 2){
                    if(d1->ano%400 == 0) quantDias = quantDias + 29;
                    else if(d1->ano%100 != 0 && d1->ano%4 == 0) quantDias += 29;
                    else quantDias += 28;
                }
                else if(mespro > 7 && mespro%2== 0) quantDias+=31;
                else if(mespro > 7 && mespro%2== 1) quantDias+=30;
            }
            
            mespro++;           
        }
        quantDias+= d2->dia;
    }
    return quantDias;
}

unsigned int numeroMesesDatas (Data *d1, Data *d2){
    unsigned int qtde = 01;
    if(d1->ano == d2->ano){
        if(d1->mes >= d2->mes){
            qtde = d1->mes - d2->mes;
        }else{
            qtde = d2->mes - d1->mes;
        }
        
    }else if(d1->ano > d2->ano){
        int aux = d1->ano - d2->ano;
        int auxD1 = d1->mes;
        int auxD2 = 12 - d2->mes;
 
        qtde = auxD1+((aux-1)*12)+auxD2;
 
    }else{
        int aux = d2->ano - d1->ano;
        int auxD2 = d2->mes;
        int auxD1 = 12 - d1->mes;
        
        qtde = auxD2+((aux-1)*12)+auxD1;
    }
    return qtde;
}

unsigned int numeroAnosDatas (Data *d1, Data *d2){
    unsigned int qtdeAnos = 0;

    if(d1->ano > d2->ano){
        qtdeAnos = d1->ano - d2->ano;
    }else{
        qtdeAnos = d2->ano - d1->ano;
    }
    return qtdeAnos;
}

unsigned int obtemDiaSemanaData (Data *d){
    unsigned int dia = d->dia;
    
    switch (d->mes) 
    {
        case 1: break;
        case 2: dia += 31; break;
        case 3: dia += 59; break;
        case 4: dia += 90; break;
        case 5: dia += 120; break;
        case 6: dia += 151; break;
        case 7: dia += 181; break;
        case 8: dia += 212; break;
        case 9: dia += 243; break;
        case 10: dia += 273; break;
        case 11: dia += 304; break;
        case 12: dia += 334; break;
    }
    if ( ((d->ano%4)==0) && ( ((d->ano%100)!=0) || ((d->ano%400)==0) ) && (d->mes > 2)){
        dia += 1;
        dia += -1 + (d->ano-1)*365 + (d->ano-1)/4 -(d->ano-1)/100 +(d->ano-1)/400 ;            
    }
    switch (dia % 7){
    case 0: return SEGUNDA; break;
    case 1: return TERCA; break;
    case 2: return QUARTA; break;
    case 3: return QUINTA; break;    
    case 4: return SEXTA; break;
    case 5: return SABADO; break;
    case 6: return DOMINGO; break;
    }
}               

char * imprimeData (Data *d, char * formato){
    char * stringRet;
    stringRet = (char *) malloc(10*sizeof(char));

    if(*formato == '1'){
        if(d->dia<10){
            stringRet[0]='0';
            stringRet[1]=d->dia;
        }else{
            stringRet[0]=(d->dia/10);
            stringRet[1]=(d->dia%10);
        }
        stringRet[2]='/';

        if(d->mes<10){
            stringRet[3]='0';
            stringRet[4]=d->mes;
        }else{
            stringRet[3]=(d->mes/10);
            stringRet[4]=(d->mes%10);
        }
        stringRet[5]='/';

        int aux;

        stringRet[6] = d->ano/1000;
        aux = d->ano%1000;
        stringRet[7] = aux/100;
        aux = aux%100;
        stringRet[8] = aux/10;
        stringRet[9] = aux%10;

    }else{
        int aux;

        stringRet[0] = d->ano/1000;
        aux = d->ano%1000;
        stringRet[1] = aux/100;
        aux = aux%100;
        stringRet[2] = aux/10;
        stringRet[3] = aux%10;

        stringRet[4]='/';

        if(d->mes<10){
            stringRet[5]='0';
            stringRet[6]=d->mes;
        }else{
            stringRet[5]=(d->mes/10);
            stringRet[6]=(d->mes%10);
        }

        stringRet[7]='/';   

        if(d->dia<10){
            stringRet[8]='0';
            stringRet[9]=d->dia;
        }else{
            stringRet[8]=(d->dia/10);
            stringRet[9]=(d->dia%10);
        }
    }
    return stringRet;
}