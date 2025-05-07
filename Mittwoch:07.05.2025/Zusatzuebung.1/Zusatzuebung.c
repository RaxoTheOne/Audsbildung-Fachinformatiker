#include <stdio.h>
#include <string.h>

void passwortVerschluesseln(char eingabe[], char verschluesselt[])
{
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        verschluesselt[i] = eingabe[i] + 1;
    }
    verschluesselt[strlen(eingabe)] = '\0';
}
void passwortEntschluesseln(char eingabe[], char entschluesselt[])
{
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        entschluesselt[i] = eingabe[i] - 1;
    }
    entschluesselt[strlen(eingabe)] = '\0';
}

int main()
{
    char benutzername[50];
    char passwort[50];
    char verschluesselt[50];
    char entschluesselt[50];

    printf("Benutzernamen eingeben: ");
    fgets(benutzername, sizeof(benutzername), stdin);
    benutzername[strcspn(benutzername, "\n")] = '\0';

    printf("Passwort eingeben: ");
    fgets(passwort, sizeof(passwort), stdin);
    passwort[strcspn(passwort, "\n")] = '\0';

    passwortVerschluesseln(passwort, verschluesselt);
    printf("Verschlüsseltes Passwort: %s\n", verschluesselt);

    passwortEntschluesseln(verschluesselt, entschluesselt);
    printf("Entschlüsseltes Passwort: %s\n", entschluesselt);

    return 0;
}