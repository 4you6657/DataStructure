#include"ͼ.h"
bool visited[MaxVertexNum];
void CreateMGraph(MGraph* G)
{
	int i, j, k;
	char ch;
	printf("�����붥�����ͱ����������ʽΪ�������� ��������\n");
	scanf_s("%d %d", &(G->n), &(G->e));
	printf("�����붥����Ϣ�������ʽΪ�������<CR>����\n");
	for (i = 0;i < G->n;i++)
		scanf_s("\n%c", &(G->vexs[i]));
	for (i = 0;i < G->n;i++)
		for (j = 0;j < G->n;j++) G->edges[i][j] = 0;
	printf("������ÿ���߶�Ӧ�������������ţ������ʽΪ��i j����\n");
	for (k = 0;k < G->e;k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
	}
}

int degree1(MGraph* G, int numb)  //��дһ���㷨������ڽӾ����ʾ������ͼ�����Ϊnumb�Ķ���Ķ�����
{
	int n = 0;
	for (int i = 0;i < G->n;i++)
	{
		if (G->edges[numb][i] != 0)
			n++;
	}
	return n;
}


void Initialjuzheng(MGraph* G)
{

	CreateMGraph(G);
	printf("����Ϊ��");
	for (int i = 0;i < G->n;i++)
		printf("%c ", G->vexs[i]);
	putchar('\n');
	for (int i = 0;i < G->n;i++)
	{
		for (int j = 0;j < G->n;j++)
			printf("%d ", G->edges[i][j]);
		putchar('\n');
	}
	int numb = 0;
	putchar('\n');

}

/*������ȱ������ڽӾ���*/
void DFS(MGraph* G, int i)
{
	int j;
	visited[i] = true;
	printf("%c", G->vexs[i]); /*��ӡ���㡣Ҳ������������*/
	for (j = 0;j < G->n;j++)
		if (G->edges[i][j] == 1 && !visited[j])
			DFS(G, j);   /*��δ���ʵ��ڽӶ���ݹ����*/
}

/*�ڽӾ������ȱ�������*/
void DFSTraverse(MGraph* G)
{
	int i;
	for (i = 0;i < G->n;i++)
		visited[i] = false;   /*��ʼ�����еĶ���״̬����δ���ʵ�״̬*/
	for (i = 0;i < G->n;i++)
		if (!visited[i]) /*��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ��*/
			DFS(G, i);
}



//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ�������ֵ��
int Out_queue(LinkQueue& Q)
{
	int e;
	if (Q.front == Q.rear) return -1;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return e;
}
/*������ȱ������ڽӾ���*/
void BFSM(MGraph* G, int k)
{
	int i, j;
	LinkQueue Q;
	InitQueue(Q);
	printf("%c", G->vexs[k]);
	visited[k] = true;
	EnQueue(Q, k);
	while (!Empty_Q(Q))
	{
		i = Out_queue(Q);
		for(j=0;j<G->n;j++)
			if (G->edges[i][j] == 1 && !visited[j])
			{
				printf("%c", G->vexs[j]);
				visited[j] = true;
				EnQueue(Q, j);
			}
	}
}

/*�ڽӾ���Ĺ�ȱ�������*/
void BFSTraverseAL(MGraph* G)
{
	int i;
	for (i = 0; i < G->n; i++) 
		visited[i] = false;
	for (i = 0; i < G->n; i++)
		if (!visited[i]) BFSM(G, i); 
}


int Findv(MGraph* G, char v) //��λ
{
	int i, t;
	for (i = 0;i < G->n;i++)
	{
		if (v == G->vexs[i])
		{
			t = i;
			break;
		}
	}
	if (t >= 0 && t < G->n)
		return t;
	else return -1;
}

