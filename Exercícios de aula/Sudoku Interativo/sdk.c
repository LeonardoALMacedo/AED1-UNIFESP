
#include <stdio.h>
#include <stdlib.h>
#include "fases.c"


int confLin(int x, int linha, int col)// mudar funcionalidade
{
    while (col >= 0)
    {
        if (x == m[linha][col])
            return 0;
        col--;
    }
    return 1;
}

int confCol(int x, int linha, int col)// mudar funcionalidade
{
    while (linha >= 0)
    {
        if (x == m[linha][col])
            return 0;
        linha--;
    }
    return 1;
}

int confBlock (int x, int linha, int col) // mudar funcionalidade
{
    while (linha >= 0)
    {
        while (col >= 0)
        {
            if (x == m[linha][col])
                return 0;
            col--;
        }
        linha--;
        col = 8;
    }
    return 1;
}


int main () 
{  
    int i, j, n, counter;
    
    
/*
    for (int i  = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
*/
    // regras, pintar o sudoku 

    return 0;
}
