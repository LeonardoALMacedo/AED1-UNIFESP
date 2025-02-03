#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int          content;        
    char         str[21];        
    struct node *next;
} node;

void pushLast (node *head, int x) {
    node *new = (node *) malloc (sizeof (node));

    while (head->next != NULL)
        head = head->next;

    head->next = new;
    new->next = NULL;
    new->content = x;
}

int buscaLista (node *head, int x) {
    int pos = 1;

    while (head->next != NULL && head->next->content != x) {
        pos++;
        head = head->next;
    }

    if (head->next == NULL)
        return -1;
    return pos;
}

void buscaInsere (node *head, int x, char *str, int mode) {
    node *temp = (node *) malloc (sizeof (node));
    temp->content = x;
    strcpy (temp->str, str);

    if (mode) // == 1 =|> crescente
        while (head->next != NULL && head->next->content < x)
            head = head->next;
    else
        while (head->next != NULL && head->next->content > x)
            head = head->next;

    temp->next = head->next;
    head->next = temp;
}

void printList (node *head) {
    head = head->next;

    while (head != NULL) {
        printf ("%s", head->str);

        if (head->next != NULL)
            printf (" ");

        head = head->next;
    }

    printf("\n");
}

int main () {
    int i, n, validade;
    char nomeCarne[21];
    node *head = (node *) malloc (sizeof (node));
    node *temp;
    head->next = NULL;
    head->content = -1;

    while (scanf("%d", &n) != EOF) {
        while (head->next != NULL) {
            temp = head->next;
            head->next = temp->next;
            free (temp);
        }

        for (i = 0; i < n; i++) {
            scanf ("%s %d", nomeCarne, &validade);
            buscaInsere (head, validade, nomeCarne, 1);
        }

        printList (head);
    }

    while (head->next != NULL) {
        node *temp = head->next;
        head->next = temp->next;
        free (temp);
    }
    free (head);

    return 0;
}
