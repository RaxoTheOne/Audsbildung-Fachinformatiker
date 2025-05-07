#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menue();
void produkte_hinzufuegen(char *);
void produkte_listen(char *);
void produkte_suchen(char *);

char produktdatei[] = "produkte.txt";
int auswahl;

struct produkt
{
    char produktname[50];
    int artikelnummer;
    float preis;
};
typedef struct produkt Produkt;

int main()
{
    do
    {
        menue();
        printf("\nIhre Auswahl: ");
        scanf("%d", &auswahl);
        getchar(); // Puffer leeren (nach scanf)

        switch (auswahl)
        {
        case 1:
            produkte_hinzufuegen(produktdatei);
            break;
        case 2:
            produkte_listen(produktdatei);
            break;
        case 3:
            produkte_suchen(produktdatei);
            break;
        case 4:
            printf("Programm wird beendet.\n");
            exit(0);
        default:
            printf("Ungueltige Auswahl.\n");
        }

    } while (1);

    return 0;
}

void menue(void)
{
    printf("\n--- Produktverwaltung ---\n");
    printf("1. Produkte Hinzufuegen\n");
    printf("2. Produkte Anzeigen\n");
    printf("3. Produkt suchen\n");
    printf("4. Ende\n");
}
void such_menue(void)
{
}
void produkte_hinzufuegen(char *dateiname)
{
    FILE *d = fopen(dateiname, "a");
    if (d == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }

    Produkt p;
    int letzteNummer = 0;

    // Letzte Artikelnummer ermitteln
    FILE *lesen = fopen(dateiname, "r");
    if (lesen != NULL)
    {
        char zeile[200];
        while (fgets(zeile, sizeof(zeile), lesen) != NULL)
        {
            int nummer;
            if (sscanf(zeile, "%d;", &nummer) == 1)
            {
                if (nummer > letzteNummer)
                    letzteNummer = nummer;
            }
        }
        fclose(lesen);
    }

    while (1)
    {
        char eingabe[100];

        printf("Produktname (\"ende\" zum Beenden): ");
        fgets(p.produktname, sizeof(p.produktname), stdin);
        p.produktname[strcspn(p.produktname, "\n")] = 0;

        if (strcmp(p.produktname, "ende") == 0)
            break;

        printf("Preis: ");
        fgets(eingabe, sizeof(eingabe), stdin);
        p.preis = atof(eingabe);

        p.artikelnummer = ++letzteNummer;

        fprintf(d, "%d;%s;%.2f\n", p.artikelnummer, p.produktname, p.preis);
        printf("Produkt gespeichert.\n");
    }

    fclose(d);
}

void produkte_listen(char *dateiname)
{
    FILE *d = fopen(dateiname, "r");
    if (d == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }

    Produkt p;
    char zeile[200];
    printf("\n--- Produktliste ---\n");
    while (fgets(zeile, sizeof(zeile), d) != NULL)
    {
        if (sscanf(zeile, "%d;%49[^;];%f", &p.artikelnummer, p.produktname, &p.preis) == 3)
        {
            printf("Nr: %d | Name: %s | Preis: %.2f €\n", p.artikelnummer, p.produktname, p.preis);
        }
        else
        {
            printf("Fehler beim Lesen der Datei.\n");
        }
    }

    fclose(d);
}

void produkte_suchen(char *dateiname)
{
    FILE *d = fopen(dateiname, "r");
    if (d == NULL)
    {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }

    int kriterium;
    printf("\n---Suchkriterium:---\n");
    printf("1. Artikelnummer\n");
    printf("2. Produktname\n");
    printf("3. Preisspanne\n");
    printf("Ihre Wahl: ");
    scanf("%d", &kriterium);
    fpurge(stdin);

    char zeile[200];
    Produkt p;
    int gefunden = 0;

    if (kriterium == 1) // Artikelnummer
    {
        int suchnummer;
        printf("Gib die Artikelnummer ein: ");
        scanf("%d", &suchnummer);

        while (fgets(zeile, sizeof(zeile), d) != NULL)
        {
            if (sscanf(zeile, "%d;%49[^;];%f", &p.artikelnummer, p.produktname, &p.preis) == 3)
            {
                if (p.artikelnummer == suchnummer)
                {
                    printf("Nr: %d | Name: %s | Preis: %.2f €\n", p.artikelnummer, p.produktname, p.preis);
                    gefunden = 1;
                }
            }
        }
    }
    else if (kriterium == 2) // Produktname
    {
        char suchbegriff[50];
        printf("Gib den Produktnamen oder ein Teil davon ein: ");
        fgets(suchbegriff, sizeof(suchbegriff), stdin);
        suchbegriff[strcspn(suchbegriff, "\n")] = 0;

        printf("\n--- Suchergebnisse ---\n");

        while (fgets(zeile, sizeof(zeile), d) != NULL)
        {
            if (sscanf(zeile, "%d;%49[^;];%f", &p.artikelnummer, p.produktname, &p.preis) == 3)
            {
                if (strstr(p.produktname, suchbegriff) != NULL)
                {
                    printf("Nr: %d | Name: %s | Preis: %.2f €\n", p.artikelnummer, p.produktname, p.preis);
                    gefunden = 1;
                }
            }
        }
    }
    else if (kriterium == 3) // Preisspanne
    {
        float preismin, preismax;
        printf("Gib den Mindestpreis ein: ");
        scanf("%f", &preismin);
        printf("Gib den Maximalpreis ein: ");
        scanf("%f", &preismax);
        getchar();
        while (fgets(zeile, sizeof(zeile), d) != NULL)
        {
            if (sscanf(zeile, "%d;%49[^;];%f", &p.artikelnummer, p.produktname, &p.preis) == 3)
            {
                if (p.preis >= preismin && p.preis <= preismax)
                {
                    printf("Nr: %d | Name: %s | Preis: %.2f €\n", p.artikelnummer, p.produktname, p.preis);
                    gefunden = 1;
                }
            }
        }
    }
    else
    {
        printf("Ungültige Auswahl!\n");
        fclose(d);
        return;
    }
    if (!gefunden)
    {
        printf("Kein passendes Produkt gefunden!\n");
    }

    fclose(d);
}
