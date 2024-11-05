#include <stdio.h>
#include <string.h>

typedef struct nome
{
    int conteudo;
    struct nome * seg;
}nome;

typedef struct lista
{
    struct nome * nome;
    struct lista * seg;
}lista;

int main ()
{
    char c;
    lista * l = malloc(sizeof(lista));
    l->seg = malloc(sizeof(lista));
    lista * p = l->seg;

    p->nome = malloc (sizeof(nome));
    nome * n = p->nome;

    while (1)
    {
        scanf("%c", &c);
        if (c == " ")
        {
            p->seg = malloc(sizeof(lista));
            p = p->seg;
            p->nome = malloc(sizeof(nome));
            n = p->nome;
            continue;
        }
        if (c == "\n")
            break;
        
    }
    
    
    return 0;
}
