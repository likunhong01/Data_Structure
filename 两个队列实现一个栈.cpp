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
//	DataType* top;//ջ��ָ��
//}stack;
//
//
//
//
//
//
////ջ��ʼ��
//void sInit(stack* s)
//{
//	assert(s);
//	QueueInit(&(s->q1));
//	QueueInit(&(s->q2));
//}
//
////��ջ
//void sPush(stack* s, DataType value)
//{
//	assert(s);
//	if (QueueEmpty(  &(s->q1)  )  )	//���q1�ǿյ�,��q2����,һ��ʼ��q2������ջ
//	{
//		QueuePush(&(s->q2), value);
//		printf("��ջ��%d\n", value);
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		QueuePush(&(s->q1), value);
//		printf("��ջ��%d\n", value);
//	}
//}
//
//void movefunction(Queue* q1, Queue* q2)//��q1��ǰn-1�����Ƶ�q2
//{
//	int leng = QueueSize(q1);
//	//printf("leng = %d\n", leng);
//	for (int i = 0; i < leng - 1; i++)
//	{
//		//ѭ��leng-1��
//		DataType tmp = QueueFront(q1);//ȡ��ͷ
//		QueuePop(q1);//q1������ͷ
//		QueuePush(q2, tmp);//q2�Ž���ͷ
//		//printf("��%d�ŵ���һ������\n", tmp);
//	}
//}
//
////��ջ
//void sPOP(stack* s)
//{
//	assert(s);
//	if (QueueEmpty(&(s->q1)))	//���q1�ǿյģ��Ǿ�Ҫ��q2����q1�����
//	{
//		movefunction(&(s->q2), &(s->q1));//��ǰn-1�����Ƶ�q1��
//		QueuePop(&(s->q2));//q2�������һ����ջ����
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		movefunction(&(s->q1), &(s->q2));
//		QueuePop(&(s->q1));//q2�������һ����ջ����
//	}
//}
//
////�鿴ջ��
//DataType sPeek(stack* s)
//{
//	assert(s);
//	if (QueueEmpty(&(s->q1)))	//���q1�ǿյģ��Ǿ�Ҫ��q2����q1�����
//	{
//		DataType tmp;
//		movefunction(&(s->q2), &(s->q1));//��ǰn-1�����Ƶ�q1��
//		tmp = QueueFront(&(s->q2));
//		QueuePop(&(s->q2));//q1������ͷ
//		QueuePush(&(s->q1), tmp);//q2�Ž���ͷ//�ƶ����һ��ȥq1
//		return tmp;
//	}
//	else if (QueueEmpty(&(s->q2)))
//	{
//		DataType tmp;
//		movefunction(&(s->q1), &(s->q2));//��ǰn-1�����Ƶ�q1��
//		tmp = QueueFront(&(s->q1));
//		QueuePop(&(s->q1));//q1������ͷ
//		QueuePush(&(s->q2), tmp);//q2�Ž���ͷ//�ƶ����һ��ȥq1
//		return tmp;
//	}
//}
//
////�鿴��С
//int sSize(stack* s)
//{
//	assert(s);
//	if (QueueEmpty(&(s->q1)))	//���q1�ǿյģ��Ǿ�Ҫ��q2����q1�����
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
////	printf("��С��%d\n", sSize(&s));
////
////	printf("ջ����%d\n", sPeek(&s));
////	sPOP(&s);
////
////	printf("ջ����%d\n", sPeek(&s));
////	sPOP(&s);
////
////	printf("ջ����%d\n", sPeek(&s));
////	sPOP(&s);
////
////	printf("��С��%d\n", sSize(&s));
////
////	system("pause");
////	return 0;
////}