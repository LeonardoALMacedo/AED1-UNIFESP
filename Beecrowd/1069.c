#include <stdio.h>

int contarDiamantes (char *str) {
    int count = 0, diamantes = 0;

    while (*str) {
        if (*str == '<') {
            count++;
        }
        else if (*str == '>' && count > 0) {
            diamantes++;
            count--;
        }
        str++;
    }
    
    return diamantes;
}

int main() {
    int n;
    char linha[1001];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", linha);
        printf("%d\n", contarDiamantes (linha));
    }

    return 0;
}
