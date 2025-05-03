#include <stdio.h>

int main() {
    double a, b, c;

    // Eingabe der Werte
    printf("Geben Sie drei Zahlen ein:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    printf("\n--- Ergebnisse ---\n");

    // 1. Quadrat von b > 4 * a * c
    if (b * b > 4 * a * c) {
        printf("1. Das Quadrat von b ist größer als das Vierfache des Produkts von a und c.\n");
    } else {
        printf("1. Bedingung NICHT erfüllt.\n");
    }

    // 2. b liegt echt zwischen a und c
    if ((a < b && b < c) || (c < b && b < a)) {
        printf("2. b liegt echt zwischen a und c.\n");
    } else {
        printf("2. Bedingung NICHT erfüllt.\n");
    }

    // 3. b != 0 && a / b > c
    if (b != 0 && (a / b) > c) {
        printf("3. b ist nicht null und a / b ist größer als c.\n");
    } else {
        printf("3. Bedingung NICHT erfüllt.\n");
    }

    // 4. (b - a) <= (c - b)
    if ((b - a) <= (c - b)) {
        printf("4. Die Differenz b - a ist nicht größer als c - b.\n");
    } else {
        printf("4. Bedingung NICHT erfüllt.\n");
    }

    // 5. Genau einer von a oder b ist kleiner als c
    if ((a < c) != (b < c)) {
        printf("5. Genau einer von a oder b ist kleiner als c.\n");
    } else {
        printf("5. Bedingung NICHT erfüllt.\n");
    }

    return 0;
}
