#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HeapDataType;

typedef struct MaxHeap{
	HeapDataType* data;
	int count;
	int MaxSize;
}MH;

//-----------�ѵĹ����ȵȷ���
int size(MH *mh);//���ضѴ�С
int isEmpty(MH *mh);//�п�
void initMaxHeap(MH* mh, int size);//��ʼ����
void initMaxHeap2(MH* mh, int size, HeapDataType* arr);//�ڶ��ֳ�ʼ����,heapify�㷨
void AdjustUp(MH* mh, int k);//����Ԫ��
void AdjustDown(MH* mh, int k);//���Ʋ���
void insertMaxHeap(MH* mh, HeapDataType value);//����Ԫ��
HeapDataType TopK(MH* mh);//����Ԫ��
void TestMaxHeap();//���Ժ���
//---------------------------

//-----�������������ԭ�����ԭ�أ�
void sortHeap(int arr[], int n);//��ԭ���㷨
void down(int arr[], int n, int k);//ԭ���㷨��������
void sortHeap2(int arr[], int n);//ԭ���㷨
//--------------------------------


//------------���ȶ���------------------
#define N 100

typedef int PQDataType;

typedef struct PriorityQueue
{
	PQDataType _a[N];
	int _size;
}PQ;

void PriorityQueueInit(PQ* q);
void PriorityQueuePush(PQ* q, PQDataType x);
void PQUp(PQ* q, int k);
void PriorityQueuePop(PQ* q);
void PQdown(PQ* q, int k);
PQDataType PriorityQueueTop(PQ* q);
size_t PriorityQueueSize(PQ* q);
size_t PriorityQueueEmpty(PQ* q);


