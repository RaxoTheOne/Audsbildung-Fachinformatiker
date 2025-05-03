#include <stdio.h>

int main() {
    float temperature, celsius, fahrenheit;
    int choice;

    // Menü für den Benutzer
    printf("Wählen Sie die Umrechnung:\n");
    printf("1. Fahrenheit in Celsius\n");
    printf("2. Celsius in Fahrenheit\n");
    printf("Ihre Wahl (1 oder 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Fahrenheit in Celsius umrechnen
        printf("Geben Sie die Temperatur in Fahrenheit ein: ");
        scanf("%f", &temperature);
        celsius = 5.0 / 9.0 * (temperature - 32);
        printf("%.1f Fahrenheit sind %.1f Celsius\n", temperature, celsius);
    } else if (choice == 2) {
        // Celsius in Fahrenheit umrechnen
        printf("Geben Sie die Temperatur in Celsius ein: ");
        scanf("%f", &temperature);
        fahrenheit = 9.0 / 5.0 * temperature + 32;
        printf("%.1f Celsius sind %.1f Fahrenheit\n", temperature, fahrenheit);
    } else {
        printf("Ungültige Wahl! Bitte wählen Sie 1 oder 2.\n");
    }

    return 0;
}
