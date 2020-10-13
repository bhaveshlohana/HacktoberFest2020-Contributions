Problem Statement:-
	N-Queen Problem
        You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. 
	A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 



#include<bits/stdc++.h>
using namespace std;
    //To print the matrix
void printer(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
    cout << endl;
}
  // To check that whether i can put queen at at particular index of row and coloumn or not
bool checker(int **arr,int row,int col,int n)
{

// Checking Same Column
    for(int i=row-1;i>=0;i--)
    {
        if(arr[i][col] == 1)
        {
            return false;
        }
    }
//Checking Upper Left Diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--)
    {
        if(arr[i][j] ==1)
        {
            return false;
        }
    }

  // Checking Upper Right Diagonal

    for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++)
    {
        if(arr[i][j] == 1)
        {
            return false;
        }
    }
    // If none of above is an obstacle then we should return true 
  return true;
}
       // To place all the queens
void placer(int** arr, int row, int n)
{
	// If the row equals to n it means we have filled all the rows and reached to n so
	// time to print the output by calling or print function we made on top
	if (row == n)
	{
		printer(arr, n);
		return;
	}
	// for each coloumn we are passing rows and checking all possible arrangements.
    for(int j=0;j<n;j++)
    {
        if(checker(arr,row,j,n))
        {
            arr[row][j] = 1;
            placer(arr,row+1,n);
		// when we will return to this position time to make it 0 and move to next coloumn and check out remaining possiblity.
            arr[row][j] = 0;
        }
    }
    return;
}
void placeNQueens(int n)
{
	// Declared a 2-d Array to store all the correct positions and initialised it with zero
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	// Called a Helper function by passing it our 2-d array and n.
     placer(arr, 0, n); 
	// Deleted the 2-D array we made to release all the occupied space.
    for(int i=0; i<n; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
int main()
{

  int n; 
  cin >> n ;
  placeNQueens(n);

}

