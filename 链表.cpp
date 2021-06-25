#include"����.h"

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
	p = polya->next;q = polyb->next;  //�ֱ�ָ����������ʽ�ĵ�һ��Ԫ��
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