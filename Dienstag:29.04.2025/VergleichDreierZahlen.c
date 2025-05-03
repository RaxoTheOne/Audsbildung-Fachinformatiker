#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Gib die erste Zahl ein: ");
    scanf("%d", &a);

    printf("Gib die zweite Zahl ein: ");
    scanf("%d", &b);

    printf("Gib die dritte Zahl ein: ");
    scanf("%d", &c);

    if (a > b && a > c) {
        printf("Die erste Zahl (%d) ist die groesste.\n", a);
    } else if (b > a && b > c) {
        printf("Die zweite Zahl (%d) ist die groesste.\n", b);
    } else if (c > a && c > b) {
        printf("Die dritte Zahl (%d) ist die groesste.\n", c);
    } else if (a == b && b == c) {
        printf("Alle drei Zahlen sind gleich gross.\n");
    } else if (a == b && a > c) {
        printf("Die erste und zweite Zahl sind gleich gross und groesster als die dritte.\n");
    } else if (a == c && a > b) {
        printf("Die erste und dritte Zahl sind gleich gross und groesster als die zweite.\n");
    } else if (b == c && b > a) {
        printf("Die zweite und dritte Zahl sind gleich gross und groesster als die erste.\n");
    } else {
        printf("Es gibt keinen eindeutigen groessten Wert.\n");
    }
    
    return 0;
}