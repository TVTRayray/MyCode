#include<stdio.h>

//结构体定义
struct Rational {
int x;
int y;
};

//初始化结构体
struct Rational make_rational(int x,int y)
{
	struct Rational r;
	r.x=x;
	r.y=y;
	return r;
};

//打印出结构体
void print_rational(struct Rational r)
{
if (r.x==0) printf ("[+] 0\n");
else printf("[+] %d/%d\n",r.x,r.y);
}

struct Rational add_rational(struct Rational a,struct Rational b)
{
int result_x,flag,flag1;
if(b.y!=a.y)
{
	result_x=(a.x*b.y)+(a.y*b.x);
	
	if(result_x==0)
	{

		struct Rational r={0,0};
		return  r;
	}
	else
	{
		flag1=GCD(result_x,(b.y*a.y));
		struct Rational r ={result_x/flag1,(a.y*b.y)/flag1};
		return r;	
	}
}
else 
{
	result_x=a.x+b.x;
	if(result_x==0)
	{

		struct Rational r={0,0};
		return  r;
	}
	else
	{
		flag=GCD(result_x,b.y);
		struct Rational r={result_x/flag,b.y/flag};
		return r;	
	}

}


};


struct Rational sub_rational(struct Rational a,struct Rational b)
{
int result_x,flag,flag1;
if(b.y!=a.y)
{
	result_x=(a.x*b.y)-(a.y*b.x);
	
	if(result_x==0)
	{

		struct Rational r={0,0};
		return  r;
	}
	else
	{
		flag1=GCD(result_x,(b.y*a.y));
		struct Rational r ={result_x/flag1,(a.y*b.y)/flag1};
		return r;	
	}
}
else 
{
	result_x=a.x-b.x;
	if(result_x==0)
	{

		struct Rational r={0,0};
		return  r;
	}
	else
	{
		flag=GCD(result_x,b.y);
		struct Rational r={result_x/flag,b.y/flag};
		return r;	
	}

}


};



struct Rational mul_rational(struct Rational a,struct Rational b)
{

int result_x,result_y;
result_x=a.x*b.x;
result_y=a.y*b.y;

if(result_x==0)
{
	struct Rational r={0,0};
	return r;
}
else
{
	
	int flag;
	flag=GCD(result_x,result_y);
	struct Rational r={result_x/flag,result_y/flag};
	return r;
}


};


struct Rational div_rational(struct Rational a,struct Rational b)
{

int result_x,result_y;
result_x=a.x*b.y;
result_y=a.y*b.x;

if(result_x==0)
{
	struct Rational r={0,0};
	return r;
}
else
{
	
	int flag;
	flag=GCD(result_x,result_y);
	struct Rational r={result_x/flag,result_y/flag};
	return r;
}


};

//求最大公约数
int GCD(int a,int b)
{

if (a%b==0)  		return b;

else 			return GCD(b,a%b);

}

struct Rational guifan (struct Rational a,struct Rational b)
{
	
}
int main(void)
{
int x1,y1,x2,y2;
printf("please input x1/y1:\n");
scanf("%d,%d",&x1,&y1);
while(y1==0)
{
printf("[-] erro! the y can't be defined zero!\n");
printf("please input x1/y1:\n");
scanf("%d,%d",&x1,&y1);
}
struct Rational a=make_rational(x1,y1);
printf("please input x2/y2:\n");
scanf("%d,%d",&x2,&y2);

while(y2==0)
{
printf("[-] erro! the y can't be defined zero!\n");
printf("please input x2/y2:\n");	
scanf("%d,%d",&x2,&y2);
}
struct Rational b=make_rational(x2,y2);
printf("the result of add is:\n");
print_rational(add_rational(a,b));
printf("the result of sub is:\n");
print_rational(sub_rational(a,b));
printf("the result of mul is:\n");
print_rational(mul_rational(a,b));
printf("the result of div is:\n");
print_rational(div_rational(a,b));
}
