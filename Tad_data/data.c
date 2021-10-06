# include <stdio.h>
# include <stdlib.h>
# include "data.h"
/* lê data */
int seleciona_opcao()
{
    int op;
    do
    {
        printf("Digite 1 para descobrir a diferenca de datas: \nDigite 2 para descobrir a data da pascoa: \n\n");
        scanf("%d",&op);
        system("cls");
    }
    while(op<1 || op>2);
    return op;
}
void le_data (Data *d1)
{
    printf("Dia:");
    scanf("%d",&d1->dia);
    printf("Mes:");
    scanf("%d",&d1->mes);
    printf("Ano:");
    scanf("%d",&d1->ano);
}
/* Valida data */
int valida_data(Data d1)
{
    if ((d1.dia >31) || (d1.ano>2100) || (d1.mes>12))
        return 0;
    else
        return 1;
}
/* Imprime data */
void imprime_data(Data d1)
{
    printf("%d/%d/%d\n", d1.dia, d1.mes, d1.ano);
}
/* calcula datas */
int calcula_datas(Data d1, Data d2)
{
    int dif;

    dif = (360*(abs(d1.ano - d2.ano))) + (30*(abs(d1.mes - d2.mes))) + (abs(d1.dia - d2.dia));

    return dif;
}
void pascoa_data(Data d1, Data *d2)
{
    int a;
    int c,n,k,i,j,m,l,d;
    a = d1.ano;

    c = a/100;
    n = a - (19*(a/19));
    k = (c - 17)/25;
    i = c - (c/4) - ((c-k)/3) +(19*n) + 15;
    i = i - (30*(i/30));
    i = i - ((i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11));
    j = a + (a/4) + i + 2 -c + (c/4);
    j = j - (7*(j/7));
    l = i - j;
    m = 3 + ((l+40)/44);
    d = l + 28 - (31*(m/4));

    d2->ano = a;
    d2->mes = m;
    d2->dia = d;
    return 0;
}
