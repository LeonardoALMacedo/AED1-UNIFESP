#include <stdio.h>
#include <stdlib.h>

long long int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    long long int *fibo = (long long int *) malloc((n + 1) * sizeof (long long int)); 

    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= n; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    long long int result = fibo[n]; 
    free(fibo); 

    return result;
}

int main() {
    int n, x;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        printf("Fib(%d) = %lld\n", x, fibonacci(x)); 
    }

    return 0;
}
