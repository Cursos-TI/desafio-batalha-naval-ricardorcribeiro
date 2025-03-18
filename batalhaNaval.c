#include <stdio.h>
// método responsável por verificar se o barco esta dentro do tabuleiro
int BarcoTabuleiro(int barco[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // trecho onde verifica se o barco esta dentro do tabuleiro, caso não esteja retorna 1
            if (barco[i] > 99 || barco[j] < 0)
                return 1;
        }
    }
    return 0;
}

// método responsável por verificar se os barcos estão na mesma posição
int VerificarSobreposicao(int barco1[3], int barco2[3], int barco3[3], int barco4[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // trecho onde e feito todas as comparações para saber se os barcos estão na mesma posição, caso estejam retorna 1
            if (barco1[i] == barco2[j] || barco1[i] == barco3[j] || barco1[i] == barco4[j] || barco2[i] == barco3[j] || barco2[i] == barco4[j] || barco3[i] == barco4[j])
                return 1;
        }
    }
    return 0;
}

// método responsável por posicionar os navios no tabuleiro
void PosicionarNavio(int barco[3], int tabuleiro[10][10])
{
    for (int i = 0; i < 3; i++)
    {
        int linha = 0, coluna = 0;
        for (int j = 0; j < barco[i]; j++)
        {
            coluna++;
            if (coluna == 10)
            {
                coluna = 0;
                linha++;
            }
        }
        tabuleiro[linha][coluna] = 3;
    }
}

// método responsável por imprimir o tabuleiro
void ImprimirTabuleiro(int tabuleiro[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 9)
                printf("%d\n", tabuleiro[i][j]);
            else
                printf("%d ", tabuleiro[i][j]);
        }
    }
}

void ColocarHabilidadeTabuleiro(int tabuleiro[10][10], int linha, int coluna, int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // validação para saber se a linha estão dentro do tabuleiro
            if ((linha + i) < 0 || (linha + i) > 9)
            {
                continue;
            }
            // validação para saber se a coluna estão dentro do tabuleiro
            if ((coluna + j) < 0 || (coluna + j) > 9)
            {
                continue;
            }
            // validação para saber se tem que desenhar a habilidade no tabuleiro
            if (habilidade[i][j] == 1)
            {
                // desenhando a habilidade no tabuleiro
                tabuleiro[linha + i][coluna + j] = 5;
            }
        }
    }
}

int main()
{
    int linha, coluna, habilidade;

    printf("digite a linha onde a habilidade vai atingir \n");
    scanf("%d", &linha);
    while (linha < 0 || linha > 9)
    {
        printf("digite um valor no intervalo e 0 a 9 \n");
        scanf("%d", &linha);
    }

    printf("digite a coluna onde a habilidade vai atingir \n");
    scanf("%d", &coluna);
    while (linha < 0 || linha > 9)
    {
        printf("digite um valor no intervalo e 0 a 9 \n");
        scanf("%d", &coluna);
    }
    printf("digite qual habilidade deseja usar \n");
    printf("1 - Octaedro\n");
    printf("2 - Cruz\n");
    printf("3 - Triangulo\n");
    scanf("%d", &habilidade);

    // Crie um tabuleiro 10x10 representado por uma matriz de inteiros.
    int tabuleiro[10][10] =
        {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Posicione 3 navios no tabuleiro. Cada navio ocupa uma célula e é representado pelo número 3.
    int navioHorizontal[3] = {0, 1, 2}, navioVertical[3] = {21, 31, 41}, navioDiagonalDireita[3] = {15, 26, 37}, navioDiagonalEsquerda[3] = {55, 64, 73};
    int octaedro[5][5] =
        {
            {0, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 1, 1, 0},
            {0, 0, 1, 0, 0}};
    int cruz[5][5] =
        {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}};
    int triangulo[5][5] =
        {
            {0, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};

    // validação para saber se os navios estão na mesma posição
    if (VerificarSobreposicao(navioHorizontal,
                              navioVertical,
                              navioDiagonalDireita,
                              navioDiagonalEsquerda))
    {
        printf("Os navios estão na mesma posição\n");
        return 0;
    }

    // validação para saber se os navios estão fora do tabuleiro
    if (BarcoTabuleiro(navioHorizontal) ||
        BarcoTabuleiro(navioVertical) ||
        BarcoTabuleiro(navioDiagonalDireita) ||
        BarcoTabuleiro(navioDiagonalEsquerda))
    {
        printf("Posição inválida\n");
        return 0;
    }

    // Posicione os navios no tabuleiro.
    PosicionarNavio(navioHorizontal, tabuleiro);
    PosicionarNavio(navioVertical, tabuleiro);
    PosicionarNavio(navioDiagonalDireita, tabuleiro);
    PosicionarNavio(navioDiagonalEsquerda, tabuleiro);

    if (habilidade == 1)
    {
        // definir centro do cruz
        linha -= 2;
        coluna -= 2;
        
        // chamando metodo para colocar a habilidade no tabuleiro
        ColocarHabilidadeTabuleiro(tabuleiro, linha, coluna, octaedro);
    }
    else if (habilidade == 2)
    {
        // definir centro do cruz
        linha -= 2;
        coluna -= 2;

        // chamando metodo para colocar a habilidade no tabuleiro
        ColocarHabilidadeTabuleiro(tabuleiro, linha, coluna, cruz);
    }
    else if (habilidade == 3)
    {
        // definir centro do cruz
        linha--;
        coluna -= 2;

        // chamando metodo para colocar a habilidade no tabuleiro
        ColocarHabilidadeTabuleiro(tabuleiro, linha, coluna, triangulo);
    }

    // Imprima o tabuleiro no console.
    ImprimirTabuleiro(tabuleiro);
    return 0;
}
