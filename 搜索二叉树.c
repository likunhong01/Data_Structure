#include "����������.h"

// �ǵݹ� 
//�����ڵ㣨�������룩
BSTreeNode* BuyBSTreeNode(BSTDataType x){
	BSTreeNode* pbst = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	pbst->_data = x;
	pbst->_left = NULL;//ע��Ҫ�����Һ����ÿգ���������whileѭ����Ӱ��
	pbst->_right = NULL;
	return pbst;
}

//����
int BSTreeInsert(BSTreeNode** tree, BSTDataType x)
{	//ע��Ҫ�������ָ�룬��Ϊtree�ĸ����ܲ����ڣ������ڵĻ�һ��ָ����ʾͻ���ִ���
	BSTreeNode* cur, *parent;
	if (*tree == NULL)	//����ǿ������ʹ���һ�������أ�1��ʾ�ɹ���
	{
		*tree = BuyBSTreeNode(x);
		return 1;
	}

	cur = *tree;//curָ����ڵ�
	parent = NULL;
	while (cur)	//curָ��ǰ�ڵ㣬��ǰ�ڵ㲻Ϊ��ʱ��x������ڵ�ǰֵ�������ߣ�С�ھ�������
	{
		if (cur->_data >x)
		{
			parent = cur;
			if (cur->_left)
			{
				cur = cur->_left;
			}
			else
			{
				break;
			}
		}
		else if (cur->_data < x)
		{
			parent = cur;
			if (cur->_right)
			{
				cur = cur->_right;
			}
			else
			{
				break;
			}
		}
		else//������Ǵ�����ͬ�ģ��޷����룬����0
		{
			return 0;
		}
	}

	//�ߵ����cur�Ѿ�Ϊ�գ�˵�����Բ����ˣ��Ͱ��������
	if (parent->_data < x)
	{
		parent->_right = BuyBSTreeNode(x);
	}
	else
	{
		parent->_left = BuyBSTreeNode(x);
	}

	return 1;//����ɹ�
}


////2.���٣��ݹ�ʵ�֣�
//void BSTreeDestory(BSTreeNode** tree)//������
//{
//	if (tree == NULL)//�Ƿ�����
//		return;
//	if (*tree == NULL)//����
//		return;
//	BSTreeNode* root = *tree;
//	BSTreeDestory(&root->_left);
//	BSTreeDestory(&root->_right);
//	BSTreeDestory(root);
//	*tree = NULL;
//	return;
//}


//����
const BSTreeNode* BSTreeFind(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;//��ǰ�ڵ�curָ����ڵ�
	while (cur)
	{
		//ֻҪ��ǰ�ڵ㲻Ϊ�գ��͸��ݶ������������ҡ�
		if (cur->_data < x)
		{
			cur = cur->_right;
		}
		else if (cur->_data > x)
		{
			cur = cur->_left;
		}
		else//����С���ҵ���
		{
			return cur;
		}
	}
	return NULL;
}

