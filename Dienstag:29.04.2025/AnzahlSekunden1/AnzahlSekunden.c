#include <stdio.h>

int main() {
    int gesamtSekunden;
    int tage, stunden, minuten, sekunden;

    // Eingabe der Gesamtanzahl an Sekunden
    printf("Geben Sie die Anzahl der Sekunden ein: ");
    scanf("%d", &gesamtSekunden);

    // Berechnung
    tage     = gesamtSekunden / (24 * 3600);
    gesamtSekunden %= (24 * 3600);

    stunden  = gesamtSekunden / 3600;
    gesamtSekunden %= 3600;

    minuten  = gesamtSekunden / 60;
    sekunden = gesamtSekunden % 60;

    // Ausgabe
    printf("\nDas entspricht:\n");
    printf("%d Tage, %d Stunden, %d Minuten, %d Sekunden\n", tage, stunden, minuten, sekunden);

    return 0;
}
