#include <stdio.h>
#include <string.h>

int fibonacci (int n, int *counter) {
    (*counter)++;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci (n - 1, counter) + fibonacci (n - 2, counter);
}

int main () {
    int n, x, counter, result;
    scanf ("%d", &n);

    while (n--) {
        scanf ("%d", &x);
        counter = 0;
        result = fibonacci (x, &counter);

        printf ("fib(%d) = %d calls = %d\n", x, counter - 1, result);
    }
  
    return 0;
}
