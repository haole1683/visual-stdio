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
			cout << "���������ݣ�����0�Խ�������" << endl;
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
		cout << "�����ɹ�" << endl;
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
				cout << "��ѯʧ�ܣ������㲻��" << endl;
				return 0;
			}
			p = p->link;
		}
		while (p)
		{
			p = p->link;
			q = q->link;
		}
		cout << "������k��λ���ϵĽ������Ϊ" << q->data << endl;
	}
};

void question1()
{
	LinkList <int> l;
	int k;
	cout << "����������ҪѰ�ҵ�����k������" << endl;
	cin >> k;
	l.LinkSearchK(k);
	system("pause");
}

