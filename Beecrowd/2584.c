#include <stdio.h>
#include <math.h>

const double pi = 3.1415926535897932384626433832795028841971693993751052;

int main () {
    int n;
    double l, resultadoFinal;

    scanf ("%d", &n);

    while (n--) {
        scanf ("%lf", &l);

        resultadoFinal = (5 * l * l) / (4 * tan (pi/5));

        printf ("%.3lf\n", resultadoFinal);
    }

    return 0;
}
