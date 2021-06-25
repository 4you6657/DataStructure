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