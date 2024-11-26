#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort (char s1[], char s2[]) {
    if (strcmp(s1, s2) > 0) {
        char temp[21];
        strcpy(temp, s1);
        strcpy(s1, s2);
        strcpy(s2, temp);
    }
}

int main () {
    int numAl, numChamada;
    char alunos[100][21];

    scanf("%d %d", &numAl, &numChamada);

    for (int i = 0; i < numAl; i++) {
        scanf("%s", alunos[i]);
    }

    for (int i = 0; i < numAl - 1; i++) {
        for (int j = 0; j < numAl - 1 - i; j++) {
            sort(alunos[j], alunos[j + 1]);
        }
    }

    printf("%s\n", alunos[numChamada - 1]);

    return 0;
}
