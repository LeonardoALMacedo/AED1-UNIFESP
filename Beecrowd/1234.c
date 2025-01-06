#include <stdio.h>
#include <string.h>

void tornaMaiscula (char c[], int i) {
    if (c[i] >= 'a' && c[i] <= 'z')
        c[i] -= 32;
}

void tornaMinuscula (char c[], int i) {
    if (c[i] >= 'A' && c[i] <= 'Z')
        c[i] += 32;
}

int main () {
    char str[51];
    int bool;
    while (gets (str)) {
        bool = 1;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == ' ')
                continue;

            if (bool) {
                tornaMaiscula (str, i);
                bool = 0;
            }

            else {
                tornaMinuscula (str, i);
                bool = 1;
            }
        }

        printf ("%s\n", str);
    }

    return 0;
}
