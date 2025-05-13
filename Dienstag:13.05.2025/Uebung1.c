#include <stdio.h>
#include <stdlib.h>

void ausgabe(int *, int);

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    ausgabe(arr, sizeof(arr) / sizeof(int));

    return 0;
}

void ausgabe(int * ipoi, int anz){
    for(int i = 0; i < anz; i++){
        printf("%s", ipoi[i] % 2 ? "un" : "");
        printf("%s %d\n", "gerade", ipoi[i]);
    }
}