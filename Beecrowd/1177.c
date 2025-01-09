#include <stdio.h>
#include <stdlib.h>

int main () {
    int T, N[1000], i, x = 0;
    scanf ("%d", &T);

    int *proximaVar = (int *) malloc (sizeof (int)*T);

    for (i = 0; i < T-1; i++)
        proximaVar[i] = i + 1;
    proximaVar[T-1] = 0;

    for (i = 0; i < 1000; i++) {
        N[i] = x;
        x = proximaVar[x];
    }

    for (i = 0; i < 1000; i++)
        printf ("N[%d] = %d\n", i, N[i]);

    return 0;
}
