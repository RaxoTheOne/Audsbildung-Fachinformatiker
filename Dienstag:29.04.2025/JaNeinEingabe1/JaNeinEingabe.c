#include <stdio.h>

int main() {
    char antwort;

    printf("Geben Sie 'j' für Ja oder 'n' für Nein ein.\n");

    while (1) {
        scanf(" %c", &antwort);  // Achten Sie darauf, dass ein Leerzeichen vor %c ist, um Eingabepuffer zu leeren

        if (antwort == 'j' || antwort == 'n') {
            break;  // Schleife verlassen, wenn 'j' oder 'n' eingegeben wird
        } else {
            printf("Ungültige Eingabe. Bitte 'j' oder 'n' eingeben.\n");
        }
    }

    printf("Eingabe abgeschlossen: %c\n", antwort);
    return 0;
}
