#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct  BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;



void CreatBitree2(BiTree& root); //�����������룬������

//�Ӹ���ʼ������α������������㷨��ͬ��Ľ�㰴�������ҵĴ�����ʣ����������
void LevelOrder(BiTree T);

void inorder(BiTree root);  //�������

void postorder(BiTree root);  //�������

void preorder(BiTree root);  //�������

//��	�������
int CountNode(BiTree root);

//��	���������
int Deepth(BiTree root);

//��	����˫��
BiTNode* Find_Father(BiTree T, char data);

//��	�����ֵܣ���/�ң�
void Findbrother(BiTree T, char data);

//��	���Һ��ӣ���/�ң�
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