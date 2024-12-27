#include <stdio.h>
#include <math.h>

int isPrime(int x) {
    if (x == 1)
        return 0;

    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    
    return 1;
}

int main() {
    int n, x;
    scanf ("%d", &n);

    while (n--) {
        scanf ("%d", &x);
        if (isPrime(x))
            printf("Prime\n");
        else
            printf ("Not Prime\n");
    }

    return 0;
}
