#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

const int n = 400000; 

void insertionSort (int n, int v[]) {
    int i, j, x;
    for (j = 1;j < n; j++) {
            x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
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

    insertionSort (n, vetor);

    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", (((double)t)/((CLOCKS_PER_SEC/1000))));

    return 0;
}
