#include <stdio.h>
#include <stdlib.h>

int main(){
    int iarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pi = iarr;

    for( ; pi < iarr + (sizeof(iarr) / sizeof(int)); pi++){
        printf("%p -> %d\n", pi, *pi);
    }
}