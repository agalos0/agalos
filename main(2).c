#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int number);

int main()
{
    int number, k;

    scanf("%d", &number);
    k = number / 2;
    if (number<=2 || (2*k != number))
   {
       printf("Wrong Input");
       return 1;
   }
    for(int i=3; i<number-2; i++){
        int p, q, N;
        N = number;
        p = i;

        //isPrime(number, root);
        if(isPrime(p)){
            q = N - p;
            if(isPrime(q)){
                printf("%d+%d=%d", p, q, N);
                break;
            }
        }
    }
    return 0;
}

bool isPrime(int number){
   double root = sqrt(number);
   for(int i=2; i<=root; i++)
   {
      if(number%i == 0)
          return false;
   }
   return true;
}
