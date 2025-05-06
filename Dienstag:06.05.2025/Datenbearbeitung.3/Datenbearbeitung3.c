#include <stdio.h>
#include <stdlib.h>

struct person
{
    char nachname[30];
    char vorname[30];
    int alter;
};
typedef struct person Person;

int main()
{
    Person p;
    char hilf[20];
    FILE * fp;
    char datname[] = "/Users/benjamingayda-knop/Audsbildung Fachinformatiker /Dienstag:06.05.2025/Datenbearbeitung.3/person.dat";

    printf("Vorname: ");
    gets(p.vorname);
    printf("Nachname: ");
    gets(p.nachname);
    printf("Alter: ");
    // scanf("%d", &p.alter);
    gets(hilf);
    p.alter = atoi(hilf);

    if ((fp = fopen(datname, "w")) != NULL)
    {
        fwrite(&p, sizeof(Person), 1, fp);

        fclose(fp);
    }
    if ((fp = fopen(datname, "r")) != NULL)
    {
        fread(&p, sizeof(Person), 1, fp);

        fclose(fp);
    }
    printf("\n%s %s %d\n", p.vorname, p.nachname, p.alter);
    return 0;
}