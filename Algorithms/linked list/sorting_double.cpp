#include <iostream>
struct Node {
int data ;
Node *next, *prev;

};
Node*head = NULL;
Node * tail = NULL;
void add (int n){
Node *t = new Node;
t -> data = n;
t -> next = NULL;
if (head == NULL)
{
head = t;
tail = t;

}
else{
t -> next = head;
head = t;
t -> next -> prev = t;
}
}
void sort(){
Node *t = new Node;
t = tail;
for (;t->prev!= NULL;t=t->prev){
for (Node *j = t->prev;j!=NULL;j =j-> prev){
if (t->data > j-> data){
int temp = t-> data;
t->data = j->data;
j->data = temp;
}
}
}
}
void print(){
Node *t = new Node;
t= tail;
while (t){
std:: cout << t->data;
t= t-> prev;
}
}
int main() {
add(2);
add(3);
add(9);
add(4);
add(1);
sort();
print();

}
