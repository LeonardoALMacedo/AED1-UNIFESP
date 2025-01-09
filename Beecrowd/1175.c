#include <stdio.h>

void inverte (int v[], int i, int j) {
    if (i >= j)
        return;
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    inverte (v, i + 1, j - 1);
}

int main () {
    int N[20];
 
    for (int i = 0; i < 20; i++)
        scanf ("%d", &N[i]);
 
    inverte (N, 0, 19);
    
    for (int i = 0; i < 20; i++)
        printf ("N[%d] = %d\n", i, N[i]);
  
    return 0;
}
