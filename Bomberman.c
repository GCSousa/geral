/*Comentario
principal do jogo*/

//Blibliotecas
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#define Q_INIMIGOS 5
#define Q_LEVELS 1
//structs
typedef struct POSICAO
{
    int x;
    int y;
} Tipo_posicao;

typedef struct DIRECAO
{
    int movex;
    int movey;
} Tipo_direcao;

typedef struct INIMIGO
{
    Tipo_posicao posicao;
    Tipo_direcao direcao;
} Tipo_inimigo;

typedef struct Mapa
{
    int mapa[11][21];
} Tipo_mapa;

typedef struct CONFIGURACOES
{
    TIPO_INIMIGO INIMIGO[Q_INIMIGOS];
    TIPO_POSICAO BOMBERMAN;
    int Nivel;
    int Vidas;
    int Pontos;
    int Bombas;
    int velocidade;
    Tipo_mapa Mapa[Q_LEVELS];
} Tipo_Configs;



// Prototipos
int SALVA_ESTADO(TIPO_ESTADO,char[]);
int LE_ESTADO(TIPO_ESTADO*,char[]);
}

void Inicia_mapa(Tipo_mapa *mapa)
{
    char mapa_teste[11][27] =
    {
        {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
        {'W','P',' ',' ','D','D','D','D',' ',' ',' ',' ',' ','B',' ',' ',' ',' ','E','W','W','W','W',' ',' ','K','W'},
        {'W',' ','W',' ','E',' ',' ',' ','W','W','W','W','W','W','W','W','W','W',' ',' ',' ',' ',' ',' ','W',' ','W'},
        {'W',' ','W','W','W','W','W','W','W','W','W','D','D','D','D','D','D','W','W','W','W',' ','D','D','D',' ','W'},
        {'W',' ',' ',' ','B',' ',' ',' ',' ',' ','W',' ','D','K','D',' ',' ',' ','E',' ',' ',' ','B',' ',' ',' ','W'},
        {'W','W','W','W','W','W','W',' ','W','W','W',' ','D','D','D',' ','W',' ','D','D','D','D','D','D','D','D','W'},
        {'W','B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','W','W','W',' ',' ',' ',' ',' ',' ',' ',' ','K',' ',' ','W'},
        {'W',' ','D','D','D','D','D',' ','D','D','D','D','D','D','D','D','D',' ','W',' ','W','W','W','W','W',' ','W'},
        {'W',' ','E',' ',' ',' ','D',' ','D','D','D','D','D','K','D','D','D',' ','W',' ',' ',' ',' ',' ','E',' ','W'},
        {'W','D','K','D',' ',' ',' ',' ','W','W','W','W','W','W','W','W','W',' ',' ',' ','W','W','W',' ',' ',' ','W'},
        {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'}
    };

    FILE *arq;
    if(!(arq = fopen(mapa_teste,"wb")))
            printf("Erro criacao");
        else
        {
            if (fwrite(&Estado, sizeof(TIPO_ESTADO), 1, arq) != 1)
                return 0;

            fclose(arq);
            return 1;

}

void le_mapa(char mapa[11][27],int *pos_inicialx, int *pos_inicialy)
{
    int i,j;
    char mapa_teste[11][27] =
    {
        {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
        {'W','P',' ',' ','D','D','D','D',' ',' ',' ',' ',' ','B',' ',' ',' ',' ','E','W','W','W','W',' ',' ','K','W'},
        {'W',' ','W',' ','E',' ',' ',' ','W','W','W','W','W','W','W','W','W','W',' ',' ',' ',' ',' ',' ','W',' ','W'},
        {'W',' ','W','W','W','W','W','W','W','W','W','D','D','D','D','D','D','W','W','W','W',' ','D','D','D',' ','W'},
        {'W',' ',' ',' ','B',' ',' ',' ',' ',' ','W',' ','D','K','D',' ',' ',' ','E',' ',' ',' ','B',' ',' ',' ','W'},
        {'W','W','W','W','W','W','W',' ','W','W','W',' ','D','D','D',' ','W',' ','D','D','D','D','D','D','D','D','W'},
        {'W','B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','W','W','W',' ',' ',' ',' ',' ',' ',' ',' ','K',' ',' ','W'},
        {'W',' ','D','D','D','D','D',' ','D','D','D','D','D','D','D','D','D',' ','W',' ','W','W','W','W','W',' ','W'},
        {'W',' ','E',' ',' ',' ','D',' ','D','D','D','D','D','K','D','D','D',' ','W',' ',' ',' ',' ',' ','E',' ','W'},
        {'W','D','K','D',' ',' ',' ',' ','W','W','W','W','W','W','W','W','W',' ',' ',' ','W','W','W',' ',' ',' ','W'},
        {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'}
    };

    for (i=0; i<11; i++)
    {
        for(j=0; j<27; j++)
        {
            mapa[i][j] = mapa_teste[i][j];
            if(mapa_teste[i][j]==' ')
            {
                printf(" ");
            }
            else if(mapa_teste[i][j]=='P')
            {
                printf("o");
                *pos_inicialx = i;
                *pos_inicialy = j;
            }
            else if(mapa_teste[i][j]=='W')
            {
                printf("#");
            }
            else if(mapa_teste[i][j]=='D')
            {
                printf("*");
            }
            else if(mapa_teste[i][j]=='K')
            {
                printf(" ");
            }
            else if(mapa_teste[i][j]=='B')
            {
                printf(" ");
            }
            else if(mapa_teste[i][j]=='E')
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    //variaveis do mapa
    char mapa[11][27];
    int pos_inicialx, pos_inicialy;
    int x,y;
    // variaveis de execucao
    int sair = 0,pause = 0;
    char tecla_press;

    int i,j;// variavel para for



    le_mapa(mapa,&pos_inicialx,&pos_inicialy);
    printf("%d %d",pos_inicialx,pos_inicialy);
    x= pos_inicialx-1;
    y= pos_inicialy-1;
    gotoxy(pos_inicialy, pos_inicialx);


    //controle de movimento
    while(sair == 0)
    {
        if (kbhit())
        {
            tecla_press = toupper(getch()); // Pega a tecla pressionada

            switch (tecla_press)
            {
            // Direita
            case 'D':
                if (mapa[x+1][y]!= 'W')
                {
                    gotoxy(x, y);
                    printf(" ");
                    x = x + 1;
                    gotoxy(x, y);
                    printf("o");
                }
                break;

            // Esquerda
            case 'A':
                if (mapa[x-1][y]!= 'W')
                {
                    gotoxy(x, y);
                    printf(" ");
                    x = x -1;
                    gotoxy(x, y);
                    printf("o");
                }
                break;
            // Cima
            case 'W':
                if (mapa[x][y-1]!= 'W')
                {
                    gotoxy(x, y);
                    printf(" ");
                    y = y - 1;
                    gotoxy(x, y);
                    printf("o");
                }
                break;
            // Baixo
            case 'S':
                if (mapa[x][y+1]!= 'W')
                {
                    gotoxy(x, y);
                    printf(" ");
                    y = y +1;
                    gotoxy(x, y);
                    printf("o");
                }
                break;
            }
            gotoxy(12, 12);
            printf("%d %d",x,y);
            gotoxy(13, 13);
            printf("%c",tecla_press);
            gotoxy(x, y);
        }
    }
    return 0;
}

// Codigos para uso posterior

/*LIMPA TELA
clrscr();
*/

/*VAI PARA CERTA LOCALIZACAO DO MAPA
gotoxy( x+1, y+1 );
*/
// atualizacao de tela
//if (atualizacao_de_tela == -2)
// {
//   atualizacao_de_tela ++;
//     clrscr();
// }


// coloca bomba
// case 66:
//    if(pause == 0)
//     {
//   }
//      break;
//Pausa o jogo
//   case 9:
//     pause = 1;
//    break;
