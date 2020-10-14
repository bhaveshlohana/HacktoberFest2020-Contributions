#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int minimum(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main()
{
	int mat[MAX][MAX], temp_mat[MAX][MAX],temp=0,temp2=0, i, j, k, l, n=0, m=0;
	printf("Enter the order of matrix (Rows x Coloumns) (Enter Separated) : ");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	printf("\nEnter the matrix elements of order (%dx%d):\n",n,m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf_s("%d", &mat[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			temp_mat[i][j] = INT_MAX;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < n; k++)
			{
				for (l = 0; l < m; l++)
				{
					if (mat[k][l] == 1)
					{
						temp = abs(i - k) + abs(j - l);
						if (temp < temp_mat[i][j])
							temp_mat[i][j] = temp;
						else
							temp_mat[i][j] = temp_mat[i][j];
					}
				}
			}
		}
	}
	printf("\nThe Distance Matrix is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", temp_mat[i][j]);
		}
		printf("\n");
	}
}