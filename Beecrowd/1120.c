#include <stdio.h>
#include <string.h>

void removeZerosAEsquerda (char str[]) {
    int i = 0, j = 0;
    
    while (str[i] == '0' && str[i + 1] != '\0')
        i++;
        
    while (str[i] != '\0')
        str[j++] = str[i++];
    str[j] = '\0';
}

void calculaNumero (int digitoFalho) {
    char numero[100001];
    scanf ("%s", numero);
    
    if (digitoFalho == 0 && strlen (numero) == 1 && numero[0] == '0')
        return;
        
    int i;
    char resultado[100001] = "";
    int pos = 0;
    
    for (i = 0; i < strlen (numero); i++)
        if ((numero[i] - '0') != digitoFalho)
            resultado[pos++] = numero[i];
    resultado[pos] = '\0';
    
    if (strlen (resultado) == 0) {
        printf ("0\n");
        return;
    }
    
    removeZerosAEsquerda (resultado);
    printf ("%s\n", resultado);
}

int main () {
    int digitoFalho;
    
    while (1) {
        scanf ("%d", &digitoFalho);
        
        char numero[100001];
        scanf ("%s", numero);
        
        if (digitoFalho == 0 && strlen (numero) == 1 && numero[0] == '0')
            break;
            
        char resultado[100001] = "";
        int pos = 0;
        
        for (int i = 0; i < strlen (numero); i++)
            if ((numero[i] - '0') != digitoFalho)
                resultado[pos++] = numero[i];
        resultado[pos] = '\0';
        
        if (strlen (resultado) == 0) {
            printf ("0\n");
            continue;
        }
        
        removeZerosAEsquerda (resultado);
        printf ("%s\n", resultado);
    }
    
    return 0;
}
