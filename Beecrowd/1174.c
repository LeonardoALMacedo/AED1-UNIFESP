#include <stdio.h>

int main () {
    double x;

    for (int i = 0; i < 100; i++) {
        scanf ("%lf", &x);
        if (x <= 10)
            printf ("A[%d] = %.1lf\n", i, x);
    }

    return 0;
}
