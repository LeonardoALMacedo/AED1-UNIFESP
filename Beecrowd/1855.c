#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x, y;

void percorreDireita (int *i, int *j, char mapa[x][y]) {
    while (*i < x) {
        if (mapa[*i][*j] != '.')
            break;
        *i++;
    }
}

void percorreEsquerda (int *i, int *j, char mapa[x][y]) {
    while (*i >= 0) {
        if (mapa[*i][*j] != '.')
            break;
        *i--;
    }
}

void percorreCima (int *i, int *j, char mapa[x][y]) {
    while (*j >= 0) {
        if (mapa[*i][*j] != '.')
            break;
        *j--;
    }
}

void percorreBaixo (int *i, int *j, char mapa[x][y]) {
    while (*j < y) {
        if (mapa[*i][*j] != '.')
            break;
        *j++;
    }
}

int main () {

    scanf ("%d %d", &x, &y);

    char mapa[x][y];

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            scanf ("%d", &mapa[i][j]);

    int i = 0, j = 0;
    while (1) {
        if (i >= x || j >= y || mapa[i][j] == '0') {
            printf ("!\n");
            break;
        }
        else if (mapa[i][j] == '*') {
            printf ("*\n");
            break;
        }
        else if (mapa[i][j] == '>') {
            mapa[i++][j] = '0';
            percorreDireita (&i, &j, mapa);
        }
        else if (mapa[i][j] == '<') {
            mapa[i--][j] = '0';
            percorreEsquerda (&i, &j, mapa);
        }
        else if (mapa[i][j] == '^') {
            mapa[i][j--] = '0';
            percorreCima (&i, &j, mapa);
        }
        else if (mapa[i][j] == 'v') {
            mapa[i][j++] = '0';
            percorreBaixo (&i, &j, mapa);
        }
    }
    
    return 0;


}
