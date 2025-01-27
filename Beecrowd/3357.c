#include <stdio.h>
#include <stdlib.h>

int main () {
    int i, j, n;
    double l, q;
    char nome[10][13];

    scanf ("%d %lf %lf", &n, &l, &q);

    for (i = 0; i < n; scanf("%s", nome[i++]));

    for (j = 0; l > q; l -= q, j++);

    printf ("%s %.1lf\n", nome[j%n], l);

    return 0;
}
