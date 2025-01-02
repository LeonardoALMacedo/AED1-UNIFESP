#include <stdio.h>

int main() {
    double x, notas[2];
    int i = 0;
    
    while (i < 2) {
        scanf ("%lf", &x);
        if (x >= 0 && x <= 10)
            notas[i++] = x;
        else
            printf ("nota invalida\n");
    }

    printf ("media = %.2lf\n", (notas[0] + notas[1]) / 2 );

    return 0;
}
