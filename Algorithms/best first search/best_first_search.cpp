// To study and implement Best First search using priority queue.
#include <iostream> 
#include <queue> 
#include <bits/stdc++.h>
using namespace std; 
  
class node { 
  
public: 
	int vex; 
  	int heuristic;//heuristic value
  
    // this is used to initialize the variables of the class 
    node(int v, int heu_value) 
        :vex(v),heuristic(heu_value) 
    { 
    } 
}; 
  
// doing operator overloading  
bool operator<(const node& n1, const node& n2) 
{ 
  
    // this will return true when second node has smaller heuristic. For e.g. we have n1.heuristic=10 and n2.heuristic=7 then the node which have 
   // least heuristic value will have the max priority
    return n1.heuristic > n2.heuristic; 
} 
struct info
{
	int vex;
	int heuristic;
	struct info* link;
};

int main() 
{ 
  	int num; //enter no. of vertices of graph
  	cout<<"Enter the total No. of vertices in graph: ";
	cin>>num;
	struct info* nodes[num+1];
	
	for(int i=0; i<=num; i++ )
	{
		nodes[i]=new info;
	}
	
	int neigh,value,b; //neigh - number of neighbor nodes, 
  
  	bool marked[num+1];
	memset(marked, 0, sizeof(marked));
	
	for(int i=1; i<=num; i++)
	{
		//Adding elements of graph
		cout<<"Enter the heuristic value & the count of subnodes of node "<<i<<": ";
		cin>>value>>neigh;
		struct info *temp=nodes[i];
		temp->heuristic=value;
		temp->vex=i;
		cout<<"Enter the subnodes & heuristic value of node "<<i<<endl;
		for(int j=0; j<neigh; j++)
		{
			temp->link=new struct info();
			temp=temp->link;
			cin>>b>>value;
			temp->heuristic=value;
			temp->vex=b;
		}
		temp->link=NULL;
	}
    //the order of the graph with their subnodes with their heuristic values
	cout<<"\nThe order represented using linked list as : subnodes (heuristic value)\n";
	for(int i=1; i<=num; i++)
	{
		struct info *temp = nodes[i];
		while(temp)
		{
			cout<<temp->vex<<"->"<<" ("<<temp->heuristic<<") ";
			temp=temp->link;
		}
		cout<<endl;
	}
	
	cout<<"\nThe order of the best first search traversal is as follows: \n";
    priority_queue <node> Q; 
  	 
  	int top;
  	struct info *temp = nodes[1];
	Q.push(node(temp->vex, temp->heuristic));
	marked[1]=true;
 	priority_queue <node> T; 
 	
	node x= Q.top();
	cout << x.vex << "  (" << x.heuristic<<") --> " << "\n"; 
	do
	{	
		// To enter the details of the sub nodes
		while(temp)
		{
			if(!marked[temp->vex])
				{
					Q.push(node(temp->vex, temp->heuristic));
					marked[temp->vex]= true;
				}
			temp=temp->link;
		}
		
		while(!T.empty())
		{
			node n = T.top();
			Q.push(node(n.vex, n.heuristic));
			T.pop();	
		}		
		
		while(!Q.empty())
		{
			node n = Q.top();
			T.push(node(n.vex, n.heuristic));
			Q.pop();
		}
		
		// T.top() refers to the node with the least heuristic value.
		x = T.top();
		top=x.vex;
		temp=nodes[top];
		cout << x.vex << "  (" << x.heuristic<<") --> " << " ";  	
		T.pop();	
	}
	while(!T.empty() && x.heuristic!=0);
	// repeat until the FINAL state i.e. heuristic = 0 is reached or the desired node is not available, in that case T would be empty.
  

    return 0; 
} 
