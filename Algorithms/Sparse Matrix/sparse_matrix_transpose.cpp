#include<iostream>
using namespace std;
void fasttranspose(int B[30][3]);
void simpletranspose(int C[30][3]);
int main()
{
    int i,k=1,j,m,n,valcnt=0;
    int a[30][30],sparse[30][3];
    cout<<"Enter the number of rows of matrix\n";
    cin>>m;
    cout<<"Enter the number of columns of matrix \n";
    cin>>n;
    cout<<"**************************************************************\n";
    cout<<"Start entering the matrix elements\n";
    sparse[0][0]=m;
    sparse[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"The matrix is :\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                valcnt++;
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=a[i][j];
                k++;
            }
        }
    }
    sparse[0][2]=valcnt;
    cout<<"**************************************************************\n";
    cout<<"The sparse matrix is\n";
    cout<<"\n";
    for(i=0;i<=valcnt;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<sparse[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }
    cout<<"**************************************************************\n";
    //fasttranspose(sparse);
    simpletranspose(sparse);
}
void fasttranspose(int B[30][3])
{
    int C[30][3];
     int i,j,m,n,position[3]={0,0,0},frequency[3]={0,0,0};
     for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        frequency[m]++;
    }
    position[0] = 1;
    for (i=1;i<B[0][1];i++)
    {
        position[i] = position [i-1] + frequency[i-1];
    }
    for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        n= position[m];
        position[m]++;
        C[n][0] = B[i][1];
        C[n][1] = B[i][0];
        C[n][2] = B[i][2];
    }
    C[0][0] = B[0][0];
    C[0][1] = B[0][1];
    C[0][2] = B[0][2];
    for(i=0;i<=B[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<C[i][j]<<" ";

        }
        cout<<"\n";
    }

}
void simpletranspose(int C[30][3])
{
    int i,j,temp;
    for(i=1;i<=C[0][2];i++)
    {
        temp=C[i][1];
        C[i][1]=C[i][0];
        C[i][0]=temp;
    }
   cout<<"THE before sort vala transpose\n";
   for(i=0;i<=C[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<C[i][j]<<" ";

        }
        cout<<"\n";
    }

    for(i=0;i<=C[0][2];i++)
    {
        for(j=1;j<C[0][2];j++)
        {
            if(C[j][0]>C[j+1][0])
            {
                temp=C[j][0];
                C[j][0]=C[j+1][0];
                C[j+1][0]=temp;
                temp=C[j][1];
                C[j][1]=C[j+1][1];
                C[j+1][1]=temp;
                temp=C[j][2];
                C[j][2]=C[j+1][2];
                C[j+1][2]=temp;
            }
        }
    }
     for(i=0;i<=C[0][2];i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<C[i][j]<<" ";

        }
        cout<<"\n";
    }

}