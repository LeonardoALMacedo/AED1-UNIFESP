#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int            cont;
    struct lista * next;
} list;

list * createNode (int x) {
    list * temp = malloc (sizeof (list));
    temp->next = NULL;
    temp->cont = x;
}

int sequence (list * head, list ** end) {
    list * temp = head->next;
    head->next = head->next->next;
    
    (*end)->next = head->next;
    head->next = head->next->next;
    (*end) = (*end)->next;
    
    int x = temp->cont;
    free (temp);
    return x;
}

int main () {
    int n;
    list * head = createNode(0), * pointer;
    while (scanf ("%d", &n)) {
        pointer = head;
        for (int i = 0; i < n; i++) {
            pointer->next = createNode(i);
        }

        pointer = pointer->next;
        int v[n-1];
        for (int i = 0; i < n-1; i++)
            v[i] = sequence (head, &pointer);

        printf ("Discarded cards:");
        for (int i = 0; i < n-2; i++) {
            printf (" %d,", v[i]);
        }
        printf (" %d", v[n-2]);
        // printNCleanList (head);
        printf ("Remaining card: %d", head->next->cont);
        // free (head->next);
        // head->next = NULL;
    }
    // free (head);
    return 0;
}
