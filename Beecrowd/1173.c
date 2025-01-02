#include <stdio.h>

int main () {
    int N[10];

    scanf ("%d", N);

    printf ("N[0] = %d\n", N[0]);

    int i = 1;
    while (i < 10) {
        N[i] = N[i-1]*2;
        printf ("N[%d] = %d\n", i, N[i]);
        i++;
    }
    
    return 0;
}
