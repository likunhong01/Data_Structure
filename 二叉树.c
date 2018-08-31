#include "BT.h"

// arr是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTNode* node, int* n, BTDataType* arr)//创建
{
	//assert(node);
	//assert(arr);
	if (arr[*n] != NULL)
	{
		//创建节点
		node = (BTNode *)malloc(sizeof(BTNode));
		node->_data = arr[(*n)];
		printf("创建节点：%d。\n", node->_data);

		(*n)++;
		node->_left = BinaryTreeCreate(node->_left, n, arr);
		(*n)++;
		node->_right = BinaryTreeCreate(node->_right, n, arr);
		return node;
	}
	else return NULL;
}

//销毁二叉树
void BinaryTreeDestory(BTNode* root)//销毁
{

}

//统计节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//统计多少叶子
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//统计第k层有多少个节点
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (1 == k)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//遍历
//递归:
//前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d\n", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	BinaryTreePrevOrder(root->_left);
	printf("%d\n", root->_data);
	BinaryTreePrevOrder(root->_right);
}

//后序
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%d\n", root->_data);
}

//层序
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, *root);
	printf("\n层序遍历顺序：");
	while (!QueueEmpty(&q))
	{
		BTNode tmp = QueuePop(&q);
		printf("%d  ", tmp._data);
		if (tmp._left != NULL)
		{
			QueuePush(&q, *(tmp._left));
		}
		if (tmp._right != NULL)
		{
			QueuePush(&q, *(tmp._right));
		}
	}
}

//非递归
void BinaryTreePrevOrderNonR(BTNode* root)//前序
{
	Stack s;
	StackInit(&s);
	StackPush(&s, root);
	printf("\n前序遍历顺序：");
	while (!StackEmpty(&s))
	{
		BTNode tmp = *StackPop(&s);
		printf("%d  ", tmp._data);
		if (tmp._right != NULL)
		{
			StackPush(&s, (tmp._right));
		}
		if (tmp._left != NULL)
		{
			StackPush(&s, (tmp._left));
		}
	}
}

void BinaryTreeInOrderNonR(BTNode* root)//中序
{
	Stack s;
	StackInit(&s);
	BTNode *tmp = root;
	printf("\n中序遍历顺序：");
	while (tmp || !StackEmpty(&s))
	{
		while (tmp)
		{
			StackPush(&s, tmp);
			tmp = tmp->_left;
		}
		tmp = StackPop(&s);
		printf("%d  ", tmp->_data);
		
		tmp = tmp->_right;
	}
}

void BinaryTreePostOrderNonR(BTNode* root)//后序
{
	Stack s;
	StackInit(&s);
	BTNode *now = root;
	BTNode *past = NULL;
	printf("\n后序遍历顺序：");

	//先走到左下角
	while (now)
	{
		StackPush(&s, now);
		now = now->_left;
	}

	while (!StackEmpty(&s))
	{
		now = StackPop(&s);

		if (now->_right == NULL || now->_right == past)
		{
			printf("%d  ", now->_data);
			past = now;
		}
		else
		{
			StackPush(&s, now);
			now = now->_right;
			//再跳到右边的左下角
			while (now)
			{
				StackPush(&s, now);
				now = now->_left;
			}
		}
	}
}

int main()
{
	BTNode root;
	int a[15] = { 1, 2, 6, NULL, NULL, 3, NULL, NULL, 4, 5, NULL, NULL, 7, NULL, NULL };
	int n = 0;
	root = *BinaryTreeCreate(&root, &n, a);
	BinaryTreeLevelOrder(&root);
	BinaryTreePrevOrderNonR(&root);
	BinaryTreeInOrderNonR(&root);
	BinaryTreePostOrderNonR(&root);
	system("pause");
	return 0;
}