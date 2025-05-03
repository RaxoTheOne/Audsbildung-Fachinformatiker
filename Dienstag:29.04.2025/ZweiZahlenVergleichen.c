#include <stdio.h>

int main()
{
    int zahl1, zahl2;

    printf("Gib die Erste Zahl ein: ");
    scanf("%d", &zahl1);

    printf("Gib die Zweite Zahl ein: ");
    scanf("%d", &zahl2);

    if (zahl1 == zahl2)
    {
        printf("Die Zahlen sind gleich.\n");
    }
    if (zahl1 != zahl2)
    {
        printf("Die Zahlen sind ungleich.\n");
    }
    if (zahl1 > zahl2)
    {
        printf("Die Erste Zahl ist groesser als die Zweite Zahl.");
    }
    if (zahl1 < zahl2)
    {
        printf("Die Erste Zahl ist kleiner als die Zweite Zahl.");
    }
    if (zahl1 >= zahl2)
    {
        printf("Die Erste Zahl ist groesser oder gleich der Zweiten Zahl");
    }
    if (zahl1 <= zahl2)
    {
        printf("Die Erste Zahl ist kleiner oder gleich der Zweiten Zahl");
    }

    return 0;
}