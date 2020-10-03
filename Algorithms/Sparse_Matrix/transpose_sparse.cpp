#include<stdio.h>
#include<iostream>

using namespace std;

//read all the assumptions carefully
class spm
{
       int r,c,v;
public:
    void push(spm *a)
    {
        int k=1;
        int m,n,ele;
        cout<<"Enter rows and columns"<<endl;
        cin>>m>>n;
        a[0].r=m;
        a[0].c=n;
        cout<<"Enter values of matrix"<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ele;
                if(ele==0)
                    continue;
                a[k].r=i;
                a[k].c=j;
                a[k].v=ele;
                k++;
            }
        }
        a[0].v=k-1;
    }
    void displaytrans(spm *a,spm *b)
    {
         int k=1;
         b[0].r=a[0].c;
         b[0].c=a[0].r;
         b[0].v=a[0].v;
         for(int i=0;i<a[0].c;i++)
         {
             for(int j=1;j<=a[0].v;j++)
             {
                 if(a[j].c==i)
                 {
                     b[k].r=a[j].c;
                     b[k].c=a[j].r;
                     b[k].v=a[j].v;
                     k++;
                 }
             }
         }
         cout<<"Transpose:"<<endl;
         display(b);
    }
    void display(spm *a)
    {
        cout<<"\nr\tc\tv"<<endl;
        cout<<a[0].r<<"\t"<<a[0].c<<"\t"<<a[0].v<<endl;
        cout<<"-------------------"<<endl;
        for(int i=1;i<=a[0].v;i++)
        {
            cout<<a[i].r<<"\t"<<a[i].c<<"\t"<<a[i].v<<endl;
        }
        cout<<"\n";
    }
    void displaytransMat(spm *a)
    {
       int k=1;
       cout<<"In Matrix Form: "<<endl;
       for(int i=0;i<a[0].r;i++)
       {
           for(int j=0;j<a[0].c;j++)
           {
               if(a[k].r==i && a[k].c==j)
               {
                   cout<<a[k].v<<"\t";
                   k++;
               }
               else
               {
                   cout<<"0\t";
               }
           }
           cout<<"\n";
       }
       cout<<"\n";
    }
};

int main()
{
    //test program...you can add your own
    spm a1,a[50],b[50];
    a1.push(a);
    a1.display(a);
    a1.displaytrans(a,b);
    a1.displaytransMat(b);
}
