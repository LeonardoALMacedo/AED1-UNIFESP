#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, p;
} aresta;

aresta *a; // vetor de arestas
int *g;    // vetor para Union-Find

// recebe um vértice e confere o parentesco
int parent (int x) {
    if (x != g[x])
        g[x] = parent (g[x]); // faz a chamada recursiva até que o vértice seja seu próprio parente

    return g[x];
}

// x = # (arestas)
int kruskal (int x) {
    int y, z; 
    int soma = 0;

    for (int i = 0; i < x; i++) {
        y = parent (a[i].u);
        z = parent (a[i].v);

        if (y != z) {
            g[y] = z; // une os parentescos para evitar repetição
            soma += a[i].p;
        }
    }

    return soma;
}

int compara (const void *a, const void *b) {
    aresta *aresta1 = (aresta *) a;
    aresta *aresta2 = (aresta *) b;
    return aresta1->p - aresta2->p;
}

int main () {
    int c, n; // c = # (cidades) // n = # (Arestas)

    while (scanf ("%d %d", &c, &n), c && n) {
        int pesoTotal = 0;
        
        a = (aresta *) malloc (n * sizeof (aresta));
        g = (int *) malloc (c * sizeof (int));

        for (int i = 0; i < n; i++) { // preenche vetor global a
            scanf ("%d %d %d", &a[i].u, &a[i].v, &a[i].p);
            pesoTotal += a[i].p;
        }
        // pesoTotal = peso de todas as arestas

        qsort (a, n, sizeof (aresta), compara); // a- array, n-número de elementos, tamanho dos elementos, função compara

        for (int i = 0; i < c; i++) // define os parentes iniciais
            g[i] = i;

        printf ("%d\n", pesoTotal - kruskal (n));

        free (a);
        free (g);
    }

    return 0;
}
