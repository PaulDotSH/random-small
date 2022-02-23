#include <time.h>
#include <stdio.h>

int main () {
    /*
   clock_t start_t, end_t, total_t;
   long i;

   start_t = clock();
   for(i=0; i< 999999999999999; i++) {
   }
   end_t = clock();
   printf("Start program, start_t = %ld\n", start_t);
   printf("Stop program, end_t = %ld\n", end_t);

   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Timp total CPU: %f\n", total_t  );

   return 0;
   */
    
    //Idk ce trb facut aici, anyway inline e faster than function calls ca avem function call stack
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",x+y);
}
