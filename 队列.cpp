#include"����.h"
#include<iostream>
using namespace std;

//����һ���ն���
bool InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) return false;
	Q.front->next = NULL;
	return true;
}

//����Ԫ��
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

//���ٶ���
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

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
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


//ȡ��ͷԪ��
int Gettop(LinkQueue Q)
{
	return Q.front->next->data;
}
//ȡ��βԪ��
int Getrear(LinkQueue Q)
{
	return Q.rear->data;
}

//չʾ���������е�Ԫ��
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
	int t=1;//�Զ�ȡ��
	char ch;
	while (flag)
	{
		printf("����������(a�ǻ�ȡ�����ţ�n�Ǿ��q��ֹͣ�Һ�)��");
		cin >> ch;
		switch (ch)
		{
		case 'a':
			printf("\n������Ϊ%d\n",t);
			EnQueue(Q, t++);
			break;
		case 'n':
			if (!Empty_Q(Q))
			{
				DEqueue(Q, n);
				printf("\n������Ϊ%d�Ĳ��˾���\n", n);
			}
			else
				printf("\n�޲��˵ȴ�����");
			break;
		case 'q':
			printf("\nֹͣ�Һţ����в������ξ��");
			while (!Empty_Q(Q))
			{
				DEqueue(Q, n);
				printf("\n������Ϊ%d�Ĳ��˾���", n);
			}
			flag = 0;
			break;
		default:printf("��Ч���\n");
			break;
		}
	}
}