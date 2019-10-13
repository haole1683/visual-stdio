#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class BinaryTreeNode
{
	//friend class BinaryTree<T>;
private:
	T element;//结点数据域
	BinaryTreeNode <T>*leftChild;//结点左孩子
	BinaryTreeNode <T>*rightChild;//结点右孩子
public:
	BinaryTreeNode();//构造
	BinaryTreeNode(const T&ele);//给定数据域的值的构造函数
	BinaryTreeNode(const T&ele, BinaryTreeNode <T> *l,BinaryTreeNode <T>*r);//给定数据域和左右孩子结点的构造函数
	BinaryTreeNode<T> *getLeftChild() const;//返回左孩子的节点
	BinaryTreeNode<T> *getRightChild() const;//返回右孩子的结点
	void setLeftChild(BinaryTreeNode *l);//设置左孩子结点
	void setRightChild(BinaryTreeNode *r);//设置右孩子结点
	T getValue() const;//返回数据
	void setValue(const T&val);//设置数据
	bool isLeaf() const;//判断该结点是否为叶子结点
	void Show();
};
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	element = 0;
	leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T & ele)
{
	element = ele;
	leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T & ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r)
{
	element = ele;
	leftChild = l;
	rightChild = r;
}
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild() const
{
	return leftChild;
}
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() const
{
	return rightChild;
}
template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode * l)
{
	leftChild = l;
}
template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode * r)
{
	rightChild = r;
}
template<class T>
T BinaryTreeNode<T>::getValue() const
{
	return element;
}
template<class T>
void BinaryTreeNode<T>::setValue(const T & val)
{
	element = val;
}
template<class T>
bool BinaryTreeNode<T>::isLeaf() const
{
	return !leftChild&&!rightChild;
}
template<class T>
void BinaryTreeNode<T>::Show()
{
	cout << T;
}



template <class T>
class BinaryTree
{
private:
	BinaryTreeNode <T> *root;//二叉树根结点
public:
	BinaryTree();//默认构造函数
	~BinaryTree();//析构函数
	bool isEmpty() const;//判断二叉树是否为空树
	BinaryTreeNode<T> *getroot() const;//返回二叉树的根节点
	BinaryTreeNode<T> *getparent(BinaryTreeNode <T> *current) const;//返回current结点的父节点
	BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode <T>*current) const;//返回current结点的左兄弟
	BinaryTreeNode<T> *getRightSibling(BinaryTreeNode <T>*current) const;//返回current结点的右兄弟
	void breathFirstOrder(BinaryTreeNode <T> *root);//广度优先遍历以root为根结点的子树
	void preOrder(BinaryTreeNode <T> *root);//先序遍历以root为根节点的子树
	void inOrder(BinaryTreeNode <T> *root);//中序遍历以root为根结点的子树
	void postOrder(BinaryTreeNode <T> *root);//后序遍历以root为根结点的子树
	void levelOrder(BinaryTreeNode <T> *root);//按层次遍历以root为根结点的子树

	void PreOrderWithoutRecusion(BinaryTreeNode <T>*root);//非递归前序遍历二叉树或者其子树
	void InOrderWithoutRecusion(BinaryTreeNode <T>*root);//非递归中序遍历二叉树或者其子树

	void deleteBinaryTree(BinaryTreeNode <T> *root);//删除以root为根结点的子树

};

//递归算法

template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root)//
{
	if (root != NULL)
	{
		visit(root);//访问当前结点
		preOrder(root->leftChild);//访问左子树
		preOrder(root->rightChild);//访问右子树
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root)
{
	if (!root)
	{
		inOrder(root->leftChild);
		visit(root);
		inOrder(root->rightChild);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* root)//后序遍历二叉树及其子树
{
	if (!root)
	{
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		visit(root);
	}

}

template<class T>//广度优先遍历
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root)
{
	queue <BinaryTreeNode <T> *>nodeQueue;//用队列来存储将要访问的结点
	BinaryTreeNode <T>* pointer = root;

	if (pointer)//如果根结点非空，将根结点移入队列
		nodeQueue.push(pointer);
	while (!nodeQueue.empty())
	{
		pointer = nodeQueue.front();
		//visit(pointer);//访问当前结点
		pointer->Show();
		nodeQueue.pop();//将访问过的结点移出队列
		if (pointer->leftChild)
			nodeQueue.push(pointer->leftChild);
		if (pointer->rightChild)
			nodeQueue.push(pointer->rightChild);
		//将访问过的结点的左右孩子节点依次加入到队尾
	}
}

template<class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T>* root)
{
	stack <BinaryTreeNode <T>*> nodeStack;//存放待访问的结点的栈
	BinaryTreeNode <T> *pointer = root;//保存根结点

	while (!nodeStack.empty() || pointer)//栈为空的时候遍历结束
	{
		if (pointer)
		{
			visit(pointer);//访问当前结点
			if (pointer->rightChild != NULL)
				nodeStack.push(pointer->rightChild);
			//当前访问的右子树的根结点入栈
			pointer = pointer->leftChild;//转向访问其右子树
		}
		else//左子树访问完毕，转向访问右子树
		{
			pointer = nodeStack.top();//读取栈顶待访问的结点
			nodeStack.pop();//删除栈顶结点
		}
	}
}

template<class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root)
{
	stack <BinaryTreeNode <T>*> nodeStack;
	
	BinaryTreeNode <T> *pointer = root;
	while (pointer || nodeStack.empty())
	{
		if (!pointer)
			nodeStack.push(pointer);
		pointer = pointer->leftChild;
	}
}

