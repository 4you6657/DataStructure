#pragma once
// 链表
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

bool GetElem(LinkList L, int i, ElemType& e);
void ListInsert(LinkList& L, int i, ElemType e);
void ListDelete(LinkList& L, int i, ElemType& e);
void display(LinkList L);
void InitList(LinkList& L);
void delete3(LinkList& L, int min, int max);


//多项式
typedef struct PolyNode
{
	int coef; //系数
	int expn; //指数
	struct PolyNode* next;
}PilyNode, * PolyList;

void duoxiangshi();
PolyList polycreate();
void AddPolyn(PolyList polya, PolyList polyb);
void display(PolyList polya1);
bool GetElem(LinkList L, int i, ElemType& e) //查找第i个元素，并赋值给e
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return false;
	e = p->data;
	return true;
}

void ListInsert(LinkList& L, int i, ElemType e)//在第i个位置插入元素e
{
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		printf("输入位置错误\n");
		return;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void ListDelete(LinkList& L, int i, ElemType& e)//删除第i个元素
{
	LNode* p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
	{
		printf("输入位置错误\n");
		return;

	}

	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
}

void display(LinkList L)//输出所有的值
{
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
}

void InitList(LinkList& L)
{
	LNode* s = new LNode;
	L = s;
	s->next = NULL;
	printf("创建成功\n");
}

////设计一个删除表中所有值小于max但大于min的元素的算法。
//void delete2(LinkList& L, int min, int max)
//{
//	int i = 1, e, r;
//	while (GetElem(L, i, e))
//	{
//		if (e<max && e>min)
//		{
//			ListDelete(L, i, r);
//			continue;
//		}
//		i++;
//	}
//}

////设计一个删除表中所有值小于max但大于min的元素的算法。
void delete3(LinkList& L, int min, int max)
{
	int i = 1, e, r;
	LinkList q = L;
	LinkList p = L->next;
	while (p != NULL)
	{
		if (p->data<max && p->data>min)
		{
			q->next = p->next;
			free(p);
			p = q->next;
		}
		else
		{
			q = q->next;
			p = p->next;
		}

	}
}


//多项式
void duoxiangshi()
{
	PolyList q, w;
	printf("请输入第一个多项式：\n");
	q = polycreate();
	printf("请输入第二个多项式：\n");
	w = polycreate();
	AddPolyn(q, w);
	display(q);
}

PolyList polycreate()
{
	PolyNode* head, * rear, * s;
	int c, e;
	head = (PolyList)malloc(sizeof(PolyNode));//头结点
	rear = head;
	scanf_s("%d %d", &c, &e);
	while (c != 0)
	{
		s = (PolyList)malloc(sizeof(PolyNode));
		s->coef = c; s->expn = e;
		rear->next = s;
		rear = s;
		scanf_s("%d %d", &c, &e);
	}
	rear->next = NULL;
	return(head);
}

void AddPolyn(PolyList polya, PolyList polyb)
{
	PolyList p, q, tail, s;
	int sum;
	p = polya->next; q = polyb->next;  //分别指向两个多项式的第一个元素
	tail = polya;
	while (p != NULL && q != NULL)
	{
		if (p->expn < q->expn)
		{
			tail->next = p; tail = p; p = p->next;
			if (p == NULL) tail->next = q;
		}
		else if (p->expn > q->expn)
		{
			tail->next = q; tail = q; q = q->next;
			if (q == NULL) tail->next = p;
		}
		else
		{
			sum = p->coef + q->coef;
			if (sum != 0)
			{
				p->coef = sum;
				tail->next = p; tail = p; p = p->next;
				s = q; q = q->next; free(s);
				if (p == NULL) tail->next = q;
				if (q == NULL) tail->next = p;
			}
			else
			{
				s = p; p = p->next; free(s);
				s = q; q = q->next; free(s);
				if (p == NULL) tail->next = q;
				if (q == NULL) tail->next = p;
			}
		}
	}
}

void display(PolyList polya1)
{
	PolyList polya = polya1;
	while (polya->next != NULL)
	{
		polya = polya->next;
		printf("%dX%d ", polya->coef, polya->expn);
	}
}

// 栈
#pragma once
#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

bool InitStack(SqStack& S);
bool Push(SqStack& S, SElemType e);  //插入元素
SElemType GetTop(SqStack S);//取栈顶元素
bool Pop(SqStack& S, SElemType& e);//删除栈顶元素(出栈)
void conversion();//应用
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
	int data, e;
	cout << "请输入要转换成2进制的十进制数：";
	cin >> data;
	while (data)
	{
		Push(q, data % 2);
		data = data / 2;
	}
	while (q.top != q.base)
	{
		Pop(q, e);
		printf("%d", e);
	}
}
// 队列
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


