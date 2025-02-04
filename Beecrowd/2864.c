#include <stdio.h>

int main () {
    int n;
    double a, b, c, resultadoFinal;

    scanf ("%d", &n);

    while (n--) {
        scanf ("%lf %lf %lf", &a, &b, &c);

        resultadoFinal = ((b*b) - (4*a*c)) / (4*a);

        if (resultadoFinal < 0)
            resultadoFinal = -resultadoFinal;

        printf ("%.2lf\n", resultadoFinal);
    }
}
