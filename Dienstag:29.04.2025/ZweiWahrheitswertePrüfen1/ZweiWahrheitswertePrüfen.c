#include <stdio.h>

int main() {
    int wahr1, wahr2;

    printf("Ist Aussage 1 wahr? (1 = ja, 0 = nein): ");
    scanf("%d", &wahr1);

    printf("Ist Aussage 2 wahr? (1 = ja, 0 = nein): ");
    scanf("%d", &wahr2);

    if (wahr1 && wahr2) {
        printf("Beide Aussagen sind wahr.\n");
    } else if (!wahr1 && !wahr2) {
        printf("Keine der Aussagen ist wahr.\n");
    } else {
        printf("Genau eine der Aussagen ist wahr.\n");
    }

    return 0;
}