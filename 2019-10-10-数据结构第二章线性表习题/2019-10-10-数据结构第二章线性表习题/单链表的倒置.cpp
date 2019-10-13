#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T> *link;
public:
	Node(T i)
	{
		data = i;
		link = NULL;
	}
	Node()
	{
		data = 0;
		link = NULL;
	}
};

template <class T>
class LinkList
{
private:
	Node <T>*list;
public:
	LinkList()
	{
		Node <T> *head = NULL, *temp;
		T data = 0;
		do
		{
			cout << "请输入数据，输入0以结束链表" << endl;
			cin >> data;
			if (!data)
				continue;
			if (!list)
				head = list = new Node<T>(data);
			else
			{
				temp = new Node<T>(data);
				head->link = temp;
				head = head->link;
			}
		} while (data);
		cout << "创建成功" << endl;
	}
	void reserve(LinkList &B)
	{
		Node <T> *temp = list,*head = list,*next = NULL;
		while (temp)
		{
			next = temp->link;
			if (temp == list)//首先先将首结点赋值给temp
			{
				head = list;//让head = list
				head->link = NULL;//将head（！！！！！即转置后最后一个结点的link置为NULL）
			}
			else
			{
				temp->link = head;
				head = temp;
			}
			temp = next;
		}
		B.list = head;
	}

	void reverse_0(Node <T> *n)//单链表反转，递归算法,但是要注意这里只是单纯的操作，没有对新生成的链表的尾结点进行赋值，也没有将头结点赋值
	{
		Node <T> *t1 = n, *t2 = n->link;
		
		if (t2->link != NULL)
			reverse_0(t2);
		/*if (t2->link == NULL)
			list = t2;
		if (t1 == list)
			t1->link = NULL;*/
		t2->link = t1;
	}
	void reverse_difui_true()
	{
		reverse_0(list);
	}

	void Show()
	{
		cout << "Showing" << endl;
		Node <T> *temp = list;
		while (temp)
		{
			cout << temp->data << endl;
			temp = temp->link;
		}
	}
	Node<T>* getHead()
	{
		return list;
	}
	LinkList(int i)
	{

	}

	void reserve_stack()//用栈的方法实现
	{
		stack<Node<T>*> s;
		Node<T> *p = list;
		while (p)//一次将链表中结点进栈
		{
			s.push(p);
			p = p->link;
		}
		Node <T> *temp = NULL;
		while (!s.empty())
		{
			s.pop(p);
			if (p->link == NULL)
				list = temp = p;
			else
			{
				temp->link = p;
				temp = temp->link;
			}
		}
		temp->link = NULL;
	}

	int Num(Node <T>*t)//用递归求链表结点
	{
		if (t == NULL)
			return 0;
		return 1 + Num(t->link);
	}
	int getNum()
	{
		return Num(list);
	}

	int Max(Node<T> *t)
	{
		if (t->link == 0)
			return t->data;//递归结束条件
	//在当前结点的后继链表中求最大值
		int temp = Max(t->link);
		//如果当前结点值大，则返回当前结点值
		if (t->data > temp)
			return t->data;
		else
			return temp;//否则返回后续最大值
	}

	//求平均值，略
};

void question2()
{
	LinkList <int> l;
	LinkList <int> l2(2);

	l.Show();
	
	l.Show();
	cout << l.getNum();
	system("pause");
}

int main()
{
	question2();
}