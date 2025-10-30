#include <stdio.h>

 int main(void){
   int j;
   int i;

   for (j = 2; j <=9; j++){
      printf("\n%d[단]\n", j);
      for (i=1; i<=9; i++){
         printf("%d x %d = %d\n", j,i,j*i);
      }
   }
   return 0;
 }

  