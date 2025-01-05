#include <stdio.h>
#include <string.h>

void reverseString (char str[], int i, int j) {
    if (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        reverseString (str, i + 1, j - 1);
    }
}

void crypto (char str[], int len) {
    int i;
    
    // 1a etapa
    for (i = 0; i < len; i++)
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            str[i] += 3;

    // 2a etapa
    reverseString (str, 0, len - 1);
    
    // 3a etapa
    for (i = len / 2; i < len; i++)
        str[i] -= 1;
}

int main () {
    char str[1001];
    int n;
    scanf ("%d", &n);
    while (n--) {
        gets (str);
        if (str[0] == '\0')
            gets (str);
        crypto (str, strlen (str));
        printf ("%s\n", str);
    }
}
