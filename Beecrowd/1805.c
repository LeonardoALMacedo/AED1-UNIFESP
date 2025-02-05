#include <stdio.h>

int main () {
    long long int x, y, valor = 0;

    scanf ("%lld %lld", &x, &y);

    valor = (x + y)* (y - x + 1) / 2;
    
    printf ("%lld\n", valor);

    return 0;
}
