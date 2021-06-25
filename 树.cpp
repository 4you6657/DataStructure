#include"��.h"

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
			printf("   %c�����ֵ���%c",data, q->rchild->data);
			return;
		//}
	}
	if (q->rchild->data == data)
	{
		//if (q->lchild != NULL)
		//{
			printf("   %c�����ֵ���%c", data,q->lchild->data);
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