#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define length 10

typedef int DataType;
typedef int size_t;

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
size_t StackSize(Stack* s);//ջ�Ĵ�С
int StackEmpty(Stack* s);//�п�

//int main()
//{
//	Stack s;
//	int x;
//	int i;
//	StackInit(&s);
//
//	StackPush(&s, 2);
//	StackPush(&s, 5);
//	StackPush(&s, 3);
//
//	//x = StackTop(&s);
//	//x = StackTop(&s);
//	//x = StackTop(&s);
//
//	//x = StackPop(&s);
//	//x = StackPop(&s);
//	//x = StackPop(&s);
//
//	x = StackSize(&s);
//
//	i = s.stackSize;
//	printf("%d,%d",i,x);
//	system("pause");
//	return 0;
//}

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
		return;
	}
	return *--(s->_top);
}

DataType StackTop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("ջΪ��");
		return;
	}
	return *(s->_top - 1);
}

size_t StackSize(Stack* s)
{
	return (s->_top - s->_end);
}

int StackEmpty(Stack* s)
{
	return 0 == (s->_top - s->_end);
}