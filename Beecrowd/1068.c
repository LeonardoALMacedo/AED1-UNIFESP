// Balanço de Parênteses I

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    char         c;
    struct lista * next;
}list;

void push (list *head, char d) {
    list * nova = malloc (sizeof(list));
    nova->next = head->next;
    head->next = nova;
    nova->c = d;
}

void pop (list *head) {
    list *temp = head->next;
    head->next = head->next->next;
    free (temp);
}

int decide (list *head, char c) {
    if (c == '(')
        push (head, c);
    else if (c == ')')
        if (head->next)
            pop (head);
        else
            return 0;
    return 1;
}

void cleanStack (list *head) {
    if (head->next) {
        list *temp = head->next;
        head->next = head->next->next;
        free (temp);
        cleanStack (head);
    }
}

int main ()
{
    int bool = 1;
    char c;

    list *head = malloc (sizeof(list));
    head->next  = NULL;

    while (scanf ("%c", &c) != EOF) {
        if (c == '\n') {
            switch (bool) {
                case 0:
                    printf ("incorrect\n");
                    bool = 1;
                    break;
                case 1:
                    if (head->next)
                        printf ("incorrect\n");
                    else
                        printf ("correct\n");
            }
            cleanStack (head);
        }
        else if (bool)
            bool = decide (head, c);
    }
    return 0;
}
