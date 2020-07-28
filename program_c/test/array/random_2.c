#include <stdio.h>
#include <stdlib.h>
#define N 100000
int a[N];
void gen_random(int upper_bound)
{
   int i,temp=0;
    for (i = 0; i < N; i++)
      { 
        temp  = rand() % upper_bound;
        if (temp>20)
        {
          i=i-1;
        }
        else a[i]=temp;
      }
}
int howmany(int value)
{
   int count = 0, i;
    for (i = 0; i < N; i++)
       if (a[i] == value)
          ++count;
     return count;
}
int main(void)
{
   int i;
    gen_random(100);
     printf("value\thow many\n");
      for (i =10; i <= 20; i++)
         printf("%d\t%d\n", i, howmany(i));
       return 0;
}
