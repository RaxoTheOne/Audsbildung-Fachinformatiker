#include <stdlib.h>
#include <stdio.h>

int main()
{
    int ai[10];
    int i;
    int anzahl = sizeof(ai) / sizeof(int);
    int hilf;
    int getauscht;

    for (i = 0; i < anzahl; i++)
    {
        printf("%d, Zahl eingeben: ", i + 1);
        scanf("%d", &ai[i]);
    }

    getauscht = 1;

    while (getauscht == 1)
    {
        getauscht = 0;
        for (i = 0; i < anzahl - 1; i++)
        {
            if (ai[i] > ai[i + 1])
            {
                hilf = ai[i];
                ai[i] = ai[i + 1];
                ai[i + 1] = hilf;
                getauscht = 1; // <- HIER ist der Fix
            }
        }
    }

    printf("\nSortierte Zahlen:\n");
    for (i = 0; i < anzahl; i++)
    {
        printf("%d\n", ai[i]);
    }

    return 0;
}