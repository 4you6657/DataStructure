#include"链表.h"

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
		s->coef = c;s->expn = e;
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
	p = polya->next;q = polyb->next;  //分别指向两个多项式的第一个元素
	tail = polya;
	while (p != NULL && q != NULL)
	{
		if (p->expn < q->expn)
		{
			tail->next = p;tail = p;p = p->next;
			if (p == NULL) tail->next = q;
		}
		else if (p->expn > q->expn)
		{
			tail->next = q;tail = q;q = q->next;
			if (q == NULL) tail->next = p;
		}
		else
		{
			sum = p->coef + q->coef;
			if (sum != 0)
			{
				p->coef = sum;
				tail->next = p;tail = p;p = p->next;
				s = q;q = q->next;free(s);
				if (p == NULL) tail->next = q;
				if (q == NULL) tail->next = p;
			}
			else
			{
				s = p;p = p->next;free(s);
				s = q;q = q->next;free(s);
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