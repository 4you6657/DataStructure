#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"����.h"


using namespace std;


void ShowMainMenu() {
	printf("\n");
	printf("*******************�㷨�����ݽṹ******************\n");
	printf("* 1  ������Ļ���������Ӧ��                       *\n");
	printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
	printf("* 3  ���еĻ���������Ӧ��                         *\n");
	printf("* 4  �������Ļ���������Ӧ��                       *\n");
	printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
	printf("* 6  �˳�                                         *\n");
	printf("***************************************************\n");
}


void LinkList1() //������
{
	LinkList L = NULL;
	int n;
	do {
		printf("\n");
		printf("**************������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ����                                         *\n");
		printf("* 3  ɾ��                                         *\n");
		printf("* 4  ����                                         *\n");
		printf("* 5  Ӧ��                                         *\n");
		printf("* 6  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("--------����������---------\n");
			InitList(L);
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			printf("������Ҫ�����λ�ú����ݣ��ÿո������");
			int i, e;
			scanf_s("%d %d", &i, &e);
			ListInsert(L, i, e);
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------\n");
			printf("������Ҫɾ����λ��:");
			scanf_s("%d", &i);
			ListDelete(L, i, e);
			break;
		case 4:
			printf("--------����Ԫ��-------\n");
			printf("������Ҫ���ҵ�λ��:");
			scanf_s("%d", &i);
			GetElem(L, i, e);
			printf("����Ϊ��%d", e);
			break;
		case 5:
			printf("--------Ӧ��---------\n");
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
		printf("****************ջ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��ջ                                         *\n");
		printf("* 2  ��ջ                                         *\n");
		printf("* 3  ȡջ��Ԫ��                                   *\n");
		printf("* 4  Ӧ��                                         *\n");
		printf("* 5  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("--------��ջ-------\n");
			int e;
			printf("�������ջԪ�أ�");
			scanf("%d", &e);
			Push(S, e);
			printf("��ջ�ɹ�");
			break;
		case 2:
			printf("--------��ջ-------\n");
			Pop(S, e);
			printf("��ջԪ��Ϊ��%d\n", e);
			break;
		case 3:
			printf("--------ȡջ��Ԫ��-------\n");
			printf("ջ��Ԫ��Ϊ��%d\n", GetTop(S));
			break;
		case 4:
			printf("--------Ӧ��-------\n");
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
		printf("*************���еĻ���������Ӧ��**************\n");
		printf("* 1  ����                                     *\n");
		printf("* 2  ����                                     *\n");
		printf("* 3  ȡ��ͷԪ��                               *\n");
		printf("* 4  ȡ��βԪ��                               *\n");
		printf("* 5  Ӧ��                                     *\n");
		printf("* 6  �˳�                                     *\n");
		printf("***********************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("---------����-------\n");
			int e;
			printf("���������Ԫ�����ݣ�");
			scanf_s("%d", &e);
			EnQueue(Q, e);
			break;
		case 2:
			printf("---------����-------\n");
			DEqueue(Q, e);
			printf("����Ԫ��Ϊ��%d\n", e);
			break;
		case 3:
			printf("---------ȡ��ͷԪ��-------\n");
			printf("��ͷԪ��Ϊ��%d\n", Gettop(Q));
			break;
		case 4:
			printf("---------ȡ��βԪ��-------\n");
			printf("��βԪ��Ϊ��%d\n", Getrear(Q));
			break;
		case 5:
			printf("---------Ӧ��-------\n");
			printf("����ͼ�Ĺ�����ȱ�����\n");
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
		printf("**************�������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ��������/��/��                             *\n");
		printf("* 3  �������                                   *\n");
		printf("* 4  ���������                                   *\n");
		printf("* 5  ����˫��                                     *\n");
		printf("* 6  �����ֵܣ���/�ң�                            *\n");
		printf("* 7  ���Һ��ӣ���/�ң�                            *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("---------����--------\n");
			printf("����������������\n");
			CreatBitree2(root);
			break;
		case 2:
			printf("---------��������/��/��-------\n");
			printf("�������Ϊ��");
			preorder(root); putchar('\n');

			printf("�������Ϊ��");
			inorder(root); putchar('\n');

			printf("�������Ϊ��");
			postorder(root); putchar('\n');
			break;
		case 3:
			printf("---------�������-------\n");
			printf("������Ϊ��%d", CountNode(root));
			break;
		case 4:
			printf("---------���������-------\n");
			printf("�������Ϊ��%d", Deepth(root));
			break;
		case 5:
			printf("---------����˫��-------\n");
			char data;
			printf("��������Ҫ����˭��˫�ף�");
			//scanf_s("%c", &data);
			cin >> data;
			Find_Father(root, data);
			break;
		case 6:
			printf("---------�����ֵܣ���/�ң�-------\n");
			printf("����Ҫ����˭���ֵܣ�");
			//scanf_s("%c", &data);
			cin >> data;
			Findbrother(root, data);
			break;
		case 7:
			printf("---------���Һ��ӣ���/�ң�-------\n");
			printf("����Ҫ����˭�ĺ��ӣ�");
			cin >> data;
			Finderchild(root, data);
			break;
		case 8:
			printf("---------Ӧ��-------\n");
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
		printf("****************ͼ�Ļ���������Ӧ��*****************\n");
		printf("* 1  �������ڽӾ���/�ڽӱ�                      *\n");
		printf("* 2  ���������/��ȣ�                            *\n");
		printf("* 3  ��λ                                         *\n");
		printf("* 4  �ҵ�һ���ڽӵ�                               *\n");
		printf("* 5  ����һ���ڽӵ�                               *\n");
		printf("* 6  ���루��/�ߣ�                                *\n");
		printf("* 7  ɾ������/�ߣ�                                *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n) {
		case 1:
			printf("---------�������ڽӾ���/�ڽӱ�-------\n");
			Initialjuzheng(G);
			break;
		case 2:
			printf("---------���������/��ȣ�-------\n");
			cout << "������ȱ���Ϊ��";
			DFSTraverse(G);//���
			putchar('\n');
			cout << "������ȱ���Ϊ��";
			BFSTraverseAL(G);
			break;
		case 3:
			printf("---------��λ-------\n");
			cout << "��������Ҫ��ѯ�ĵ㣺";
			char v;
			cin >> v;
			int t;
			t = Findv(G, v);
			if (t >= 0) cout << v << "��" << t << "��λ��";
			else cout << "û���ҵ�";
			break;
		case 4:
			printf("---------�ҵ�һ���ڽӵ�-------\n");
			printf("����Ҫ���ҵ�˭�ĵ�һ���ڽӵ㣺");
			cin >> v;
			t = FirstAdjVex(G, v);
			if (t)
				cout << v << "����һ���ڽӵ���" << G->vexs[t] << endl;
			else cout << "û���ҵ�" << endl;
			break;
		case 5:
			printf("---------����һ���ڽӵ�-------\n");
			char w;
			cout << "��������Ҫ����˭�����˭����һ���ڽӵ㣺";
			cin >> v;
			cin >> w;
			t = NextAdjVex(G, v, w);
			if (t)
				cout << v << "�����" << w << "����һ���ڽӵ���" << G->vexs[t] << endl;
			else cout << "û���ҵ�" << endl;
			break;
		case 6:
			printf("---------���루��/�ߣ�-------\n");
			int a, b, p;
			cout << "������Ҫ����㻹�Ǳߣ�(1�� 2��)";
			cin >> p;
			if (p == 1)
			{
				cout << "��������Ҫ����ĵ㣺";
				char dian;
				cin >> dian;
				InsetV(G, dian);
			}
			if (p == 2)
			{
				cout << "��������Ҫ����ıߣ�";
				cin >> a >> b;
				InsetE(G, a, b);
			}
			break;
		case 7:
			printf("---------ɾ������/�ߣ�-------\n");
			cout << "������Ҫɾ���㻹�Ǳߣ�(1�� 2��)";
			cin >> p;
			if (p == 1)
			{
				//cout << "��������Ҫɾ���ĵ㣺";
				/*char dian;
				cin >> dian;*/
				DeleteV(G);
			}
			if (p == 2)
			{
				cout << "��������Ҫɾ���ıߣ�";
				cin >> a >> b;
				DeleteE(G, a, b);
			}
			break;
		case 8:
			printf("---------Ӧ��-------\n");
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
		printf("��ѡ��");
		scanf("%d", &n);
		switch (n) {
		case 1:LinkList1(); break;//������
		case 2:Stack(); break;//ջ
		case 3:Queue(); break;//����
		case 4:BiTree1(); break;//��
		case 5:Graph(); break;//ͼ
		case 6:break;
		default:printf("ERROR!"); break;
		}
	} while (n != 6);
}
