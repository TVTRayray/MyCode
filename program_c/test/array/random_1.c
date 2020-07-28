#include <stdio.h>
#include <stdlib.h>
#define N 100000
int a[N];
void gen_random(int upper_bound)
{
   int i;
    for (i = 0; i < N; i++)
       a[i] = rand() % upper_bound;
}
int howmany(int value)
{
   int count = 0, i;
    for (i = 0; i < N; i++)
       if (a[i] == value)
          ++count;
     return count;
}
void print_count(int *a)
{
    for(int i=0;i<10;i++)
    {
        printf("%d\t",i);
        for(int j=0;j<a[i];j++)
        {
        printf("*");
        }
        printf("\n");
    }
}
int main(void)
{
   int i,histogram[10]={};
    gen_random(10);
    for (i=0;i<10;i++)
    {
      ++histogram[a[i]];//对应的下标就是这个数出现的次数
    }
    print_count(histogram);
    // printf("value\thow many\n");
    // for (i = 0; i < 10; i++)
    // {   printf("%d\t%d\n", i, howmany(i));}
       return 0;
}
