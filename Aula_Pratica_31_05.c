// Salva e carrega estado do jogo Bomberman.
#include <stdio.h>
#define Q_INIMIGOS 5 // Quantidade de inimigos
//Structs
typedef struct POSICAO
{
    int x;
    int y;
} TIPO_POSICAO;

typedef struct DIRECAO
{
    int movex;
    int movey;
} TIPO_DIRECAO;

typedef struct INIMIGO
{
    struct POSICAO posicao;
    struct DIRECAO direcao;
} TIPO_INIMIGO;

typedef struct ESTADO
{
    TIPO_INIMIGO INIMIGO[Q_INIMIGOS];
    TIPO_POSICAO BOMBERMAN;
    int NIVEL;
    int VIDAS;
    int PONTOS;
} TIPO_ESTADO;
// Prototipos
int SALVA_ESTADO(TIPO_ESTADO,char[]);
int LE_ESTADO(TIPO_ESTADO*,char[]);
// MAIN
int main(void)
{
    // Declaraçoes
    int opcao;
    int erro = 1;
    int i;
    char NOME_arq[]= {"config"};
    TIPO_ESTADO Estado;
    //Laço que mantem o Programa rodando enquanto a opcao é diferente de 3 (sair)
    do
    {
        printf("\n 1-Salva Estado\n 2-Carrega Estado\n 3-Sair\n\n Opcao: ");
        scanf("%d",&opcao);
        // Consistencia de entrada
        while (opcao != 1 && opcao!=2 && opcao!=3)
        {
            system ("cls");
            printf("\n 1-Salva Estado\n 2-Carrega Estado\n 3-Sair\n\n Opcao: ");
            scanf("%d",&opcao);
        }
        system ("cls");
        //opcao 1
        if (opcao == 1)
        {
            system ("cls");
            for (i=0; i< Q_INIMIGOS; i++)
            {
                printf("\nInforme as coordenadas x e y da posicao do inimigo %d: ",i);
                scanf("%d%d",&Estado.INIMIGO[i].posicao.x,&Estado.INIMIGO[i].posicao.y);
                printf ("Informe os deslocamentos do inimigo %d em x e y: ",i);
                scanf("%d%d",&Estado.INIMIGO[i].direcao.movex,&Estado.INIMIGO[i].direcao.movey);
            }
            printf("\nInforme as coordenadas x e y da Bomberman: ");
            scanf("%d%d",&Estado.BOMBERMAN.x,&Estado.BOMBERMAN.y);

            printf("\nInforme o nivel: ");
            scanf("%d",&Estado.NIVEL);
            printf("\nInforme as vidas: ");
            scanf("%d",&Estado.VIDAS);
            printf("\nInforme a pontuacao: ");
            scanf("%d",&Estado.PONTOS);

            erro = SALVA_ESTADO(Estado,NOME_arq);
            if (erro == 0)
            {
                printf("erro ao salvar estado");
            }
            printf("\n");
            printf("\Aperte Enter para sair...");
            getchar();
            getchar();
            system ("cls");
        }
        //opcao 1
        else if (opcao == 2)
        {
            system ("cls");
            erro = LE_ESTADO(&Estado,NOME_arq);
            if (erro == 0)
            {
                printf("erro ao ler estado");
            }
            for (i=0; i<Q_INIMIGOS; i++)
            {
                printf("\nCoordenadas do inimigo %d: \n \t X:%d \t Y:%d",i,Estado.INIMIGO[i].posicao.x,Estado.INIMIGO[i].posicao.y);
                printf("\ndirecao do inimigo %d: \n \t X:%d \t Y:%d",i,Estado.INIMIGO[i].direcao.movex,Estado.INIMIGO[i].direcao.movey);
                printf("\n");
            }
            printf("\n\nNivel: %d",Estado.NIVEL);
            printf("\n\nVidas: %d",Estado.VIDAS);
            printf("\n\nPontuacao: %d",Estado.PONTOS);
            printf("\n\n");
            printf("\Aperte Enter para sair...");
            getchar();
            getchar();
            system ("cls");
        }
    }while (opcao!= 3);
    return 0;
}

    int SALVA_ESTADO(TIPO_ESTADO Estado,char *NOME_arq)
    {
        FILE *arq;
        int i;

        if(!(arq = fopen(NOME_arq,"wb")))
            printf("Erro criacao");
        else
        {
            if (fwrite(&Estado, sizeof(TIPO_ESTADO), 1, arq) != 1)
                return 0;

            fclose(arq);
            return 1;
        }
    }

    int LE_ESTADO(TIPO_ESTADO *Estado,char *NOME_arq)
    {
         FILE *arq;
        int i;

        if(!(arq = fopen(NOME_arq,"rb")))
            printf("Erro criacao");

        if (fread(Estado, sizeof(TIPO_ESTADO), 1, arq) != 1)
            return 0;

        else
        {
            fclose(arq);
            return 1;
        }
    }


