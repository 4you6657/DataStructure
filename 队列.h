#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

//���� �ṹ��
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

//���ջ�Ƿ�Ϊ��
bool Empty_Q(LinkQueue Q);

/* Ӧ�� */
void SeeDoctor();
