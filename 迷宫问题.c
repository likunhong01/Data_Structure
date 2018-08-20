#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6 //N*N的迷宫
#define length N * N//最大行走步数

typedef struct Pos
{
	int x;//横坐标0到N-1
	int y;//纵坐标0到N-1
}Pos;

typedef struct Stack
{
	Pos* _top;//栈顶指针
	Pos* _end;//栈底指针
	int stackSize;//栈的容量
}Stack;

void pathPrint();//打印路径
void MazeGetShortPath(Pos entry, Stack* path);//从第一部开始走
void myStackInit(Stack* s);//栈初始化
void zoulu(Pos now, int* arr);//走每一步的判断以及递归
void myStackPush(Stack* s, Pos x);//压入栈
Pos myStackPop(Stack* s);//弹出栈
int StackEmpty(Stack* s);//判空栈

Stack Path;//定义路径栈
Stack* s = &Path;//定义路径栈的指针，指向这个存放路径栈
Pos enterPoint;//起点
Pos finalPoint;//终点
int count = 0;//统计一共多少种走法



//------------------分割线，以上皆为头文件-----------------------------



void pathPrint()
{
	int x = 0;
	int y = 0;
	int i = 0;
	Pos* tmp = s->_end;//把栈底备份
	while (s->_top != s->_end)
	{
		i++;//第i步走到哪个格子
		x = s->_end->x;
		y = s->_end->y;
		s->_end++;
		printf("第%d步：(%d,%d)\n", i, x, y);
	}
	s->_end = tmp;//_end指针回到栈底
}

void zoulu(Pos now, int arr[N][N])
{
	if (finalPoint.x == now.x && finalPoint.y == now.y)//如果now点是终点，输出走法，并返回
	{
		count++;//给出路总数+1
		printf("--------第%d种走法--------\n",count);
		pathPrint();//打印步骤
		Pos p = myStackPop(s);//弹出终点
		arr[p.x][p.y] = 1;//重置终点可走（退回看看有没有别的走法）
		return;
	}
	//没到终点的情况：
	if (1 == arr[now.x - 1][now.y] && now.x - 1 >= 0)//如果now点的上面可以走并且不超过棋盘
	{
		Pos nowup;//创建一个now上面的点
		nowup.x = now.x - 1;
		nowup.y = now.y;
		myStackPush(s, nowup);//吧点压入栈
		arr[now.x - 1][now.y] = -1;//标记走过
		zoulu(nowup, arr);//走到上面一个点
	}
	if (1 == arr[now.x + 1][now.y] && now.x + 1 < N)//下面的点可走
	{
		Pos nowdn;
		nowdn.x = now.x + 1;
		nowdn.y = now.y;
		myStackPush(s, nowdn);
		arr[now.x + 1][now.y] = -1;//标记走过
		zoulu(nowdn, arr);
	}
	if (1 == arr[now.x][now.y - 1] && now.y - 1 >= 0)//左边点
	{
		Pos nowlf;
		nowlf.x = now.x;
		nowlf.y = now.y - 1;
		myStackPush(s, nowlf);
		arr[now.x][now.y - 1] = -1;//标记走过
		zoulu(nowlf, arr);
	}
	if (1 == arr[now.x][now.y + 1] && now.y + 1 < N)//右边点
	{
		Pos nowrg;
		nowrg.x = now.x;
		nowrg.y = now.y + 1;
		myStackPush(s, nowrg);
		arr[now.x][now.y + 1] = -1;//标记走过
		zoulu(nowrg, arr);
	}
	//如果都不可以走，说明是当前走的这条路的死路，就弹出这个点，并且重置。
	//当前递归层次结束会返回到上次调用的地方，并不会走重复路，这是代码核心。
	Pos p = myStackPop(s);
	arr[p.x][p.y] = 1;
}

void MazeGetShortPath(Pos entry, Stack* path, int arr[N][N])
{
	myStackPush(path, entry);//吧起点压入后就开始走路
	arr[entry.x][entry.y] = -1;//标记走过
	zoulu(*(s->_top - 1), arr);
}

void myStackInit(Stack* s)
{
	//给栈申请空间
	s->_end = (Pos*)malloc(length * sizeof(Pos));
	//判断是否申请成功
	if (!s->_end)
	{
		exit(0);
	}
	//初始化栈数组空间
	s->_top = s->_end;//最开始栈顶等于栈低
	s->stackSize = length;
	return;
}

void myStackPush(Stack* s, Pos x)
{
	//断言
	assert(s);
	if (s->stackSize == s->_top - s->_end)//判断栈空间是不是满了，满了就追加空间（动态栈）
	{
		printf("空间已满,追加空间");
		s->_end = (Pos*)realloc(s->_end, (s->stackSize + length) * sizeof(Pos));
		if (!s->_end)
		{
			exit(0);
		}
		s->_top = s->_end + s->stackSize;//设置栈顶
		s->stackSize += length;//设置栈长度
	}
	*(s->_top) = x;//设置x
	s->_top++;//指针后移
	return;
}

int StackEmpty(Stack* s)
{
	return 0 == (s->_top - s->_end);//或者判断两个指针是否相等也可以
}

Pos myStackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("栈为空");
		return;
	}
	return *--(s->_top);//栈顶指针下移并取出那个值
}

int main()
{
	//二维数组：1表示可以走，0表示不可以走
	int maze[N][N] =
	{
		{ 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0 },
	};
	//设置起点和终点坐标
	enterPoint.x = 5;
	enterPoint.y = 2;
	finalPoint.x = 4;
	finalPoint.y = 5;
	//初始化栈
	myStackInit(s);
	//开始走了
	MazeGetShortPath(enterPoint, s, &maze);

	system("pause");
	return 0;
}