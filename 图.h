#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"队列.h"

//邻接矩阵
//#define MAX 9999
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
	VertexType vexs[MaxVertexNum];  //顶点表
	EdgeType edges[MaxVertexNum][MaxVertexNum]; //边
	int n, e;  //顶点数，边数
	int in[MaxVertexNum];//存储各个顶点的入度值
}MGraph;

void CreateMGraph(MGraph* G);

int degree1(MGraph* G, int numb);//编写一个算法，求出邻接矩阵表示的无向图中序号为numb的顶点的度数。

void Initialjuzheng(MGraph* G);

void DFS(MGraph* G, int i);
void DFSTraverse(MGraph* G);

//若队列不空，则删除Q的队头元素，并返回值；
int Out_queue(LinkQueue& Q);
/*广度优先遍历（邻接矩阵）*/
void BFSM(MGraph* G, int k);
/*邻接矩阵的广度遍历操作*/
void BFSTraverseAL(MGraph* G);

int Findv(MGraph* G, char v); //定位
int FirstAdjVex(MGraph* G, char v);//返回v的第一个邻接顶点
int NextAdjVex(MGraph* G, char v, char w);//返回v的（相对于w的）下一个邻接顶点

void linjiejuzhen(MGraph* G);//打印邻接矩阵
void InsetE(MGraph* G, int v, int w);//插入边
void DeleteE(MGraph* G, int v, int w);//删除边
void InsetV(MGraph* G, char dian);//插入点
void DeleteV(MGraph* G);//删除最后一个点


void linjieyingyong();//邻接矩阵的应用

#define STACK_MAXSIZE 100
typedef struct//辅助栈
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
void llljuzhen(MGraph* G);//应用初始化矩阵