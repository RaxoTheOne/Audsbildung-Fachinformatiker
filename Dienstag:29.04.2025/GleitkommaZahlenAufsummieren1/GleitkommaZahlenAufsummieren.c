#include <stdio.h>

int main() {
    double zahl, summe = 0.0;

    printf("Geben Sie positive Gleitpunktzahlen ein. Die Eingabe endet, wenn die Summe 100 überschreitet oder eine ungültige Zahl eingegeben wird.\n");

    while (scanf("%lf", &zahl) == 1) {
        if (zahl < 0) {
            printf("Ungültige Eingabe: Nur positive Zahlen sind erlaubt.\n");
            break;
        }

        summe += zahl;

        if (summe > 100) {
            printf("Die Summe hat 100 überschritten. Programm beendet.\n");
            break;
        }
    }

    printf("Summe der Zahlen: %.2f\n", summe);
    return 0;
}
