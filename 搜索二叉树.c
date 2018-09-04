#include "搜索二叉树.h"

// 非递归 
//创建节点（辅助插入）
BSTreeNode* BuyBSTreeNode(BSTDataType x){
	BSTreeNode* pbst = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	pbst->_data = x;
	pbst->_left = NULL;//注意要把左右孩子置空，否则后面的while循环受影响
	pbst->_right = NULL;
	return pbst;
}

//插入
int BSTreeInsert(BSTreeNode** tree, BSTDataType x)
{	//注意要传入二级指针，因为tree的跟可能不存在，不存在的话一级指针访问就会出现错误
	BSTreeNode* cur, *parent;
	if (*tree == NULL)	//如果是空树，就创建一个根返回（1表示成功）
	{
		*tree = BuyBSTreeNode(x);
		return 1;
	}

	cur = *tree;//cur指向根节点
	parent = NULL;
	while (cur)	//cur指向当前节点，当前节点不为空时，x如果大于当前值就往右走，小于就往左走
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
		else//否则就是存在相同的，无法插入，返回0
		{
			return 0;
		}
	}

	//走到这里，cur已经为空，说明可以插入了，就按定义插入
	if (parent->_data < x)
	{
		parent->_right = BuyBSTreeNode(x);
	}
	else
	{
		parent->_left = BuyBSTreeNode(x);
	}

	return 1;//插入成功
}


////2.销毁（递归实现）
//void BSTreeDestory(BSTreeNode** tree)//销毁树
//{
//	if (tree == NULL)//非法操作
//		return;
//	if (*tree == NULL)//空树
//		return;
//	BSTreeNode* root = *tree;
//	BSTreeDestory(&root->_left);
//	BSTreeDestory(&root->_right);
//	BSTreeDestory(root);
//	*tree = NULL;
//	return;
//}


//查找
const BSTreeNode* BSTreeFind(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;//当前节点cur指向根节点
	while (cur)
	{
		//只要当前节点不为空，就根据定义往左往右找。
		if (cur->_data < x)
		{
			cur = cur->_right;
		}
		else if (cur->_data > x)
		{
			cur = cur->_left;
		}
		else//不大不小就找到了
		{
			return cur;
		}
	}
	return NULL;
}

//删除一个点，成功返回1，否则返回0
int BSTreeRemove(BSTreeNode** tree, BSTDataType x)
{
	//定义当前节点和父节点
	BSTreeNode *parent, *cur;
	cur = *tree;
	parent = *tree;

	//定义当前节点是他的父节点的左节点还是右节点,1为左
	int isleft = 1;

	//找到要删除的点和他的父节点
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
			printf("没有该节点");
			return 0;
		}
	}
	//寻找结束，cur指向要删除节点，parrent指向他的父节点，isleft = 1说明cur是parrent的左节点。

	//开始删除
	//1、是叶子节点
	if (cur->_left == NULL && cur->_right == NULL)
	{	
		//（1）如果是根节点直接删除
		if (cur == *tree)
		{
			cur = NULL;
			free(cur);
		}
		//（2）如果是左边就parrent->left = null ; free(left);
		else if (isleft)
		{
			parent->_left = NULL;
			free(cur);
		}
		//（3）如果是右边就删右边
		else
		{
			parent->_right = NULL;
			free(cur);
		}
	}
		


	//2、是带有一个子节点的节点
	//（1）带有的是左节点：
	else if (cur->_right == NULL)
	{
		//1>删除的节点是根，把左节点变成跟
		if (*tree == cur)
		{
			*tree = cur->_left;
			free(cur);
		}
		//2>删除的节点是parent的左节点，把parent的左指针指向cur的左节点。free(now)
		else if (isleft)
		{
			parent->_left = cur->_left;
			free(cur);
		}
		//3>是parent的右节点，把parent的右指针指向now的左节点。free(now)
		else
		{
			parent->_right = cur->_left;
			free(cur);
		}
	}

	//（2）带有的是右节点：
	else if (cur->_left == NULL)
	{
		//1>删除根，把右节点变成根
		if (*tree == cur)
		{
			*tree = cur->_right;
			free(cur);
		}
		//2>删的是p的左节点，把p的左接上now的右
		else if (isleft)
		{
			parent->_left = cur->_right;
			free(cur);
		}
		//3>删p的右，把p的右接上now的右节点
		else
		{
			parent->_right = cur->_right;
			free(cur);
		}
	}
		
			

	//3、删除有两个子节点的节点
	//寻找中序后继节点替换删除的节点，后继节点为，比删除节点大，但比他的右子树的任何一个节点都小（先右走，在一直坐走到底）
	else
	{
		//寻找后继节点的时候，要吧他从父亲那断开
		BSTreeNode* houji = getHouji(cur);

		//1>删除根，把后继节点变成根
		if (*tree == cur)
		{
			houji->_left = cur->_left;
			houji->_right = cur->_right;
			free(cur);
		}
		//2>删的是p的左节点，把p的左接上后继节点
		else if (isleft)
		{
			parent->_left = houji;
			houji->_left = cur->_left;
			houji->_right = cur->_right;
			free(cur);
		}
		//3>删p的右，把p的右接上后继节点，
		else
		{
			parent->_right = houji;
			houji->_left = cur->_left;
			houji->_right = cur->_right;
			free(cur);
		}
	}

}

//寻找中序后继节点
BSTreeNode* getHouji(BSTreeNode* del)
{
	//寻找后继节点的时候，要吧他从父亲那断开
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
// 递归插入
int BSTreeInsertR(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;

	//如果x大于当前节点，就去右子树插入
	if (x > cur->_data)
	{
		//如果右正好是空的，直接插入
		if (cur->_right == NULL)
		{
			
			cur->_right = BuyBSTreeNode(x);
		}
		//否则去右子树里继续想办法插入
		else
		{
			return BSTreeInsertR(cur->_right, x);
		}
	}
	//如果x小于当前节点，就去左子树插入
	else if (x < cur->_data)
	{
		if (cur->_left == NULL)//左孩子正好空
		{
			cur->_left = BuyBSTreeNode(x);
		}
		else//否则就去左子树插入
		{
			return BSTreeInsertR(cur->_left, x);
		}
	}
	else
	{
		return 0;//存在相同无法插入
	}
}

const BSTreeNode* BSTreeFindR(BSTreeNode** tree, BSTDataType x)
{
	BSTreeNode* cur = *tree;
	//大于就去右子树找，小于就去左子树找
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
		return cur;//找到了
	}
}

int BSTreeRemoveR(BSTreeNode** tree, BSTDataType x)
{
	//递归找到要删除的点
	//找到中序后继节点
	//继续上面的替换操作
	
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

	BSTreeRemove(&tree, 12);//删叶子
	BSTreeRemove(&tree, 6);
	BSTreeRemove(&tree, 2);
	BSTreeRemove(&tree, 3);
}