#include"栈.h"
#include<iostream>
using namespace std;
bool InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) return false;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool Push(SqStack& S, SElemType e)  //插入元素
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return true;
}

SElemType GetTop(SqStack S)
{
	if (S.top == S.base) return 0;
	return *(S.top - 1);
}

bool Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base) return false;
	e = *(--S.top);
	return true;
}

void conversion()//应用
{
	SqStack q;
	InitStack(q);
	int data,e;
	cout << "请输入要转换成2进制的十进制数：";
	cin >> data;
	while (data)
	{
		Push(q, data % 2);
		data = data / 2;
	}
	while (q.top!=q.base)
	{
		Pop(q, e);
		printf("%d", e);
	}
}