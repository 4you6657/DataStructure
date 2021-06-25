#pragma once
// ����
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


//����ʽ
typedef struct PolyNode
{
	int coef; //ϵ��
	int expn; //ָ��
	struct PolyNode* next;
}PilyNode, * PolyList;

void duoxiangshi();
PolyList polycreate();
void AddPolyn(PolyList polya, PolyList polyb);
void display(PolyList polya1);
bool GetElem(LinkList L, int i, ElemType& e) //���ҵ�i��Ԫ�أ�����ֵ��e
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

void ListInsert(LinkList& L, int i, ElemType e)//�ڵ�i��λ�ò���Ԫ��e
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
		printf("����λ�ô���\n");
		return;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void ListDelete(LinkList& L, int i, ElemType& e)//ɾ����i��Ԫ��
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
		printf("����λ�ô���\n");
		return;

	}

	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
}

void display(LinkList L)//������е�ֵ
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
	printf("�����ɹ�\n");
}

////���һ��ɾ����������ֵС��max������min��Ԫ�ص��㷨��
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

////���һ��ɾ����������ֵС��max������min��Ԫ�ص��㷨��
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


//����ʽ
void duoxiangshi()
{
	PolyList q, w;
	printf("�������һ������ʽ��\n");
	q = polycreate();
	printf("������ڶ�������ʽ��\n");
	w = polycreate();
	AddPolyn(q, w);
	display(q);
}

