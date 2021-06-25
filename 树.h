#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct  BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;



void CreatBitree2(BiTree& root); //先序序列输入，创建树

//从根开始，按层次遍历二叉树的算法，同层的结点按从左至右的次序访问（层序遍历）
void LevelOrder(BiTree T);

void inorder(BiTree root);  //中序遍历

void postorder(BiTree root);  //后序遍历

void preorder(BiTree root);  //先序遍历

//③	求结点个数
int CountNode(BiTree root);

//④	求树的深度
int Deepth(BiTree root);

//⑤	查找双亲
BiTNode* Find_Father(BiTree T, char data);

//⑥	查找兄弟（左/右）
void Findbrother(BiTree T, char data);

//⑦	查找孩子（左/右）
BiTNode* LchildNode(BiTree t);
BiTNode* RchildNode(BiTree t);
void Finderchild(BiTree root, char data);


#include <iostream>
using namespace std;
#pragma warning (disable:4996)

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;
int min(HuffmanTree HT, int k);
void Select(HuffmanTree HT, int k, int& s1, int& s2);
void Create_HuffmanTree(HuffmanTree& HT, int* w, int n);
void HuffmanCoding(HuffmanTree HT, HuffmanCode& HC, int n);
int countWPL(HuffmanTree HT, int n);
void h();