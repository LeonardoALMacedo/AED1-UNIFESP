#include<stdio.h>
int main()
{
    char a[100];
    int i, j, len, maiuscula, minuscula, numero, caractereProibido;

    while (gets (a))
    {
        maiuscula = 0, minuscula = 0, numero = 0, caractereProibido = 0;
        len = strlen(a);
        if (len >= 6 && len <= 32)
        {
            for (i = 0; i < len; i++)
            {
                if(a[i] >= 'A' && a[i] <= 'Z')
                    maiuscula++;
                else if(a[i] >= 'a' && a[i] <= 'z')
                    minuscula++;
                else if(a[i] >= '0' && a[i] <= '9')
                    numero++;
                else
                    caractereProibido++;
            }
            if (caractereProibido || !maiuscula || !minuscula || !numero)
                printf("Senha invalida.\n");
            else
                printf("Senha valida.\n");
        }
        else
            printf("Senha invalida.\n");
    }
    
    return 0;
}
