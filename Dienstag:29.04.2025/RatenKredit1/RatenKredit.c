#include <stdio.h>
#include <math.h>

int main() {
    double kredit, zinssatz, rate;
    int laufzeit;
    double q;

    // Eingabe der Daten
    printf("*** Berechnung der monatlichen Raten eines Kredits ***\n\n");
    printf("Geben Sie folgende Werte ein.\n");

    printf("Hoehe des Kredits: ");
    scanf("%lf", &kredit);

    printf("Jaehrlicher Zinssatz: ");
    scanf("%lf", &zinssatz);

    printf("Laufzeit in Monaten: ");
    scanf("%d", &laufzeit);

    // Berechnung von q (1 + Zinssatz / 100 / 12)
    q = 1 + (zinssatz / 100) / 12;

    // Berechnung der monatlichen Rate mit der gegebenen Formel
    rate = kredit * q * pow(q, laufzeit) * (q - 1) / (pow(q, laufzeit) - 1);

    // Ausgabe der monatlichen Rate
    printf("\nDie monatliche Rate fuer diesen Kredit: %.2f\n", rate);

    return 0;
}
