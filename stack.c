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
	DataType* _end; //栈顶指针
	int stackSize;
}Stack;

// 栈的实现接口 
void StackInit(Stack* s);//初始化栈
void StackPush(Stack* s, DataType x);//压栈
DataType StackPop(Stack* s);//出栈
DataType StackTop(Stack* s);//查看栈顶
size_t StackSize(Stack* s);//栈的大小
int StackEmpty(Stack* s);//判空

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
		return;
	}
	return *--(s->_top);
}

DataType StackTop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("栈为空");
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