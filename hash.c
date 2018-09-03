#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define HASHSIZE 1000

typedef int keyType;
typedef int valueType;

typedef struct hashtable
{
	valueType* elem;	//数组元素的基质，动态分配数组
	int count;	//当前元素的个数
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

//除留余数法
int hash(int value)
{
	return value % HASHSIZE;
}

//插入关键字
void InsertHash(HT* ht, keyType key, valueType value)
{
	int key = hash(value);
	//while (ht->elem[addr])	//当addr里有值的时候，出现冲突
	//{
	//	//开放定址法
	//	addr = (addr + 1) % HASHSIZE;
	//}

	//如果存在相同的则直接覆盖
	ht->elem[key] = value;
}

//查找关键字
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
