#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

//队列 结构体
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

//检查栈是否为空
bool Empty_Q(LinkQueue Q);

/* 应用 */
void SeeDoctor();
