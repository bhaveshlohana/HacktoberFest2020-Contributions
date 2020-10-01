
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NU LL;


void printList() {

   struct node *ptr = head;

   printf("\n[head] =>");

   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void insert(int data) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
   link->next = head;
   head = link;
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   printList();
   return 0;
}
