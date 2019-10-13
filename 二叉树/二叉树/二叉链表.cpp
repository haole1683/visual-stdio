#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class BiTNode
{
public:
	T data;
	BiTNode *lchild, *rchild;
	BiTNode(T i):data(i)
	{
		lchild = rchild = NULL;
	}
};

//�������ı���
//ָ���ǴӸ�������������ĳ�ִ������η��ʶ����������н�㣬ʹ��ÿ�����
//������һ���ҽ�������һ��

//�������ı�����ʽ�кܶ࣬������Ҫ���֣���ͼ

//�������Ľ����ͱ����㷨

//����һ�ö�������Լ���û�����ǰ������ķ�ʽ��������
template <class Model>
void CreateBiTree(BiTNode<Model> **T)
{
	Model c;

	cin >> c;
	//cin�����س���ո������ȡ��
	if ('#' == c)
	{
		*T = NULL;
	}
	else
	{
		(*T) = new BiTNode<Model>(c);
		CreateBiTree(&(*T)->lchild);//����������
		CreateBiTree(&(*T)->rchild);//����������
		//ע������T��ָ��ָ���ָ�룬������ָ��
		//https://blog.csdn.net/qq_31186123/article/details/81172792
	}
}

//���ʶ��������ľ����������Ҫ�ɹ�
template <class Model>
void visit(Model c,int level)
{
	cout << c << "λ�ڵ�" << level << "��" << endl;
}

//ǰ�����������
template <class Model>
void PreOrderTraverse(BiTNode<Model> *T, int level)
{
	if (T)
	{
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);

		/*
		���������
			PreOrderTraverse(T->lchild, level + 1);
			visit(T->data, level);
			PreOrderTraverse(T->rchild, level + 1);

		����������
			PreOrderTraverse(T->lchild, level + 1);
			PreOrderTraverse(T->rchild, level + 1);
			visit(T->data, level);
		*/
	}
}

int practice()
{
	int level = 1;
	BiTNode<char> *T = NULL;

	CreateBiTree(&T);
	PreOrderTraverse(T, level);

	return 0;
}

