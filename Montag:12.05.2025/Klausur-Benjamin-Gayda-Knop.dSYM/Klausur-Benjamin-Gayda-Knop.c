#include <stdio.h>
#include <string.h>

// Strukturdefinition
struct Firma {
    char name[66];     // 65 + 1 für '\0'
    char ort[66];      // 65 + 1 für '\0'
    int gruendungsjahr;
    float umsatz;
};

// Funktionsprototypen
int VonBis();
int countCapitals(const char *text);
void eingabeFirma(struct Firma *f);
void writeStruct(struct Firma f);

int main() {
    // Aufgabe 2: VonBis()
    int summe = VonBis();
    printf("Die Summe der positiven Zahlen im Bereich ist: %d\n\n", summe);

    // Aufgabe 3: countCapitals()
    char text[100];
    printf("Bitte geben Sie einen Text ein: ");
    fgets(text, sizeof(text), stdin);
    int grossbuchstaben = countCapitals(text);
    printf("Anzahl der Großbuchstaben: %d\n\n", grossbuchstaben);

    // Aufgabe 4: struct Firma eingeben und anzeigen
    struct Firma firma;
    eingabeFirma(&firma);

    // Aufgabe 5: struct in Datei schreiben
    writeStruct(firma);

    return 0;
}

// Aufgabe 2: VonBis()
int VonBis() {
    int untergrenze, obergrenze, summe = 0;

    printf("Untergrenze: ");
    scanf("%d", &untergrenze);
    printf("Obergrenze: ");
    scanf("%d", &obergrenze);

    if (untergrenze > obergrenze) {
        int temp = untergrenze;
        untergrenze = obergrenze;
        obergrenze = temp;
    }

    for (int i = untergrenze; i <= obergrenze; i++) {
        printf("%d %s\n", i, (i % 2 == 0) ? "gerade" : "ungerade");
        if (i > 0) summe += i;
    }

    return summe;
}

// Aufgabe 3: countCapitals()
int countCapitals(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') count++;
    }
    return count;
}

// Aufgabe 4: Firma einlesen und anzeigen
void eingabeFirma(struct Firma *f) {
    while (getchar() != '\n'); // Eingabepuffer leeren nach scanf()

    printf("Firmenname: ");
    fgets(f->name, sizeof(f->name), stdin);
    f->name[strcspn(f->name, "\n")] = '\0'; // Zeilenumbruch entfernen

    printf("Firmenort: ");
    fgets(f->ort, sizeof(f->ort), stdin);
    f->ort[strcspn(f->ort, "\n")] = '\0';

    printf("Gründungsjahr: ");
    scanf("%d", &f->gruendungsjahr);

    printf("Umsatz (z.B. 999.45): ");
    scanf("%f", &f->umsatz);

    // Ausgabe
    printf("\n--- Firmendaten ---\n");
    printf("Name: %s\n", f->name);
    printf("Ort: %s\n", f->ort);
    printf("Gründungsjahr: %d\n", f->gruendungsjahr);
    printf("Umsatz: %.2f\n\n", f->umsatz);
}


// Aufgabe 5: writeStruct()
void writeStruct(struct Firma f) {
    FILE *datei = fopen("firmen.dat", "a"); // anhängen
    if (datei == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }

    fprintf(datei, "Name: %s\nOrt: %s\nJahr: %d\nUmsatz: %.2f\n---\n",
            f.name, f.ort, f.gruendungsjahr, f.umsatz);
    
    fclose(datei);
    printf("Daten wurden in 'firmen.dat' gespeichert.\n");
}
