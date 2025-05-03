#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int main()
{

    char text[100];
    int getauscht;
    int i;
    char hilf;

    printf("Gib ein Wort ein: ");
    // gets();
    gets(text);
    // scanf("%s", text);

    printf("%s", text);
    // Textlänge
    int anzahl = strlen(text);

    // Ausgabe Textlänge
    printf("Textleange: %d\n", anzahl);

    getauscht = -1;

    while (getauscht == -1)
    {
        getauscht = 0;
        for (i = 0; i < anzahl - 1; i++)
        {
            if (tolower(text[i]) > tolower(text[i + 1]))
            {   
                // Werte tauschen
                hilf = text[i];
                text[i] = text[i + 1];
                text[i + 1] = hilf;
                getauscht = -1; 
            }
        }
    }
    // Ausgabe des sortierten Textes
    printf("%s\n", text);
}