#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//ջ�Ͷ��г�ʼ������
#define length 20

//�������ڵ���������
typedef int BTDataType;

//�������ڵ�ṹ��
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode DataType;//ջ�Ͷ��д洢����

//ջ�Ľṹ��
typedef struct Stack
{
	DataType* _top;
	DataType* _end; //ջ��ָ��
	int stackSize;
}Stack;

//���нڵ�ṹ��
typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

//���нṹ��
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;


//------���з���----------------------------------------
void QueueInit(Queue* q);//��ʼ��
void QueuePush(Queue* q, DataType x);//����
DataType QueuePop(Queue* q);//����
DataType QueueFront(Queue* q);//��ͷ
DataType QueueBack(Queue* q);//��β
int QueueSize(Queue* q);//����С
int QueueEmpty(Queue* q);//�п�
//------------------------------------------------------



//------����������--------------------------------------
// a��һ��ǰ�����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);//����
void BinaryTreeDestory(BTNode* root);//���ٶ�����

int BinaryTreeSize(BTNode* root);//ͳ�ƽڵ����
int BinaryTreeLeafSize(BTNode* root);//ͳ�ƶ���Ҷ��
int BinaryTreeLevelKSize(BTNode* root, int k);//ͳ�Ƶ�k���ж��ٸ��ڵ�

//����
//�ݹ�
void BinaryTreePrevOrder(BTNode* root);//ǰ�����
void BinaryTreeInOrder(BTNode* root);//�������
void BinaryTreePostOrder(BTNode* root);//�������

void BinaryTreeLevelOrder(BTNode* root);//�������

//�ǵݹ�
void BinaryTreePrevOrderNonR(BTNode* root);//ǰ��
void BinaryTreeInOrderNonR(BTNode* root);//����
void BinaryTreePostOrderNonR(BTNode* root);//����

void TestBinaryTree();
//------------------------------------------------------



//------ջ����------------------------------------------
void StackInit(Stack* s);//��ʼ��ջ
void StackPush(Stack* s, DataType *x);//ѹջ
DataType* StackPop(Stack* s);//��ջ
DataType* StackTop(Stack* s);//�鿴ջ��
int StackSize(Stack* s);//ջ�Ĵ�С
int StackEmpty(Stack* s);//�п�
//------ջ����------------------------------------------