#include <stdio.h>

int main () {
    long long int x, y, result;
    // por algum motivo o exercicio da um valor que não cabe em uma int, ou a int usada no beecrowd tem 2 bytes ao inves e 4

    while (scanf ("%lld %lld", &x, &y) != EOF) {

        if (x < 0)
            x = -x;
        if (y < 0)
            y = -y;

        result = (x | y) - (x & y);
        printf ("%lld\n", result);
    }

    return 0;
}
