#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[50];
    struct Node* next;
} Node;


Node* createNode (char* nome) {
    Node *nova = (Node *) malloc (sizeof(Node));
    strcpy (nova->nome, nome);
    nova->next = NULL;
    return nova;
}

void insereFinal (Node** head, char* nome) {
    Node* nova = createNode (nome);
    
    if (*head == NULL) {
        *head = nova;
        return;
    }
    
    Node* atual = *head;
    while (atual->next != NULL)
        atual = atual->next;

    atual->next = nova;
}

void juntaLista (Node** head, Node* novosAmigos, char* amigo) {
    if (*head == NULL)
        return;
    
    if (strcmp ((*head)->nome, amigo) == 0) {
        Node* temp = novosAmigos;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = *head;
        *head = novosAmigos;
        return;
    }
    
    Node* atual = *head;
    Node* anterior = NULL;
    
    while (atual != NULL && strcmp (atual->nome, amigo) != 0) {
        anterior = atual;
        atual = atual->next;
    }
    
    if (atual != NULL) {
        Node* temp = novosAmigos;

        while (temp->next != NULL)
            temp = temp->next;

        anterior->next = novosAmigos;
        temp->next = atual;
    }
}

Node* criaListaPelaString (char* linha) {
    Node* head = NULL;
    char* token = strtok (linha, " ");
    
    while (token != NULL) {
        insereFinal (&head, token);
        token = strtok (NULL, " ");
    }
    
    return head;
}

void printLista (Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        printf("%s", atual->nome);
        if (atual->next != NULL) {
            printf(" ");
        }
        atual = atual->next;
    }
    printf("\n");
}

void freeLista (Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        free (temp);
    }
}

int main () {
    char linha[5000];
    Node *listaAtual = NULL, *novosAmigos = NULL;
    
    fgets (linha, sizeof (linha), stdin);
    linha[strcspn(linha, "\n")] = 0;
    listaAtual = criaListaPelaString (linha);
    
    fgets (linha, sizeof (linha), stdin);
    linha[strcspn(linha, "\n")] = 0;
    novosAmigos = criaListaPelaString (linha);
    
    fgets (linha, sizeof (linha), stdin);
    linha[strcspn (linha, "\n")] = 0;
    
    if (strcmp (linha, "nao") != 0)
        juntaLista (&listaAtual, novosAmigos, linha);
    else {
        Node* atual = listaAtual;

        while (atual->next != NULL)
            atual = atual->next;

        atual->next = novosAmigos;
    }
    
    printLista (listaAtual);
    
    freeLista (listaAtual);
    
    return 0;
}
