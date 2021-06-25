#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"函数.h"


using namespace std;


void ShowMainMenu() {
	printf("\n");
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  队列的基本操作及应用                         *\n");
	printf("* 4  二叉树的基本操作及应用                       *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
}


void LinkList1() //单链表
{
	LinkList L = NULL;
	int n;
	do {
		printf("\n");
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  应用                                         *\n");
		printf("* 6  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("--------创建单链表---------\n");
			InitList(L);
			break;
		case 2:
			printf("--------插入元素-------\n");
			printf("请输入要插入的位置和数据，用空格隔开：");
			int i, e;
			scanf_s("%d %d", &i, &e);
			ListInsert(L, i, e);
			break;
		case 3:
			printf("--------删除元素-------\n");
			printf("请输入要删除的位置:");
			scanf_s("%d", &i);
			ListDelete(L, i, e);
			break;
		case 4:
			printf("--------查找元素-------\n");
			printf("请输入要查找的位置:");
			scanf_s("%d", &i);
			GetElem(L, i, e);
			printf("数据为：%d", e);
			break;
		case 5:
			printf("--------应用---------\n");
			duoxiangshi();
			break;
		case 6: break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 6);
}

void Stack() {
	int n;
	SqStack S;
	InitStack(S);
	do {
		printf("\n");
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  应用                                         *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("--------进栈-------\n");
			int e;
			printf("请输入进栈元素：");
			scanf("%d", &e);
			Push(S, e);
			printf("进栈成功");
			break;
		case 2:
			printf("--------出栈-------\n");
			Pop(S, e);
			printf("出栈元素为：%d\n", e);
			break;
		case 3:
			printf("--------取栈顶元素-------\n");
			printf("栈顶元素为：%d\n", GetTop(S));
			break;
		case 4:
			printf("--------应用-------\n");
			conversion();
			break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}

void Queue() {
	int n;
	LinkQueue Q;
	InitQueue(Q);
	do {
		printf("\n");
		printf("*************队列的基本操作及应用**************\n");
		printf("* 1  入列                                     *\n");
		printf("* 2  出列                                     *\n");
		printf("* 3  取队头元素                               *\n");
		printf("* 4  取队尾元素                               *\n");
		printf("* 5  应用                                     *\n");
		printf("* 6  退出                                     *\n");
		printf("***********************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("---------入列-------\n");
			int e;
			printf("请输入入队元素数据：");
			scanf_s("%d", &e);
			EnQueue(Q, e);
			break;
		case 2:
			printf("---------出列-------\n");
			DEqueue(Q, e);
			printf("出队元素为：%d\n", e);
			break;
		case 3:
			printf("---------取队头元素-------\n");
			printf("队头元素为：%d\n", Gettop(Q));
			break;
		case 4:
			printf("---------取队尾元素-------\n");
			printf("队尾元素为：%d\n", Getrear(Q));
			break;
		case 5:
			printf("---------应用-------\n");
			printf("用在图的广度优先遍历中\n");
			break;
		case 6:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 6);
}

void BiTree1() {
	int n;
	BiTree root = NULL;
	do {
		printf("\n");
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  遍历（先/中/后）                             *\n");
		printf("* 3  求结点个数                                   *\n");
		printf("* 4  求树的深度                                   *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟（左/右）                            *\n");
		printf("* 7  查找孩子（左/右）                            *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建--------\n");
			printf("请以先序输入树：\n");
			CreatBitree2(root);
			break;
		case 2:
			printf("---------遍历（先/中/后）-------\n");
			printf("先序遍历为：");
			preorder(root); putchar('\n');

			printf("中序遍历为：");
			inorder(root); putchar('\n');

			printf("后序遍历为：");
			postorder(root); putchar('\n');
			break;
		case 3:
			printf("---------求结点个数-------\n");
			printf("结点个数为：%d", CountNode(root));
			break;
		case 4:
			printf("---------求树的深度-------\n");
			printf("树的深度为：%d", Deepth(root));
			break;
		case 5:
			printf("---------查找双亲-------\n");
			char data;
			printf("请输入想要查找谁的双亲：");
			//scanf_s("%c", &data);
			cin >> data;
			Find_Father(root, data);
			break;
		case 6:
			printf("---------查找兄弟（左/右）-------\n");
			printf("你想要查找谁的兄弟：");
			//scanf_s("%c", &data);
			cin >> data;
			Findbrother(root, data);
			break;
		case 7:
			printf("---------查找孩子（左/右）-------\n");
			printf("你想要查找谁的孩子：");
			cin >> data;
			Finderchild(root, data);
			break;
		case 8:
			printf("---------应用-------\n");
			h();
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}

void Graph() {
	int n;
	MGraph* G = new MGraph;
	do {
		printf("\n");
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建（邻接矩阵/邻接表）                      *\n");
		printf("* 2  遍历（深度/广度）                            *\n");
		printf("* 3  定位                                         *\n");
		printf("* 4  找第一个邻接点                               *\n");
		printf("* 5  找下一个邻接点                               *\n");
		printf("* 6  插入（点/边）                                *\n");
		printf("* 7  删除（点/边）                                *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建（邻接矩阵/邻接表）-------\n");
			Initialjuzheng(G);
			break;
		case 2:
			printf("---------遍历（深度/广度）-------\n");
			cout << "深度优先遍历为：";
			DFSTraverse(G);//深度
			putchar('\n');
			cout << "广度优先遍历为：";
			BFSTraverseAL(G);
			break;
		case 3:
			printf("---------定位-------\n");
			cout << "请输入你要查询的点：";
			char v;
			cin >> v;
			int t;
			t = Findv(G, v);
			if (t >= 0) cout << v << "在" << t << "的位置";
			else cout << "没有找到";
			break;
		case 4:
			printf("---------找第一个邻接点-------\n");
			printf("你想要查找的谁的第一个邻接点：");
			cin >> v;
			t = FirstAdjVex(G, v);
			if (t)
				cout << v << "的下一个邻接点是" << G->vexs[t] << endl;
			else cout << "没有找到" << endl;
			break;
		case 5:
			printf("---------找下一个邻接点-------\n");
			char w;
			cout << "请输入你要查找谁相对于谁的下一个邻接点：";
			cin >> v;
			cin >> w;
			t = NextAdjVex(G, v, w);
			if (t)
				cout << v << "相对于" << w << "的下一个邻接点是" << G->vexs[t] << endl;
			else cout << "没有找到" << endl;
			break;
		case 6:
			printf("---------插入（点/边）-------\n");
			int a, b, p;
			cout << "请问是要插入点还是边？(1点 2边)";
			cin >> p;
			if (p == 1)
			{
				cout << "请输入你要插入的点：";
				char dian;
				cin >> dian;
				InsetV(G, dian);
			}
			if (p == 2)
			{
				cout << "请输入你要插入的边：";
				cin >> a >> b;
				InsetE(G, a, b);
			}
			break;
		case 7:
			printf("---------删除（点/边）-------\n");
			cout << "请问是要删除点还是边？(1点 2边)";
			cin >> p;
			if (p == 1)
			{
				//cout << "请输入你要删除的点：";
				/*char dian;
				cin >> dian;*/
				DeleteV(G);
			}
			if (p == 2)
			{
				cout << "请输入你要删除的边：";
				cin >> a >> b;
				DeleteE(G, a, b);
			}
			break;
		case 8:
			printf("---------应用-------\n");
			linjieyingyong();
			break;

		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}

int main() {

	int n;
	do {
		ShowMainMenu();
		printf("请选择：");
		scanf("%d", &n);
		switch (n) {
		case 1:LinkList1(); break;//单链表
		case 2:Stack(); break;//栈
		case 3:Queue(); break;//队列
		case 4:BiTree1(); break;//树
		case 5:Graph(); break;//图
		case 6:break;
		default:printf("ERROR!"); break;
		}
	} while (n != 6);
}
