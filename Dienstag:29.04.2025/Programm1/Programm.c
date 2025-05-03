#include <stdio.h>

int main()
{
   int i = 0, j = 0, expr;

   expr = i++ && (j = 1);
   printf("i = %d  j = %d  expr = %d\n", i, j, expr);

   i = 0, j = 0;
   expr = i++ || (j = 2);
   printf("i = %d  j = %d  expr = %d\n", i, j, expr);

   i = 1, j = 1;
   expr = i>j || ++i && j--;
   printf("i = %d  j = %d  expr = %d\n", i, j, expr);

   return 0;
}