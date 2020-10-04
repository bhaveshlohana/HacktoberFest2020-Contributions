#include <iostream>
using namespace std;

class Node
{
public:
	Node *prev, *next;
	int data;
};

class DLinkedList
{
private:
	Node *first;

public:
	DLinkedList()
	{
		first = nullptr;
	}
	DLinkedList(int A[], int n);
	~DLinkedList();

	void Display();
	void Insert(int idx, int x);
	int Length();
	void Delete(int idx);
	void Reverse();
};

DLinkedList::DLinkedList(int A[], int n)
{
	Node *t, *last;
	first = new Node();
	first->data = A[0];
	first->next = first->prev = nullptr;
	last = first;
	for (int i = 1; i < n; i++)
	{
		t = new Node();
		t->data = A[i];
		t->next = nullptr;
		t->prev = last;
		last->next = t;
		last = t;
	}
}

DLinkedList::~DLinkedList()
{
	Node *p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

void DLinkedList::Display()
{
	Node *p = first;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void DLinkedList::Insert(int idx, int x)
{
	Node *p = first, *t;
	if (idx < 0 || idx > Length())
	{
		return;
	}
	else if (idx == 0)
	{
		t = new Node();
		t->data = x;
		t->prev = nullptr;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for (int i = 0; i < idx - 1; i++)
			p = p->next;
		t = new Node();
		t->data = x;
		t->prev = p;
		t->next = p->next;
		p->next = t;
	}
}

void DLinkedList::Delete(int idx)
{
	Node *p = first;
	if (idx < 0 || idx > Length())
		return;
	else if (idx == 0)
	{
		first = first->next;
		if (first)
			first->prev = nullptr;
		delete p;
	}
	else
	{
		for (int i = 0; i < idx - 1; i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if (p->next)
		{
			p->next->prev = p->prev;
		}
		delete p;
	}
}

int DLinkedList::Length()
{
	int len = 0;
	Node *p = first;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

void DLinkedList::Reverse()
{
	Node *p = first, *t;
	while (p)
	{
		t = p->next;
		p->next = p->prev;
		p->prev = t;
		first = p;
		p = t;
	}
	delete t;
}

int main()
{
	int A[] = {1, 2, 3, 4, 5};
	DLinkedList l(A, 5);
	l.Insert(5, 6);
	l.Reverse();
	l.Display();
	l.~DLinkedList();
	return 0;
}