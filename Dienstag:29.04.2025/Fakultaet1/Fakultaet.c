#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    unsigned long long fakultaet = 1; // große Datentypwahl für große Fakultätswerte
    char zeichen;

    printf("Bitte geben Sie eine positive ganze Zahl ein: ");

    // Eingabeprüfung: scanf gibt 1 zurück, wenn eine gültige ganze Zahl gelesen wurde
    if (scanf("%d%c", &n, &zeichen) != 2 || zeichen != '\n') {
        printf("Fehler: Keine gültige ganze Zahl eingegeben.\n");
        return 1;
    }

    if (n < 0) {
        printf("Fehler: Die Zahl darf nicht negativ sein.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        fakultaet *= i;
    }

    printf("Die Fakultät von %d ist: %llu\n", n, fakultaet);
    return 0;
}
