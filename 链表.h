#pragma once
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