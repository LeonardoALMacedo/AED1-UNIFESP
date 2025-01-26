#include <stdio.h>
#include <stdlib.h>
#define tamanhoMaximo 100000

int compararCresc (const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compararDecresc (const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, temp, i = 0, j = 0;
    
    int *headP = malloc (tamanhoMaximo * sizeof(int));
    int *headI = malloc (tamanhoMaximo * sizeof(int));
    
    scanf ("%d", &n);

    while (n--) {
        scanf("%d", &temp);

        if (temp % 2 == 0)
            headP[i++] = temp;
        else
            headI[j++] = temp;
    }

    qsort (headP, i, sizeof(int), compararCresc);
    qsort (headI, j, sizeof(int), compararDecresc);

    for (int k = 0; k < i; k++)
        printf ("%d\n", headP[k]);

    for (int k = 0; k < j; k++)
        printf ("%d\n", headI[k]);

    free (headP);
    free (headI);

    return 0;
}
