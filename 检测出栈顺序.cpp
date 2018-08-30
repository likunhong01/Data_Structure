#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

typedef int dataType;

bool check(dataType *in, dataType *out, int len_in, int len_out)
{
	assert(in);
	assert(out);
	if (len_in != len_out)//长度不等，不能匹配
	{
		return false;
	}

	stack<dataType> s;
	int j = 0;
	//关键点：每次push判断是否是out里下一个出栈元素，如果是就出掉，并且继续判断能不能出掉压在下面的
	for (int i = 0; i < len_in; i++)
	{
		s.push(in[i]);
		while (s.size() > 0 && s.top() == out[j])
		{
			s.pop();
			j++;
		}
	}
	//如果s里面最后都出掉了说明能匹配上，如果没出完就不能匹配。
	if (0 == s.size())
	{
		return true;
	}
	return false;
}

int main()
{
	int in[] = { 1, 2, 3, 4, 5 };       //入栈序列  
	int out[] = { 4, 5, 3, 2, 1 };      //出栈序列  
	bool rs = check(in, out, sizeof(in) / sizeof(in[0]), sizeof(out) / sizeof(out[0]));
	if (rs)
		cout << "合法" << endl;
	else
		cout << "不合法" << endl;
	system("pause");
	return 0;
}