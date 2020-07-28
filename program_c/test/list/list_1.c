// 线性表的顺序存储结构的操作实现
#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;
typedef struct{
    ElemType *list;
    int MaxSize;    //线性表的最大长度
    int length;     //当前的长度
} SeqList;

void InitList(SeqList *L, int ms) //传入一个值，初始化表
{
      if (ms < 0) //检查ms是否有效
            {
                      printf("[-]ms值非法！\n");
                      exit(1);
            }
      L->MaxSize = ms; 
      //置线性表初始存储容量为ms
      L->list = (ElemType *)malloc(ms*sizeof(ElemType)); 
      //动态存储空间分配
      if (!L->list)
            {
                      printf("动态存储分配失败！\n");
                      exit(1);
            }
       L->length = 0; //初始化线性表为0
       printf("======  顺序表初始化完成  ======\n");
}

void DestoryList(SeqList *L) //删除表
{
if (L->list !=NULL)
  {
    free(L->list);
    L->list=0;
    L->length=L->MaxSize=0;

  }
}

int Length(SeqList L) //求表长
{
  return L.length;
}

int Empty(SeqList *L) //判断是否为空表
{
  if (L->length == 0)
        return 1;
    else
        return 0;

}

ElemType GetElem(SeqList *L,int i)//按位查找
{
  if (i< 1 || i > L->length)
    {
        printf("[-]元素序号越界！\n");
        exit(1);
    }
    return L->list[i-1];

}

int LocateElem(SeqList *L,ElemType x)//按值查找
{
  int i;
    for (i = 0; i < L->length; i++) 
    //此处类型ElemType为整型，当为字符串类型（char *）时，
        if (L->list[i] == x)      
        //if语句应改为: if (strcmp(L->list[i], x) == 0)
            return i;
    return -1;

}

void PrintList(SeqList *L) //打印线性表
{ 
  int i;
  for(i=0;i<L->length;i++) //i<L->length不能等于
  
      printf("%d\n",L->list[i] );
      
}

void InsertNewList(SeqList *L, ElemType x,int i)//将数组的值传入线性表
{

   
    L->list[L->length]=x;
    L->length++;
}

void InsertList(SeqList *L,ElemType x,int pos) //在指定位置插入一个值
{
  if(pos<1 || pos>(L->length)+1)
    exit(1);
  if (L->length >=L->MaxSize)
    exit(1);
  for(int j=L->length;j>=pos;j--)
  {
    L->list[j]=L->list[j-1];
  }
  L->length++;
  L->list[pos-1]=x;
}

void DeletList(SeqList *L,int pos) //删除指定位置的值
{
  ElemType x;
  if(pos<1 || pos>(L->length))
    exit(1);
  x = L->list[pos-1];
  printf("位于%d位置的元素%d被删除了\n",pos,x);
  for(int j=pos;j<L->length;j++)
  {
    L->list[j-1]=L->list[j];
  }
  L->length--;
}
void main()
{
  int a[10]={2,4,5,7,8,9,11,13,16,18};
  int i;
  SeqList L;
printf("======  开始初始化顺序表  ======\n");
printf("=                                                         =\n");
printf("=                                                         =\n");
  InitList(&L,15);

  
printf("%s\n","[+]开始传入数据" );
  for (i=0;i<10;i++)
  {
   InsertNewList(&L,a[i],i);
  }

  printf("[+]向表中指定位置插入数据\n");
  InsertList(&L,19,1);

  printf("[+]表中指定位置的数据是：\n");
  printf("[+]%d\n", GetElem(&L,1));
  
  printf("[+]元素16在表中的位置是：%d\n",LocateElem(&L,16));
  printf("[+]表的长度是%d\n",Length(L));
  
printf("====== 开始检查是否为空表 ======\n");
  if(Empty(&L)==0)
  {
    printf("[+]表不为空\n");
  }
  else printf("[-]表为空\n");
  printf("====== 检查结束 ======\n");
  //DestoryList(&L);
printf("====== 开始打印表 ======\n");
  PrintList(&L);
printf("====== 打印结束 ======\n");
  
  DeletList(&L,7);
}
