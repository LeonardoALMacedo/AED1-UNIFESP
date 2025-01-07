#include <stdio.h>
#include <string.h>

void combinar (char result[], char str1[], int len1, char str2[], int len2) {
    int i = 0, j = 0;

    while (i < len1 && i < len2) {
        result[j++] = str1[i];
        result[j++] = str2[i];
        i++;
    }

    while (i < len1)
        result[j++] = str1[i++];
    while (i < len2)
        result[j++] = str2[i++];

    result[j] = '\0';
}

int main () {
    int n, len1, len2;
    char str1[51], str2[51], result[101];

    scanf ("%d", &n);
    while (n--) {
        scanf ("%s %s", str1, str2);
        len1 = strlen (str1);
        len2 = strlen (str2);

        combinar (result, str1, len1, str2, len2);

        printf ("%s\n", result);
    }

    return 0;
}
