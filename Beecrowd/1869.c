#include <stdio.h>

char nums[32] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
char res[500];

void trocaBase (unsigned long long x) {
    if (x == 0) {
        printf ("0\n");
        return;
    }
    
    int i = 0;
    while (x > 0) {
        res[i++] = nums[x % 32];
        x /= 32;
    }
    
    while (i > 0)
        printf ("%c", res[--i]);
    printf ("\n");
}

int main () {
    unsigned long long N;
    
    while (1) {
        scanf ("%llu", &N);

        if (N == 0)
            break;

        trocaBase (N);
    }
    
    printf ("0\n");
    return 0;
}
