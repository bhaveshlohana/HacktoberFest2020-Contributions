#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
  node(val){
    data = val;
    next = NULL;
  }
};
node* findMiddle(node *head){
  //1 -> 2 -> 3 -> 4 -> 5 return 3
  //11 -> 12 -> 13 -> 14 return 12

  node *fast = head, *slow = head;
  while(1){
    fast = fast -> next;
    if(!fast)
      return slow;
    fast = fast->next;
    if(!fast)
      return slow;
    slow = slow->next;
  }
}

int main(){
  //call here
}