int FirstAdjVex(MGraph* G, char v)//����v�ĵ�һ���ڽӶ���
{
	int i,t;
	t = Findv(G, v);
	if (t >= 0 && t < G->n)
	{
		for (i = 0; i < G->n; i++)
		{
			if (G->edges[t][i])
			{
				return i;
			}
		}
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(MGraph* G, char v, char w)//����v�ģ������w�ģ���һ���ڽӶ���
{
	int i;
	int v1, w1;
	v1 = Findv(G, v);
	w1 = Findv(G, w);
	if (v1 >= 0 && v1 < G->n)
	{
		if (w1 >= 0 && w1 < G->n)
		{
			for (i = w1 + 1; i < G->n; i++)
			{
				if (G->edges[v1][i])
				{
					return i;
				}
			}
		}
	}
	return -1;
}//NextAdjVex

void linjiejuzhen(MGraph* G)
{
	for (int i = 0;i < G->n;i++)
	{
		for (int j = 0;j < G->n;j++)
			printf("%d ", G->edges[i][j]);
		putchar('\n');
	}
}
void InsetE(MGraph* G, int v, int w)
{
	if (v >= 0 && v < G->n && w >= 0 && w < G->n)
	{
		G->edges[v][w] = 1;
	}
	else printf("����ʧ��");
	putchar('\n');
	printf("�µ��ڽӾ���Ϊ��\n");
	linjiejuzhen(G);
}
void DeleteE(MGraph* G, int v, int w)
{
	if (v >= 0 && v < G->n && w >= 0 && w < G->n)
	{
		G->edges[v][w] = 0;
	}
	else printf("ɾ��ʧ��");
	putchar('\n');
	printf("�µ��ڽӾ���Ϊ��\n");
	linjiejuzhen(G);
}

void InsetV(MGraph* G, char dian)//�����
{
	G->n++;
	G->vexs[G->n - 1] = dian;
	for(int i=0;i<G->n;i++)
	{
		G->edges[G->n - 1][i] = 0;
	}
	for (int i = 0;i < G->n;i++)
	{
		G->edges[i][G->n - 1] = 0;
	}
	linjiejuzhen(G);
}
void DeleteV(MGraph* G)//ɾ�����һ����
{
	for (int i = 0;i < G->n;i++)
	{
		G->edges[G->n - 1][i] = 0;
	}
	for (int i = 0;i < G->n;i++)
	{
		G->edges[i][G->n - 1] = 0;
	}
	G->n--;
	linjiejuzhen(G);
}





void StackInit(Stack1* S)
{
	S->top = 0;
}

bool StackEmpty(Stack1* S)
{
	if (S->top == 0)
		return true;
	return false;
}

bool StackFull(Stack1* S)
{
	if (S->top == STACK_MAXSIZE - 1)
		return true;
	return false;
}

bool StackPop(Stack1* S, int* e)
{
	if (StackEmpty(S))
		return false;
	*e = S->data[S->top--];
	return true;
}

bool StackPush(Stack1* S, int e)
{
	if (StackFull(S))
		return false;
	S->data[++S->top] = e;
	return true;
}


//�ڽӾ���ʵ����������
bool MGraphTopologicalSort(MGraph* G)
{
	//ѭ������
	int i, j, k;
	//�����������������������߹��Ľڵ���Ŀ
	int count = 0;
	//ջ
	Stack1 S;
	StackInit(&S);
	//��ʼ�����ݣ������е����Ϊ0�ļ���ջ
	for (i = 0;i < G->n;i++)
	{
		if (G->in[i] == 0)
		{
			StackPush(&S, i);//���Ϊ0�Ķ������ջ
		}
	}
	while (!StackEmpty(&S))
	{
		StackPop(&S, &k);
		printf("%c->", G->vexs[k]);
		count++;
		for (i = 0;i < G->n;i++)
		{
			if (G->edges[k][i] == 1)
			{
				G->in[i]--;
				if (G->in[i] == 0)
				{
					StackPush(&S, i);
				}
			}
		}
	}
	//�������õ�����������Ľڵ���ĿС���ܵģ�˵��������ͨͼ
	if (count < G->n)
		return false;
	return true;
}

//Ӧ�ó�ʼ������
void llljuzhen(MGraph* G)
{
	int i, j, k;
	printf("�����붥�����ͱ����������ʽΪ�������� ��������\n");
	scanf_s("%d %d", &(G->n), &(G->e));
	printf("�����붥����Ϣ�������ʽΪ�������<CR>����\n");
	for (i = 0;i < G->n;i++)
		scanf_s("\n%c", &(G->vexs[i]));
	//��ȳ�ʼ��
	for (i = 0;i < G->n;i++)
	{
		G->in[i] = 0;
	}
	//���б߳�ʼ��
	for (i = 0;i < G->n;i++)
		for (j = 0;j < G->n;j++) G->edges[i][j] = 0;
	printf("������ÿ���߶�Ӧ�������������ţ������ʽΪ��i j����\n");
	for (k = 0;k < G->e;k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
		G->in[j]++;
	}

	printf("����Ϊ��");
	for (int i = 0;i < G->n;i++)
		printf("%c ", G->vexs[i]);
	putchar('\n');
	for (int i = 0;i < G->n;i++)
	{
		for (int j = 0;j < G->n;j++)
			printf("%d ", G->edges[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void linjieyingyong()
{
	MGraph* G = new MGraph;
	llljuzhen(G);
	MGraphTopologicalSort(G);
}


