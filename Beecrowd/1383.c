#include <stdio.h>

int verify (int* bool, int* x, int len) 
// bool = 0 (false) => vetor x tem algum valor 0, do contrário: bool = 1 (true)
//
{
    for (int i = 0; i < len; i++)
    {
        bool = bool && x[i];
    }
}

int main ()
{
    // quantidade de tabuleiros a verificar
    int numTabuleiros, instancia;
    scanf("%d", &numTabuleiros);
    int m[9][9];

    for (instancia = 1; instancia <= numTabuleiros; instancia++)
    {
        int isTrue = 1; // --------------------------------- procurar como usar booleans --------------------------------
        // 1 => resolução viável 
        // 0 => não é uma resolução

    // loop input matriz
        for (int i = 0; i < numTabuleiros; i++)
        {
            scanf("%d %d %d %d %d %d %d %d %d", &m[i][0], &m[i][1], &m[i][2], &m[i][3], &m[i][4], &m[i][5], &m[i][6], &m[i][7], &m[i][8]);
        }

        // array cheio de 0 (false)
        int count[10]; 
        // isTrue = isTrue && count[i]; // codigo pra ser adicionado ao final
        int counter = 0;
        while (1)
        {
            for (int i = 0; i < 10; i++)
            {
                count[i] = 0;
            }
            int lin = 0, linMax = 2, col = 0, colMax = 2;
            while (lin <= linMax)
            {
                while (col <= colMax)
                {
                    // soma 1 pra tornar verdadeiro. Se um número repetir algo vai ficar como false
                    count[m[lin][col]]++;
                }
            }

            // verificar veracidade do 3 x 3
            verify (isTrue, count, 10);
            if (isTrue == 0)
                break;
            
            counter++;
            if (counter == 3 || counter == 6)
            {
                lin += 3;
                linMax += 3;
                col = 0;
                colMax = 2;
            }
            if (counter == 9)
            {
                break;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                
            }
        }
        printf ("Instancia %d\n", instancia);
        if (isTrue == 1)
            printf ("SIM\n\n");
        else 
            printf("NAO\n\n");
    }
    return 0;
}
