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

//二叉树的遍历
//指的是从根结点出发，按照某种次序依次访问二叉树中所有结点，使得每个结点
//被访问一次且仅被访问一次

//二叉树的遍历方式有很多，但是主要四种，见图

//二叉树的建立和遍历算法

//创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
template <class Model>
void CreateBiTree(BiTNode<Model> **T)
{
	Model c;

	cin >> c;
	//cin遇到回车与空格结束读取，
	if ('#' == c)
	{
		*T = NULL;
	}
	else
	{
		(*T) = new BiTNode<Model>(c);
		CreateBiTree(&(*T)->lchild);//创建左子树
		CreateBiTree(&(*T)->rchild);//创建右子树
		//注意这里T是指向指针的指针，即二重指针
		//https://blog.csdn.net/qq_31186123/article/details/81172792
	}
}

//访问二叉树结点的具体操作，你要干哈
template <class Model>
void visit(Model c,int level)
{
	cout << c << "位于第" << level << "层" << endl;
}

//前序遍历二叉树
template <class Model>
void PreOrderTraverse(BiTNode<Model> *T, int level)
{
	if (T)
	{
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);

		/*
		中序遍历：
			PreOrderTraverse(T->lchild, level + 1);
			visit(T->data, level);
			PreOrderTraverse(T->rchild, level + 1);

		后续遍历：
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

