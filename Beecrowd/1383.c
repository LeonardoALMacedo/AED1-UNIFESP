/*
Período Noturno
Leonardo Arantes Lopes Macedo
RA: 176558
macedoleonardo870@gmail.com
*/


#include <stdio.h>

int m[9][9]; // matriz pra armazenar o sudoku
int isTrue; // int pra marcar a veracidade da soluçao: 1 = true, 0 = false;


int alLinha (int linha)
    // analiza repetição de algarismos na LINHA
    // return 1 => não tem : return 0 => tem repetição
{
    int algCount[10] = {};
    for (int i = 0; i < 9; i++)
        algCount[m[linha][i]]++;
    
    for (int i = 1; i < 10; i++)
        if (!algCount[i])
            return 0;

    return 1;
}

int alColuna (int coluna)
    // analiza repetição de algarismos na COLUNA
    // return 1 => não tem : return 0 => tem repetição
{
    int algCount[10] = {};
    for (int i = 0; i < 9; i++)
        algCount[m[i][coluna]]++;
    
    for (int i = 1; i < 10; i++)
        if (!algCount[i])
            return 0;
    
    return 1;
}

int al3x3(int linha3x3, int coluna3x3)
{
    // linha3x3 = {0,1,2}
    // coluna3x3 = {0,1,2}
    // analiza repetição em blocos 3x3 da matriz m
    // return 0 => há algarismo repetido : return 1 => não há repetição
    int algCount[10] = {};
    for (int i = 0 + linha3x3*3; i < 3 + linha3x3*3; i++)
        for (int j = 0 + coluna3x3*3; j < 3 + coluna3x3*3; j++)
        {
            algCount[m[i][j]]++;
        }
    for (int i = 1; i < 10; i++)
    {
        if (!algCount[i])
            return 0;
    }
    return 1;
}

int main()
{  
    int k; // le o numero de soluções a serem conferidas
    scanf("%d", &k);

    for (int instancia = 1; instancia <= k; instancia++)
    {
        isTrue = 1;
        // loop pra analizar cada solução
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                // loop pra dar entrada na solução
                scanf("%d", &m[i][j]);
            }

        printf("Instancia %d\n", instancia);
        
        for (int i = 0; i < 9; i++)
        {
            // analizar as colunas
            isTrue = alColuna(i);
            if (!isTrue)
            {
                printf("NAO\n\n");
                break;
            }
        }
        if (!isTrue)
            continue;

        for (int i = 0; i < 9; i++)
        {
            // analizar as linhas
            isTrue = alLinha(i);
            if (!isTrue)
            {
                printf("NAO\n\n");
                break;
            }
        }
        if (!isTrue)
            continue;


        // analizar 3x3
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                isTrue = al3x3(i, j);
                if (!isTrue)
                {
                    printf("NAO\n\n");
                    break;
                }
            }
            if (!isTrue)
                break;
        }
        if (!isTrue)
            continue;
        
        printf("SIM\n\n");
    }
}
