/*TAD DATA (dd,mm,aaaa)*/
/* TIPO DE DADO exportado */
struct data
{
    int dia;
    int mes;
    int ano;
};
typedef struct data Data;
/* OPERAÇÕES Exportadas */
int seleciona_opcao();
/* lê data */
void le_data (Data *d1);
/* Valida data */
int valida_data(Data d1);
/* Imprime data */
void imprime_data(Data d1);
/* calcula datas */
int calcula_datas(Data d1, Data d2);
void pascoa_data(Data d1, Data *d2);
