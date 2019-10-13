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
	void reserve(LinkList &B)
	{
		Node <T> *temp = list,*head = list,*next = NULL;
		while (temp)
		{
			next = temp->link;
			if (temp == list)//�����Ƚ��׽�㸳ֵ��temp
			{
				head = list;//��head = list
				head->link = NULL;//��head��������������ת�ú����һ������link��ΪNULL��
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

	void reverse_0(Node <T> *n)//������ת���ݹ��㷨,����Ҫע������ֻ�ǵ����Ĳ�����û�ж������ɵ������β�����и�ֵ��Ҳû�н�ͷ��㸳ֵ
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

	void reserve_stack()//��ջ�ķ���ʵ��
	{
		stack<Node<T>*> s;
		Node<T> *p = list;
		while (p)//һ�ν������н���ջ
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

	int Num(Node <T>*t)//�õݹ���������
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
			return t->data;//�ݹ��������
	//�ڵ�ǰ���ĺ�������������ֵ
		int temp = Max(t->link);
		//�����ǰ���ֵ���򷵻ص�ǰ���ֵ
		if (t->data > temp)
			return t->data;
		else
			return temp;//���򷵻غ������ֵ
	}

	//��ƽ��ֵ����
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