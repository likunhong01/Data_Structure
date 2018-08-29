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

//-----------堆的构建等等方法
int size(MH *mh);//返回堆大小
int isEmpty(MH *mh);//判空
void initMaxHeap(MH* mh, int size);//初始化堆
void initMaxHeap2(MH* mh, int size, HeapDataType* arr);//第二种初始化堆,heapify算法
void AdjustUp(MH* mh, int k);//上移元素
void AdjustDown(MH* mh, int k);//下移操作
void insertMaxHeap(MH* mh, HeapDataType value);//插入元素
HeapDataType TopK(MH* mh);//弹出元素
void TestMaxHeap();//测试函数
//---------------------------

//-----堆排序的两个（原地与非原地）
void sortHeap(int arr[], int n);//非原地算法
void down(int arr[], int n, int k);//原地算法辅助下移
void sortHeap2(int arr[], int n);//原地算法
//--------------------------------


//------------优先队列------------------
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


