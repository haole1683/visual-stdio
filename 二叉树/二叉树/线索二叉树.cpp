#include <iostream>
#include <stdlib.h>

using namespace std;

//����������

//����

//�����洢��־λ
//Link(0):��ʾָ�����Һ��ӵ�ָ��
//Thread(1):��ʾָ��ǰ����̵�����
typedef enum{Link,Thread} PointerTag;

template <class Model>
class BiThrNode
{
public:
	Model data;
	BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
};

//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
template <class T>
BiThrNode<T>* pre;

//����һ�ö�������Լ���û�����ǰ������ķ�ʽ��������
template <class Model>
void CreateBiThrTree(BiThrNode<Model> **T)
{
	Model c;
	cin >> c;
	if ('#' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = new BiThrNode<Model>;
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

//�������������
template <class Model>
void InThreading(BiThrNode <Model> *T)
{
	if (T)
	{
		InThreading(T->lchild);//�ݹ�����������
		
		if (!T->lchild)//����ýڵ�û�����ӣ�����lTagΪThread������lchildָ����һ�����ʵĽ��
		{
			T->ltag = Thread;
			T->lchild = pre<Model>;
		}

		if (!pre<Model>->rchild)
		{
			pre<Model>->rtag = Thread;
			pre<Model>->rchild = T;
		}
		//��Ϊ�Ѿ�֪����T��ǰ����pre���������pre���ҽڵ�û�еĻ����ܹ������洢T��������

		pre<Model> = T;

		InThreading(T->rchild);//�ݹ��Һ���������
	}
}

template <class Model>
void InOrderThreading(BiThrNode<Model> **p,BiThrNode<Model> *T)
{
	*p = new BiThrNode<Model>;
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if (!T)
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre<Model> = *p;
		InThreading(T);
		pre<Model>->rchild = *p;
		pre<Model>->rtag = Thread;
		(*p)->rchild = pre<Model>;
	}
}

template <class Model>
void visit(Model T)
{
	cout << T;
}

//����������������ǵݹ�
template <class Model>
void InOrderTraverse(BiThrNode<Model>*T)
{
	BiThrNode<Model> *p;
	p = T->lchild;

	while (p != T)
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}

		visit(p->data);

		while (p->rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			visit(p->data);
		}

		p = p->rchild;
	}
}

void practice2()
{
	BiThrNode<char> *T = NULL,*P = NULL;

	CreateBiThrTree(&T);

	InOrderThreading(&P,T);

	cout << "�������������Ϊ" << endl;
	
	InOrderTraverse(P);
}

int main()
{
	practice2();
	system("pause");
}