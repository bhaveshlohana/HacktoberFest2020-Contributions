#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void display(struct Node *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}
void duplicates(struct Node *p)
{
  struct Node *pre,*q;
  pre = first;
  while(pre!=NULL && pre->next!=NULL){
      q = pre;
      while(q->next !=NULL){
          if(pre->data ==q->next->data ){
              struct Node*n = q->next;
              q->next = q->next->next;
              free(n); 
          }
          else{
              q=q->next;
          }
      }
      pre=pre->next;
  }
}
int main()
{
    int n, element;
    printf("Enter no of nodes");
    scanf("%d", &n);
    struct Node *t, *last;
    printf("enter data of 1 node");
    scanf("%d", &element);
 
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = element;
    first->next = NULL;
    last = first;

    for (int i = 2; i <= n; i++)
    {
        printf("enter data of %d node", i);
        scanf("%d", &element);
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = element;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    display(first, n);
    duplicates(first);
    printf("\nAfter removing duplicates\n");
    display(first, n);
}