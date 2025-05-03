#include <stdio.h>

int main() {
    double d, h;
    const double PI = 3.141593;

    // Eingabe
    printf("Geben Sie den Durchmesser des Zylinders ein (in cm): ");
    scanf("%lf", &d);

    printf("Geben Sie die Hoehe des Zylinders ein (in cm): ");
    scanf("%lf", &h);

    // Berechnungen
    double mantelflaeche = PI * d * h;
    double volumen = PI * (d / 2) * (d / 2) * h;

    // Ausgabe
    printf("Mantelflaeche: %.2f cm²\n", mantelflaeche);
    printf("Volumen: %.2f cm³\n", volumen);

    return 0;
}
