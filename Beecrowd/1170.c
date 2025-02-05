#include <stdio.h>
 
int main () {
    int n, count;
    double x;
    
    scanf ("%d", &n);
    
    while (n--) {
        scanf ("%lf", &x);
        count = 0;

        while (x > 1) {
            count++;
            x /= 2;
        }
        
        printf ("%d dias\n", count);
    }
 
    return 0;
}