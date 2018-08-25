#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//栈和队列初始化长度
#define length 20

//二叉树节点数据类型
typedef int BTDataType;

//二叉树节点结构体
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

typedef BTNode DataType;//栈和队列存储类型

//栈的结构体
typedef struct Stack
{
	DataType* _top;
	DataType* _end; //栈顶指针
	int stackSize;
}Stack;

//队列节点结构体
typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

//队列结构体
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;


//------队列方法----------------------------------------
void QueueInit(Queue* q);//初始化
void QueuePush(Queue* q, DataType x);//加入
DataType QueuePop(Queue* q);//弹出
DataType QueueFront(Queue* q);//看头
DataType QueueBack(Queue* q);//看尾
int QueueSize(Queue* q);//看大小
int QueueEmpty(Queue* q);//判空
//------------------------------------------------------



//------二叉树方法--------------------------------------
// a是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);//创建
void BinaryTreeDestory(BTNode* root);//销毁二叉树

int BinaryTreeSize(BTNode* root);//统计节点个数
int BinaryTreeLeafSize(BTNode* root);//统计多少叶子
int BinaryTreeLevelKSize(BTNode* root, int k);//统计第k层有多少个节点

//遍历
//递归
void BinaryTreePrevOrder(BTNode* root);//前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历
void BinaryTreePostOrder(BTNode* root);//后序遍历

void BinaryTreeLevelOrder(BTNode* root);//层序遍历

//非递归
void BinaryTreePrevOrderNonR(BTNode* root);//前序
void BinaryTreeInOrderNonR(BTNode* root);//中序
void BinaryTreePostOrderNonR(BTNode* root);//后序

void TestBinaryTree();
//------------------------------------------------------



//------栈方法------------------------------------------
void StackInit(Stack* s);//初始化栈
void StackPush(Stack* s, DataType *x);//压栈
DataType* StackPop(Stack* s);//出栈
DataType* StackTop(Stack* s);//查看栈顶
int StackSize(Stack* s);//栈的大小
int StackEmpty(Stack* s);//判空
//------栈方法------------------------------------------