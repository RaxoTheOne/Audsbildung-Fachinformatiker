#include <stdio.h>

int main()
{
    int punkte, note;

    printf("Bitte geben Sie die erreichten Punkte ein (0-100): ");
    scanf("%d", &punkte);

    if (punkte >= 91 && punkte <= 100)
    {
        note = 1;
    }
    else if (punkte >= 81)
    {
        note = 2;
    }
    else if (punkte >= 67)
    {
        note = 3;
    }
    else if (punkte >= 50)
    {
        note = 4;
    }
    else if (punkte >= 30)
    {
        note = 5;
    }
    else if (punkte = 0)
    {
        note = 6;
    }
    else
    {
        printf("Ungueltige Eingabe!\n");
        return 1;
    }
    printf("Die Schulnote ist: %d\n", note);

    return 0;
}