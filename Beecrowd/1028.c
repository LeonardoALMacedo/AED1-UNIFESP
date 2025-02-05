#include <stdio.h>

int mdc (int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    if (a < 0)
        return -a;
    return a;
}

int main () {
    int n, x, y, maiorDivisor;

    scanf ("%d", &n);

    while (n--) {
        scanf ("%d %d", &x, &y);

        maiorDivisor = mdc (x, y);

        if (maiorDivisor < 0)
            maiorDivisor = -maiorDivisor;
        
        printf ("%d\n", maiorDivisor);
    }

    return 0;
}
