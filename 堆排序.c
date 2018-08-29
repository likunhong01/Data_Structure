#include "MHandPQ.h"

//堆排序
void sortHeap(int arr[], int n){
	MH mh;
	initMaxHeap(&mh, n);
	for (int i = 0; i < n; i++)
	{
		insertMaxHeap(&mh, arr[i]);
	}
	for (int i = n - 1; i >= 0; i--){
		arr[i] = TopK(&mh);
	}
}


//下面是原地堆排序
void down(int arr[], int n, int k){
	while (k * 2 < n)
	{
		int j = k * 2 + 1;
		if (j + 1 < n && arr[j] < arr[j+1])
		{
			j = j + 1;
		}
		if (arr[j] <= arr[k])
		{
			break;
		}
		int tmp = arr[j];
		arr[j] = arr[k];
		arr[k] = tmp;
		k = j;
	}
}

//原地堆排序
void sortHeap2(int arr[], int n){
	for (int i = (n-1)/2; i >= 0; i--)
	{
		down(arr, n, i);
	}
	for (int i = n - 1; i > 0 ; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		down(arr,n,0);
	}
}