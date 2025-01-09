#include <stdio.h>
#include <string.h>

void decodificar (int x, char str[]) {
    int len = strlen (str);

    for (int i = 0; i < len; i++) {
        if (str[i] - x < 65) {
            int k = 65 - (str[i] - x);
            str[i] = 91 - k;
        }
        else {
            str[i] -= x;
        }
    }
  
    printf ("%s\n", str);
}

int main () {
    int n, x;
    char str[51];

    scanf ("%d\n", &n);
    while (n--) {
        scanf ("%s\n%d", str, &x);
    	
        decodificar (x, str);
    }

    return 0;
}
