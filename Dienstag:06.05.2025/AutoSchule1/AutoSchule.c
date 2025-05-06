#include <stdio.h>
#include <stdlib.h>

struct car
{
   char fabrikat[30];
   char modell[30];
   int baujahr;
   int hg;
};
typedef struct car Car;

int main()
{
    Car Auto;

    char hilf[20];
    FILE *fp;
    char datname[] = "C:\\Mist\\auto.dat";

    printf("Fabrikat: ");
    gets(Auto.fabrikat);
    printf("Modell: ");
    gets(Auto.modell);
    printf("Baujahr: ");

    gets(hilf);
    Auto.baujahr = atoi(hilf);

    printf("Hoechstgeschwindigkeit: ");

    gets(hilf);
    Auto.hg = atoi(hilf);

    if( ( fp = fopen(datname, "a")) != NULL )
    {
        fwrite(&Auto, sizeof(Auto), 1, fp);

        fclose( fp );
    }
    int zaehler= 0;

    if( ( fp = fopen(datname, "r")) != NULL )
    {
        while( (fread(&Auto, sizeof(Auto), 1, fp)) == 1 )
        {
            printf("\n%s %s %d %d\n",
                Auto.fabrikat, Auto.modell, Auto.baujahr, Auto.hg);
                zaehler++;
        }

    printf("%d Autos erfasst\n", zaehler);

        fclose( fp );
    }

    return 0;
}