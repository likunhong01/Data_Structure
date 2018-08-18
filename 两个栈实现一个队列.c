#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define length 10

typedef int DataType;

typedef struct Stack
{
	DataType* _top;
	DataType* _end; //栈顶指针
	int stackSize;
}Stack;

// 栈的实现接口 
void StackInit(Stack* s);//初始化栈
void StackPush(Stack* s, DataType x);//压栈
DataType StackPop(Stack* s);//出栈
DataType StackTop(Stack* s);//查看栈顶
int StackSize(Stack* s);//栈的大小
int StackEmpty(Stack* s);//判空


void StackInit(Stack* s)
{
	//给栈申请空间
	s->_end = (DataType*)malloc(length * sizeof(DataType));
	//判断是否申请成功
	if (!s->_end)
	{
		exit(0);
	}
	//初始化栈数组空间
	s->_top = s->_end;//最开始栈顶等于栈低
	s->stackSize = length;
	return;
}

void StackPush(Stack* s, DataType x)
{
	//断言
	assert(s);
	if (s->stackSize == s->_top - s->_end)
	{
		printf("空间已满,追加空间");
		s->_end = (DataType*)realloc(s->_end, (s->stackSize + length) * sizeof(DataType));
		if (!s->_end)
		{
			exit(0);
		}
		s->_top = s->_end + s->stackSize;//设置栈顶
		s->stackSize += length;//设置栈长度
	}
	*(s->_top) = x;//设置x
	s->_top++;
	return;
}

DataType StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("栈为空");
		return NULL;
	}
	return *--(s->_top);
}

DataType StackTop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("栈为空");
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
	DataType* top;//栈顶指针
}queue;



//队列初始化
void qInit(queue* q)
{
	assert(q);
	StackInit(&(q->s1));
	StackInit(&(q->s2));
}

//入队列
void qPush(queue* q, DataType value)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//如果q1是空的,往q2里入,一开始往q2里面入栈
	{
		StackPush(&(q->s2), value);
		printf("入队列：%d\n", value);
	}
	else if (StackEmpty(&(q->s2)))
	{
		StackPush(&(q->s1), value);
		printf("入栈：%d\n", value);
	}
}

void movefunction(Stack* s1, Stack* s2)//把s1的n个倒到s2去
{
	int leng = StackSize(s1);
	//printf("leng = %d\n", leng);
	for (int i = 0; i < leng; i++)
	{
		StackPush(s2, StackTop(s1));
		StackPop(s1);
	}
}

//出队列
void qPOP(queue* q)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//如果q1是空的，那就要吧s2的往s1里面存
	{
		movefunction(&(q->s2), &(q->s1));//把s2的复制到s1里
		StackPop(&(q->s1));//取出s1的顶
		movefunction(&(q->s1), &(q->s2));//把s1的复制回到s2里
	}
	else if (StackEmpty(&(q->s2)))
	{
		movefunction(&(q->s1), &(q->s2));//把s1的复制到s2里
		StackPop(&(q->s2));//取出s2的顶
		movefunction(&(q->s2), &(q->s1));//把s2的复制回到s1里
	}
}

//查看队头
DataType qPeek(queue* q)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//如果q1是空的，那就要吧q2的往q1里面存
	{
		DataType tmp;
		movefunction(&(q->s2), &(q->s1));//把s2的复制到s1里
		tmp = StackTop(&(q->s1));//取出s1的顶
		movefunction(&(q->s1), &(q->s2));//把s1的复制回到s2里
		return tmp;
	}
	else if (StackEmpty(&(q->s2)))
	{
		DataType tmp;
		movefunction(&(q->s1), &(q->s2));//把s1的复制到s2里
		tmp = StackTop(&(q->s2));//取出s2的顶
		movefunction(&(q->s2), &(q->s1));//把s2的复制回到s1里
		return tmp;
	}
}

//查看大小
int qSize(queue* q)
{
	assert(q);
	if (StackEmpty(&(q->s1)))	//如果q1是空的，那就要吧q2的往q1里面存
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

	printf("当前大小：%d\n", qSize(&q));
	printf("队头：%d\n", qPeek(&q));
	qPOP(&q);

	printf("当前大小：%d\n", qSize(&q));
	printf("队头：%d\n", qPeek(&q));
	qPOP(&q);

	printf("当前大小：%d\n", qSize(&q));
	printf("对头：%d\n", qPeek(&q));
	qPOP(&q);

	printf("当前大小：%d\n", qSize(&q));

	system("pause");
	return 0;
}