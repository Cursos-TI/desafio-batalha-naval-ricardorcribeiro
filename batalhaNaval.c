#include <stdio.h>

int main()
{
    // 1. Crie um tabuleiro 10x10 representado por uma matriz de inteiros.
    int tabuleiro[10][10] =
        {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // 2. Posicione 3 navios no tabuleiro. Cada navio ocupa uma célula e é representado pelo número 3.
    int navioHorizontal[3] = {11, 12, 13}, navioVertical[3] = {21, 31, 41};

    // loop para fazer as validações	para saber se os navios estão na mesma posição ou se estão fora do tabuleiro
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // validação para saber se os navios estão na mesma posição
            if (navioHorizontal[i] == navioVertical[j])
            {
                printf("Os navios estão na mesma posição\n");
                return 0;
            }
            // validação para saber se os navios estão fora do tabuleiro
            if (navioHorizontal[i] > 99 || navioVertical[j] > 99 || navioHorizontal[i] < 0 || navioVertical[j] < 0)
            {
                printf("Posição inválida\n");
                return 0;
            }
        }
    }
    // loop para posicionar os navios no tabuleiro
    for (int i = 0; i < 3; i++)
    {
        // criando variáveis para linha e coluna para posicionar os navios no sentido horizontal
        int linha = 0, coluna = 0;
        for (int j = 0; j < navioHorizontal[i]; j++)
        {
            coluna++;
            // quando a coluna chegar a 10, a coluna volta a ser 0 e a linha é incrementada
            if (coluna == 10)
            {
                coluna = 0;
                linha++;
            }
        }
        // posicionar o navio no tabuleiro
        tabuleiro[linha][coluna] = 3;

        // resetando as variáveis linha e coluna para posicionar os navios no sentido vertical
        linha = 0;
        coluna = 0;

        for (int j = 0; j < navioVertical[i]; j++)
        {
            coluna++;
            // quando a coluna chegar a 10, a coluna volta a ser 0 e a linha é incrementada
            if (coluna == 10)
            {
                coluna = 0;
                linha++;
            }
        }
        // posicionar o navio no tabuleiro
        tabuleiro[linha][coluna] = 3;
    }

    // 3. Imprima o tabuleiro no console.
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 8)
                printf("%d\n", tabuleiro[i][j]);
            else
                printf("%d ", tabuleiro[i][j]);
        }
    }
    return 0;
}
