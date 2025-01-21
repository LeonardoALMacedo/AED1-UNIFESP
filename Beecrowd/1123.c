#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxValue = 1000000;
const int maxNumber = 250;

int buscaMenor (int n, int v[n], int visitado[n]) {
    int x, valor = maxValue;
    
    for (int i = 0; i < maxNumber)
        if (v[n] < valor && !visitado[n])
            x = n;
    
    return x;
}

int dijkstra (int graph[maxNumber][maxNumber], int n, int source, int destino) {
    int dist[n], visitados[n], i, count = n, u;

    for (i = 0; i < n; i++)
        dist[i] = maxNumber;
    dist[source] = 0;

    // roda cada vertice
    while (count--) {
        // menor distancia
        u = buscaMenor (n, dist);
        visitados[u] = 1;

        // roda arestas
        for (i = 0; i < n; i++) {
            if (i == u)
                continue;

            // Atualiza valores
            if (dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
        }
    }
    return dist[destino];
}

int main () {

    
    
    return 0;


}