PolyList polycreate()
{
	PolyNode* head, * rear, * s;
	int c, e;
	head = (PolyList)malloc(sizeof(PolyNode));//ͷ���
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
	p = polya->next; q = polyb->next;  //�ֱ�ָ����������ʽ�ĵ�һ��Ԫ��
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

// ջ
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
bool Push(SqStack& S, SElemType e);  //����Ԫ��
SElemType GetTop(SqStack S);//ȡջ��Ԫ��
bool Pop(SqStack& S, SElemType& e);//ɾ��ջ��Ԫ��(��ջ)
void conversion();//Ӧ��
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

bool Push(SqStack& S, SElemType e)  //����Ԫ��
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

void conversion()//Ӧ��
{
	SqStack q;
	InitStack(q);
	int data, e;
	cout << "������Ҫת����2���Ƶ�ʮ��������";
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
// ����
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


//����һ���ն���
bool InitQueue(LinkQueue& Q);

//����Ԫ��
bool EnQueue(LinkQueue& Q, int e);

//���ٶ���
bool DEstroyQueue(LinkQueue& Q);

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
bool DEqueue(LinkQueue& Q, int& e);

//ȡ��ͷԪ��
int Gettop(LinkQueue Q);

//ȡ��βԪ��
int Getrear(LinkQueue Q);

//չʾ���������е�Ԫ��
void display(LinkQueue Q);

bool Empty_Q(LinkQueue Q);
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

// ������
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct  BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;



void CreatBitree2(BiTree& root); //�����������룬������

//�Ӹ���ʼ������α������������㷨��ͬ��Ľ�㰴�������ҵĴ�����ʣ����������
void LevelOrder(BiTree T);

void inorder(BiTree root);  //�������

void postorder(BiTree root);  //�������

void preorder(BiTree root);  //�������

//��	�������
int CountNode(BiTree root);

//��	���������
int Deepth(BiTree root);

//��	����˫��
BiTNode* Find_Father(BiTree T, char data);

//��	�����ֵܣ���/�ң�
void Findbrother(BiTree T, char data);

//��	���Һ��ӣ���/�ң�
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


void CreatBitree2(BiTree& root) //�����������룬������
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

//�Ӹ���ʼ������α������������㷨��ͬ��Ľ�㰴�������ҵĴ�����ʣ����������
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

void inorder(BiTree root)  //�������
{
	if (root != NULL)
	{
		inorder(root->lchild);
		printf("%c", root->data);
		inorder(root->rchild);
	}
}

void postorder(BiTree root)  //�������
{
	if (root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c", root->data);
	}
}

void preorder(BiTree root)  //�������
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//��	�������
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
//��	���������
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
//��	����˫��
BiTNode* Find_Father(BiTree T, char data)
{

	if (T == NULL)
		return NULL;
	if (T->lchild != NULL)//�����Ӵ��ڵ�ʱ��Ž����жϣ�����������
	{
		if (T->lchild->data == data)
		{
			printf("�ýڵ�ĸ������:%c", T->data);
			return T;
			//flag = 1;//ȫ�ֱ���������һ����־flag=false������ҵ�����㣬��flag��ֵΪtrue
		}
	}
	if (T->rchild != NULL)//����������ʾ
	{
		if (T->rchild->data == data)
		{
			printf("�ýڵ�ĸ������:%c", T->data);
			return T;
			//flag = 1;
		}

	}
	Find_Father(T->lchild, data);
	Find_Father(T->rchild, data);
}
//��	�����ֵܣ���/�ң�
void Findbrother(BiTree T, char data)
{
	BiTNode* q = Find_Father(T, data);
	if (q == NULL) return;
	if (q->lchild == NULL || q->rchild == NULL)
	{
		printf("��û���ֵ�");
		return;
	}
	if (q->lchild->data == data)
	{
		//if (q->rchild != NULL)
		//{
		printf("   %c�����ֵ���%c", data, q->rchild->data);
		return;
		//}
	}
	if (q->rchild->data == data)
	{
		//if (q->lchild != NULL)
		//{
		printf("   %c�����ֵ���%c", data, q->lchild->data);
		return;
		//}
	}
}
//��	���Һ��ӣ���/�ң�
BiTNode* LchildNode(BiTree t)
{

	if (t->lchild != NULL) {

		printf("���ӽڵ㣺%c\n", t->lchild->data);
		return t->lchild;
	}
	else {
		printf("�ýڵ������Ϊ��\n");
	}
}
BiTNode* RchildNode(BiTree t)
{
	if (t->rchild != NULL) {

		printf("�Һ��ӽڵ㣺%c\n", t->rchild->data);
		return t->rchild;
	}
	else {
		printf("�ýڵ���Һ���Ϊ��\n");
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

//********Ӧ��*************//
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
int countWPL(HuffmanTree HT, int n) //��Ȩ·������
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
	cout << "���������n=";
	cin >> n;
	int w[100];
	cout << "\n�������Ȩ��";
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	HuffmanTree HT;
	HuffmanCode HC;
	Create_HuffmanTree(HT, w, n);
	cout << "\n��Ȩ·������:";
	cout << countWPL(HT, n) << endl;
	cout << "��Ҷ�ӵ��������룺" << endl;
	HuffmanCoding(HT, HC, n);
}
// ͼ
#pragma once
#include<stdio.h>
#include<stdlib.h>

//�ڽӾ���
//#define MAX 9999
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vexs[MaxVertexNum];  //�����
	EdgeType edges[MaxVertexNum][MaxVertexNum]; //��
	int n, e;  //������������
	int in[MaxVertexNum];//�洢������������ֵ
}MGraph;

void CreateMGraph(MGraph* G);

int degree1(MGraph* G, int numb);//��дһ���㷨������ڽӾ����ʾ������ͼ�����Ϊnumb�Ķ���Ķ�����

void Initialjuzheng(MGraph* G);

void DFS(MGraph* G, int i);
void DFSTraverse(MGraph* G);

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ�������ֵ��
int Out_queue(LinkQueue& Q);
/*������ȱ������ڽӾ���*/
void BFSM(MGraph* G, int k);
/*�ڽӾ���Ĺ�ȱ�������*/
void BFSTraverseAL(MGraph* G);

int Findv(MGraph* G, char v); //��λ
int FirstAdjVex(MGraph* G, char v);//����v�ĵ�һ���ڽӶ���
int NextAdjVex(MGraph* G, char v, char w);//����v�ģ������w�ģ���һ���ڽӶ���

void linjiejuzhen(MGraph* G);//��ӡ�ڽӾ���
void InsetE(MGraph* G, int v, int w);//�����
void DeleteE(MGraph* G, int v, int w);//ɾ����
void InsetV(MGraph* G, char dian);//�����
void DeleteV(MGraph* G);//ɾ�����һ����


void linjieyingyong();//�ڽӾ����Ӧ��

#define STACK_MAXSIZE 100
typedef struct//����ջ
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
void llljuzhen(MGraph* G);//Ӧ�ó�ʼ������

bool visited[MaxVertexNum];
void CreateMGraph(MGraph* G)
{
	int i, j, k;
	printf("�����붥�����ͱ����������ʽΪ�������� ��������\n");
	scanf_s("%d %d", &(G->n), &(G->e));
	printf("�����붥����Ϣ�������ʽΪ�������<CR>����\n");
	for (i = 0; i < G->n; i++)
		scanf_s("\n%c", &(G->vexs[i]));
	//��ȳ�ʼ��
	for (i = 0; i < G->n; i++)
	{
		G->in[i] = 0;
	}
	//���б߳�ʼ��
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++) G->edges[i][j] = 0;
	printf("������ÿ���߶�Ӧ�������������ţ������ʽΪ��i j����\n");
	for (k = 0; k < G->e; k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
		G->in[j]++;
	}

	printf("����Ϊ��");
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

int degree1(MGraph* G, int numb)  //��дһ���㷨������ڽӾ����ʾ������ͼ�����Ϊnumb�Ķ���Ķ�����
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
	printf("����Ϊ��");
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

/*������ȱ������ڽӾ���*/
void DFS(MGraph* G, int i)
{
	int j;
	visited[i] = true;
	printf("%c", G->vexs[i]); /*��ӡ���㡣Ҳ������������*/
	for (j = 0; j < G->n; j++)
		if (G->edges[i][j] == 1 && !visited[j])
			DFS(G, j);   /*��δ���ʵ��ڽӶ���ݹ����*/
}

/*�ڽӾ������ȱ�������*/
void DFSTraverse(MGraph* G)
{
	int i;
	for (i = 0; i < G->n; i++)
		visited[i] = false;   /*��ʼ�����еĶ���״̬����δ���ʵ�״̬*/
	for (i = 0; i < G->n; i++)
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
		for (j = 0; j < G->n; j++)
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

int FirstAdjVex(MGraph* G, char v)//����v�ĵ�һ���ڽӶ���
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
void DeleteV(MGraph* G)//ɾ�����һ����
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
	for (i = 0; i < G->n; i++)
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
	for (i = 0; i < G->n; i++)
		scanf_s("\n%c", &(G->vexs[i]));
	//��ȳ�ʼ��
	for (i = 0; i < G->n; i++)
	{
		G->in[i] = 0;
	}
	//���б߳�ʼ��
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++) G->edges[i][j] = 0;
	printf("������ÿ���߶�Ӧ�������������ţ������ʽΪ��i j����\n");
	for (k = 0; k < G->e; k++)
	{
		scanf_s("\n%d %d", &i, &j);
		G->edges[i][j] = 1;
		G->in[j]++;
	}

	printf("����Ϊ��");
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


