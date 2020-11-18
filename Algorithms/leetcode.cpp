#include<bits/stdc++.h>
#include <sstream>  // for string streams 
#include <string>
using namespace std;
int best_pair(int price[], int profit, int n){
	map<int, int> mp;
	int dist = 1000;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(price[j]-price[i] == profit){
				mp[j] = (i+1) * 10 + (j+1);
				dist = min(j, dist);
			}
		}
	}
	return mp[dist];
}
string find_min_days(int profit[], int price[], int n, int d)
{
	string s, s_res;
	for(int i = 0; i < d; i++){
		stringstream ss;

		int temp = best_pair(price, profit[i], n);
		ss << temp;
		string str = ss.str();
		if(s.size() != 0){
			s += ',';
		}
		s += str;
	}
	int size = s.size();
	for(int i = 0; i < size; i++){
		s_res += s[i];
		if(s[i] != ',' && i != size-1){
			if(s[i+1] != ','){
			s_res += ' ';

			}
		}
	}
	return s_res;	
}

int main ()
{
	int n,d,i;
	string answer="";
	cin>>n>>d;
	int price[n];
	int profit[d];
	for (i=0;i<n;i++)
		cin>>price[i];
	for (i=0;i<d;i++)
	    cin>>profit[i];
    answer = find_min_days(profit,price, n, d);

    // Do not remove below line
	cout<<answer<<endl;
    // Do not print anything after this line

	return 0;
}

// int a = 10;
// char *intStr = itoa(a);
// string str = string(intStr);


// 6 2  
 
// 3 1 2 1 4 5
 
// 3
 
// 2


// 6 2
  
// 3 6 9 8 2 4 
 
// 5
 
// 2	

// ss << a;
// string str = ss.str();
