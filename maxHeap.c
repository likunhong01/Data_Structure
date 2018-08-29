#include "MHandPQ.h"

//返回堆大小
int size(MH *mh){
	return mh->count;
}

//判空
int isEmpty(MH *mh){
	return 0 == mh->count;
}

//下移
void AdjustDown(MH* mh, int k){
	while (k * 2 <= mh->count)
	{
		int j = k * 2;
		if (j + 1 <= mh->count && mh->data[j] < mh->data[j + 1])//如果右孩子存在且右孩子比左孩子大
		{
			j = j + 1;
		}
		if (mh->data[k] > mh->data[j])//如果节点比孩子大
		{
			break;
		}
		//否则交换k和j
		int tmp = mh->data[k];
		mh->data[k] = mh->data[j];
		mh->data[j] = tmp;

		k = j;
	}
}


//初始化堆
void initMaxHeap(MH* mh, int size){
	mh->MaxSize = size;
	mh->data = (HeapDataType*)malloc((mh->MaxSize + 1) * sizeof(HeapDataType));//从1开始存储
	mh->count = 0;
}

//第二种初始化堆,heapify算法
void initMaxHeap2(MH* mh, int size, HeapDataType* arr){
	mh->MaxSize = size;
	mh->data = (HeapDataType*)malloc((mh->MaxSize + 1) * sizeof(HeapDataType));//从1开始存储

	//吧arr数组的值赋给这个堆
	for (int i = 0; i < size; i++)
	{
		mh->data[i + 1] = arr[i];
	}
	mh->count = size;

	//整合堆操作
	for (int i = mh->count / 2; i > 0; i--)
	{
		AdjustDown(mh, i);
	}
}

//上移元素
void AdjustUp(MH* mh, int k){
	while (1 < k && mh->data[k / 2] < mh->data[k])
	{
		int tmp = mh->data[k / 2];
		mh->data[k / 2] = mh->data[k];
		mh->data[k] = tmp;
		k /= 2;
	}
}

//插入元素
void insertMaxHeap(MH* mh, HeapDataType value){
	//看看有没有满
	assert(mh->count + 1 <= mh->MaxSize);

	//count为最后一个元素
	mh->data[mh->count + 1] = value;
	mh->count++;

	AdjustUp(mh,mh->count);//上移到合适位置

}

//弹出元素
HeapDataType TopK(MH* mh){
	assert(mh->count > 0);

	//获得顶端元素
	HeapDataType res = mh->data[1];

	//把最后的赋值给顶端
	mh->data[1] = mh->data[mh->count];
	//最后的元素置0，并且count--
	mh->data[(mh->count)--] = 0;

	//把顶端元素下移到合适位置
	AdjustDown(mh, 1);

	return res;
}

void TestMaxHeap()
{
	MH mh;
	initMaxHeap(&mh, 10);
	insertMaxHeap(&mh, 2);
	insertMaxHeap(&mh, 1);
	insertMaxHeap(&mh, 3);
	insertMaxHeap(&mh, 5);
	insertMaxHeap(&mh, 4);

	for (int i = 0; i < 5; i++)
	{
		int x = TopK(&mh);
		printf("%d  ", x);
	}

	system("pause");
	return 0;
}