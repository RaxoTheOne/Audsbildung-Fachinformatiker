#include <stdio.h>

int main(){
    int zahl;

    printf("Gib eine ganze Zahl ein: ");
    scanf("%d", &zahl);

    if((zahl % 2 == 0) && (zahl > 10)){
        printf("Die Zahl ist gerade und groesser als 10.\n");
    }
    if((zahl % 2 != 0) || (zahl < 0)){
        printf("Die Zahl ist ungerade oder kleiner als 0.\n");
    }
    return 0;
}