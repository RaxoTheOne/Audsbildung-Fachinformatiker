#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;

    int *p = &a;

    printf("Wert: %d Adresse: %p\n", a, &a);
    printf("Wert: %d zeigt auf Speicherplatz %p eigene Adresse %p\n", *p, p, &p);

    a = 10;
    printf("Wert: %d Adresse: %p\n", a, &a);
    printf("Wert: %d zeigt auf Speicherplatz %p eigene Adresse %p\n", *p, p, &p);

    *p = 25;
    printf("Wert: %d Adresse: %p\n", a, &a);
    printf("Wert: %d zeigt auf Speicherplatz %p eigene Adresse %p\n", *p, p, &p);

    p++;
    printf("Wert: %d Adresse: %p\n", a, &a);
    printf("Wert: %d zeigt auf Speicherplatz %p eigene Adresse %p\n", *p, p, &p);
    return 0;
}