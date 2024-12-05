#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxIndex (int v[], int n) {
    int max = v[0], index = 0;
    for (int i = 1; i < n; i++)
        if (v[i] > max) {
            max = v[i];
            index = i;
        }
    return index;
}

/* (v[], 0, len)
void OrganizeR (int v[], int i) {
    int temp;
    if (i <= 500) {
        if (v[i*2] > v[i]) {
            temp = v[i];
            v[i] = v[i*2];
            v[i*2] = temp;
        }
        if (v[i*2+1] > v[i]) {
            temp = v[i];
            v[i] = v[i*2];
            v[i*2] = temp;
        }
        return OrganizeR (v, i + 1);
    }
}
void queueOrganize (int v[]) {
    OrganizeR (v, 0);
}*/

int compareInts(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x > y) return -1;
    else if (x < y) return 1;
    return 0;
}

void pushQueue (int v[], int * f, int x) {
    v[*f++] = x;
}

void pushPQueue (int v[], int * f, int x) {
    v[*f++] = x;
    qsort (v, 1000, sizeof(int), compareInts);
    //queueOrganize (v);
}

void pushStack (int v[], int * f, int x) {
    v[*f++] = x;
}

int popQueue (int v[], int * r) {
    int temp = v[--*r];
    v[*r] = 0;
    return temp;
}

int popPQueue (int v[], int * f) {
    int temp = v[0];
    v[0] = 0;
    *f--;
    qsort (v, 1000, sizeof(int), compareInts);
    return temp;
}

// v[] só tem int > 0 && < 100
int popStack (int v[], int * f) {
    int temp = v[*f];
    v[--*f] = 0;
    return temp;
}

void clearVet (int v[], int n) {
    v[--n] = 0;
    if (n != -1)
        return clearVet (v, n-1);
}

int main () {
    int n, acao, valor;
    int queue[1000], rQ = 0, fQ = 0;
    int pQueue[1000], fPQ = 0;
    int stack[1000], fS = -1;
    int queueBool = 1, pQueueBool = 1, stackBool = 1;

    while (scanf ("%d", &n) != EOF) {
        queueBool = 1, pQueueBool = 1, stackBool = 1;
        clearVet (queue, 1000);
        clearVet (pQueue, 1001);
        clearVet (stack, 1000); 
        rQ = 0, fQ = -1, fPQ = 0, fS = -1;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &acao, &valor);
            if (acao == 1) {
                pushQueue (queue, &fQ, valor);
                pushPQueue (pQueue, &fPQ, valor);
                pushStack (stack, &fS, valor);
            }
            if (acao == 2) {
                if (popQueue (queue, &rQ) != valor)
                    queueBool--;
                if (popPQueue (pQueue, &fPQ) != valor)
                    pQueueBool--;
                if (popStack (stack, &fS) != valor)
                    stackBool--;
            }
        }
        if (stackBool == 1)
            printf ("stack\n");
        else if (queueBool == 1 && !(pQueueBool == 1))
            printf ("queue\n");
        else if (pQueueBool == 1 && !(queueBool == 1))
            printf ("priority queue\n");
        else if (queueBool == 1 && pQueueBool == 1)
            printf ("not sure\n");
        else
            printf ("impossible  %d  %d  %d\n", queueBool, pQueueBool, stackBool);
    }
    return 0;
}
