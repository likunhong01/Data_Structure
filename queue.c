#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define length 10

typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q);//��ʼ��
void QueuePush(Queue* q, DataType x);//����
void QueuePop(Queue* q);//����
DataType QueueFront(Queue* q);//��ͷ
DataType QueueBack(Queue* q);//��β
size_t QueueSize(Queue* q);//����С
int QueueEmpty(Queue* q);//�п�

//int main()
//{
//	Queue q;
//	int x = 0;
//	int i = 0;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 3);
//	QueuePush(&q, 2);
//	QueuePush(&q, 6);
//	QueuePush(&q, 2);
//	//QueuePop(&q);
//
//	
//	x = QueueFront(&q);
//	i = QueueBack(&q);
//
//	printf("%d,%d", x, i);
//	printf("\n%d",QueueSize(&q));
//	system("pause");
//	return 0;
//}


void QueueInit(Queue* q)
{
	assert(&q);
	//����ռ�
	q->_head = (QueueNode*)malloc(length * sizeof(QueueNode));
	if (!q->_head)
	{
		exit(0);
	}
	q->_tail = q->_head;
	q->_head->_next = NULL;
	return;
}

void QueuePush(Queue* q, DataType x)
{
	assert(&q);
	//����ڵ�ռ�	
	QueueNode* newNode;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));

	if (NULL == newNode)
	{
		exit(0);
	}

	newNode->_data = x;
	newNode->_next = NULL;
	q->_tail->_next = newNode;
	q->_tail = newNode;
	return;
}

void QueuePop(Queue* q)
{
	assert(&q);
	if (QueueEmpty(q))
	{
		return;
	}
	QueueNode* p;
	p = q->_head->_next;//pָ���һ������
	q->_head->_next = p->_next;//��ͷ����nextָ���һ�����ݵ�next
	if (q->_tail == p)//���ֻʣһ��Ԫ�أ���tailָ��ָ��ͷ���
	{
		q->_tail = q->_head;
	}
	free(p);
}

DataType QueueFront(Queue* q){
	assert(q);
	if (QueueEmpty(q))
	{
		return NULL;
	}
	return q->_head->_next->_data;
}

DataType QueueBack(Queue* q){
	assert(q);
	if (QueueEmpty(q))
	{
		return NULL;
	}
	return q->_tail->_data;
}

size_t QueueSize(Queue* q)
{
	return (q->_tail - q->_head) / sizeof(QueueNode) - 1;
}

int QueueEmpty(Queue* q)
{
	return q->_head == q->_tail;
}