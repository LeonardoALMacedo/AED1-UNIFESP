#include <stdio.h>
#include <stdlib.h>

int *vetorUnion;

void inicializar (int n) {
    vetorUnion = (int *) malloc ((n + 1) * sizeof (int));

    for (int i = 1; i <= n; i++)
        vetorUnion[i] = i;
}

int encontrar (int x) {
    if (vetorUnion[x] == x)
        return x;

    return vetorUnion[x] = encontrar (vetorUnion[x]);
}

void unir (int x, int y) {
    int rx = encontrar (x);
    int ry = encontrar (y);

    if (rx != ry)
        vetorUnion[ry] = rx;
}

int main () {
    int n, l;
    scanf ("%d %d", &n, &l);

    inicializar (n);

    for (int i = 0; i < l; i++) {
        int x, y;
        scanf ("%d %d", &x, &y);
        unir (x, y);
    }
    
    int representante = encontrar (1);
    int completo = 1;
    
    for (int i = 2; i <= n; i++)
        if (encontrar (i) != representante) {
            completo = 0;
            break;
        }
    
    if (completo)
        printf ("COMPLETO\n");
    else
        printf ("INCOMPLETO\n");
    
    return 0;
}
