#include <stdio.h>

int main() {
    int year;

    // Eingabe des Jahres
    printf("Geben Sie ein Jahr ein: ");
    scanf("%d", &year);

    // Überprüfung, ob es ein Schaltjahr ist
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d ist ein Schaltjahr.\n", year);
    } else {
        printf("%d ist kein Schaltjahr.\n", year);
    }

    return 0;
}

