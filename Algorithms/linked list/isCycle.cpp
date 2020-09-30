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
bool isCycle(node *head){
  //1 -> 2 -> 3 -> 4 -> 5 return 3
  //11 -> 12 -> 13 -> 14 return 12
  if(!head)
    return false
  node *fast = head, *slow = head;
  while(1){
    fast = fast -> next;
    if(!fast)
      break;
    fast = fast->next;
    if(!fast)
      break;
    slow = slow->next;
    
    if(fast == slow)
      return true;
  }
  return false;
}

int main(){
  //call here
}
