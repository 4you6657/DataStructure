#include"图.h"
bool visited[MaxVertexNum];
void CreateMGraph(MGraph* G)
{
	int i, j, k;
	char ch;
	printf("请输入顶点数和边数（输入格式为：顶点数 边数）：\n");
	scanf_s("%d %d", &(G->n), &(G->e));
	printf("请输入顶点信息（输入格式为：顶点号<CR>）：\n");
	for (i = 0;i < G->n;i++)
		scanf_s("\n%c", &(G->vexs[i]));
	for (i = 0;i < G->n;i++)
		for (j = 0;j < G->n;j++) G->edges[i][j] = 0;
	printf("请输入每条边对应的两个顶点的序号（输入格式为：i j）：\n");
	for (k = 0;k < G->e;k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
	}
}

int degree1(MGraph* G, int numb)  //编写一个算法，求出邻接矩阵表示的无向图中序号为numb的顶点的度数。
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
	printf("顶点为：");
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

/*深度优先遍历（邻接矩阵）*/
void DFS(MGraph* G, int i)
{
	int j;
	visited[i] = true;
	printf("%c", G->vexs[i]); /*打印顶点。也可以其他操作*/
	for (j = 0;j < G->n;j++)
		if (G->edges[i][j] == 1 && !visited[j])
			DFS(G, j);   /*对未访问的邻接顶点递归调用*/
}

/*邻接矩阵的深度遍历操作*/
void DFSTraverse(MGraph* G)
{
	int i;
	for (i = 0;i < G->n;i++)
		visited[i] = false;   /*初始化所有的顶点状态都是未访问的状态*/
	for (i = 0;i < G->n;i++)
		if (!visited[i]) /*对未访问过的顶点调用DFS，若是连通图，只会执行一次*/
			DFS(G, i);
}



//若队列不空，则删除Q的队头元素，并返回值；
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
/*广度优先遍历（邻接矩阵）*/
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

/*邻接矩阵的广度遍历操作*/
void BFSTraverseAL(MGraph* G)
{
	int i;
	for (i = 0; i < G->n; i++) 
		visited[i] = false;
	for (i = 0; i < G->n; i++)
		if (!visited[i]) BFSM(G, i); 
}


int Findv(MGraph* G, char v) //定位
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

int FirstAdjVex(MGraph* G, char v)//返回v的第一个邻接顶点
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

int NextAdjVex(MGraph* G, char v, char w)//返回v的（相对于w的）下一个邻接顶点
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
	else printf("插入失败");
	putchar('\n');
	printf("新的邻接矩阵为：\n");
	linjiejuzhen(G);
}
void DeleteE(MGraph* G, int v, int w)
{
	if (v >= 0 && v < G->n && w >= 0 && w < G->n)
	{
		G->edges[v][w] = 0;
	}
	else printf("删除失败");
	putchar('\n');
	printf("新的邻接矩阵为：\n");
	linjiejuzhen(G);
}

void InsetV(MGraph* G, char dian)//插入点
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
void DeleteV(MGraph* G)//删除最后一个点
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


//邻接矩阵实现拓扑排序
bool MGraphTopologicalSort(MGraph* G)
{
	//循环变量
	int i, j, k;
	//计数器，计算拓扑排序所走过的节点数目
	int count = 0;
	//栈
	Stack1 S;
	StackInit(&S);
	//初始化数据，把所有的入度为0的加入栈
	for (i = 0;i < G->n;i++)
	{
		if (G->in[i] == 0)
		{
			StackPush(&S, i);//入度为0的顶点号入栈
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
	//如果计算得到的拓扑排序的节点数目小于总的，说明不是连通图
	if (count < G->n)
		return false;
	return true;
}

//应用初始化矩阵
void llljuzhen(MGraph* G)
{
	int i, j, k;
	printf("请输入顶点数和边数（输入格式为：顶点数 边数）：\n");
	scanf_s("%d %d", &(G->n), &(G->e));
	printf("请输入顶点信息（输入格式为：顶点号<CR>）：\n");
	for (i = 0;i < G->n;i++)
		scanf_s("\n%c", &(G->vexs[i]));
	//入度初始化
	for (i = 0;i < G->n;i++)
	{
		G->in[i] = 0;
	}
	//所有边初始化
	for (i = 0;i < G->n;i++)
		for (j = 0;j < G->n;j++) G->edges[i][j] = 0;
	printf("请输入每条边对应的两个顶点的序号（输入格式为：i j）：\n");
	for (k = 0;k < G->e;k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
		G->in[j]++;
	}

	printf("顶点为：");
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


