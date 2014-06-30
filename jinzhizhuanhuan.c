//此程序用堆栈实现了十进制转换为二进制算法
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#define M 100
typedef int datatype;
typedef struct
{
    datatype data[M];
    int top; 
}seqstack;
void InitStack(seqstack *s)//初始化顺序栈
{    
    s->top=-1;
}
int StackEmpty(seqstack *s)//判断栈是否为空
{    
    if (s->top>=0) return 1;
    else return 0;
}
seqstack *push(seqstack *s,datatype x)//元素入栈函数
{ 
	if (s->top==M-1) return NULL;
	else {  s->top++;s->data[s->top]=x;}
	return s; 
}
datatype pop(seqstack *s)//元素出栈函数 
{ 
	datatype x;
	x=s->data[s->top];
	s->top--;
	return x;
} 
void main()// 对于输入的任意一个非负十进制整数，打印输出与其等值的二进制数
{                 
	seqstack *s;
	datatype n,e; //n为输入，e为输出

	while(1)
	{
		int i=0,j=0;
		printf("����һ��ʮ��������\n");
		scanf("%u",&n);  // 输入非负十进制整数n 
		s=(struct seqstack*)malloc(sizeof(int));
		InitStack(s); // 初始化栈
		if (s==NULL) exit(0); 
		while(n) 
		{
			push(s,n%2); // 入栈n除以2的余数(2进制的低位)
			i++;         // 统计入栈元素个数 
			n=n/2;
		}
		printf("������Ӧ�Ķ��������ǣ�\n");
		while(j<i) // 输出二进制 
		{
			j++; 
			e=pop(s); // 弹出栈顶元素且赋值给e
			printf("%d",e); 
		}
		printf("\n");
	}
	
}
