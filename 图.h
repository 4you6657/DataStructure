#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"����.h"

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