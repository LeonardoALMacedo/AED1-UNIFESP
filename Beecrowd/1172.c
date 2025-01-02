#include <stdio.h>

int main() {
    int i, n, X[10];

    for (i = 0; i < 10; i++) {
        scanf ("%d", &n);
        if (n > 0)
            X[i] = n;
        else
            X[i] = 1;
    }

    for (i = 0; i < 10; i++)
        printf ("X[%d] = %d\n", i, X[i]);
    
    return 0;
}
