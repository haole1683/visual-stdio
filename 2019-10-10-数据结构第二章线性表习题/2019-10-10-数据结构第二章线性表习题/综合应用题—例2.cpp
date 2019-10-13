#include <iostream>

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
	int LinkSearchK(int k)
	{
		Node <T> *p, *q;
		p = q = list;
		int k1 = k;
		while (k1--)
		{	
			if (!p && !k1)
			{
				cout << "查询失败，链表结点不足" << endl;
				return 0;
			}
			p = p->link;
		}
		while (p)
		{
			p = p->link;
			q = q->link;
		}
		cout << "倒数第k哥位置上的结点数据为" << q->data << endl;
	}
};

void question1()
{
	LinkList <int> l;
	int k;
	cout << "请输入您想要寻找倒数第k个数据" << endl;
	cin >> k;
	l.LinkSearchK(k);
	system("pause");
}

