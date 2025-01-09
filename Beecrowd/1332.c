#include <stdio.h>
#include <string.h>

void identifica (char str[], char letra1[]) {
    int len = strlen (str), counter = 0;

    if (len == 5) {
        printf ("%d\n", 3);
        return;
    }

    // compara com "one"
    for (int i = 0; i < 3; i++)
        if (str[i] != letra1[i])
            counter++;
    
    if (counter > 1)
        printf ("%d\n", 2);
    else
        printf ("%d\n", 1);

}

int main () {
    char letra1[4] = "one";
    int n;
    char str[6];

    scanf ("%d\n", &n);
    while (n--) {
        scanf ("%s\n", str);
    	
        identifica (str, letra1);
    }

    return 0;
}
