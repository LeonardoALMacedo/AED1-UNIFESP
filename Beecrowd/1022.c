#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} racional;

int mdc (int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    if (a < 0)
        return -a;
    return a;
}

racional simplifica (racional r) {
    int divisor = mdc (r.numerador, r.denominador);
    r.numerador /= divisor;
    r.denominador /= divisor;
    return r;
}

racional operacoes (racional r1, racional r2, char operador) {
    racional resultado;

    switch (operador) {
        case '+':
            resultado.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
            resultado.denominador = r1.denominador * r2.denominador;
            break;
        case '-':
            resultado.numerador = r1.numerador * r2.denominador - r2.numerador * r1.denominador;
            resultado.denominador = r1.denominador * r2.denominador;
            break;
        case '*':
            resultado.numerador = r1.numerador * r2.numerador;
            resultado.denominador = r1.denominador * r2.denominador;
            break;
        default: // operador == '/'
            resultado.numerador = r1.numerador * r2.denominador;
            resultado.denominador = r1.denominador * r2.numerador;
            break;
    }

    return resultado;
}

int main () {
    int n;
    racional r1, r2, resultado, simplificado;
    char operador;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {

        scanf ("%d / %d %c %d / %d", &r1.numerador, &r1.denominador, &operador, &r2.numerador, &r2.denominador);
        
        resultado = operacoes (r1, r2, operador);

        simplificado = simplifica (resultado);
        
        printf ("%d/%d = %d/%d\n", resultado.numerador, resultado.denominador, simplificado.numerador, simplificado.denominador);
    }

    return 0;
}
