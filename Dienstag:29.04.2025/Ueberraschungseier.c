#include <stdio.h>

int main(){
    int kinder;
    int eier;
    int eierProKind;
    int rest;

    printf("Anzahl der Kinder: ");
    scanf("%d", &kinder);

    printf("Anzahl der Überraschungseier: ");
    scanf("%d", &eier);

    eierProKind = eier / kinder;
    rest = eier % kinder;

    printf("Jedes Kind bekommt %d Ei(er).\n", eierProKind);
    printf("Uebrig gebliebene Eier: %d\n", rest);

    return 0;
}