#include <stdio.h>

int main()
{
   int a = 3, b = 3;

   a *= a;       printf("a = %d\n", a);
   a %= b + 1;   printf("a = %d\n", a);
   a = b--;      printf("a = %d  b = %d\n", a, b);
   a += 5 * b;   printf("a = %d\n", a);
   a /= b;       printf("a = %d\n", a);

   return 0;
}