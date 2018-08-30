#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

typedef int dataType;

bool check(dataType *in, dataType *out, int len_in, int len_out)
{
	assert(in);
	assert(out);
	if (len_in != len_out)//���Ȳ��ȣ�����ƥ��
	{
		return false;
	}

	stack<dataType> s;
	int j = 0;
	//�ؼ��㣺ÿ��push�ж��Ƿ���out����һ����ջԪ�أ�����Ǿͳ��������Ҽ����ж��ܲ��ܳ���ѹ�������
	for (int i = 0; i < len_in; i++)
	{
		s.push(in[i]);
		while (s.size() > 0 && s.top() == out[j])
		{
			s.pop();
			j++;
		}
	}
	//���s������󶼳�����˵����ƥ���ϣ����û����Ͳ���ƥ�䡣
	if (0 == s.size())
	{
		return true;
	}
	return false;
}

int main()
{
	int in[] = { 1, 2, 3, 4, 5 };       //��ջ����  
	int out[] = { 4, 5, 3, 2, 1 };      //��ջ����  
	bool rs = check(in, out, sizeof(in) / sizeof(in[0]), sizeof(out) / sizeof(out[0]));
	if (rs)
		cout << "�Ϸ�" << endl;
	else
		cout << "���Ϸ�" << endl;
	system("pause");
	return 0;
}