#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Zeiger auf char
    // char *p = "Hallo Du Geile Sau"; // Zeiger auf String
    char str[] = "Hallo Du Geile Sau";
    char *p; // Zeiger auf String
    printf("Adresse von String %p Inhalt %s\n", str, str);
    /*
    char *p = str;
    printf("Zeigt auf Adresse %p Inhalt %s\n", p, p);

    p++ ; // Zeiger um 1 erhöhen
    printf("Zeigt auf Adresse %p Inhalt %s\n", p, p);
    
    *p += 1; // Zeiger auf Adresse, Wert um 1 erhöhen
    printf("Zeigt auf Adresse %p Inhalt %s\n", p, p);*/
    /*for(p = str; *p != '\0'; p++)
    {
        printf("Zeigt auf Adresse %p Inhalt %c\n", p, *p);
    }*/
    // Zeiger auf int
   for(p = str; *p != '\0'; p++, (*p)++)
    {
        printf("Zeigt auf Adresse %p Inhalt %c\n", p, *p);
    }
    
    return 0;
}