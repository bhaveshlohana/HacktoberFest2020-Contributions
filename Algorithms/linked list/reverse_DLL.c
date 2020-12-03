#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *prev;
  int data;
  struct node *next;
};
struct node* create(){
  struct node *first;
  first=(struct node*)malloc(sizeof(struct node));
  first->prev=NULL;
  first->next=NULL;
  printf("Enter data for node\n");
  scanf("%d",&first->data);
  return first;
}
void printlist(struct node *start){
  struct node *p;
  p=start;
  printf("\n");
  while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}
int main(){
struct node *f=NULL;
f=create();
struct node *s=NULL;
s=create();
f->next=s;
s->prev=f;
s->next=NULL;
struct node *t=NULL;
t=create();
s->next=t;
t->prev=s;
t->next=NULL;
printf("\nA three node list has been created.\n");
printlist(f);
struct node *p;
p=f;
struct node *temp;
while(p!=NULL){
  temp=p->prev;
  p->prev=p->next;
  p->next=temp;
  p=p->prev;
}
printf("\nReverse of the three node list has been created.\n");
printlist(temp->prev);
return 0;
}
