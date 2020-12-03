#include<stdio.h>

#define MAX 100
int arr[MAX][MAX];

void remainder(int i, int x, int n)
{
	int p = 2, j = 0;
	for (j = i + 1; j < n; j++)
		arr[j][x] = p++;
	for (j = 0; j < i; j++)
		arr[j][x] = p++;

}
void onepos(int n)
{
	int r = n - 1;
	int l = 0;
	
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i][r] = 1;
			remainder(i, r, n);
			r--;
		}
		else
		{
			arr[i][l] = 1;
			remainder(i, l, n);
			l++;
		}
	}
}
void printmat(int n)
{
	int i, j;
	printf("\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int n;
	printf("Enter the order of the matrix:");
	scanf_s("%d", &n);

	onepos(n);
	printmat(n);
}