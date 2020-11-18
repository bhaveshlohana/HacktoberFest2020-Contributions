#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
struct Node *next;};

Node *inserting(Node *head,int data)
{
Node *t= new Node();
t->data= data;
t->next= head;
return t;
}
Node *segregate(Node *head)
{
Node *odd_start,*odd_end,*even_start,*even_end;
odd_start=odd_end=even_start=even_end=NULL;
while(head!= NULL)
{
if(head->data %2 ==0)
{
if(even_start== NULL)
even_end=even_start= head;
else
{
even_end->next= head;
even_end= even_end->next;
}

}
else
{
if(odd_start== NULL)
odd_start= odd_end= head;
else
{
odd_end->next= head;
odd_end= odd_end->next ;
}
}
head= head->next;
}
if(even_start== NULL || odd_start== NULL) return head;
else
{
even_end->next= odd_start;
odd_end->next= NULL;
}
return even_start;
}

void print(Node *head)
{
while(head!= NULL)
{
cout<<(head->data)<<"\t";
head = head->next;
}
}
int main()
{
Node *head= NULL;
head= inserting(head,10);
head= inserting(head,3);
head= inserting(head,140);
head= inserting(head,35);
head= inserting(head,130);
head= inserting(head,36);
head= inserting(head,160);
head= inserting(head,31);
// segregate into even and odd
cout<<"Original List is ::\n";
print(head);
head= segregate(head);
cout<<"\nList after segregating is ::\n";
print(head);

return 0;
}
