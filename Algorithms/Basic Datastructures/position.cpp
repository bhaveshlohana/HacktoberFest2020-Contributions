/*You are given a linked list, L, and another linked list, P, containing integers sorted in ascending order.
The operation PrintLots(L,P) will print the elements in L that are in positions specified by P.
For instance, if P = 1,3,4,6, the first, third, fourth, and sixth elements in L are printed.
Write the procedure PrintLots(L,P).*/

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* link;
};

void printLots(struct node* L,struct node* P)
{
    struct node* dummyP;
    struct node* dummyL;
    int i = 0, idx, outofelement;

    dummyP = P->link;
    dummyL = L->link;

    while (dummyP != NULL)
    {
        idx = dummyP->data;
        if (idx >= 0)
        {
            if (idx < i)
            {
                dummyL = L->link;
                i = 0;
            }
            for(; i < idx; i++)
            {
                if (dummyL->link != NULL)
                {
                    dummyL = dummyL->link;
                }
                else
                {
                    outofelement = 1;
                    break;
                }
            }
            if (outofelement == 1)
            {
                cout<<idx<<" ";
            }
            else{
                cout<<dummyL->data;
            }
        }
        else
        {
            exit(EXIT_FAILURE);
        }
        outofelement = 0;
        dummyP = dummyP->link;
    }
}

void push(struct node** list, int add){
    node* temp = new node;
    temp->data=add;
    temp->link= *list;
    *list = temp;
}

int main(){
    int n,m,add;
    char wc;
    struct node* list1=NULL;
    struct node* list2=NULL;
    cout<<"Enter the Max of List 1: ";
    cin>>n;
    cout<<"Enter the Max of List 1: ";
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>add;
        push(&list1,add);
    }
    for(int i=0;i<m;i++){
        cin>>add;
        push(&list2,add);
    }
    printLots(list1,list2);
    cout<<endl;
}

