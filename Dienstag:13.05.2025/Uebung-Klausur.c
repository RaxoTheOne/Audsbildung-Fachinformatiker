#include <stdio.h>
#include <stdlib.h>

int countCapitals(char *s);
int countCapitalsMitPoi(char *s);

int main()
{

    char str[] = "Hallo Welt";

    printf("%d Grossbuchstaben: ", countCapitals(str));
    printf("%d Grossbuchstaben: ", countCapitalsMitPoi(str));

    return 0;
}

int countCapitals(char *s)
{
    int anz = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            anz++;
        }
    }
    return anz;
}

int countCapitalsMitPoi(char *s)
{
    int anz;

    for (; *s != '\0'; s++)
    {
        if (*s >= 'A' && *s <= 'Z')
            ;
        anz++;
    }
    return anz;
}