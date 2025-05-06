#include <stdio.h>
#include <stdlib.h>

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
        fflush(stdin);
        do
        {
            printf("\nProduktname:");
            gets(produkname);

            if (strcmp(produkname, "ende") == 0)
            {

                fclose(d);
                break;
            }
            fprintf(d, "%s", produkname);

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
        while (fgets(puffer, sizeof(puffer), d) != NULL)
            ;

        //

        printf("- %s\n", puffer);
    }
}
