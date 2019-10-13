#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class BinaryTreeNode
{
	//friend class BinaryTree<T>;
private:
	T element;//���������
	BinaryTreeNode <T>*leftChild;//�������
	BinaryTreeNode <T>*rightChild;//����Һ���
public:
	BinaryTreeNode();//����
	BinaryTreeNode(const T&ele);//�����������ֵ�Ĺ��캯��
	BinaryTreeNode(const T&ele, BinaryTreeNode <T> *l,BinaryTreeNode <T>*r);//��������������Һ��ӽ��Ĺ��캯��
	BinaryTreeNode<T> *getLeftChild() const;//�������ӵĽڵ�
	BinaryTreeNode<T> *getRightChild() const;//�����Һ��ӵĽ��
	void setLeftChild(BinaryTreeNode *l);//�������ӽ��
	void setRightChild(BinaryTreeNode *r);//�����Һ��ӽ��
	T getValue() const;//��������
	void setValue(const T&val);//��������
	bool isLeaf() const;//�жϸý���Ƿ�ΪҶ�ӽ��
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
	BinaryTreeNode <T> *root;//�����������
public:
	BinaryTree();//Ĭ�Ϲ��캯��
	~BinaryTree();//��������
	bool isEmpty() const;//�ж϶������Ƿ�Ϊ����
	BinaryTreeNode<T> *getroot() const;//���ض������ĸ��ڵ�
	BinaryTreeNode<T> *getparent(BinaryTreeNode <T> *current) const;//����current���ĸ��ڵ�
	BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode <T>*current) const;//����current�������ֵ�
	BinaryTreeNode<T> *getRightSibling(BinaryTreeNode <T>*current) const;//����current�������ֵ�
	void breathFirstOrder(BinaryTreeNode <T> *root);//������ȱ�����rootΪ����������
	void preOrder(BinaryTreeNode <T> *root);//���������rootΪ���ڵ������
	void inOrder(BinaryTreeNode <T> *root);//���������rootΪ����������
	void postOrder(BinaryTreeNode <T> *root);//���������rootΪ����������
	void levelOrder(BinaryTreeNode <T> *root);//����α�����rootΪ����������

	void PreOrderWithoutRecusion(BinaryTreeNode <T>*root);//�ǵݹ�ǰ���������������������
	void InOrderWithoutRecusion(BinaryTreeNode <T>*root);//�ǵݹ������������������������

	void deleteBinaryTree(BinaryTreeNode <T> *root);//ɾ����rootΪ����������

};

//�ݹ��㷨

template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root)//
{
	if (root != NULL)
	{
		visit(root);//���ʵ�ǰ���
		preOrder(root->leftChild);//����������
		preOrder(root->rightChild);//����������
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
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* root)//���������������������
{
	if (!root)
	{
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		visit(root);
	}

}

template<class T>//������ȱ���
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root)
{
	queue <BinaryTreeNode <T> *>nodeQueue;//�ö������洢��Ҫ���ʵĽ��
	BinaryTreeNode <T>* pointer = root;

	if (pointer)//��������ǿգ���������������
		nodeQueue.push(pointer);
	while (!nodeQueue.empty())
	{
		pointer = nodeQueue.front();
		//visit(pointer);//���ʵ�ǰ���
		pointer->Show();
		nodeQueue.pop();//�����ʹ��Ľ���Ƴ�����
		if (pointer->leftChild)
			nodeQueue.push(pointer->leftChild);
		if (pointer->rightChild)
			nodeQueue.push(pointer->rightChild);
		//�����ʹ��Ľ������Һ��ӽڵ����μ��뵽��β
	}
}

template<class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T>* root)
{
	stack <BinaryTreeNode <T>*> nodeStack;//��Ŵ����ʵĽ���ջ
	BinaryTreeNode <T> *pointer = root;//��������

	while (!nodeStack.empty() || pointer)//ջΪ�յ�ʱ���������
	{
		if (pointer)
		{
			visit(pointer);//���ʵ�ǰ���
			if (pointer->rightChild != NULL)
				nodeStack.push(pointer->rightChild);
			//��ǰ���ʵ��������ĸ������ջ
			pointer = pointer->leftChild;//ת�������������
		}
		else//������������ϣ�ת�����������
		{
			pointer = nodeStack.top();//��ȡջ�������ʵĽ��
			nodeStack.pop();//ɾ��ջ�����
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