//构造一个空队列
bool InitQueue(LinkQueue& Q);

//插入元素
bool EnQueue(LinkQueue& Q, int e);

//销毁队列
bool DEstroyQueue(LinkQueue& Q);

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
bool DEqueue(LinkQueue& Q, int& e);

//取队头元素
int Gettop(LinkQueue Q);

//取队尾元素
int Getrear(LinkQueue Q);

//展示队列中所有的元素
void display(LinkQueue Q);

bool Empty_Q(LinkQueue Q);
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

// 二叉树
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct  BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;



void CreatBitree2(BiTree& root); //先序序列输入，创建树

//从根开始，按层次遍历二叉树的算法，同层的结点按从左至右的次序访问（层序遍历）
void LevelOrder(BiTree T);

void inorder(BiTree root);  //中序遍历

void postorder(BiTree root);  //后序遍历

void preorder(BiTree root);  //先序遍历

//③	求结点个数
int CountNode(BiTree root);

//④	求树的深度
int Deepth(BiTree root);

//⑤	查找双亲
BiTNode* Find_Father(BiTree T, char data);

//⑥	查找兄弟（左/右）
void Findbrother(BiTree T, char data);

//⑦	查找孩子（左/右）
BiTNode* LchildNode(BiTree t);
BiTNode* RchildNode(BiTree t);
void Finderchild(BiTree root, char data);


#include <iostream>
using namespace std;
#pragma warning (disable:4996)

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;
int min(HuffmanTree HT, int k);
void Select(HuffmanTree HT, int k, int& s1, int& s2);
void Create_HuffmanTree(HuffmanTree& HT, int* w, int n);
void HuffmanCoding(HuffmanTree HT, HuffmanCode& HC, int n);
int countWPL(HuffmanTree HT, int n);
void h();


void CreatBitree2(BiTree& root) //先序序列输入，创建树
{
	char ch;
	//scanf_s("%c", &ch);
	cin >> ch;
	if (ch == '-')
		root = NULL;
	else
	{
		root = new BiTNode;
		root->data = ch;
		CreatBitree2(root->lchild);
		CreatBitree2(root->rchild);
	}
}

//从根开始，按层次遍历二叉树的算法，同层的结点按从左至右的次序访问（层序遍历）
void LevelOrder(BiTree T)
{
	BiTree Queue[100];
	int front, rear;
	if (T == NULL) return;
	front = -1;
	rear = 0;
	Queue[rear] = T;
	while (front != rear)
	{
		front++;
		printf("%c", Queue[front]->data);
		if (Queue[front]->lchild != NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->lchild;
		}
		if (Queue[front]->rchild != NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->rchild;
		}

	}

}

void inorder(BiTree root)  //中序遍历
{
	if (root != NULL)
	{
		inorder(root->lchild);
		printf("%c", root->data);
		inorder(root->rchild);
	}
}

void postorder(BiTree root)  //后序遍历
{
	if (root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c", root->data);
	}
}

void preorder(BiTree root)  //先序遍历
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//③	求结点个数
int CountNode(BiTree root)
{
	int nl = 0, nr = 0, n = 0;
	if (root == NULL) return n;
	else
	{
		nl = CountNode(root->lchild);
		nr = CountNode(root->rchild);
		return nl + nr + 1;
	}
}
//④	求树的深度
int Deepth(BiTree root)
{
	int dl = 0, dr = 0, d = 0;
	if (root == NULL) return d;
	else
	{
		dl = Deepth(root->lchild);
		dr = Deepth(root->rchild);
		return (dl >= dr ? dl + 1 : dr + 1);
	}
}
//⑤	查找双亲
BiTNode* Find_Father(BiTree T, char data)
{

	if (T == NULL)
		return NULL;
	if (T->lchild != NULL)//当左孩子存在的时候才进行判断，否则程序出错
	{
		if (T->lchild->data == data)
		{
			printf("该节点的父结点是:%c", T->data);
			return T;
			//flag = 1;//全局变量设置了一个标志flag=false，如果找到父结点，则flag赋值为true
		}
	}
	if (T->rchild != NULL)//如左子树所示
	{
		if (T->rchild->data == data)
		{
			printf("该节点的父结点是:%c", T->data);
			return T;
			//flag = 1;
		}

	}
	Find_Father(T->lchild, data);
	Find_Father(T->rchild, data);
}
//⑥	查找兄弟（左/右）
void Findbrother(BiTree T, char data)
{
	BiTNode* q = Find_Father(T, data);
	if (q == NULL) return;
	if (q->lchild == NULL || q->rchild == NULL)
	{
		printf("他没有兄弟");
		return;
	}
	if (q->lchild->data == data)
	{
		//if (q->rchild != NULL)
		//{
		printf("   %c的右兄弟是%c", data, q->rchild->data);
		return;
		//}
	}
	if (q->rchild->data == data)
	{
		//if (q->lchild != NULL)
		//{
		printf("   %c的左兄弟是%c", data, q->lchild->data);
		return;
		//}
	}
}
//⑦	查找孩子（左/右）
BiTNode* LchildNode(BiTree t)
{

	if (t->lchild != NULL) {

		printf("左孩子节点：%c\n", t->lchild->data);
		return t->lchild;
	}
	else {
		printf("该节点的左孩子为空\n");
	}
}
BiTNode* RchildNode(BiTree t)
{
	if (t->rchild != NULL) {

		printf("右孩子节点：%c\n", t->rchild->data);
		return t->rchild;
	}
	else {
		printf("该节点的右孩子为空\n");
	}
}

