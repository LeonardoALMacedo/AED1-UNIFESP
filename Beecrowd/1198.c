#include <stdio.h>

int main () {
    long long int x, y, valor = 0;

    while (scanf ("%lld %lld", &x, &y) != EOF) {
        valor = x - y;
        if (valor < 0)
            valor = -valor;
        
        printf ("%lld\n", valor);
    }

    return 0;
}
