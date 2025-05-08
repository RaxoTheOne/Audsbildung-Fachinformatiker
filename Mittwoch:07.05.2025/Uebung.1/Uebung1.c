#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct devisen
{
    char land[50];
    char wechselkuerzel[4];
    float kurs;
    float euroBetrag;
    float umgerechneterBetrag;
};
typedef struct devisen Devisen;

int main()
{

    Devisen d;
    char eingabe[30];
    char datname[] = "devisen.csv";
    FILE *fp;

    printf("Gib das Land ein: ");
    fgets(d.land, sizeof(d.land), stdin);
    d.land[strcspn(d.land, "\n")] = 0;

    printf("Gib das Wechselkürzel ein: ");
    fgets(d.wechselkuerzel, sizeof(d.wechselkuerzel), stdin);
    d.wechselkuerzel[strcspn(d.wechselkuerzel, "\n")] = 0;

    printf("Gib den Kurs ein: ");
    fpurge(stdin);
    scanf("%f", &d.kurs);

    printf("Gib den Betrag in Euro ein: ");
    scanf("%f", &d.euroBetrag);

    d.umgerechneterBetrag = d.kurs * d.euroBetrag;

    if ((fp = fopen(datname, "a")) != NULL)
    {
        fwrite(&d, sizeof(Devisen), 1, fp);

        fclose(fp);
    }
    else
    {
        printf("Datei konnte nicht geöffnet werden!\n");
        return 1;
    }
    if ((fp = fopen(datname, "r")) != 0)
    {
        while ((fread(&d, sizeof(Devisen), 1, fp)) == 1)
        {
            printf("Land: %s\n", d.land);
            printf("Wechselkürzel: %s\n", d.wechselkuerzel);
            printf("Kurs: %.2f\n", d.kurs);
            printf("Euro-Betrag: %.2f\n", d.euroBetrag);
            printf("Umgerechneter Betrag: %.2f\n", d.umgerechneterBetrag);
        }
        fclose(fp);
    }else
    {
        printf("Datei konnte nicht geöffnet werden!\n");
        return 1;
    }
    printf("Die Datei wurde erfolgreich geschrieben und gelesen.\n");
}