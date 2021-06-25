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