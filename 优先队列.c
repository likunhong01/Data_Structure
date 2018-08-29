#include "MHandPQ.h"

//��ʼ��
void PriorityQueueInit(PQ* q){
	assert(q);
	q->_size = 0;
}

//���,ֱ�ӷ����������һ��
void PriorityQueuePush(PQ* q, PQDataType x){
	assert(q);
	assert(q->_size <= N);
	q->_a[q->_size] = x;
	q->_size++;
}

//���ӣ���������heapify�㷨ת���ɶѣ��Ӷ����Զ���
void PriorityQueuePop(PQ* q){
	assert(q);
	if (q->_size == 0)
	{
		return;
	}
	MH mh;
	initMaxHeap2(&mh, q->_size, q->_a);
	TopK(&mh);//����
}

//�鿴��ͷ�����ȼ���ߣ�
PQDataType PriorityQueueTop(PQ* q){
	assert(q);
	if (q->_size == 0)
	{
		return;
	}
	MH mh;
	initMaxHeap2(&mh, q->_size, q->_a);
	return mh.data[1];//��д�Ķ�ʵ������1��ʼ��ȡ����
}

//���ش�С
size_t PriorityQueueSize(PQ* q){
	return q->_size;
}

//�����Ƿ�Ϊ��
size_t PriorityQueueEmpty(PQ* q){
	return 0 == q->_size;
}

void TestPQ(){
	PQ pq;
	PriorityQueueInit(&pq);
	PriorityQueuePush(&pq, 2);
	PriorityQueuePush(&pq, 5);
	PriorityQueuePush(&pq, 7);
	PriorityQueuePush(&pq, 3);
	PriorityQueuePush(&pq, 9);

	printf("%d", PriorityQueueTop(&pq));
}