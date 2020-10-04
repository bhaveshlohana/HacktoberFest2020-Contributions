#include<bits/stdc++.h>	
using namespace std;
struct Node{
	int number;
	Node* link;
};
Node* start = nullptr;
int insert_reverse(int n){
	Node *first = new Node;
	first->number = n;
	first->link = start;
	start = first;
	return 0;
}
void print(){
	if(start == nullptr){
		cout << "Empty linked list" << endl;
	}
	else{
		while(start != nullptr){
		cout << start->number << endl;
		start = start->link;
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    thread t2(insert_reverse,10);
    thread t3(insert_reverse,20);
    t2.join();
    t3.join();
    print();
}
