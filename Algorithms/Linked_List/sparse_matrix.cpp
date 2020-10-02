#include <iostream>
using namespace std;

class Node
{
public:
	int col;
	int row;
	int val;
	Node *next;
};

class Matrix
{
private:
	Node *first;
	int rows, cols;

public:
	Matrix(int a)
	{
		first->val = a;
		first->row = first->col = 0;
		first->next = nullptr;
		cols = rows = 1;
	}
	Matrix(int **A, int m, int n);
	~Matrix();
	void Display();
};

Matrix::Matrix(int **A, int m, int n)
{
	rows = m;
	cols = n;
	Node *t, *last;
	first = new Node();
	first->val = A[0][0];
	first->row = first->col = 0;
	first->next = nullptr;
	last = first;
	for (int i = 0; i < m; i++)
	{
		if (i != 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[i][j] != 0)
				{
					t = new Node();
					t->val = A[i][j];
					t->row = i;
					t->col = j;
					t->next = nullptr;
					last->next = t;
					last = t;
				}
			}
		}
		else
		{
			for (int j = 1; j < n; j++)
			{
				if (A[i][j] != 0)
				{
					t = new Node();
					t->val = A[i][j];
					t->row = i;
					t->col = j;
					t->next = nullptr;
					last->next = t;
					last = t;
				}
			}
		}
	}
}

Matrix::~Matrix()
{
	Node *p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

void Matrix::Display()
{
	Node *p = first;
	while (p)
	{
		cout << "row:" << p->row << " "
			 << "col:" << p->col << " "
			 << "val:" << p->val << endl;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int m, n;
	cout << "Enter row and column\n";
	cin >> m >> n;
	int **A = new int *[m];
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	Matrix mat(A, 3, 3);
	mat.Display();
	mat.~Matrix();
	return 0;
}