//ɾ��һ���㣬�ɹ�����1�����򷵻�0
int BSTreeRemove(BSTreeNode** tree, BSTDataType x)
{
	//���嵱ǰ�ڵ�͸��ڵ�
	BSTreeNode *parent, *cur;
	cur = *tree;
	parent = *tree;

	//���嵱ǰ�ڵ������ĸ��ڵ����ڵ㻹���ҽڵ�,1Ϊ��
	int isleft = 1;

	//�ҵ�Ҫɾ���ĵ�����ĸ��ڵ�
	while (cur->_data != x)
	{
		parent = cur;
		if (cur->_data > x)
		{
			cur = cur->_left;
			isleft = 1;
		}
		else
		{
			cur = cur->_right;
			isleft = 0;
		}

		if (cur == NULL)
		{
			printf("û�иýڵ�");
			return 0;
		}
	}
	//Ѱ�ҽ�����curָ��Ҫɾ���ڵ㣬parrentָ�����ĸ��ڵ㣬isleft = 1˵��cur��parrent����ڵ㡣

	//��ʼɾ��
	//1����Ҷ�ӽڵ�
	if (cur->_left == NULL && cur->_right == NULL)
	{	
		//��1������Ǹ��ڵ�ֱ��ɾ��
		if (cur == *tree)
		{
			cur = NULL;
			free(cur);
		}
		//��2���������߾�parrent->left = null ; free(left);
		else if (isleft)
		{
			parent->_left = NULL;
			free(cur);
		}
		//��3��������ұ߾�ɾ�ұ�
		else
		{
			parent->_right = NULL;
			free(cur);
		}
	}
		


	//2���Ǵ���һ���ӽڵ�Ľڵ�
	//��1�����е�����ڵ㣺
	else if (cur->_right == NULL)
	{
		//1>ɾ���Ľڵ��Ǹ�������ڵ��ɸ�
		if (*tree == cur)
		{
			*tree = cur->_left;
			free(cur);
		}
		//2>ɾ���Ľڵ���parent����ڵ㣬��parent����ָ��ָ��cur����ڵ㡣free(now)
		else if (isleft)
		{
			parent->_left = cur->_left;
			free(cur);
		}
		//3>��parent���ҽڵ㣬��parent����ָ��ָ��now����ڵ㡣free(now)
		else
		{
			parent->_right = cur->_left;
			free(cur);
		}
	}

	//��2�����е����ҽڵ㣺
	else if (cur->_left == NULL)
	{
		//1>ɾ���������ҽڵ��ɸ�
		if (*tree == cur)
		{
			*tree = cur->_right;
			free(cur);
		}
		//2>ɾ����p����ڵ㣬��p�������now����
		else if (isleft)
		{
			parent->_left = cur->_right;
			free(cur);
		}
		//3>ɾp���ң���p���ҽ���now���ҽڵ�
		else
		{
			parent->_right = cur->_right;
			free(cur);
		}
	}
		
			

	//3��ɾ���������ӽڵ�Ľڵ�
	//Ѱ�������̽ڵ��滻ɾ���Ľڵ㣬��̽ڵ�Ϊ����ɾ���ڵ�󣬵����������������κ�һ���ڵ㶼С�������ߣ���һֱ���ߵ��ף�
	else
	{
		//Ѱ�Һ�̽ڵ��ʱ��Ҫ�����Ӹ����ǶϿ�
		BSTreeNode* houji = getHouji(cur);

		//1>ɾ�������Ѻ�̽ڵ��ɸ�
		if (*tree == cur)
		{
			houji->_left = cur->_left;
			houji->_right = cur->_right;
			free(cur);
		}
		//2>ɾ����p����ڵ㣬��p������Ϻ�̽ڵ�
		else if (isleft)
		{
			parent->_left = houji;
			houji->_left = cur->_left;
			houji->_right = cur->_right;
			free(cur);
		}
		//3>ɾp���ң���p���ҽ��Ϻ�̽ڵ㣬
		else
		{
			parent->_right = houji;
			houji->_left = cur->_left;
			houji->_right = cur->_right;
			free(cur);
		}
	}

}

//Ѱ�������̽ڵ�
BSTreeNode* getHouji(BSTreeNode* del)
{
	//Ѱ�Һ�̽ڵ��ʱ��Ҫ�����Ӹ����ǶϿ�
	BSTreeNode* parrent = del;
	BSTreeNode *now = del;
	BSTreeNode *houji = del->_right;
	
	if (!houji->_left)
	{
		parrent->_right = NULL;
	}
	else
	{
		while(houji->_left)
		{
			parrent = houji;
			houji = houji->_left;
		}
		parrent->_left = NULL;
	}
	return houji;
}



void BSTreeDestory(BSTreeNode* tree);


/////////////////////////////////////////////////////// 
// �ݹ����
int BSTreeInsertR(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;

	//���x���ڵ�ǰ�ڵ㣬��ȥ����������
	if (x > cur->_data)
	{
		//����������ǿյģ�ֱ�Ӳ���
		if (cur->_right == NULL)
		{
			
			cur->_right = BuyBSTreeNode(x);
		}
		//����ȥ�������������취����
		else
		{
			return BSTreeInsertR(cur->_right, x);
		}
	}
	//���xС�ڵ�ǰ�ڵ㣬��ȥ����������
	else if (x < cur->_data)
	{
		if (cur->_left == NULL)//�������ÿ�
		{
			cur->_left = BuyBSTreeNode(x);
		}
		else//�����ȥ����������
		{
			return BSTreeInsertR(cur->_left, x);
		}
	}
	else
	{
		return 0;//������ͬ�޷�����
	}
}

const BSTreeNode* BSTreeFindR(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;
	//���ھ�ȥ�������ң�С�ھ�ȥ��������
	if (x > cur->_data)
	{
		return BSTreeFindR(cur->_right, x);
	}
	else if (x < cur->_data)
	{
		return BSTreeFindR(cur->_left, x);
	}
	else
	{
		return cur;//�ҵ���
	}
}

int BSTreeRemoveR(BSTreeNode** tree, BSTDataType x)
{
	//�ݹ��ҵ�Ҫɾ���ĵ�
	//�ҵ������̽ڵ�
	//����������滻����
	
}

void test()
{
	BSTreeNode* tree = NULL;
	BSTreeInsert(&tree,5);
	BSTreeInsert(&tree, 3);
	BSTreeInsert(&tree, 2);
	BSTreeInsert(&tree, 4);
	BSTreeInsert(&tree, 1);
	BSTreeInsert(&tree, 8);
	BSTreeInsert(&tree, 10);
	BSTreeInsert(&tree, 6);
	BSTreeInsert(&tree, 7);
	BSTreeInsert(&tree, 9);
	BSTreeInsert(&tree, 12);

	BSTreeRemove(&tree, 12);//ɾҶ��
	BSTreeRemove(&tree, 6);
	BSTreeRemove(&tree, 2);
	BSTreeRemove(&tree, 3);
}