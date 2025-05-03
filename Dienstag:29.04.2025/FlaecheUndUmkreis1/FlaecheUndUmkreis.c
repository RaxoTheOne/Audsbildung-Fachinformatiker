#include <stdio.h>
#include <math.h>

int main() {
    float s, area, radius;

    // Eingabe der Seitenlänge des Dreiecks
    printf("Geben Sie die Seitenlänge des gleichseitigen Dreiecks ein: ");
    scanf("%f", &s);

    // Berechnung der Fläche des gleichseitigen Dreiecks
    area = (s * s) / 4 * sqrt(3);

    // Berechnung des Radius des Umkreises
    radius = s / sqrt(3);

    // Ausgabe der Ergebnisse mit zwei Dezimalstellen
    printf("Fläche des gleichseitigen Dreiecks: %.2f\n", area);
    printf("Radius des Umkreises: %.2f\n", radius);

    return 0;
}
