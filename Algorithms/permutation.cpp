#include <bits/stdc++.h>
using namespace std;

void perm(char s[], int l, int h)
{
	if(l==h) cout << s << "\n" ;
	else{
		for(int i=l; i<=h; i++){
			swap(s[l],s[i]);
			perm(s, l+1, h);
			swap(s[l],s[i]);
		}
	}
}

int main(){
	char s[] = "permutation";
	perm(s, 0, 10);
}
