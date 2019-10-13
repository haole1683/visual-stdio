#include <iostream>
#include <stdlib.h>

using namespace std;

//线索二叉树

//扩容

//线索存储标志位
//Link(0):表示指向左右孩子的指针
//Thread(1):表示指向前驱后继的线索
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

//全局变量，始终指向刚刚访问过的结点
template <class T>
BiThrNode<T>* pre;

//创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
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

//中序遍历线索化
template <class Model>
void InThreading(BiThrNode <Model> *T)
{
	if (T)
	{
		InThreading(T->lchild);//递归左孩子线索化
		
		if (!T->lchild)//如果该节点没有左孩子，设置lTag为Thread，并把lchild指向上一个访问的结点
		{
			T->ltag = Thread;
			T->lchild = pre<Model>;
		}

		if (!pre<Model>->rchild)
		{
			pre<Model>->rtag = Thread;
			pre<Model>->rchild = T;
		}
		//因为已经知道了T的前驱是pre，所以如果pre的右节点没有的话就能够用来存储T的线索了

		pre<Model> = T;

		InThreading(T->rchild);//递归右孩子线索化
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

//中序遍历二叉树，非递归
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

	cout << "中序遍历输出结果为" << endl;
	
	InOrderTraverse(P);
}

int main()
{
	practice2();
	system("pause");
}