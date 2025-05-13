#include <stdio.h>
#include <stdlib.h>

void ausgabe(int *, int);
void ausgabe2(int *, int);

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    ausgabe(arr, sizeof(arr) / sizeof(int));
    ausgabe2(arr, sizeof(arr) / sizeof(int));

    return 0;
}

void ausgabe(int * ipoi, int anz){
    for(int i = 0; i < anz; i++){
        printf("%s", ipoi[i] % 2 ? "un" : "");
        printf("%s %d\n", "gerade", ipoi[i]);
    }
}

void ausgabe2(int * ipoi, int anz){
    for(int *poi = ipoi; poi < ipoi + anz; poi++){
        printf("%d %s%s\n", *poi, *poi % 2 ? "un" : "", "gerade");   
    }
}