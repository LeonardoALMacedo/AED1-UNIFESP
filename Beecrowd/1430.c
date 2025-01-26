#include <stdio.h>
#include <stdlib.h>

double valor (char c) {
    switch (c) {
        case 'W': return 1;
        case 'H': return 0.5;
        case 'Q': return 0.25;
        case 'E': return 0.125;
        case 'S': return 0.0625;
        case 'T': return 0.03125;
        case 'X': return 0.015625;
        default: return 0;
    }
}

int main () {
    int count, i;
    double sum;
    char linha[201];

    while (1) {
        scanf ("%s", linha);

        if (linha[0] == '*')
            break;

        count = 0;
        sum = 0;

        for (i = 0; i < strlen(linha); i++) {
            if (linha[i] == '/') {
                if (sum == 1) {
                    count++;
                    sum = 0;
                    continue;
                }
                sum = 0;
                continue;
            }
            sum += valor (linha[i]);
        }

        printf ("%d\n", count);
    }

    return 0;
}
