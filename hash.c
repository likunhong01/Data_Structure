#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define HASHSIZE 1000

typedef int keyType;
typedef int valueType;

typedef struct hashtable
{
	valueType* elem;	//����Ԫ�صĻ��ʣ���̬��������
	int count;	//��ǰԪ�صĸ���
}HT;

void InitHashTable(HT* ht)
{	
	assert(ht);
	ht->count = 0;
	ht->elem = (valueType*)malloc(sizeof(valueType)* HASHSIZE);
	for (int i = 0; i < HASHSIZE; i++)
	{
		ht->elem[i] = NULL;
	}
}

//����������
int hash(int value)
{
	return value % HASHSIZE;
}

//����ؼ���
void InsertHash(HT* ht, keyType key, valueType value)
{
	int key = hash(value);
	//while (ht->elem[addr])	//��addr����ֵ��ʱ�򣬳��ֳ�ͻ
	//{
	//	//���Ŷ�ַ��
	//	addr = (addr + 1) % HASHSIZE;
	//}

	//���������ͬ����ֱ�Ӹ���
	ht->elem[key] = value;
}

//���ҹؼ���
valueType SearchHash(HT* ht, keyType key)
{
	assert(ht);
	assert(ht->elem[key]);
	return ht->elem[key];
}

int HashTableRemove(HT* ht, keyType key)
{
	assert(ht);
	ht->elem[key] = NULL;
}

void HashTableDestory(HT* ht)
{
	assert(ht);
	for (int i = 0; i < HASHSIZE; i++)
	{
		ht->elem[i] = NULL;
	}
}
