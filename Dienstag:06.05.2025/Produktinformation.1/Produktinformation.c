#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funktion zum Speichern eines Produkts in die Datei
void produkt_speichern() {
    char produktname[50];
    float preis;
    FILE *fp = fopen("produkte.txt", "a"); // Datei im Anhänge-Modus öffnen

    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return;
    }

    printf("Produktname: ");
    fgets(produktname, sizeof(produktname), stdin);
    produktname[strcspn(produktname, "\n")] = 0; // Entfernt das '\n'

    printf("Preis: ");
    scanf("%f", &preis);
    // Eingabepuffer leeren nach scanf

    fprintf(fp, "%s %.2f\n", produktname, preis); // Speichert Produktname und Preis in Datei
    fclose(fp);
    printf("Produkt gespeichert!\n");
}

// Funktion zum Anzeigen aller gespeicherten Produkte
void produkte_anzeigen() {
    char zeile[100];
    FILE *fp = fopen("produkte.txt", "r"); // Datei im Lese-Modus öffnen

    if (fp == NULL) {
        printf("Keine gespeicherten Produkte gefunden!\n");
        return;
    }

    printf("\nGespeicherte Produkte:\n");

    while (fgets(zeile, sizeof(zeile), fp)) {
        printf("%s", zeile); // Gibt Produktinformationen aus
    }

    fclose(fp);
}

// Hauptmenü und Steuerung des Programms
int main() {
    int auswahl;

    while (1) {
        printf("\nMenü:\n");
        printf("1. Produkt speichern\n");
        printf("2. Produkte anzeigen\n");
        printf("3. Beenden\n");
        printf("Wähle eine Option: ");

        scanf("%d", &auswahl);
        getchar(); // WICHTIG! Eingabepuffer nach scanf leeren

        switch (auswahl) {
            case 1:
                produkt_speichern();
                break;
            case 2:
                produkte_anzeigen();
                break;
            case 3:
                printf("Programm beendet.\n");
                return 0;
            default:
                printf("Ungültige Auswahl, bitte erneut versuchen.\n");
        }
    }

    return 0;
}
