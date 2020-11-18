#include<bits/stdc++.h>
using namespace std;

int main()
{ 
  int N;
  cin>>N;
  int Prefix[N+1];
  Prefix[1] = 1; Prefix[2] = 2;
	for(int i = 3; i <= N ; i++) Prefix[i] = i;
	for(int i=2; i < N; i++){
		if (Prefix[i] != i) continue;
		for(int j = 2*i; j < N; j+=i){
			if (Prefix[j] == j)
				Prefix[j] = i;
		}
	}

}
