#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel
{
    char         content[50];
    struct cel * next;
} list;

void printall (list * l)
{
    printf ("%s", l->content);
    if (l->next)
        return printall (l->next);
}

void printif (list * l, char name[], list * l2, int * counter)
{
    int n = strlen(name);
    if (n > strlen(l->content))
        n = strlen(l->content);
    n--;

    for (int i = 0; i < n; i++)
    {
        if (l->content[i] != name[i])
        {
            n = 0;
            break;
        }
    }

    if (!n)
    printf ("%s ", l->content);

    else 
    {
        printall (l2);
        *counter--;
        printf ("%s ", l->content);
    }

    if (l->next)
        return printif (l->next, name, l2, counter);
}

int main()
{
    int x = 1, *counter = &x;
    char c, name[50];
    list l1,l2;
    list * l;

    int i = 0;
    l = &l1;
    l->next =  malloc(sizeof(list));
    scanf("%c", l->content[0]);
    scanf("%c", &c);
    while (l->content[i] != "\n")
    {
        if (l->content[i] != " ")
        {
            l->next = malloc(sizeof(list));
            l = l->next;
        }
        i++;
        l->content[i] = c;
        scanf("%c", &c);
    }


    i = 0;
    l = &l2;
    l->next = malloc(sizeof(list));
    scanf("%c", l->content[0]);
    scanf("%c", &c);
    while (l->content[i] != "\n")
    {
        if (l->content[i] != " ")
        {
            l->next = malloc(sizeof(list));
            l = l->next;
        }
        i++;
        l->content[i] = c;
        scanf("%c", &c);
    }
    scanf("%s", &name);

    printif (&l1, name, &l2, counter);

    if (x)
        printall(&l2);

    return 0;
}
