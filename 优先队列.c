#include "MHandPQ.h"

//初始化
void PriorityQueueInit(PQ* q){
	assert(q);
	q->_size = 0;
}

//入队,直接放在数组最后一个
void PriorityQueuePush(PQ* q, PQDataType x){
	assert(q);
	assert(q->_size <= N);
	q->_a[q->_size] = x;
	q->_size++;
}

//出队，把数组用heapify算法转换成堆，从而出对顶层
void PriorityQueuePop(PQ* q){
	assert(q);
	if (q->_size == 0)
	{
		return;
	}
	MH mh;
	initMaxHeap2(&mh, q->_size, q->_a);
	TopK(&mh);//出堆
}

//查看队头（优先级最高）
PQDataType PriorityQueueTop(PQ* q){
	assert(q);
	if (q->_size == 0)
	{
		return;
	}
	MH mh;
	initMaxHeap2(&mh, q->_size, q->_a);
	return mh.data[1];//我写的堆实现是用1开始存取数字
}

//返回大小
size_t PriorityQueueSize(PQ* q){
	return q->_size;
}

//返回是否为空
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