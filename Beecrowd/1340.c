#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max (int v[], n) {
    int x = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > x)
            x = v[i];
    }
    return x;
}

void pushStack (int v[], int * f, int x) {
    v[++*f] = x;
}

// v[] só tem int > 0 && < 100
void popStack (int v[], int * f) {
    v[*f--] = 0;
}

void pushQueue (int v[], int * f, int x) {
    v[++*f] = x;
}

void popQueue (int v[], int * r) {
    v[*f--] = 0;
}

void PQueueOrganize ()

void pushPQueue (int v[], int * f, int n) {
    
}

void popPQueue (int v[], int * f, int n)

int main () {
    int n, acao, valor;
    int fila[1000], r, f;
    int fPrio[1000], r, f;
    int pilha[1000], f;
    int fPrioBool = 1, fBool = 1, pilhaBool = 1;
    while (scanf ("%d", &n) != EOF) {
        r = 0;
        f = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &acao, &valor);
            if (acao == 1) {

            }
            if (acao == 2) {
                if (fPrioBool)
                    if (lista!= max (lista, f))
                        fPrioBool--;
                if (fila)
                    if (valor != lista[r])
                        fila--;
                if (pilha)
                    if (valor != lista[f])
                        pilha--;
                if (pilha && fila)
            }
        }
        //
    }

    return 0;
}