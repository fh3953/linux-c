//�˳����ö�ջʵ����ʮ����ת��Ϊ�������㷨
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
void InitStack(seqstack *s)//��ʼ��˳��ջ
{    
    s->top=-1;
}
int StackEmpty(seqstack *s)//�ж�ջ�Ƿ�Ϊ��
{    
    if (s->top>=0) return 1;
    else return 0;
}
seqstack *push(seqstack *s,datatype x)//Ԫ����ջ����
{ 
	if (s->top==M-1) return NULL;
	else {  s->top++;s->data[s->top]=x;}
	return s; 
}
datatype pop(seqstack *s)//Ԫ�س�ջ���� 
{ 
	datatype x;
	x=s->data[s->top];
	s->top--;
	return x;
} 
void main()// �������������һ���Ǹ�ʮ������������ӡ��������ֵ�Ķ�������
{                 
	seqstack *s;
	datatype n,e; //nΪ���룬eΪ���
	while(1)
	{
		int i=0,j=0;
		printf("����һ��ʮ��������\n");
		scanf("%u",&n);  // ����Ǹ�ʮ��������n 
		s=(struct seqstack*)malloc(sizeof(int));
		InitStack(s); // ��ʼ��ջ
		if (s==NULL) exit(0); 
		while(n) 
		{
			push(s,n%2);  // ��ջn����2������(2���Ƶĵ�λ)
			i++;          // ͳ����ջԪ�ظ��� 
			n=n/2;
		}
		printf("������Ӧ�Ķ��������ǣ�\n");
		while(j<i) // ��������� 
		{
			j++; 
			e=pop(s); // ����ջ��Ԫ���Ҹ�ֵ��e
			printf("%d",e); 
		}
		printf("\n");
	}
	
}
