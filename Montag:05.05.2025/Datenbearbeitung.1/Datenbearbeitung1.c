#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *datei;
    datei = fopen("test2.txt", "a");

    if (datei == NULL)
    {
        printf("Datei kann nicht geoeffnet werden.");
        return (-1);
    }

    // Schreiben die Datei  fprint
    fprintf(datei, "dfgdfgdfgdfgdfgdg 5");
    fclose(datei);

    FILE *datei_lessen;
    datei_lessen = fopen("test2.txt", "r");

    if (datei_lessen == NULL)
    {
        printf("Datei kann nicht geoeffnet werden.");
        return (-1);
    }

    // Array fuer Datei zu speichern
    char datei_arr[200];
    // Lesen wir die Datei
    while (feof(datei_lessen) == 0)
    {
        fgets(datei_arr, sizeof(datei_arr), datei_lessen);
        printf("%s", datei_arr);
    }

    fclose(datei_lessen);
}
