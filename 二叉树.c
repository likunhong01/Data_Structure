#include "BT.h"

// arr��һ��ǰ�����������
BTNode* BinaryTreeCreate(BTNode* node, int* n, BTDataType* arr)//����
{
	//assert(node);
	//assert(arr);
	if (arr[*n] != NULL)
	{
		//�����ڵ�
		node = (BTNode *)malloc(sizeof(BTNode));
		node->_data = arr[(*n)];
		printf("�����ڵ㣺%d��\n", node->_data);

		(*n)++;
		node->_left = BinaryTreeCreate(node->_left, n, arr);
		(*n)++;
		node->_right = BinaryTreeCreate(node->_right, n, arr);
		return node;
	}
	else return NULL;
}

//���ٶ�����
void BinaryTreeDestory(BTNode* root)//����
{

}

//ͳ�ƽڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//ͳ�ƶ���Ҷ��
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

//ͳ�Ƶ�k���ж��ٸ��ڵ�
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

//����
//�ݹ�:
//ǰ�����
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

//�������
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

//����
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

//����
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, *root);
	printf("\n�������˳��");
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

//�ǵݹ�
void BinaryTreePrevOrderNonR(BTNode* root)//ǰ��
{
	Stack s;
	StackInit(&s);
	StackPush(&s, root);
	printf("\nǰ�����˳��");
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

void BinaryTreeInOrderNonR(BTNode* root)//����
{
	Stack s;
	StackInit(&s);
	BTNode *tmp = root;
	printf("\n�������˳��");
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

void BinaryTreePostOrderNonR(BTNode* root)//����
{
	Stack s;
	StackInit(&s);
	BTNode *now = root;
	BTNode *past = NULL;
	printf("\n�������˳��");

	//���ߵ����½�
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
			//�������ұߵ����½�
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