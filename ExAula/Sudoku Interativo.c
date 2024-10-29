#include <stdio.h>
#include <stdlib.h>

int m[9][9] = {}; // variável do sudoku


int main (int argc, char* argv[]) 
{  
    int nR1[9] = {}, nR2[9] = {}, algDispo[9], i, j, n;
    
    // gera numeros aleatorios da linha pra serem transformados em 0
    for (i = 0; i < 9; i++)
    {
        nR1[i] = rand()%9;
        nR2[i] = rand()%9;
    }
    
    // monta o sudoku com 0s ou numeros
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            algDispo[j] = -1;
        for (j = 0; j < 9; j++)
        {
            if (j != nR1[i] && j != nR2[i])
                while (1)
                {
                    n = rand()%9;
                    if (algDispo[n])
                        m[i][j] = n+1;
                }
            else
            {
                m[i][j] = 0;
            }
        }
    }

    // regras, pintar o sudoku 

    return 0;
}
