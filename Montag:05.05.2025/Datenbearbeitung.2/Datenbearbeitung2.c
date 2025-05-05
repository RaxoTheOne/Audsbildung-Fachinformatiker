#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menue();

void produkte_hinzufuegen(char *);
void produkte_listen(char *);

char produktdatei[] = "produkte.txt";
int auswahl;

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
            printf("Programm wird beendet.\n");
            exit(0);
        default:
            printf("Ungueltige Auswahl.\n");
        }

    } while (1);

    return 0;
}

void menue()
{
    printf("\n--- Produktverwaltung ---\n");
    printf("1. Produkte Hinzufuegen\n");
    printf("2. Produkte Anzeigen\n");
    printf("3. Ende\n");
}

void produkte_hinzufuegen(char *dateiname)
{
    FILE *d = fopen(dateiname, "a");

    if (d != NULL)
    {
        char produktname[100];
        do
        {
            printf("Produktname (\"ende\" zum Beenden): ");
            fgets(produktname, sizeof(produktname), stdin);

            // Zeilenumbruch entfernen
            size_t len = strlen(produktname);
            if (len > 0 && produktname[len - 1] == '\n')
            {
                produktname[len - 1] = '\0';
            }

            if (strcmp(produktname, "ende") == 0)
            {
                break;
            }

            fprintf(d, "%s\n", produktname);

        } while (1);

        fclose(d);
    }
    else
    {
        printf("Fehler beim Öffnen der Datei.\n");
    }
}

void produkte_listen(char *dateiname)
{
    FILE *d = fopen(dateiname, "r");

    if (d != NULL)
    {
        char zeile[100];
        printf("\n--- Produktliste ---\n");

        while (fgets(zeile, sizeof(zeile), d) != NULL)
        {
            printf("%s", zeile);
        }

        fclose(d);
    }
    else
    {
        printf("Fehler beim Öffnen der Datei.\n");
    }
}
