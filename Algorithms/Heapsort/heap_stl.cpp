#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){

vector<int> v1= {40,20,15,10,5};

//converting vector into heap
//using make heap function

make_heap(v1.begin(),v1.end());
v1.push_back(70);
push_heap(v1.begin(),v1.end());

//Displaying max element of heap

//using front()

cout<<"The maximum element of heap is: ";
cout<<v1.front()<<endl;

for(int i= 0;i<v1.size();i++){
cout<<v1[i]<<endl;
}

cout<<"After pushing" <<endl;
for(int i= 0;i<v1.size();i++)
{
cout<<v1[i]<<endl;
}

pop_heap(v1.begin(),v1.end());

cout<<"After Popping:\n";

for(int i=0;i<v1.size();i++)
cout<<v1[i]<<endl;


vector<int>::iterator it1;
if(is_heap(v1.begin(),v1.end()))
cout<<"The container is heap:";
else
cout<<"The container is not heap:";
cout<<endl;


vector<int>::iterator it= is_heap_until(v1.begin(),v1.end());

cout<<"The heap elements in container are:";
for(it1 = v1.begin();it1!= it;it1++)

cout<<*it1<<" ";
cout<<endl;

return 0;
}
