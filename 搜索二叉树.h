#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int BSTDataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;

	BSTDataType _data;
}BSTreeNode;

/////////////////////////////////////////////////////// 
// ·ÇµÝ¹é 
BSTreeNode* BuyBSTreeNode(BSTDataType x);
int BSTreeInsert(BSTreeNode** tree, BSTDataType x);
const BSTreeNode* BSTreeFind(BSTreeNode* tree, BSTDataType x);
int BSTreeRemove(BSTreeNode** tree, BSTDataType x);
void BSTreeDestory(BSTreeNode** tree);
BSTreeNode* getHouji(BSTreeNode* del);

/////////////////////////////////////////////////////// 
// µÝ¹é 
int BSTreeInsertR(BSTreeNode** tree, BSTDataType x);
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, BSTDataType x);
int BSTreeRemoveR(BSTreeNode** tree, BSTDataType x);
void test();

//void TestBSTree() 
//{ 
// //BSTreeNode* tree = NULL; 
// //BSTreeInsert(&tree, 4); 
// //BSTreeInsert(&tree, 2); 
// //BSTreeInsert(&tree, 1); 
// //BSTreeInsert(&tree, 3); 
// //BSTreeInsert(&tree, 2); 
// 
// //const BSTreeNode* node = BSTreeFind(tree, 2); 
// //printf("Find 2? %d\n", node->_data); 
// 
// int a[] = {5,3,4,1,7,8,2,6,0,9}; 
// BSTreeNode* tree = NULL; 
// 
// for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) 
// { 
// BSTreeInsert(&tree, a[i]); 
// } 
// 
// BSTreeInOrder(tree); 
// printf("\n"); 
// 
// BSTreeRemove(&tree, 4); 
// BSTreeRemove(&tree, 8); 
// BSTreeRemove(&tree, 3); 
// BSTreeRemove(&tree, 7); 
// BSTreeRemove(&tree, 5); 
// 
// BSTreeInOrder(tree); 
// printf("\n"); 
// 
// BSTreeRemove(&tree, 0); 
// BSTreeRemove(&tree, 1); 
// BSTreeRemove(&tree, 2); 
// BSTreeRemove(&tree, 3); 
// BSTreeRemove(&tree, 4); 
// BSTreeRemove(&tree, 5); 
// BSTreeRemove(&tree, 6); 
// BSTreeRemove(&tree, 7); 
// BSTreeRemove(&tree, 8); 
// BSTreeRemove(&tree, 9); 
// 
// BSTreeInOrder(tree); 
// printf("\n"); 
//};