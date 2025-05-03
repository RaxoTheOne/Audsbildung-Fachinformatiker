#include <stdio.h>

int main() {
    long zahl;

    printf("Geben Sie ganze Zahlen ein. Zum Beenden ein ungültiges Zeichen eingeben.\n");

    while (scanf("%ld", &zahl) == 1) {
        printf("Quadrat der Zahl %ld: %ld\n", zahl, zahl * zahl);
    }

    printf("Ungültige Eingabe erkannt. Programm beendet.\n");
    return 0;
}
