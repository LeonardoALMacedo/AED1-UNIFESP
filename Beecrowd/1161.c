#include <stdio.h>

long long int fatorial (int n) {
    long long int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int M, N;
    long long int sum;
    
    while (scanf ("%d %d", &M, &N) != EOF) {
        sum = fatorial (M) + fatorial (N);
        printf ("%lld\n", sum);
    }
 
    return 0;
}
