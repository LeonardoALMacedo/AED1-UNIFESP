#include <stdio.h>

void verifica () {
    int i, x, counter = 0;
    char grade;
    
    for (i = 0; i < 5; i++) {
        scanf ("%d", &x);
        if (x <= 127) {
            grade = 65 + i;
            counter++;
        }
    }
    
    if (counter == 1)
        printf ("%c\n", grade);
    else
        printf ("*\n");
}

int main () {
    int i, x;
    
    while (scanf ("%d", &x), x != 0)
        for (i = 0; i < x; i++)
            verifica ();
    
    return 0;
}