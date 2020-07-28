#include<stdio.h>

int test_1(int *p)
{
	*p=*p+100;
	return *p;
}


int test_2(int q)
{
	
	return (q+100);
}

int main(void)
{
	int q,r1,r2;
	int a=100;
	
	//q=a;
	r1=test_1(&a);
	//r2=test_2(q,a);
	printf("%d\n",r1);
	//printf("%d\n",r2);
	printf("a=%d\n",a);
}