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
    menue();
    printf("\nIhre Auswahl:");
    scanf("%d", &auswahl);

    switch (auswahl)
    {
    case 1:
        produkte_hinzufuegen(produktdatei);
        break;
    case 2:
        produkte_listen(produktdatei);
        break;
    }

    //
}

void menue()
{

    printf("1. Produkte Hinzufuegen\n");
    printf("2. Produkte lesen\n");
    printf("3. Ende");
}

void produkte_hinzufuegen(char *dateiname)
{

    FILE *d = fopen(dateiname, "a");

    if (d != NULL)
    {
        char produkname[30];
        int preis;
        do
        {
            printf("\nProduktname:");
            fpurge(stdin);
            gets(produkname);

            if (strcmp(produkname, "ende") == 0)
            {

                fclose(d);
                break;
            }
            printf("Preis:");
            scanf("%d", &preis);

            fprintf(d, "%s", produkname);
            fprintf(d, "%d\n", preis);

        } while (strcmp(produkname, "ende") != 0);
    }
}

void produkte_listen(char *dateiname)
{
    FILE *d = fopen(dateiname, "r");

    if (d != NULL)
    {

        printf("Die gespeicherten Produkte:\n");
        char puffer[200];
        int preispuffer;

        while (fgets(puffer, sizeof(puffer), d) != NULL)
            ;

        //
        puffer[strlen(puffer)-1] = '\0';
        if (fscanf(d, "%d", &preispuffer) == 1)
        {
            printf("- %s Preis: %d\n", puffer, preispuffer);
        }
    }
}