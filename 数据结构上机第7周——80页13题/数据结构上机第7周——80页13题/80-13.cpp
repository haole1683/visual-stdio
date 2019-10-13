#include <iostream>
#include <stdlib.h>

using namespace std;

enum stage
{
	OK, Error
};

class stack
{
private:
	int maxsize;
	int tail;
	char *data;
public:
	stack(int);
	stage push(char&);
	stage pop(char&);
	int getlen();
	void clear();
	bool isEmpty();
	char gettop()
	{
		return data[tail - 1];
	}

};
stack::stack(int max)
{
	tail = 0;
	maxsize = max;
	data = new char[maxsize + 1];
}
stage stack::push(char &c)
{
	if (tail == maxsize)
	{
		//cout << "�������޷���ջ" << endl;
		return Error;
	}
	data[tail++] = c;
	return OK;
}
bool stack::isEmpty()
{
	return !tail;
}
stage stack::pop(char &c)
{
	if (!tail)
	{
		//cout << "��Ԫ�أ��޷���ջ" << endl;
		return Error;
	}
	c = data[tail - 1];
	tail--;
	return OK;
}
int stack::getlen()
{
	return tail;
}
void stack::clear()
{
	delete[] data;
}

int main()
{
	stack s(100);
	char c;
	char a = 'a';
	bool succes = true;
	while ((c = getchar()) != '\n')
	{
		
		if (c == '[' || c == '{' || c == '(')
		{
			s.push(c);
			/*if (c == '['&& s.gettop() == '{' || c == '(' && s.gettop() == '[');
			else
				cout << "���Ų�β���" << endl;*/
		}
		

		if (c == ']' || c == '}' || c == ')')
		{
			if (s.isEmpty())
			{
				switch (c)
				{
				case')':
					cout << "()��ƥ��" << endl;
					break;
				case']':
					cout << "[]��ƥ��" << endl;
					break;
				case'}':
					cout << "{}��ƥ��" << endl;
					break;
				}
				succes = false;
				continue;
			}

			s.pop(a);
			if (a == '(' && c == ')')
				continue;
			if (a == '[' && c == ']')
				continue;
			if (a == '{' && c == '}')
				continue;
			succes = false;
		}
	}
	if (succes &&s.isEmpty())
		cout << "ƥ��ɹ�" << endl;
	else
	{
		cout << "ƥ��ʧ��" << endl;
		while (!s.isEmpty())
		{
			s.pop(c);
			switch (c)
			{
			case'(':
				cout << "()��ƥ��" << endl;
				break;
			case'[':
				cout << "[]��ƥ��" << endl;
				break;
			case'{':
				cout << "{}��ƥ��" << endl;
				break;
			}
		}
	}
	system("pause");
}