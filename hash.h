#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int KeyType;
typedef int ValueType;

typedef enum Status
{
	EMPTY,
	EXITS,
	DELETE,
}Status;

typedef struct HashNode
{
	KeyType _key;
	ValueType _value;
	Status _status;
}HashNode;

typedef struct HashTable
{
	HashNode* _tables;
	size_t _size;
	size_t _N;
}HashTable;

void HashTableInit(HashTable* ht);
int HashTableInsert(HashTable* ht, KeyType key, ValueType value);
HashNode* HashTableFind(HashTable* ht, KeyType key);
int HashTableRemove(HashTable* ht, KeyType key);
void HashTableDestory(HashTable* ht);
