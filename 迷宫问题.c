#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6 //N*N���Թ�
#define length N * N//������߲���

typedef struct Pos
{
	int x;//������0��N-1
	int y;//������0��N-1
}Pos;

typedef struct Stack
{
	Pos* _top;//ջ��ָ��
	Pos* _end;//ջ��ָ��
	int stackSize;//ջ������
}Stack;

void pathPrint();//��ӡ·��
void MazeGetShortPath(Pos entry, Stack* path);//�ӵ�һ����ʼ��
void myStackInit(Stack* s);//ջ��ʼ��
void zoulu(Pos now, int* arr);//��ÿһ�����ж��Լ��ݹ�
void myStackPush(Stack* s, Pos x);//ѹ��ջ
Pos myStackPop(Stack* s);//����ջ
int StackEmpty(Stack* s);//�п�ջ

Stack Path;//����·��ջ
Stack* s = &Path;//����·��ջ��ָ�룬ָ��������·��ջ
Pos enterPoint;//���
Pos finalPoint;//�յ�
int count = 0;//ͳ��һ���������߷�



//------------------�ָ��ߣ����Ͻ�Ϊͷ�ļ�-----------------------------



void pathPrint()
{
	int x = 0;
	int y = 0;
	int i = 0;
	Pos* tmp = s->_end;//��ջ�ױ���
	while (s->_top != s->_end)
	{
		i++;//��i���ߵ��ĸ�����
		x = s->_end->x;
		y = s->_end->y;
		s->_end++;
		printf("��%d����(%d,%d)\n", i, x, y);
	}
	s->_end = tmp;//_endָ��ص�ջ��
}

void zoulu(Pos now, int arr[N][N])
{
	if (finalPoint.x == now.x && finalPoint.y == now.y)//���now�����յ㣬����߷���������
	{
		count++;//����·����+1
		printf("--------��%d���߷�--------\n",count);
		pathPrint();//��ӡ����
		Pos p = myStackPop(s);//�����յ�
		arr[p.x][p.y] = 1;//�����յ���ߣ��˻ؿ�����û�б���߷���
		return;
	}
	//û���յ�������
	if (1 == arr[now.x - 1][now.y] && now.x - 1 >= 0)//���now�����������߲��Ҳ���������
	{
		Pos nowup;//����һ��now����ĵ�
		nowup.x = now.x - 1;
		nowup.y = now.y;
		myStackPush(s, nowup);//�ɵ�ѹ��ջ
		arr[now.x - 1][now.y] = -1;//����߹�
		zoulu(nowup, arr);//�ߵ�����һ����
	}
	if (1 == arr[now.x + 1][now.y] && now.x + 1 < N)//����ĵ����
	{
		Pos nowdn;
		nowdn.x = now.x + 1;
		nowdn.y = now.y;
		myStackPush(s, nowdn);
		arr[now.x + 1][now.y] = -1;//����߹�
		zoulu(nowdn, arr);
	}
	if (1 == arr[now.x][now.y - 1] && now.y - 1 >= 0)//��ߵ�
	{
		Pos nowlf;
		nowlf.x = now.x;
		nowlf.y = now.y - 1;
		myStackPush(s, nowlf);
		arr[now.x][now.y - 1] = -1;//����߹�
		zoulu(nowlf, arr);
	}
	if (1 == arr[now.x][now.y + 1] && now.y + 1 < N)//�ұߵ�
	{
		Pos nowrg;
		nowrg.x = now.x;
		nowrg.y = now.y + 1;
		myStackPush(s, nowrg);
		arr[now.x][now.y + 1] = -1;//����߹�
		zoulu(nowrg, arr);
	}
	//������������ߣ�˵���ǵ�ǰ�ߵ�����·����·���͵�������㣬�������á�
	//��ǰ�ݹ��ν����᷵�ص��ϴε��õĵط������������ظ�·�����Ǵ�����ġ�
	Pos p = myStackPop(s);
	arr[p.x][p.y] = 1;
}

void MazeGetShortPath(Pos entry, Stack* path, int arr[N][N])
{
	myStackPush(path, entry);//�����ѹ���Ϳ�ʼ��·
	arr[entry.x][entry.y] = -1;//����߹�
	zoulu(*(s->_top - 1), arr);
}

void myStackInit(Stack* s)
{
	//��ջ����ռ�
	s->_end = (Pos*)malloc(length * sizeof(Pos));
	//�ж��Ƿ�����ɹ�
	if (!s->_end)
	{
		exit(0);
	}
	//��ʼ��ջ����ռ�
	s->_top = s->_end;//�ʼջ������ջ��
	s->stackSize = length;
	return;
}

void myStackPush(Stack* s, Pos x)
{
	//����
	assert(s);
	if (s->stackSize == s->_top - s->_end)//�ж�ջ�ռ��ǲ������ˣ����˾�׷�ӿռ䣨��̬ջ��
	{
		printf("�ռ�����,׷�ӿռ�");
		s->_end = (Pos*)realloc(s->_end, (s->stackSize + length) * sizeof(Pos));
		if (!s->_end)
		{
			exit(0);
		}
		s->_top = s->_end + s->stackSize;//����ջ��
		s->stackSize += length;//����ջ����
	}
	*(s->_top) = x;//����x
	s->_top++;//ָ�����
	return;
}

int StackEmpty(Stack* s)
{
	return 0 == (s->_top - s->_end);//�����ж�����ָ���Ƿ����Ҳ����
}

Pos myStackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		printf("ջΪ��");
		return;
	}
	return *--(s->_top);//ջ��ָ�����Ʋ�ȡ���Ǹ�ֵ
}

int main()
{
	//��ά���飺1��ʾ�����ߣ�0��ʾ��������
	int maze[N][N] =
	{
		{ 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0 },
	};
	//���������յ�����
	enterPoint.x = 5;
	enterPoint.y = 2;
	finalPoint.x = 4;
	finalPoint.y = 5;
	//��ʼ��ջ
	myStackInit(s);
	//��ʼ����
	MazeGetShortPath(enterPoint, s, &maze);

	system("pause");
	return 0;
}