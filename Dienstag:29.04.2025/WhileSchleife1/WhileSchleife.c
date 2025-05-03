#include <stdio.h>

int main() {
    int n = 10, k = 3;
    long binomi = 1;

    // Variante 1: while-Schleife
    /*
    int i = 1, j = n;
    while (i <= k)
        binomi = binomi * j-- / i++;
    */

    // Variante 2: for-Schleife
    /*
    for (int i = 1, j = n; i <= k; i++, j--)
        binomi = binomi * j / i;
    */
    
    // Variante 3: do-while-Schleife
    
    int i = 1, j = n;
    do {
        binomi = binomi * j-- / i++;
    } while (i <= k);
    
    printf("Binomialkoeffizient %d ueber %d = %ld\n", n, k, binomi);
    return 0;
}
