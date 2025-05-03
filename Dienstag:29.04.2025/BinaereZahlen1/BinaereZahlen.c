#include <stdio.h>
#include <ctype.h>  // Für die Funktion isspace()

int main() {
    char ch;
    long long decimal = 0;  // Dezimaler Wert der binären Zahl
    int bit;

    printf("Geben Sie eine binäre Zahl ein (nur 0 und 1, führende Leerzeichen werden ignoriert):\n");

    while ((ch = getchar()) != '\n') {  // Liest Zeichen bis zum Zeilenumbruch
        if (isspace(ch)) {
            continue;  // Wenn das Zeichen ein Leerzeichen ist, überspringen
        }

        if (ch == '0' || ch == '1') {
            bit = ch - '0';  // Umwandlung des Charakters '0' oder '1' in die entsprechende Zahl 0 oder 1
            decimal = decimal * 2 + bit;  // Dezimalwert berechnen
        } else {
            printf("Ungültiges Zeichen '%c' erkannt. Nur 0 oder 1 sind erlaubt.\n", ch);
            return 1;  // Fehler, falls ein anderes Zeichen als 0 oder 1 eingegeben wird
        }
    }

    printf("Der Dezimalwert der eingegebenen binären Zahl ist: %lld\n", decimal);

    return 0;
}
