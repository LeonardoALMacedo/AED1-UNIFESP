#include <stdio.h>

int getLed(char x){
    switch (x){
        case '1':
            return 2;
        case '2':
            return 5;
        case '3':
            return 5;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 3;
        case '8':
            return 7;
        case '9':
            return 6;
    }
    return 6; // default -> x = 0;
}

int main()
{
    int n, i, len, sum = 0;
    char str[1001];

    scanf("%d ",&n);
    while (n--)
    {
        scanf("%s", str);
        len = strlen(str);

        for(i = 0; i < len; i++)
            sum += getLed (str[i]);

        printf("%d leds\n", sum);
        sum = 0;
    }
    return 0;
}
