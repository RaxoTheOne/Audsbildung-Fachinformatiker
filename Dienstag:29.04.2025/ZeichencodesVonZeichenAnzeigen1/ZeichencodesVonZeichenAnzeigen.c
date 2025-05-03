#include <stdio.h>

int main() {
    unsigned char zeile[100];  // Pufferspeicher für die Eingabe
    int i = 0;

    printf("*** Zeichencodes von Zeichen anzeigen. ***\n\n");
    printf("Geben Sie die Zeichen in einer Zeile ein:\n");
    
    fgets((char *)zeile, sizeof(zeile), stdin);  // Liest die ganze Zeile inkl. Leerzeichen

    printf("\n    Zeichen  dezimal  hexadezimal  oktal\n");
    printf("----------------------------------------\n");

    while (zeile[i] != '\n' && zeile[i] != '\0') {
        printf("%2d.    %c      %4d        %02X        %03o\n", 
               i + 1, zeile[i], zeile[i], zeile[i], zeile[i]);
        i++;
    }

    return 0;
}
