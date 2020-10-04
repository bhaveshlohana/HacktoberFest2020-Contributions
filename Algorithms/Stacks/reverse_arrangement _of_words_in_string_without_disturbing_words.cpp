/*
input=
1
i.like.this.program.very.much

output=
much.very.program.this.like.i        
*/

#include <iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    stack<char>s;
	    stack<char>temp;
	    for(int i=0;i<str.size();i++)
	    {
	        s.push(str[i]);
	    }
	    while(!s.empty())
	    {
	        char x=s.top();
	        s.pop();
	        if(x=='.'){
	            while(!temp.empty())
	            {
	                cout<<temp.top();
	                temp.pop();
	            }
	            cout<<x;
	        }
	        else
	        {
	            temp.push(x);
	        }
	    }
	     while(!temp.empty())
	            {
	                cout<<temp.top();
	                temp.pop();
	            }
	    cout<<'\n';
	}
	return 0;
}
