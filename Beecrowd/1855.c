#include <stdio.h>
#include <string.h>

int x, y;

int main () {
    scanf ("%d %d\n", &x, &y);

    char mapa[100][100];

    for (int i = 0; i < y; i++)
        gets (mapa[i]);

    int i = 0, j = 0;

    while (1) {
        if (i < 0 || j < 0 || i >= y || j >= x) {
            printf("!\n");
            break;
        }

        char atual = mapa[i][j];

        if (atual == '*') {
            printf("*\n");
            break;
        }
        else if (atual == '0') {
            printf("!\n");
            break;
        }

        mapa[i][j] = '0';

        if (atual == '>') {
            while (j + 1 < x && mapa[i][j + 1] == '.')
                j++;
            j++;
        }
        else if (atual == '<') {
            while (j - 1 >= 0 && mapa[i][j - 1] == '.')
                j--;
            j--;
        }
        else if (atual == '^') {
            while (i - 1 >= 0 && mapa[i - 1][j] == '.')
                i--;
            i--;
        }
        else if (atual == 'v') {
            while (i + 1 < y && mapa[i + 1][j] == '.')
                i++;
            i++;
        }
        else {
            printf("!\n");
            break;
        }
    }

    return 0;
}
