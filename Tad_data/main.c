# include <stdio.h>
# include <stdlib.h>
# include "data.h"
int main()
{
    Data d1,d2;
    int count=0,d;

    d = seleciona_opcao();

    switch (d)
    {
    case 1:
        do
        {
            le_data(&d1);
            if (valida_data(d1))
            {
                count++;
                if(count < 2)
                    d2 = d1;
            }
            system("cls");
        }
        while(count <2);
        system("cls");

        d = calcula_datas(d1, d2);
        printf(" A diferenca de dias entre as datas escritas eh de %d dias \n",d);
        break;

    case 2:
        d=1;
        do
        {
            le_data(&d1);
            if (valida_data(d1))
                d=0;
            system("cls");
        }
        while(d);
        system("cls");

        pascoa_data(d1,&d2);
        imprime_data(d2);
        break;

    }
    return 0;
}
