#include <stdio.h>
 
int main () {
 
    int dia = 0, mes = 0, ano = 0, x;
    scanf ("%d", &x);
    
    while (x >= 365){
        x -= 365;
        ano++;
    }
    
    while (x >= 30){
        x -= 30;
        mes++;
    }
    
    dia += x;

    printf ("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
  
    return 0;
}
