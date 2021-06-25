#include"队列.h"
#include<iostream>
using namespace std;

//构造一个空队列
bool InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) return false;
	Q.front->next = NULL;
	return true;
}

//插入元素
bool EnQueue(LinkQueue& Q, int e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return false;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

//销毁队列
bool DEstroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return true;
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
bool DEqueue(LinkQueue& Q, int& e)
{
	if (Q.front == Q.rear) return false;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;  
	free(p);
	return true;
}


//取队头元素
int Gettop(LinkQueue Q)
{
	return Q.front->next->data;
}
//取队尾元素
int Getrear(LinkQueue Q)
{
	return Q.rear->data;
}

//展示队列中所有的元素
void display(LinkQueue Q)
{
	if (Q.front == Q.rear) return;
	QueuePtr q = Q.front->next;
	while (q != NULL)
	{
		printf("%d\n", q->data);
		q = q->next;
	}
}

bool Empty_Q(LinkQueue Q)
{
	if (Q.front == Q.rear) return true;
	else return false;
}




void SeeDoctor()
{
	LinkQueue Q;
	InitQueue(Q);
	int flag = 1;
	int n;
	int t=1;//自动取号
	char ch;
	while (flag)
	{
		printf("请输入命令(a是获取病历号，n是就诊，q是停止挂号)：");
		cin >> ch;
		switch (ch)
		{
		case 'a':
			printf("\n病历号为%d\n",t);
			EnQueue(Q, t++);
			break;
		case 'n':
			if (!Empty_Q(Q))
			{
				DEqueue(Q, n);
				printf("\n病历号为%d的病人就诊\n", n);
			}
			else
				printf("\n无病人等待就诊");
			break;
		case 'q':
			printf("\n停止挂号，下列病人依次就诊：");
			while (!Empty_Q(Q))
			{
				DEqueue(Q, n);
				printf("\n病历号为%d的病人就诊", n);
			}
			flag = 0;
			break;
		default:printf("无效命令！\n");
			break;
		}
	}
}