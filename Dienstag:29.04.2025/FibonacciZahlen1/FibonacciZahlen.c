#include <stdio.h>

int main() {
    int n = 30;  // Anzahl der Fibonacci-Zahlen
    unsigned long long fib[n];  // großer Typ für große Werte

    // Erste zwei Zahlen initialisieren
    fib[0] = 0;
    fib[1] = 1;

    // Berechnung ab dem 3. Element
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Ausgabe der Zahlen
    printf("Die ersten %d Fibonacci-Zahlen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%2d. %llu\n", i + 1, fib[i]);
        if((i + 1) % 5 == 0)
        printf("\n");
    }

    return 0;
}
