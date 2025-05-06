#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fahrzeug
{
    int baujahr;
    char hersteller[30];
    char modell[30];
    float höchstgeschwindigkeit;
};
typedef struct fahrzeug Fahrzeug;
int main()
{

    Fahrzeug f;
    char eingabe[20];
    char datname[] = "auto.dat";
    FILE *fp;

    printf("Hersteller: ");
    fgets(f.hersteller, sizeof(f.hersteller), stdin);
    f.hersteller[strcspn(f.hersteller, "\n")] = 0;

    printf("Modell: ");
    fgets(f.modell, sizeof(f.modell), stdin);
    f.modell[strcspn(f.modell, "\n")] = 0;

    printf("Baujahr: ");
    fgets(eingabe, sizeof(eingabe), stdin);
    f.baujahr = atoi(eingabe);

    printf("Höchstgeschwindigkeit: ");
    fgets(eingabe, sizeof(eingabe), stdin);
    f.höchstgeschwindigkeit = atof(eingabe);

    if ((fp = fopen(datname, "w")) != NULL)
    {
        fwrite(&f, sizeof(Fahrzeug), 1, fp);

        fclose(fp);
    }
    else
    {
        printf("Datei konnte nicht geöffnet werden.\n");
        return 1;
    }
    int zaehler = 0;
    if ((fp = fopen(datname, "r")) != NULL)
    {
        while((fread(&f, sizeof(Fahrzeug), 1, fp)) ==1)
            printf("\n%s %s %d %.2f\n", f.hersteller, f.modell, f.baujahr, f.höchstgeschwindigkeit);

        fclose(fp);
    }
    return 0;
}