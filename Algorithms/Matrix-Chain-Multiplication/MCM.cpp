#include <bits/stdc++.h>
#include<ctime>

using namespace std;

void printParenthesis(int i, int j, int n,vector<vector<int>>bracket, char &name)
{
  if (i == j)
  {
    cout << name++;
    return;
  }
  
  cout << "(";
  
  printParenthesis(i, bracket[i][j], n, bracket, name);
  printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
  cout << ")";
}

int main()
{
  clock_t c_start = clock();
  cout<<"Enter no.of matrices: ";
  int n;
  cin>>n;

  int dimensions[n+1];
  cout<<"Enter the dimensions of matrices:\n";
  
  for(int i=0;i<=n;i++)
  {
    cin>>dimensions[i];
  }

  vector<vector<int>>costTable(n+1,vector<int>(n+1,0));
  vector<vector<int>>kTable(n+1,vector<int>(n+1,0));
  
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n-i+1;j++)
    {
      int x=i+j-1;
      
      costTable[j][x]=INT_MAX;
      
      for(int k=j;k<x;k++)
      {
        int cost=costTable[j][k]+costTable[k+1][x]+dimensions[j-1]*dimensions[k]*dimensions[x];

        if(costTable[j][x]>cost)
        {
          costTable[j][x]=cost;
          kTable[j][x]=k;
        }
      }
  }
}

  cout<<endl<<endl;
  cout<<"Cost Table for matrix multiplication: \n";
  
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    { 
      cout<<costTable[i][j]<<" ";
    }
    cout<<endl;
  }

  char ch='A';
  cout<<endl;
  cout<<"Parenthesis for matrix multiplication: \n";
  
  printParenthesis(1, n, n, kTable, ch);
  cout<<endl;
  clock_t c_end = clock();
  long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
  cout << "\nCPU time used in MCM: " << time_elapsed_ms << " ms\n";
return 0;
}
