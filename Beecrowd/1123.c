#include <stdio.h>
const int maxNumber = 250;
const int valorMaximo = 1000000;

void limpaGrafoMatriz (int grafo[maxNumber][maxNumber], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grafo[i][j] = valorMaximo;
}

int buscaMenorPeso (int n, int v[n], int visitado[n]) {
    int x = 0, valor = valorMaximo;
    
    for (int i = 0; i < n; i++)
        if (v[i] < valor && !visitado[i]) {
            valor = v[i];
            x = i;
        }
    
    return x;
}

int dijkstra (int grafo[maxNumber][maxNumber], int n, int s, int destino) {
    int peso[n], visitados[n], i, u;

    for (i = 0; i < n; i++) {
        peso[i] = valorMaximo;
        visitados[i] = 0;
    }
    peso[s] = 0;

    while (1) {
        u = buscaMenorPeso(n, peso, visitados);

        if (visitados[u] || u == destino - 1)
            break;
        
        visitados[u] = 1;

        for (i = 0; i < n; i++)
            if (i == u)
                continue;

            else if (grafo[u][i] != valorMaximo && peso[u] != valorMaximo && peso[u] + grafo[u][i] < peso[i])
                peso[i] = peso[u] + grafo[u][i];
    }

    return peso[destino - 1];
}

int main () {
    int i, j, cidades, estradas, destino, s, u, v, p;
    int grafo[maxNumber][maxNumber];
    limpaGrafoMatriz(grafo, maxNumber);

    while (1) {
        scanf("%d %d %d %d", &cidades, &estradas, &destino, &s);

        if (cidades == 0 && estradas == 0 && destino == 0 && s == 0)
            break;

        for (i = 0; i < estradas; i++) {
            scanf("%d %d %d", &u, &v, &p);
            grafo[u][v] = p;
            grafo[v][u] = p;
        }

        // Para cada cidade da rota
        for (i = 0; i < destino - 1; i++)
            // tira todos caminhos que saem da rota
            for (j = 0; j < cidades; j++)
                if (j != i + 1)
                    grafo[i][j] = valorMaximo;
        grafo[s][s] = 0;

        printf("%d\n", dijkstra(grafo, cidades, s, destino));
        
        // Reseta o grafo após o cálculo
        limpaGrafoMatriz(grafo, cidades);
    }
    
    return 0;
}
