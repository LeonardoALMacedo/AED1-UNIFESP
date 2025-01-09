#include <stdio.h>
#include <string.h>

void verify (char str1[], char str2[]) {
    int len1 = strlen (str1);
    int len2 = strlen (str2);

    if (len1 < len2) {
        printf ("nao encaixa\n");
        return;
    }

    int i = len1 - len2, j = 0;
    while (i < len1)
        if (str1[i++] != str2[j++]) {
            printf ("nao encaixa\n");
            return;
        }
    
    printf ("encaixa\n");
}

int main () {
    int n;
    char num1[1001], num2[1001];

    scanf ("%d\n", &n);
    while (n--) {
        scanf ("%s %s\n", num1, num2);
    	
        verify (num1, num2);
    }

    return 0;
}
