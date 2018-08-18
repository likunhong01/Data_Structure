#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define length 10

typedef int DataType;

typedef struct Stack
{
	DataType* _top;
	DataType* _end; //ջ��ָ��
	int stackSize;
}Stack;

// ջ��ʵ�ֽӿ� 
void StackInit(Stack* s);//��ʼ��ջ
void StackPush(Stack* s, DataType x);//ѹջ
DataType StackPop(Stack* s);//��ջ
DataType StackTop(Stack* s);//�鿴ջ��
int StackSize(Stack* s);//ջ�Ĵ�С
int StackEmpty(Stack* s);//�п�


void StackInit(Stack* s)
{
	//��ջ����ռ�
	s->_end = (DataType*)malloc(length * sizeof(DataType));
	//�ж��Ƿ�����ɹ�
	if (!s->_end)
	{
		exit(0);
	}
	//��ʼ��ջ����ռ�
	s->_top = s->_end;//�ʼջ������ջ��
	s->stackSize = length;
	return;
}

void StackPush(Stack* s, DataType x)
{
	//����
	assert(s);
	if (s->stackSize == s->_top - s->_end)
	{
		printf("�ռ�����,׷�ӿռ�");
		s->_end = (DataType*)realloc(s->_end, (s->stackSize + length) * sizeof(DataType));
		if (!s->_end)
		{
			exit(0);
		}
		s->_top = s->_end + s->stackSize;//����ջ��
		s->stackSize += length;//����ջ����
	}
	*(s->_top) = x;//����x
	s->_top++;
	return;
}

DataType StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("ջΪ��");
		return NULL;
	}
	return *--(s->_top);
}

DataType StackTop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("ջΪ��");
		return NULL;
	}
	return *(s->_top - 1);
}

int StackSize(Stack* s)
{
	DataType* p = s->_end;
	int n = 0;
	while (p != s->_top)
	{
		p++;
		n++;
	}
	return n;
}

int StackEmpty(Stack* s)
{
	return 0 == (s->_top - s->_end);
}
































#include "stack.c"


typedef struct queue
{
	Stack s1;
	Stack s2;
	DataType* top;//ջ��ָ��
}queue;



//���г�ʼ��
void qInit(queue* q)
{
	assert(q);
	StackInit(&(q->s1));
	StackInit(&(q->s2));
}

//�����
void qPush(queue* q, DataType value)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//���q1�ǿյ�,��q2����,һ��ʼ��q2������ջ
	{
		StackPush(&(q->s2), value);
		printf("����У�%d\n", value);
	}
	else if (StackEmpty(&(q->s2)))
	{
		StackPush(&(q->s1), value);
		printf("��ջ��%d\n", value);
	}
}

void movefunction(Stack* s1, Stack* s2)//��s1��n������s2ȥ
{
	int leng = StackSize(s1);
	//printf("leng = %d\n", leng);
	for (int i = 0; i < leng; i++)
	{
		StackPush(s2, StackTop(s1));
		StackPop(s1);
	}
}

//������
void qPOP(queue* q)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//���q1�ǿյģ��Ǿ�Ҫ��s2����s1�����
	{
		movefunction(&(q->s2), &(q->s1));//��s2�ĸ��Ƶ�s1��
		StackPop(&(q->s1));//ȡ��s1�Ķ�
		movefunction(&(q->s1), &(q->s2));//��s1�ĸ��ƻص�s2��
	}
	else if (StackEmpty(&(q->s2)))
	{
		movefunction(&(q->s1), &(q->s2));//��s1�ĸ��Ƶ�s2��
		StackPop(&(q->s2));//ȡ��s2�Ķ�
		movefunction(&(q->s2), &(q->s1));//��s2�ĸ��ƻص�s1��
	}
}

//�鿴��ͷ
DataType qPeek(queue* q)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//���q1�ǿյģ��Ǿ�Ҫ��q2����q1�����
	{
		DataType tmp;
		movefunction(&(q->s2), &(q->s1));//��s2�ĸ��Ƶ�s1��
		tmp = StackTop(&(q->s1));//ȡ��s1�Ķ�
		movefunction(&(q->s1), &(q->s2));//��s1�ĸ��ƻص�s2��
		return tmp;
	}
	else if (StackEmpty(&(q->s2)))
	{
		DataType tmp;
		movefunction(&(q->s1), &(q->s2));//��s1�ĸ��Ƶ�s2��
		tmp = StackTop(&(q->s2));//ȡ��s2�Ķ�
		movefunction(&(q->s2), &(q->s1));//��s2�ĸ��ƻص�s1��
		return tmp;
	}
}

//�鿴��С
int qSize(queue* q)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//���q1�ǿյģ��Ǿ�Ҫ��q2����q1�����
	{
		return StackSize(&(q->s2));
	}
	else if (StackEmpty(&(q->s2)))
	{
		return StackSize(&(q->s1));
	}
}



int main()
{
	queue q;
	qInit(&q);
	qPush(&q, 1);
	qPush(&q, 2);
	qPush(&q, 3);
	qPush(&q, 4);
	qPush(&q, 5);

	printf("��ǰ��С��%d\n", qSize(&q));
	printf("��ͷ��%d\n", qPeek(&q));
	qPOP(&q);

	printf("��ǰ��С��%d\n", qSize(&q));
	printf("��ͷ��%d\n", qPeek(&q));
	qPOP(&q);

	printf("��ǰ��С��%d\n", qSize(&q));
	printf("��ͷ��%d\n", qPeek(&q));
	qPOP(&q);

	printf("��ǰ��С��%d\n", qSize(&q));

	system("pause");
	return 0;
}