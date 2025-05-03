#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// 1. Liefert den mittleren Wert von drei double-Werten
double median3(double a, double b, double c) {
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}

// 2. Schreibt die aktuelle Zeit und den Status in eine Protokolldatei
void logStatus() {
    FILE *file = fopen("log.txt", "a");
    if (file != NULL) {
        time_t now = time(NULL);
        char *zeit = ctime(&now);
        fprintf(file, "[%s] Programmstatus: OK\n", zeit);
        fclose(file);
    }
}

// 3. Berechnet die Steigung einer Geraden durch zwei Punkte
double geradesteigung(double x1, double y1, double x2, double y2) {
    if (x2 - x1 == 0) {
        fprintf(stderr, "Fehler: Division durch Null (x1 == x2)\n");
        return INFINITY;
    }
    return (y2 - y1) / (x2 - x1);
}

// 4. Berechnet den größten gemeinsamen Teiler (ggT)
int ggt(int a, int b) {
    if (b == 0) return abs(a);
    return ggt(b, a % b);
}

// 5. Berechnet die Summe einer geometrischen Reihe q^0 + q^1 + ... + q^n
double geomReihe(double q, int n) {
    double summe = 0.0;
    for (int i = 0; i <= n; i++) {
        summe += pow(q, i);
    }
    return summe;
}

// 6. Initialisiert die Anwendung, gibt true bei Erfolg zurück
bool InitApplication() {
    printf("Anwendung wird initialisiert...\n");
    return true;
}

// Hauptprogramm zur Demonstration
int main() {
    if (!InitApplication()) {
        printf("Initialisierung fehlgeschlagen.\n");
        return 1;
    }

    logStatus();

    // Median3 Beispiel
    double a = 5.3, b = 2.1, c = 7.8;
    printf("Median von %.2f, %.2f, %.2f ist %.2f\n", a, b, c, median3(a, b, c));

    // Geradesteigung Beispiel
    double x1 = 1.0, y1 = 2.0, x2 = 4.0, y2 = 5.0;
    printf("Steigung der Geraden durch (%.1f, %.1f) und (%.1f, %.1f): %.2f\n",
           x1, y1, x2, y2, geradesteigung(x1, y1, x2, y2));

    // GGT Beispiel
    int zahl1 = 36, zahl2 = 60;
    printf("GGT von %d und %d ist %d\n", zahl1, zahl2, ggt(zahl1, zahl2));

    // Geometrische Reihe Beispiel
    double q = 0.5;
    int n = 5;
    printf("Summe der geometrischen Reihe mit q=%.2f bis n=%d: %.5f\n", q, n, geomReihe(q, n));

    return 0;
}
