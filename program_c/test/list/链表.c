//线性表在单链表上的操作实现
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;  //定义元素类型
typedef struct LNode{           //定义单链表结点类型
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;




//头插法建立单链表
 LinkList  List_HeadInsert (LNode *L, ElemType a[], int Length){
	

	LNode *s;
	L = (LinkList)malloc(sizeof(LNode));			 //创建一个头结点
	L->next = NULL;
	for (int i=0;i<Length;i++){
			
			s=(LNode*)malloc(sizeof(LNode));
			s->data = a[i];
			s->next = L->next;
			L->next = s;
	}															 
	printf("[+]插入成功\n");
	LNode *p;
	p = L->next;
	for (int j=0;j<10;j++){
		printf("链表数据的值为%d\n",p->data);
		p = p->next;
	}
	return  L;
}

//尾插法建立单链表
LinkList  List_TailInsert(LNode *L,ElemType a[], int Length){
	
	L = (LinkList)malloc(sizeof(LNode));	
	LNode *s,*r=L;
	
	for(int i=0;i<Length;i++){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r=s;
	}
	r->next = NULL;
	printf("[+]插入成功\n");

	
	return L;
}

//按序号查找
LinkList GetElem(LNode *L,int i)
{
	int j = 1;
	LNode *p = L->next;
	if (i == 0){
		return L;
	}
	if (i < 1){
		return NULL;
	}
	while(p && j<i){
		p = p->next;
		j++;
	}
	return p;
}


//按值查找
LinkList LocateElem(LNode *L,ElemType e){
	LNode *p = L->next;
	while (p!=NULL && p->data!=e){
		p = p->next;
	}
	return p;
}

//插入结点
void InsertList(LNode *L,ElemType x,int i)
{
	LNode *p,*s;

	if (i == 0){
		printf("[-]表为空\n");
		exit(1);
	}
	if (i < 1){
		printf("[-]error!插入位置非法\n");
		exit(1);
	}

	s->data = x;
	p = GetElem(L,i-1);
	s->next = p->next;
	p->next = s;

}

//删除结点
void DeleteList(LNode *L,int i){
	LNode *p,*s;
	if (i == 0){
		printf("[-]表为空\n");
		exit(1);
	}
	if (i < 1){
		printf("[-]error!删除位置非法\n");
		exit(1);
	}
	p = GetElem(L,i-1);
	s = p->next;
	p->next = s->next;
	free(s);
}

//求链表长度
int Length_List(LNode *L){
	int i=0;
	LNode *p = L->next;
	
	while(p!=NULL){
		p = p->next;
		i++;
	}
	return i;
}

//打印

void PrintList(LNode *L){
	LNode *p;
	p = L->next;
	while(p){
		printf("%d\n",p->data);
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	LNode L1,L2;
	LNode *pL1,*pL2;
	int array[]={1,2,3,4,5,6,7,8,9,10};

	int Length;
	Length = sizeof(array)/sizeof(array[0]);
	printf("数组长度是%d\n",Length );
	pL1 = List_HeadInsert(&L1,array,Length);
	//List_TailInsert(&L2,array,Length);
	

	//Length_List(&L1);
	//Length_List(&L2);
	//PrintList(&L1);
	//PrintList(&L2);
	
	printf("[+]表的长度为%d\n",Length_List(pL1));
	return 0;
}