//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <assert.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#include "queue.c"
//
//
//typedef struct stack
//{
//	Queue q1;
//	Queue q2;
//	DataType* top;//栈顶指针
//}stack;
//
//
//
//
//
//
////栈初始化
//void sInit(stack* s)
//{
//	assert(s);
//	QueueInit(&(s->q1));
//	QueueInit(&(s->q2));
//}
//
////入栈
//void sPush(stack* s, DataType value)
//{
//	assert(s);
//	if (QueueEmpty(  &(s->q1)  )  )	//如果q1是空的,往q2里入,一开始往q2里面入栈
//	{
//		QueuePush(&(s->q2), value);
//		printf("入栈：%d\n", value);
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		QueuePush(&(s->q1), value);
//		printf("入栈：%d\n", value);
//	}
//}
//
//void movefunction(Queue* q1, Queue* q2)//吧q1的前n-1个复制到q2
//{
//	int leng = QueueSize(q1);
//	//printf("leng = %d\n", leng);
//	for (int i = 0; i < leng - 1; i++)
//	{
//		//循环leng-1次
//		DataType tmp = QueueFront(q1);//取队头
//		QueuePop(q1);//q1弹出队头
//		QueuePush(q2, tmp);//q2放进队头
//		//printf("把%d放到另一个队列\n", tmp);
//	}
//}
//
////出栈
//void sPOP(stack* s)
//{
//	assert(s);
//	if (QueueEmpty(&(s->q1)))	//如果q1是空的，那就要吧q2的往q1里面存
//	{
//		movefunction(&(s->q2), &(s->q1));//把前n-1个复制到q1里
//		QueuePop(&(s->q2));//q2弹出最后一个（栈顶）
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		movefunction(&(s->q1), &(s->q2));
//		QueuePop(&(s->q1));//q2弹出最后一个（栈顶）
//	}
//}
//
////查看栈顶
//DataType sPeek(stack* s)
//{
//	assert(s);
//	if (QueueEmpty(&(s->q1)))	//如果q1是空的，那就要吧q2的往q1里面存
//	{
//		DataType tmp;
//		movefunction(&(s->q2), &(s->q1));//把前n-1个复制到q1里
//		tmp = QueueFront(&(s->q2));
//		QueuePop(&(s->q2));//q1弹出队头
//		QueuePush(&(s->q1), tmp);//q2放进队头//移动最后一个去q1
//		return tmp;
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		DataType tmp;
//		movefunction(&(s->q1), &(s->q2));//把前n-1个复制到q1里
//		tmp = QueueFront(&(s->q1));
//		QueuePop(&(s->q1));//q1弹出队头
//		QueuePush(&(s->q2), tmp);//q2放进队头//移动最后一个去q1
//		return tmp;
//	}
//}
//
////查看大小
//int sSize(stack* s)
//{
//	assert(s);
//	if (QueueEmpty(&(s->q1)))	//如果q1是空的，那就要吧q2的往q1里面存
//	{
//		return QueueSize(&(s->q2));
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		return QueueSize(&(s->q1));
//	}
//}
//
//
//
////int main()
////{
////	stack s;
////	sInit(&s);
////	sPush(&s, 1);
////	sPush(&s, 2);
////	sPush(&s, 3);
////	sPush(&s, 4);
////	sPush(&s, 5);
////
////	printf("大小：%d\n", sSize(&s));
////
////	printf("栈顶：%d\n", sPeek(&s));
////	sPOP(&s);
////
////	printf("栈顶：%d\n", sPeek(&s));
////	sPOP(&s);
////
////	printf("栈顶：%d\n", sPeek(&s));
////	sPOP(&s);
////
////	printf("大小：%d\n", sSize(&s));
////
////	system("pause");
////	return 0;
////}