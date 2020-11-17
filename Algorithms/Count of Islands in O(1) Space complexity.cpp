#include <bits/stdc++.h> 
using namespace std; 
int r=5,c=5;
int isSafe(int a[][5], int row, int col) 
{ 
    return (row >= 0) && (row < r) && (col >= 0) && (col < c) && (a[row][col]>0); 
} 

void DFS(int a[][5], int row, int col) 
{ 

    a[row][col] = a[row][col]*-1; 

    if (isSafe(a, row + 1, col)) 
        DFS(a, row + 1, col ); 
    if (isSafe(a, row - 1, col)) 
        DFS(a, row - 1, col ); 
    if (isSafe(a, row , col + 1)) 
        DFS(a, row , col + 1); 
    if (isSafe(a, row , col-1)) 
        DFS(a, row , col - 1); 

} 

int countIslands(int a[][5]) 
{ 
    int count = 0; 
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 

            if (a[i][j]>0 ) { 
               DFS(a, i, j); 
               ++count; 
            } 
    return count; 
} 

int main() 
{ 
    int a[][5] =   { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 1, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 1, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 

    cout << "Number of islands is: " << countIslands(a); 

    return 0; 
}