void Finderchild(BiTree root, char data)
{
	if (root != NULL)
	{
		//printf("%c", root->data);
		if (root->data == data)
		{
			LchildNode(root);
			RchildNode(root);
			return;
		}
		Finderchild(root->lchild, data);
		Finderchild(root->rchild, data);
	}
}

//********应用*************//
int min(HuffmanTree HT, int k) {
	int i = 0;
	int min;
	int min_weight;
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;
	for (; i < k; i++) {
		if (HT[i].weight < min_weight && HT[i].parent == -1) {
			min_weight = HT[i].weight;
			min = i;
		}
	}
	HT[min].parent = 1;
	return min;
}
void Select(HuffmanTree HT, int k, int& s1, int& s2) {
	s1 = min(HT, k);
	s2 = min(HT, k);
}

void Create_HuffmanTree(HuffmanTree& HT, int* w, int n) {
	if (n <= 1) return;
	HuffmanTree p;
	int m = 2 * n - 1;
	HT = (HuffmanTree)malloc(m * sizeof(HTNode));
	if (!HT) {
		cout << "HuffmanTree malloc faild" << endl;
		exit(-1);
	}
	int i;
	for (i = 0; i < n; i++) {
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = *w;
		w++;
	}
	for (; i < m; i++) {
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}
	int s1, s2;
	for (i = n; i < m; i++) {
		Select(HT, i, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void HuffmanCoding(HuffmanTree HT, HuffmanCode& HC, int n) {
	HC = (HuffmanCode)malloc(n * sizeof(char*));
	if (!HC) {
		cout << "HuffmanCode malloc faild!" << endl;
		exit(-1);
	}
	char* code = (char*)malloc(n * sizeof(char));
	if (!code) {
		cout << "code malloc faild!" << endl;
		exit(-1);
	}
	code[n - 1] = '\0';
	int i;
	for (i = 0; i < n; i++) {
		int current = i;
		int father = HT[i].parent;
		int start = n - 1;

		while (father != -1) {
			if (HT[father].lchild == current)
				code[--start] = '0';
			else
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		if (!HC[i]) {
			cout << "HC[i] malloc faild!";
			exit(-1);
		}
		strcpy(HC[i], code + start);
	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", HC[i]);
	}
	free(code);
}
int countWPL(HuffmanTree HT, int n) //带权路径长度
{
	int i, countRoads, WPL = 0;
	for (i = 0; i < n; i++) {
		int father = HT[i].parent;
		countRoads = 0;

		while (father != -1) {
			countRoads++;
			father = HT[father].parent;
		}
		WPL += countRoads * HT[i].weight;
	}
	return  WPL;
}

void h()
{
	int n;
	cout << "输入结点个数n=";
	cin >> n;
	int w[100];
	cout << "\n输入结点的权：";
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	HuffmanTree HT;
	HuffmanCode HC;
	Create_HuffmanTree(HT, w, n);
	cout << "\n带权路径长度:";
	cout << countWPL(HT, n) << endl;
	cout << "从叶子到根结点编码：" << endl;
	HuffmanCoding(HT, HC, n);
}
// 图
#pragma once
#include<stdio.h>
#include<stdlib.h>

//邻接矩阵
//#define MAX 9999
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vexs[MaxVertexNum];  //顶点表
	EdgeType edges[MaxVertexNum][MaxVertexNum]; //边
	int n, e;  //顶点数，边数
	int in[MaxVertexNum];//存储各个顶点的入度值
}MGraph;

void CreateMGraph(MGraph* G);

int degree1(MGraph* G, int numb);//编写一个算法，求出邻接矩阵表示的无向图中序号为numb的顶点的度数。

void Initialjuzheng(MGraph* G);

void DFS(MGraph* G, int i);
void DFSTraverse(MGraph* G);

//若队列不空，则删除Q的队头元素，并返回值；
int Out_queue(LinkQueue& Q);
/*广度优先遍历（邻接矩阵）*/
void BFSM(MGraph* G, int k);
/*邻接矩阵的广度遍历操作*/
void BFSTraverseAL(MGraph* G);

int Findv(MGraph* G, char v); //定位
int FirstAdjVex(MGraph* G, char v);//返回v的第一个邻接顶点
int NextAdjVex(MGraph* G, char v, char w);//返回v的（相对于w的）下一个邻接顶点

void linjiejuzhen(MGraph* G);//打印邻接矩阵
void InsetE(MGraph* G, int v, int w);//插入边
void DeleteE(MGraph* G, int v, int w);//删除边
void InsetV(MGraph* G, char dian);//插入点
void DeleteV(MGraph* G);//删除最后一个点


void linjieyingyong();//邻接矩阵的应用

#define STACK_MAXSIZE 100
typedef struct//辅助栈
{
	int data[STACK_MAXSIZE];
	int top;
}Stack1;

void StackInit(Stack1* S);
bool StackEmpty(Stack1* S);
bool StackFull(Stack1* S);
bool StackPop(Stack1* S, int* e);
bool StackPush(Stack1* S, int e);
bool MGraphTopologicalSort(MGraph* G);
void llljuzhen(MGraph* G);//应用初始化矩阵

bool visited[MaxVertexNum];
void CreateMGraph(MGraph* G)
{
	int i, j, k;
	printf("请输入顶点数和边数（输入格式为：顶点数 边数）：\n");
	scanf_s("%d %d", &(G->n), &(G->e));
	printf("请输入顶点信息（输入格式为：顶点号<CR>）：\n");
	for (i = 0; i < G->n; i++)
		scanf_s("\n%c", &(G->vexs[i]));
	//入度初始化
	for (i = 0; i < G->n; i++)
	{
		G->in[i] = 0;
	}
	//所有边初始化
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++) G->edges[i][j] = 0;
	printf("请输入每条边对应的两个顶点的序号（输入格式为：i j）：\n");
	for (k = 0; k < G->e; k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
		G->in[j]++;
	}

	printf("顶点为：");
	for (int i = 0; i < G->n; i++)
		printf("%c ", G->vexs[i]);
	putchar('\n');
	for (int i = 0; i < G->n; i++)
	{
		for (int j = 0; j < G->n; j++)
			printf("%d ", G->edges[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

int degree1(MGraph* G, int numb)  //编写一个算法，求出邻接矩阵表示的无向图中序号为numb的顶点的度数。
{
	int n = 0;
	for (int i = 0; i < G->n; i++)
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
	for (int i = 0; i < G->n; i++)
		printf("%c ", G->vexs[i]);
	putchar('\n');
	for (int i = 0; i < G->n; i++)
	{
		for (int j = 0; j < G->n; j++)
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
	for (j = 0; j < G->n; j++)
		if (G->edges[i][j] == 1 && !visited[j])
			DFS(G, j);   /*对未访问的邻接顶点递归调用*/
}

/*邻接矩阵的深度遍历操作*/
void DFSTraverse(MGraph* G)
{
	int i;
	for (i = 0; i < G->n; i++)
		visited[i] = false;   /*初始化所有的顶点状态都是未访问的状态*/
	for (i = 0; i < G->n; i++)
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
		for (j = 0; j < G->n; j++)
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
	for (i = 0; i < G->n; i++)
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
	int i, t;
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
	for (int i = 0; i < G->n; i++)
	{
		for (int j = 0; j < G->n; j++)
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
	for (int i = 0; i < G->n; i++)
	{
		G->edges[G->n - 1][i] = 0;
	}
	for (int i = 0; i < G->n; i++)
	{
		G->edges[i][G->n - 1] = 0;
	}
	linjiejuzhen(G);
}
void DeleteV(MGraph* G)//删除最后一个点
{
	for (int i = 0; i < G->n; i++)
	{
		G->edges[G->n - 1][i] = 0;
	}
	for (int i = 0; i < G->n; i++)
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
	for (i = 0; i < G->n; i++)
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
		for (i = 0; i < G->n; i++)
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
	for (i = 0; i < G->n; i++)
		scanf_s("\n%c", &(G->vexs[i]));
	//入度初始化
	for (i = 0; i < G->n; i++)
	{
		G->in[i] = 0;
	}
	//所有边初始化
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++) G->edges[i][j] = 0;
	printf("请输入每条边对应的两个顶点的序号（输入格式为：i j）：\n");
	for (k = 0; k < G->e; k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
		G->in[j]++;
	}

	printf("顶点为：");
	for (int i = 0; i < G->n; i++)
		printf("%c ", G->vexs[i]);
	putchar('\n');
	for (int i = 0; i < G->n; i++)
	{
		for (int j = 0; j < G->n; j++)
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


