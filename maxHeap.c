#include "MHandPQ.h"

//���ضѴ�С
int size(MH *mh){
	return mh->count;
}

//�п�
int isEmpty(MH *mh){
	return 0 == mh->count;
}

//����
void AdjustDown(MH* mh, int k){
	while (k * 2 <= mh->count)
	{
		int j = k * 2;
		if (j + 1 <= mh->count && mh->data[j] < mh->data[j + 1])//����Һ��Ӵ������Һ��ӱ����Ӵ�
		{
			j = j + 1;
		}
		if (mh->data[k] > mh->data[j])//����ڵ�Ⱥ��Ӵ�
		{
			break;
		}
		//���򽻻�k��j
		int tmp = mh->data[k];
		mh->data[k] = mh->data[j];
		mh->data[j] = tmp;

		k = j;
	}
}


//��ʼ����
void initMaxHeap(MH* mh, int size){
	mh->MaxSize = size;
	mh->data = (HeapDataType*)malloc((mh->MaxSize + 1) * sizeof(HeapDataType));//��1��ʼ�洢
	mh->count = 0;
}

//�ڶ��ֳ�ʼ����,heapify�㷨
void initMaxHeap2(MH* mh, int size, HeapDataType* arr){
	mh->MaxSize = size;
	mh->data = (HeapDataType*)malloc((mh->MaxSize + 1) * sizeof(HeapDataType));//��1��ʼ�洢

	//��arr�����ֵ���������
	for (int i = 0; i < size; i++)
	{
		mh->data[i + 1] = arr[i];
	}
	mh->count = size;

	//���϶Ѳ���
	for (int i = mh->count / 2; i > 0; i--)
	{
		AdjustDown(mh, i);
	}
}

//����Ԫ��
void AdjustUp(MH* mh, int k){
	while (1 < k && mh->data[k / 2] < mh->data[k])
	{
		int tmp = mh->data[k / 2];
		mh->data[k / 2] = mh->data[k];
		mh->data[k] = tmp;
		k /= 2;
	}
}

//����Ԫ��
void insertMaxHeap(MH* mh, HeapDataType value){
	//������û����
	assert(mh->count + 1 <= mh->MaxSize);

	//countΪ���һ��Ԫ��
	mh->data[mh->count + 1] = value;
	mh->count++;

	AdjustUp(mh,mh->count);//���Ƶ�����λ��

}

//����Ԫ��
HeapDataType TopK(MH* mh){
	assert(mh->count > 0);

	//��ö���Ԫ��
	HeapDataType res = mh->data[1];

	//�����ĸ�ֵ������
	mh->data[1] = mh->data[mh->count];
	//����Ԫ����0������count--
	mh->data[(mh->count)--] = 0;

	//�Ѷ���Ԫ�����Ƶ�����λ��
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