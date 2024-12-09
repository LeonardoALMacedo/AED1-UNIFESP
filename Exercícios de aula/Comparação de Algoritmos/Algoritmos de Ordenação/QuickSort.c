#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

const int n = 400000;

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}

void QuickSort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        QuickSort (p, j - 1, v);
        QuickSort (j + 1, r, v);
    }
}

int main(){
    clock_t t;
    int vetor[n];
    
    //semente de aleatoriedade
    srand ((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for (int a = 0; a < n; a++)
        vetor[a] = rand() % n; 
    
    t = clock(); 

    QuickSort (0, n, vetor);

    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", (((double)t)/((CLOCKS_PER_SEC/1000))));

    return 0;
}
