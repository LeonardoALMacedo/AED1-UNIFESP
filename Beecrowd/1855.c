#include <stdio.h>
#include <string.h>

int x, y;

int main () {
    scanf ("%d %d\n", &x, &y);

    char mapa[y][x];

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
            do {
                j++;
            }
            while (j < x && mapa[i][j] == '.');
        }
        else if (atual == '<') {
            do {
                j--;
            }
            while (j >= 0 && mapa[i][j] == '.');
        }
        else if (atual == '^') {
            do {
                i--;
            }
            while (i >= 0 && mapa[i][j] == '.');
        }
        else if (atual == 'v') {
            do {
                i++;
            }
            while (i < y && mapa[i][j] == '.');
        }
        else {
            printf("!\n");
            break;
        }
    }

    return 0;
}
