#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char cont[21];
    struct lista * next;
}list;

void adiciona (char base[], char v[], int n) {
    if (base[n] != ' ' || base[n] != '\n') {
        *v = base[n];
        return adiciona (base, v+1, n+1);
    }
}

int Busca (list * l, char v[]) {
    if (l->next == 0) {
        return 1;
    }
    if (!(strcmp (l->next, v))) {
        return 0;
    }
    return (l->next, v);
}

int main () {
    int n, x;
    char linha[20001];
    list * head = malloc (sizeof (list)), pList = head;
    head->next = NULL;

    scanf ("%d", &x);
    while (x--) {
        n = 0;
        fgets (linha, 20000, stdin);
        for (int i = 0; i < 20001; i++) {
            if (linha[i] == '\n')
                break;
            if (linha[i] == ' ')
                if (pList->next != NULL)
                    pList = pList->next;
                else
                    
        }
    }
    return 0;
}
